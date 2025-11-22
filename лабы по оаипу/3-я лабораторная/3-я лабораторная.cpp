#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// функция для добавления товаров в файл
void addpr() {
    setlocale(LC_ALL, "RU");
    ofstream file("orders.txt", ios::app);
    string name;
    int quantity;
    double price;

    cout << "ввод товаров: " << endl;

    bool continueInput = true; // флаг для продолжения ввода

    while (continueInput) {
        cout << "название товара: ";
        getline(cin, name);

        if (name == "стоп" || name.empty()) {
            continueInput = false; // меняем флаг на false для выхода из цикла
        }
        else {
            cout << "количество: ";
            cin >> quantity;
            cout << "цена: ";
            cin >> price;
            cin.ignore(); // очистка буфера

            // запись в файл
            file << name << " " << quantity << " " << price << endl;

            // запись в output.txt
            ofstream out("output.txt", ios::app);
            out << "добавлен: " << name << " " << quantity << " " << price << endl;
            out.close();
        }
    }
    file.close();
}

// функция для поиска товара
void searchpr() {
    setlocale(LC_ALL, "RU");
    ifstream file("orders.txt");
    string searchn, name;
    int quantity;
    double price;
    bool found = false;

    cout << "введите название для поиска: ";
    getline(cin, searchn);

    ofstream out("output.txt", ios::app);
    out << "поиск: " << searchn << endl;

    while (file >> name >> quantity >> price) {
        if (name == searchn) {
            cout << "найдено: " << name << " " << quantity << " " << price << endl;
            out << "найдено: " << name << " " << quantity << " " << price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "товар не найден!" << endl;
        out << "товар не найден!" << endl;
    }

    file.close();
    out.close();
}

// функция для показа всех товаров
void showallpr() {
    setlocale(LC_ALL, "RU");
    ifstream file("orders.txt");
    string name;
    int quantity;
    double price;

    cout << "все товары:" << endl;
    ofstream out("output.txt", ios::app);
    out << "показать все товары:" << endl;

    while (file >> name >> quantity >> price) {
        cout << name << " " << quantity << " " << price << endl;
        out << name << " " << quantity << " " << price << endl;
    }

    file.close();
    out.close();
}

// функция для показа товаров по цене
void showbyprice() {
    setlocale(LC_ALL, "RU");
    ifstream file("orders.txt");
    string name;
    int quantity;
    double price, maxprice;

    cout << "введите максимальную цену: ";
    cin >> maxprice;
    cin.ignore();

    cout << "товары до " << maxprice << " руб.:" << endl;
    ofstream out("output.txt", ios::app);
    out << "товары до " << maxprice << " руб.:" << endl;

    while (file >> name >> quantity >> price) {
        if (price <= maxprice) {
            cout << name << " " << quantity << " " << price << endl;
            out << name << " " << quantity << " " << price << endl;
        }
    }

    file.close();
    out.close();
}

// главное меню
int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    ofstream clear1("orders.txt");
    clear1.close();

    ofstream clear2("output.txt");
    clear2.close();

    bool programRunning = true; // флаг для работы программы

    while (programRunning) {
        cout << "\n    меню    " << endl;
        cout << "1 - добавить товары" << endl;
        cout << "2 - поиск товара" << endl;
        cout << "3 - показать все" << endl;
        cout << "4 - товары по цене" << endl;
        cout << "5 - выход" << endl;
        cout << "выберите: ";
        cin >> choice;
        cin.ignore(); // пропускаем пробелы

        switch (choice) {
        case 1:
            addpr();
            break;
        case 2:
            searchpr();
            break;
        case 3:
            showallpr();
            break;
        case 4:
            showbyprice();
            break;
        case 5:
            cout << "выход!" << endl;
            programRunning = false; // меняем флаг для выхода из цикла
            break;
        default:
            cout << "неверный выбор!" << endl;
        }
    }
    return 0;
}

