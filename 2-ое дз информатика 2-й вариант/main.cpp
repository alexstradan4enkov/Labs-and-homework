#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <pqxx/pqxx>

// Структуры
struct Sale {
    int sale_id;
    std::string sale_date;
    int product_id;
    int customer_id;
    int quantity;
    double amount;
};

struct Product {
    int product_id;
    std::string product_name;
    std::string category;
    double price;
};

struct Customer {
    int customer_id;
    std::string customer_name;
    std::string region;
};

// Функция для чтения CSV
template<typename T>
std::vector<T> loadCSV(const std::string& filename, const std::string& type) {
    std::vector<T> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file " << filename << std::endl;
        return data;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        // Пропускаем пустые строки
        if (line.empty()) continue;

        std::stringstream ss(line);
        T record;
        std::string temp;

        try {
            if (type == "sale") {
                std::getline(ss, temp, ',');
                record.sale_id = std::stoi(temp);

                std::getline(ss, record.sale_date, ',');

                std::getline(ss, temp, ',');
                record.product_id = std::stoi(temp);

                std::getline(ss, temp, ',');
                record.customer_id = std::stoi(temp);

                std::getline(ss, temp, ',');
                record.quantity = std::stoi(temp);

                std::string amount_str;
                std::getline(ss, amount_str);
                if (!amount_str.empty()) {
                    record.amount = std::stod(amount_str);
                }
                else {
                    record.amount = 0.0;
                }
            }
            else if (type == "product") {
                std::getline(ss, temp, ',');
                record.product_id = std::stoi(temp);

                std::getline(ss, record.product_name, ',');
                std::getline(ss, record.category, ',');

                std::string price_str;
                std::getline(ss, price_str);
                if (!price_str.empty()) {
                    record.price = std::stod(price_str);
                }
                else {
                    record.price = 0.0;
                }
            }
            else if (type == "customer") {
                std::getline(ss, temp, ',');
                record.customer_id = std::stoi(temp);

                std::getline(ss, record.customer_name, ',');
                std::getline(ss, record.region);
            }

            data.push_back(record);
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << std::endl;
            std::cerr << "Error: " << e.what() << std::endl;
            continue;
        }
    }
    file.close();

    std::cout << "Loaded " << data.size() << " records from " << filename << std::endl;
    return data;
}

// Преобразование даты 
std::string convertToDateFormat(const std::string& date_str) {
    // Просто проверяем, что дата не пустая и возвращаем как есть
    if (date_str.empty()) {
        return "";
    }
    return date_str; // CSV уже содержит даты в формате YYYY-MM-DD
}

// Функции вставки в таблицы 
void insertProducts(pqxx::connection& conn, const std::vector<Product>& products) {
    pqxx::work txn(conn);
    for (const auto& p : products) {
        txn.exec_params(
            "INSERT INTO products_dim(product_id, product_name, category, price) VALUES($1,$2,$3,$4)",
            p.product_id, p.product_name, p.category, p.price
        );
    }
    txn.commit();
    std::cout << "Данные products_dim загружены.\n";
}

void insertCustomers(pqxx::connection& conn, const std::vector<Customer>& customers) {
    pqxx::work txn(conn);
    for (const auto& c : customers) {
        txn.exec_params(
            "INSERT INTO customers_dim(customer_id, customer_name, region) VALUES($1,$2,$3)",
            c.customer_id, c.customer_name, c.region
        );
    }
    txn.commit();
    std::cout << "Данные customers_dim загружены.\n";
}

void insertSales(pqxx::connection& conn, const std::vector<Sale>& sales) {
    pqxx::work txn(conn);
    for (const auto& s : sales) {
        std::string date_str = convertToDateFormat(s.sale_date);
        txn.exec_params(
            "INSERT INTO sales_fact(sale_id, sale_date, product_id, customer_id, quantity, amount) VALUES($1,$2,$3,$4,$5,$6)",
            s.sale_id, date_str, s.product_id, s.customer_id, s.quantity, s.amount
        );
    }
    txn.commit();
    std::cout << "Данные sales_fact загружены.\n";
}

