#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// базовый класс: банковский счет
class BankAccount {
protected:
    string accountNumber;  // номер счета
    string ownerName;      // имя владельца
    double balance;        // баланс

public:
    // конструктор
    BankAccount(string accNum, string name, double initialBalance) {
        accountNumber = accNum;
        ownerName = name;
        balance = initialBalance;
    }

    // метод для пополнения счета
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "успешно пополнено: " << amount << " руб." << endl;
        } else {
            cout << "ошибка: сумма пополнения должна быть положительной!" << endl;
        }
    }

    // метод для снятия средств
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "успешно снято: " << amount << " руб." << endl;
            return true;
        } else if (amount > balance) {
            cout << "ошибка: недостаточно средств на счете!" << endl;
            cout << "запрошено: " << amount << " руб., доступно: " << balance << " руб." << endl;
            return false;
        } else {
            cout << "ошибка: сумма снятия должна быть положительной!" << endl;
            return false;
        }
    }

    // метод для отображения информации о счете
    virtual void displayInfo() {
        cout << "\n=== информация о банковском счете ===" << endl;
        cout << "номер счета: " << accountNumber << endl;
        cout << "владелец: " << ownerName << endl;
        cout << "баланс: " << fixed << setprecision(2) << balance << " руб." << endl;
    }

    // геттер для баланса (может понадобиться в производном классе)
    double getBalance() const {
        return balance;
    }

    // сеттер для баланса
    void setBalance(double newBalance) {
        balance = newBalance;
    }

    // виртуальный деструктор (хорошая практика при наследовании)
    virtual ~BankAccount() {
        cout << "счет " << accountNumber << " закрыт." << endl;
    }
};

// производный класс: сберегательный счет
class SavingsAccount : public BankAccount {
private:
    double interestRate;  // процентная ставка (в процентах)

public:
    // конструктор с дополнительным параметром процентной ставки
    SavingsAccount(string accNum, string name, double initialBalance, double rate)
        : BankAccount(accNum, name, initialBalance) {
        interestRate = rate;
    }

    // метод для начисления процентов
    void applyInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "начислены проценты: " << fixed << setprecision(2) 
             << interest << " руб. по ставке " << interestRate << "%" << endl;
    }

    // переопределенный метод для отображения информации
    void displayInfo() override {
        cout << "\n=== информация о сберегательном счете ===" << endl;
        cout << "номер счета: " << accountNumber << endl;
        cout << "владелец: " << ownerName << endl;
        cout << "баланс: " << fixed << setprecision(2) << balance << " руб." << endl;
        cout << "процентная ставка: " << interestRate << "%" << endl;
    }

    // геттер для процентной ставки
    double getInterestRate() const {
        return interestRate;
    }

    // сеттер для процентной ставки
    void setInterestRate(double newRate) {
        if (newRate >= 0) {
            interestRate = newRate;
            cout << "процентная ставка изменена на " << newRate << "%" << endl;
        } else {
            cout << "ошибка: процентная ставка не может быть отрицательной!" << endl;
        }
    }
};

// функция для отображения разделителя (для лучшей читаемости)
void printSeparator() {
    cout << "\n" << string(50, '=') << "\n" << endl;
}

int main() {
    // установка вывода чисел с фиксированной точностью
    cout << fixed << setprecision(2);

    cout << "=== банковская система ===\n" << endl;

    // создание обычного банковского счета
    cout << "1. создание обычного банковского счета:" << endl;
    BankAccount regularAccount("40817810099910004321", "Иванов Иван Иванович", 5000.00);
    regularAccount.displayInfo();

    // операции с обычным счетом
    printSeparator();
    cout << "2. операции с обычным банковским счетом:" << endl;
    
    regularAccount.deposit(3000.00);  // пополнение
    regularAccount.withdraw(2000.00); // снятие
    regularAccount.withdraw(10000.00); // попытка снять больше, чем есть
    regularAccount.displayInfo();

    // создание сберегательного счета
    printSeparator();
    cout << "3. создание сберегательного счета:" << endl;
    SavingsAccount savingsAccount("42301810712345678901", "Петрова Мария Сергеевна", 10000.00, 5.0);
    savingsAccount.displayInfo();

    // операции со сберегательным счетом
    printSeparator();
    cout << "4. операции со сберегательным счетом:" << endl;
    
    savingsAccount.deposit(5000.00);  // пополнение
    savingsAccount.withdraw(3000.00); // снятие
    savingsAccount.applyInterest();   // начисление процентов
    savingsAccount.displayInfo();

    // демонстрация изменения процентной ставки
    printSeparator();
    cout << "5. изменение условий сберегательного счета:" << endl;
    savingsAccount.setInterestRate(7.5);  // увеличиваем процентную ставку
    savingsAccount.applyInterest();       // начисляем проценты по новой ставке
    savingsAccount.displayInfo();

    // работа с указателем на базовый класс (демонстрация полиморфизма)
    printSeparator();
    cout << "6. демонстрация полиморфизма:" << endl;
    
    BankAccount* accountPtr;
    
    // указатель указывает на обычный счет
    accountPtr = &regularAccount;
    cout << "\nчерез указатель на BankAccount (обычный счет):" << endl;
    accountPtr->displayInfo();
    
    // указатель указывает на сберегательный счет
    accountPtr = &savingsAccount;
    cout << "\nчерез указатель на BankAccount (сберегательный счет):" << endl;
    accountPtr->displayInfo();

    printSeparator();
    cout << "=== работа программы завершена ===" << endl;

    return 0;
}
