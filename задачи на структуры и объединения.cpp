/* 1)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Employee {
    string name;
    int age;
    string position;
    double salary;
};

int main() {
    cout << "учет сотрудников\n" << endl;

    int count;
    cout << "введите количество сотрудников: ";
    cin >> count;
    cin.ignore();

    vector<Employee> employees(count);
    double totalSalary = 0;

    for (int i = 0; i < count; i++) {
        cout << "\nвведите данные сотрудника " << (i + 1) << ":\n";

        cout << "введите имя сотрудника: ";
        getline(cin, employees[i].name);

        cout << "введите возраст сотрудника: ";
        cin >> employees[i].age;
        cin.ignore();

        cout << "введите должность сотрудника: ";
        getline(cin, employees[i].position);

        cout << "введите зарплату сотрудника: ";
        cin >> employees[i].salary;
        cin.ignore();

        totalSalary += employees[i].salary;
    }

    int youngestIndex = 0;
    int oldestIndex = 0;

    for (int i = 1; i < count; i++) {
        if (employees[i].age < employees[youngestIndex].age) {
            youngestIndex = i;
        }
        if (employees[i].age > employees[oldestIndex].age) {
            oldestIndex = i;
        }
    }

    cout << "\nрезультаты:\n";
    cout << "самый молодой сотрудник: "
        << employees[youngestIndex].name
        << ", возраст: " << employees[youngestIndex].age
        << ", должность: " << employees[youngestIndex].position
        << ", зарплата: " << employees[youngestIndex].salary << endl;

    cout << "самый старший сотрудник: "
        << employees[oldestIndex].name
        << ", возраст: " << employees[oldestIndex].age
        << ", должность: " << employees[oldestIndex].position
        << ", зарплата: " << employees[oldestIndex].salary << endl;

    cout << "средняя зарплата всех сотрудников: "
        << (totalSalary / count) << endl;

    return 0;
}
*/
/* 2)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BankAccount {
    string accountNumber;
    string ownerName;
    double balance;
};

int findAccountByNumber(const vector<BankAccount>& accounts, const string& accountNumber) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    cout << "банковский счет\n" << endl;

    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\nвыберите действие:\n";
        cout << "1. создать новый банковский счет\n";
        cout << "2. пополнить счет\n";
        cout << "3. снять деньги со счета\n";
        cout << "4. показать информацию о счете\n";
        cout << "5. выйти\n";
        cout << "ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            BankAccount newAccount;

            cout << "введите номер счета: ";
            getline(cin, newAccount.accountNumber);

            if (findAccountByNumber(accounts, newAccount.accountNumber) != -1) {
                cout << "счет с таким номером уже существует!\n";
                break;
            }

            cout << "введите имя владельца счета: ";
            getline(cin, newAccount.ownerName);

            newAccount.balance = 0.0;
            accounts.push_back(newAccount);

            cout << "банковский счет создан.\n";
            break;
        }

        case 2: {
            string accountNumber;
            double amount;

            cout << "введите номер счета для пополнения: ";
            getline(cin, accountNumber);

            int index = findAccountByNumber(accounts, accountNumber);
            if (index == -1) {
                cout << "счет с таким номером не найден!\n";
                break;
            }

            cout << "введите сумму для пополнения: ";
            cin >> amount;
            cin.ignore();

            if (amount <= 0) {
                cout << "сумма должна быть положительной!\n";
                break;
            }

            accounts[index].balance += amount;
            cout << "счет пополнен на " << amount << " рублей.\n";
            break;
        }

        case 3: {
            string accountNumber;
            double amount;

            cout << "введите номер счета для снятия: ";
            getline(cin, accountNumber);

            int index = findAccountByNumber(accounts, accountNumber);
            if (index == -1) {
                cout << "счет с таким номером не найден!\n";
                break;
            }

            cout << "введите сумму для снятия: ";
            cin >> amount;
            cin.ignore();

            if (amount <= 0) {
                cout << "сумма должна быть положительной!\n";
                break;
            }

            if (accounts[index].balance < amount) {
                cout << "недостаточно средств на счете!\n";
                cout << "доступно: " << accounts[index].balance << " рублей\n";
                break;
            }

            accounts[index].balance -= amount;
            cout << "со счета снято " << amount << " рублей.\n";
            break;
        }

        case 4: {
            string accountNumber;

            cout << "введите номер счета для показа информации: ";
            getline(cin, accountNumber);

            int index = findAccountByNumber(accounts, accountNumber);
            if (index == -1) {
                cout << "счет с таким номером не найден!\n";
                break;
            }

            cout << "\nинформация о счете:\n";
            cout << "номер счета: " << accounts[index].accountNumber << "\n";
            cout << "имя владельца счета: " << accounts[index].ownerName << "\n";
            cout << "баланс: " << accounts[index].balance << " рублей\n";
            break;
        }

        case 5:
            cout << "программа завершена.\n";
            break;

        default:
            cout << "неверный выбор. попробуйте снова.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
*/
/* 3)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

void addBook(vector<Book>& library) {
    Book newBook;

    cout << "введите название книги: ";
    getline(cin, newBook.title);

    cout << "введите автора книги: ";
    getline(cin, newBook.author);

    cout << "введите год издания: ";
    cin >> newBook.year;
    cin.ignore();

    cout << "введите жанр книги: ";
    getline(cin, newBook.genre);

    library.push_back(newBook);
    cout << "книга '" << newBook.title << "' добавлена в библиотеку.\n";
}

void removeBook(vector<Book>& library, const string& title) {
    for (size_t i = 0; i < library.size(); i++) {
        if (library[i].title == title) {
            cout << "книга '" << library[i].title << "' удалена из библиотеки.\n";
            library.erase(library.begin() + i);
            return;
        }
    }
    cout << "книга с названием '" << title << "' не найдена.\n";
}

void findBooksByAuthor(const vector<Book>& library, const string& author) {
    bool found = false;
    cout << "\nкниги автора '" << author << "':\n";

    for (const auto& book : library) {
        if (book.author == author) {
            cout << "  - " << book.title
                << " (" << book.year
                << ", " << book.genre << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "книги данного автора не найдены.\n";
    }
}

void displayAllBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "библиотека пуста.\n";
        return;
    }

    cout << "\nвсе книги в библиотеке (" << library.size() << " книг):\n";
    for (size_t i = 0; i < library.size(); i++) {
        cout << i + 1 << ". '" << library[i].title
            << "' - " << library[i].author
            << " (" << library[i].year
            << ", " << library[i].genre << ")\n";
    }
}

int main() {
    cout << "библиотека\n" << endl;

    vector<Book> library;
    int choice;

    do {
        cout << "\nменю библиотеки:\n";
        cout << "1. добавить книгу\n";
        cout << "2. удалить книгу по названию\n";
        cout << "3. найти книги по автору\n";
        cout << "4. показать все книги\n";
        cout << "5. выйти\n";
        cout << "ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addBook(library);
            break;

        case 2: {
            string title;
            cout << "введите название книги для удаления: ";
            getline(cin, title);
            removeBook(library, title);
            break;
        }

        case 3: {
            string author;
            cout << "введите автора для поиска: ";
            getline(cin, author);
            findBooksByAuthor(library, author);
            break;
        }

        case 4:
            displayAllBooks(library);
            break;

        case 5:
            cout << "выход из программы библиотеки.\n";
            break;

        default:
            cout << "неверный выбор. попробуйте снова.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
*/
/* 4)
#include <iostream>

using namespace std;

union Variant {
    int intValue;
    double doubleValue;
    char charValue;
};

int main() {
    cout << "хранение различных типов данных\n" << endl;

    Variant data;
    char typeChoice;

    cout << "выберите тип данных:\n";
    cout << "i - целое число (int)\n";
    cout << "d - число с плавающей запятой (double)\n";
    cout << "c - символ (char)\n";
    cout << "ваш выбор: ";
    cin >> typeChoice;

    switch (typeChoice) {
    case 'i':
    case 'I':
        cout << "введите целое число: ";
        cin >> data.intValue;
        cout << "вы ввели целое число: " << data.intValue << endl;
        break;

    case 'd':
    case 'D':
        cout << "введите число с плавающей запятой: ";
        cin >> data.doubleValue;
        cout << "вы ввели число с плавающей запятой: " << data.doubleValue << endl;
        break;

    case 'c':
    case 'C':
        cout << "введите символ: ";
        cin >> data.charValue;
        cout << "вы ввели символ: '" << data.charValue << "'" << endl;
        break;

    default:
        cout << "неверный выбор типа данных.\n";
        break;
    }

    cout << "\nразмер объединения variant: " << sizeof(Variant) << " байт" << endl;
    cout << "это максимальный размер из трех типов (int, double, char)" << endl;

    return 0;
}
*/
/* 5)
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

union ShapeData {
    struct {
        double radius;
    } circle;

    struct {
        double length;
        double width;
    } rectangle;
};

enum ShapeType { CIRCLE, RECTANGLE };

int main() {
    cout << "управление геометрическими фигурами\n" << endl;

    ShapeData shapeData;
    ShapeType type;
    int choice;

    cout << "выберите фигуру:\n";
    cout << "1 - круг\n";
    cout << "2 - прямоугольник\n";
    cout << "ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        type = CIRCLE;
        cout << "введите радиус круга: ";
        cin >> shapeData.circle.radius;

        if (shapeData.circle.radius <= 0) {
            cout << "ошибка: радиус должен быть положительным числом!\n";
            return 1;
        }

        double area = M_PI * shapeData.circle.radius * shapeData.circle.radius;
        cout << "площадь круга: " << fixed << setprecision(2)
            << area << endl;

        double circumference = 2 * M_PI * shapeData.circle.radius;
        cout << "длина окружности: " << circumference << endl;
        break;
    }

    case 2: {
        type = RECTANGLE;
        cout << "введите длину прямоугольника: ";
        cin >> shapeData.rectangle.length;
        cout << "введите ширину прямоугольника: ";
        cin >> shapeData.rectangle.width;

        if (shapeData.rectangle.length <= 0 || shapeData.rectangle.width <= 0) {
            cout << "ошибка: длина и ширина должны быть положительными числами!\n";
            return 1;
        }

        double area = shapeData.rectangle.length * shapeData.rectangle.width;
        cout << "площадь прямоугольника: " << area << endl;

        double perimeter = 2 * (shapeData.rectangle.length + shapeData.rectangle.width);
        cout << "периметр прямоугольника: " << perimeter << endl;
        break;
    }

    default:
        cout << "неверный выбор фигуры.\n";
        return 1;
    }

    cout << "\nинформация о структуре данных:\n";
    cout << "размер объединения shapedata: " << sizeof(ShapeData) << " байт" << endl;
    cout << "объединение хранит только один набор данных за раз (круг или прямоугольник)" << endl;

    return 0;
}
*/
/* 6)
#include <iostream>
#include <iomanip>

using namespace std;

union DateTime {
    struct {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    } components;

    int allComponents[6];
};

bool isValidDate(int year, int month, int day) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth;
    switch (month) {
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29;
        }
        else {
            daysInMonth = 28;
        }
        break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
        break;
    }

    return day <= daysInMonth;
}

bool isValidTime(int hour, int minute, int second) {
    return (hour >= 0 && hour <= 23) &&
        (minute >= 0 && minute <= 59) &&
        (second >= 0 && second <= 59);
}

int main() {
    cout << "хранение даты и времени\n" << endl;

    DateTime dt;

    cout << "введите год: ";
    cin >> dt.components.year;

    cout << "введите месяц (1-12): ";
    cin >> dt.components.month;

    cout << "введите день: ";
    cin >> dt.components.day;

    if (!isValidDate(dt.components.year, dt.components.month, dt.components.day)) {
        cout << "ошибка: некорректная дата!\n";
        return 1;
    }

    cout << "введите час (0-23): ";
    cin >> dt.components.hour;

    cout << "введите минуту (0-59): ";
    cin >> dt.components.minute;

    cout << "введите секунду (0-59): ";
    cin >> dt.components.second;

    if (!isValidTime(dt.components.hour, dt.components.minute, dt.components.second)) {
        cout << "ошибка: некорректное время!\n";
        return 1;
    }

    cout << "\nрезультаты:\n";

    cout << "дата и время: "
        << dt.components.year << "-"
        << setw(2) << setfill('0') << dt.components.month << "-"
        << setw(2) << setfill('0') << dt.components.day << " "
        << setw(2) << setfill('0') << dt.components.hour << ":"
        << setw(2) << setfill('0') << dt.components.minute << ":"
        << setw(2) << setfill('0') << dt.components.second << endl;

    cout << "текстовый формат: ";
    cout << dt.components.day << ".";
    cout << dt.components.month << ".";
    cout << dt.components.year << " ";
    cout << dt.components.hour << ":";
    cout << dt.components.minute << ":";
    cout << dt.components.second << endl;

    cout << "\nпредставление в виде массива: ";
    for (int i = 0; i < 6; i++) {
        cout << dt.allComponents[i];
        if (i < 5) cout << ", ";
    }
    cout << endl;

    cout << "\nинформация о структуре данных:\n";
    cout << "размер объединения datetime: " << sizeof(DateTime) << " байт" << endl;
    cout << "все компоненты используют одну и ту же область памяти" << endl;

    return 0;
}
*/