// Аналитические запросы 

void runAnalytics(pqxx::connection& conn) {
    struct Query {
        std::string sql;
        std::string description;
    };

    std::vector<Query> queries = {
        { "SELECT p.category, SUM(s.amount) AS total_sales "
          "FROM sales_fact s "
          "JOIN products_dim p ON s.product_id = p.product_id "
          "GROUP BY p.category "
          "ORDER BY total_sales DESC;", "Объем продаж по категориям" },

        { "SELECT c.region, COUNT(s.sale_id) AS number_of_sales "
          "FROM sales_fact s "
          "JOIN customers_dim c ON s.customer_id = c.customer_id "
          "GROUP BY c.region "
          "ORDER BY number_of_sales DESC;", "Количество покупок по регионам" },

        { "SELECT EXTRACT(YEAR FROM s.sale_date) AS year, "
          "EXTRACT(MONTH FROM s.sale_date) AS month, "
          "AVG(s.amount) AS average_ticket "
          "FROM sales_fact s "
          "GROUP BY year, month "
          "ORDER BY year, month;", "Средний чек по месяцам" }
    };

    for (const auto& q : queries) {
        std::cout << "\n=== " << q.description << " ===\n";

        try {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec(q.sql);

            int nfields = res.columns();

            // Заголовки
            for (int i = 0; i < nfields; i++) {
                std::cout << res.column_name(i) << "\t";
            }
            std::cout << "\n";

            // Данные
            for (const auto& row : res) {
                for (int i = 0; i < nfields; i++) {
                    std::cout << row[i].c_str() << "\t";
                }
                std::cout << "\n";
            }

        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка выполнения запроса '" << q.description << "': " << e.what() << std::endl;
        }
    }
}

// Главная функция
int main() {
    try {
        std::cout << "Starting program..." << std::endl;

        // Сначала проверим наличие CSV файлов
        std::ifstream test1("products.csv");
        std::ifstream test2("customers.csv");
        std::ifstream test3("sales.csv");

        if (!test1.is_open()) std::cout << "ERROR: products.csv not found!" << std::endl;
        else std::cout << "products.csv found" << std::endl;

        if (!test2.is_open()) std::cout << "ERROR: customers.csv not found!" << std::endl;
        else std::cout << "customers.csv found" << std::endl;

        if (!test3.is_open()) std::cout << "ERROR: sales.csv not found!" << std::endl;
        else std::cout << "sales.csv found" << std::endl;

        test1.close();
        test2.close();
        test3.close();

        // Подключение к БД
        std::cout << "Connecting to database..." << std::endl;
        pqxx::connection c("dbname=dwh user=postgres password=GP1A042372 host=localhost");

        if (conn.is_open()) {
            std::cout << "Connected to database: " << conn.dbname() << std::endl;
        }
        else {
            std::cerr << "Cannot connect to database!" << std::endl;
            return 1;
        }

        // Загрузка CSV
        std::cout << "\nLoading CSV files..." << std::endl;
        auto products = loadCSV<Product>("products.csv", "product");
        auto customers = loadCSV<Customer>("customers.csv", "customer");
        auto sales = loadCSV<Sale>("sales.csv", "sale");

        std::cout << "Products loaded: " << products.size() << std::endl;
        std::cout << "Customers loaded: " << customers.size() << std::endl;
        std::cout << "Sales loaded: " << sales.size() << std::endl;

        // Проверка данных
        if (products.empty() || customers.empty() || sales.empty()) {
            std::cerr << "ERROR: One or more CSV files are empty!" << std::endl;
            return 1;
        }

       
        // Аналитика
        std::cout << "\nRunning analytics..." << std::endl;
        runAnalytics(conn);

        std::cout << "\nPROGRAM COMPLETED SUCCESSFULLY!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "\nEXCEPTION: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
