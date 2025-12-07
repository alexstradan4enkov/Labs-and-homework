/* 1) 
#include <iostream>
#include <string>

using namespace std;

// базовый класс - печатное издание
class Publication {
protected:
    string title;  // название публикации
    
public:
    // конструктор
    Publication(string t = "") : title(t) {}
    
    // метод для отображения базовой информации
    void displayInfo() {
        cout << "название: " << title;
    }
    
    // метод для установки названия
    void setTitle(string t) {
        title = t;
    }
    
    // метод для получения названия
    string getTitle() {
        return title;
    }
};

// производный класс - книга
class Book : public Publication {
private:
    string author;  // автор книги
    int year;       // год выпуска
    
public:
    // конструктор с параметрами
    Book(string t = "", string a = "", int y = 0) : Publication(t), author(a), year(y) {}
    
    // переопределенный метод для отображения информации
    void displayInfo() {
        cout << "название: " << title << ", автор: " << author << ", год выпуска: " << year << endl;
    }
    
    // метод для установки автора
    void setAuthor(string a) {
        author = a;
    }
    
    // метод для установки года выпуска
    void setYear(int y) {
        year = y;
    }
    
    // метод для получения автора
    string getAuthor() {
        return author;
    }
    
    // метод для получения года выпуска
    int getYear() {
        return year;
    }
};

int main() {
    cout << "программа: класс 'книга'\n" << endl;
    
    // создаем объект книги с использованием конструктора
    Book book1("война и мир", "лев толстой", 1869);
    
    cout << "создана книга через конструктор:\n";
    book1.displayInfo();
    
    // создаем пустую книгу и заполняем данные через методы
    Book book2;
    book2.setTitle("преступление и наказание");
    book2.setAuthor("фёдор достоевский");
    book2.setYear(1866);
    
    cout << "\nсоздана книга через методы set:\n";
    book2.displayInfo();
    
    // демонстрация работы с базовым классом
    Publication pub("газета 'правда'");
    cout << "\nобъект базового класса:\n";
    pub.displayInfo();
    cout << endl;
    
    // демонстрация наследования
    Publication* ptr = &book1;  // указатель базового класса на объект производного
    cout << "\nвызов displayInfo через указатель базового класса:\n";
    ptr->displayInfo();
    
    return 0;
}
*/
/* 2)
#include <iostream>
#include <string>

using namespace std;

// базовый класс - геометрическая фигура
class Shape {
protected:
    double length;  // длина

public:
    // конструктор
    Shape(double l = 0) : length(l) {}

    // виртуальный метод для отображения информации
    virtual void displayInfo() {
        cout << "длина: " << length;
    }

    // чисто виртуальный метод для вычисления площади (делаем класс абстрактным)
    virtual double calculateArea() = 0;

    // метод для установки длины
    void setLength(double l) {
        length = l;
    }

    // метод для получения длины
    double getLength() {
        return length;
    }

    // виртуальный деструктор
    virtual ~Shape() {}
};

// производный класс - прямоугольник
class Rectangle : public Shape {
private:
    double width;  // ширина

public:
    // конструктор с параметрами
    Rectangle(double l = 0, double w = 0) : Shape(l), width(w) {}

    // метод для вычисления площади
    double calculateArea() override {
        return length * width;
    }

    // метод для вычисления периметра
    double calculatePerimeter() {
        return 2 * (length + width);
    }

    // переопределенный метод для отображения информации
    void displayInfo() override {
        cout << "длина: " << length << ", ширина: " << width
            << ", площадь: " << calculateArea()
            << ", периметр: " << calculatePerimeter() << endl;
    }

    // метод для установки ширины
    void setWidth(double w) {
        width = w;
    }

    // метод для получения ширины
    double getWidth() {
        return width;
    }
};

int main() {
    cout << "программа: класс 'прямоугольник'\n" << endl;

    // создаем прямоугольник с использованием конструктора
    Rectangle rect1(5.0, 3.0);

    cout << "создан прямоугольник через конструктор:\n";
    rect1.displayInfo();

    // создаем пустой прямоугольник и заполняем данные через методы
    Rectangle rect2;
    rect2.setLength(7.5);
    rect2.setWidth(4.2);

    cout << "\nсоздан прямоугольник через методы set:\n";
    rect2.displayInfo();

    // демонстрация вычислений отдельно
    cout << "\nдополнительные вычисления для rect2:\n";
    cout << "площадь: " << rect2.calculateArea() << endl;
    cout << "периметр: " << rect2.calculatePerimeter() << endl;

    // демонстрация полиморфизма через указатель базового класса
    cout << "\nдемонстрация полиморфизма:\n";
    Shape* shapePtr = &rect1;  // указатель базового класса на объект производного

    // вызываем переопределенный метод
    shapePtr->displayInfo();

    // пример создания нескольких прямоугольников
    cout << "\n\nсоздание нескольких прямоугольников:\n";

    Rectangle rectangles[3] = {
        Rectangle(2, 3),
        Rectangle(4, 5),
        Rectangle(6, 7)
    };

    for (int i = 0; i < 3; i++) {
        cout << "прямоугольник " << i + 1 << ": ";
        rectangles[i].displayInfo();
    }

    // пример работы с пользовательским вводом
    cout << "\nвведите данные для нового прямоугольника:\n";
    double l, w;
    cout << "введите длину: ";
    cin >> l;
    cout << "введите ширину: ";
    cin >> w;

    Rectangle userRect(l, w);
    cout << "\nваш прямоугольник:\n";
    userRect.displayInfo();

    return 0;
}
*/
