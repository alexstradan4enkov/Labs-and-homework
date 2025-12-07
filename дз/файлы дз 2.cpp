/*
1)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("book.txt");
    ofstream result("results.txt");
    string word, line;
    int lineNum = 1, count = 0;

    cout << "Введите слово для поиска: ";
    cin >> word;

    while (getline(file, line)) {
        size_t pos = line.find(word);
        while (pos != string::npos) {
            result << "Строка " << lineNum << ", позиция " << pos << ": " << word << endl;
            count++;
            pos = line.find(word, pos + 1);
        }
        lineNum++;
    }

    cout << "Найдено: " << count << " вхождений" << endl;
    file.close();
    result.close();
    return 0;
}
*/
/* 2)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("config.txt");
    string line, content;

    while (getline(in, line)) {
        if (line.find("timeout=") == 0) {
            line = "timeout=60";
        }
        content += line + "\n";
    }
    in.close();

    ofstream out("config.txt");
    out << content;
    out.close();

    cout << "Конфиг обновлен!" << endl;
    return 0;
}
*/
/* 3)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream log("application.log");
    string line;
    int partNum = 1, lineCount = 0;
    ofstream part;

    while (getline(log, line)) {
        if (lineCount % 10 == 0) {  // по 10 строк в файле
            if (part.is_open()) part.close();
            part.open("log_part" + to_string(partNum++) + ".txt");
        }
        part << line << endl;
        lineCount++;
    }

    cout << "Создано " << (partNum - 1) << " файлов" << endl;
    log.close();
    return 0;
}
*/
/* 4)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int numbers[] = { 15, 23, 7, 42, 18, 91, 3, 56, 77, 10 };

    // Запись
    ofstream out("numbers.bin", ios::binary);
    out.write((char*)numbers, sizeof(numbers));
    out.close();

    // Чтение
    ifstream in("numbers.bin", ios::binary);
    int readNumbers[10];
    in.read((char*)readNumbers, sizeof(readNumbers));

    int sum = 0;
    cout << "Числа: ";
    for (int num : readNumbers) {
        cout << num << " ";
        sum += num;
    }
    cout << "\nСумма: " << sum << endl;
    in.close();
    return 0;
}
*/
/* 5)
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    double grade;
};

int main() {
    Student students[3] = {
        {1, "Иван", 20, 4.5},
        {2, "Мария", 19, 4.8},
        {3, "Алексей", 21, 4.2}
    };

    // Запись
    ofstream out("students.dat", ios::binary);
    out.write((char*)students, sizeof(students));
    out.close();

    // Чтение
    ifstream in("students.dat", ios::binary);
    Student readStudents[3];
    in.read((char*)readStudents, sizeof(readStudents));

    cout << "Студенты:\n";
    for (auto s : readStudents) {
        cout << s.name << " - " << s.grade << endl;
    }
    in.close();
    return 0;
}
*/
/* 6)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("products.csv");
    file << "id,name,price,quantity\n";

    for (int i = 1; i <= 20; i++) {
        file << i << ",Товар" << i << ","
            << (100 + i * 100) << "," << (i % 20 + 1) << "\n";
    }

    file.close();
    cout << "CSV файл создан!" << endl;
    return 0;
}
*/
/* 7)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("products.csv");
    string line;

    getline(file, line); // пропустить заголовок

    double total = 0;
    cout << "Товары:\n";
    while (getline(file, line)) {
        cout << line << endl;
        // Простая обработка - в реальности нужно парсить CSV
        size_t pos = line.find_last_of(',');
        if (pos != string::npos) {
            int quantity = stoi(line.substr(pos + 1));
            total += quantity;
        }
    }

    cout << "Общее количество: " << total << endl;
    file.close();
    return 0;
}
*/
/* 8)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("products.csv");
    ofstream out("filtered.csv");
    string line;

    getline(in, line); // заголовок
    out << line << "\n";

    int count = 0;
    while (getline(in, line)) {
        // Простой фильтр - товары с ID > 10
        int id = stoi(line.substr(0, line.find(',')));
        if (id > 10) {
            out << line << "\n";
            count++;
        }
    }

    cout << "Отфильтровано: " << count << " товаров" << endl;
    in.close();
    out.close();
    return 0;
}
*/
/* 9)
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream in("products.csv");
    vector<string> lines;
    string line;

    while (getline(in, line)) {
        lines.push_back(line);
    }
    in.close();

    // Сортируем все строки кроме заголовка
    sort(lines.begin() + 1, lines.end());

    ofstream out("sorted.csv");
    for (auto l : lines) {
        out << l << "\n";
    }
    out.close();

    cout << "Товары отсортированы!" << endl;
    return 0;
}
*/
/* 10)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("config.json");
    file << "{\n";
    file << "  \"app_name\": \"My App\",\n";
    file << "  \"timeout\": 30\n";
    file << "}";
    file.close();

    cout << "JSON файл создан!" << endl;
    return 0;
}
*/
/* 11)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("sensor_data.txt");
    ofstream out("filtered_data.txt");
    double temp, sum = 0;
    int count = 0;

    while (in >> temp) {
        if (temp >= -50 && temp <= 50) {
            out << temp << endl;
            sum += temp;
            count++;
        }
    }

    cout << "Средняя температура: " << (sum / count) << endl;
    in.close();
    out.close();
    return 0;
}
*/
/* 11)
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    vector<int> numbers(100000, 42); // 100000 чисел

    // Метод 1: по одному
    auto start = chrono::steady_clock::now();
    ofstream file1("test1.bin", ios::binary);
    for (int num : numbers) {
        file1.write((char*)&num, sizeof(num));
    }
    file1.close();
    auto end = chrono::steady_clock::now();
    auto time1 = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Метод 2: все сразу
    start = chrono::steady_clock::now();
    ofstream file2("test2.bin", ios::binary);
    file2.write((char*)numbers.data(), numbers.size() * sizeof(int));
    file2.close();
    end = chrono::steady_clock::now();
    auto time2 = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "По одному: " << time1.count() << " мс\n";
    cout << "Все сразу: " << time2.count() << " мс" << endl;
    return 0;
}

*/
