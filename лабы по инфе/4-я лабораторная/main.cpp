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
        logAction("Äîáàâëåí ïðîäóêò: " + name);
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
    logAction("Ñîçäàí çàêàç");
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
    logAction("Äîáàâëåíà ïîçèöèÿ çàêàçà");
}

void revenue(pqxx::connection& c)
{
    pqxx::work txn(c);
    auto r = txn.exec(
        "SELECT name, SUM(total_price) AS revenue "
        "FROM products p JOIN order_items oi ON p.id=oi.product_id "
        "GROUP BY name"
    );

    for (auto row : r)
        cout << row["name"].c_str()
        << " | Âûðó÷êà: " << row["revenue"].as<double>() << endl;
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
            cout << "\n1 Äîáàâèòü òîâàð\n2 Ñîçäàòü çàêàç\n3 Äîáàâèòü ïîçèöèþ\n4 Âûðó÷êà\n0 Âûõîä\n> ";
            cin >> ch;

            if (ch == 0) break;

            if (ch == 1) {
                string name;
                double price;
                int t;
                cout << "Íàçâàíèå öåíà òèï(1-digital 2-physical): ";
                cin >> name >> price >> t;

                Product* p = (t == 1)
                    ? (Product*)new DigitalProduct(name, price)
                    : (Product*)new PhysicalProduct(name, price);

                p->save(c);
                delete p;
            }

            if (ch == 2)
                cout << "ID çàêàçà: " << createOrder(c) << endl;

            if (ch == 3) {
                int o, p, q;
                cout << "order_id product_id quantity: ";
                cin >> o >> p >> q;
                addOrderItem(c, o, p, q);
            }

            if (ch == 4)
                revenue(c);
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

}
