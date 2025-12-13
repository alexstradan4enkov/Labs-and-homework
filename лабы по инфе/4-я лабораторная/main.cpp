#include <iostream>
#include <pqxx/pqxx>
#include <fstream>

using namespace std;

void logAction(const string& msg)
{
    ofstream log("log.txt", ios::app);
    log << msg << endl;
}

class Product {
protected:
    string name;
    double price;

public:
    Product(string n, double p) : name(n), price(p) {}
    virtual ~Product() {}
    virtual string type() const = 0;

    virtual void save(pqxx::connection& c)
    {
        pqxx::work txn(c);
        txn.exec(
            "INSERT INTO products (name, price, product_type) VALUES (" +
            txn.quote(name) + ", " +
            txn.quote(price) + ", " +
            txn.quote(type()) + ")"
        );
        txn.commit();
        logAction("Добавлен продукт: " + name);
    }
};

class DigitalProduct : public Product {
public:
    DigitalProduct(string n, double p) : Product(n, p) {}
    string type() const override { return "digital"; }
};

class PhysicalProduct : public Product {
public:
    PhysicalProduct(string n, double p) : Product(n, p) {}
    string type() const override { return "physical"; }
};

int createOrder(pqxx::connection& c)
{
    pqxx::work txn(c);
    auto r = txn.exec(
        "INSERT INTO orders (order_date) VALUES (CURRENT_DATE) RETURNING order_id"
    );
    txn.commit();
    logAction("Создан заказ");
    return r[0][0].as<int>();
}

void addOrderItem(pqxx::connection& c, int oid, int pid, int qty)
{
    pqxx::work txn(c);
    auto r = txn.exec(
        "SELECT price FROM products WHERE id=" + txn.quote(pid)
    );
    double price = r[0][0].as<double>();
    double total = price * qty;

    txn.exec(
        "INSERT INTO order_items (order_id, product_id, quantity, total_price) VALUES (" +
        txn.quote(oid) + "," +
        txn.quote(pid) + "," +
        txn.quote(qty) + "," +
        txn.quote(total) + ")"
    );
    txn.commit();
    logAction("Добавлена позиция заказа");
}

void revenue(pqxx::connection& c)
{
    pqxx::work txn(c);
    auto r = txn.exec(
        "SELECT name, SUM(total_price) AS revenue "
        "FROM products p JOIN order_items oi ON p.id=oi.product_id "
        "GROUP BY name"
    );

    cout << "\n--- Общая выручка по каждому товару ---\n";
    for (auto row : r)
        cout << row["name"].c_str()
        << " | Выручка: " << row["revenue"].as<double>() << endl;
}

void top3Products(pqxx::connection& c)
{
    pqxx::work txn(c);
    auto r = txn.exec(
        "SELECT name, SUM(quantity) AS total_sold "
        "FROM products p JOIN order_items oi ON p.id=oi.product_id "
        "GROUP BY name "
        "ORDER BY total_sold DESC "
        "LIMIT 3"
    );

    cout << "\n--- Топ-3 самых продаваемых товаров ---\n";
    for (auto row : r)
        cout << row["name"].c_str()
        << " | Продано: " << row["total_sold"].as<int>() << endl;
}

void averageOrderValue(pqxx::connection& c)
{
    pqxx::work txn(c);
    auto r = txn.exec(
        "SELECT AVG(order_total) FROM ("
        "SELECT order_id, SUM(total_price) AS order_total "
        "FROM order_items "
        "GROUP BY order_id) t"
    );

    cout << "\n--- Средняя стоимость заказа ---\n";
    cout << r[0][0].as<double>() << endl;
}

void orderCountPerProduct(pqxx::connection& c)
{
    pqxx::work txn(c);
    auto r = txn.exec(
        "SELECT name, COUNT(DISTINCT order_id) AS orders_count "
        "FROM products p JOIN order_items oi ON p.id=oi.product_id "
        "GROUP BY name"
    );

    cout << "\n--- Количество заказов для каждого товара ---\n";
    for (auto row : r)
        cout << row["name"].c_str()
        << " | Заказов: " << row["orders_count"].as<int>() << endl;
}

int main()
{   
    setlocale(LC_ALL, "Russian");
    try {
        pqxx::connection c(
            "dbname=sales_db user=postgres password=GP1A042372 host=localhost"
        );

        cout << "Connected to " << c.dbname() << endl;

        int ch;
        while (true) {
            cout << "\n1 Добавить товар\n2 Создать заказ\n3 Добавить позицию\n4 Выручка\n5 Топ-3 товаров\n6 Средняя стоимость заказа\n7 Количество заказов по товару\n0 Выход\n> ";
            cin >> ch;

            if (ch == 0) break;
            if (ch == 1) {
                string name;
                double price;
                int t;
                cout << "Название цена тип(1-digital 2-physical): ";
                cin >> name >> price >> t;

                Product* p = (t == 1)
                    ? (Product*)new DigitalProduct(name, price)
                    : (Product*)new PhysicalProduct(name, price);

                p->save(c);
                delete p;
            }

            if (ch == 2)
                cout << "ID заказа: " << createOrder(c) << endl;

            if (ch == 3) {
                int o, p, q;
                cout << "order_id product_id quantity: ";
                cin >> o >> p >> q;
                addOrderItem(c, o, p, q);
            }

            if (ch == 4)
                revenue(c);

            if (ch == 5)
                top3Products(c);

            if (ch == 6)
                averageOrderValue(c);

            if (ch == 7)
                orderCountPerProduct(c);
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}
