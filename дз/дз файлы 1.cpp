/* 1) #include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
	ofstream outFile("ванялох.txt");
	outFile << "Привет, мир!";
	outFile.close();
	ifstream inFile("ванялох.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
	
	return 0;
}
*/
/* 2)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("data.txt");
    int count = 0;
    string line;

    while (getline(file, line)) {
        count++;
    }

    cout << "Количество строк в файле: " << count << endl;
    return 0;
}
*/
/* 3)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("text.txt");
    int count = 0;
    string word;

    while (file >> word) {
        count++;
    }

    cout << "Количество слов в файле: " << count << endl;
    return 0;
}
*/
/* 4)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream source("source.txt");
    ofstream copy("copy.txt");
    int lineCount = 0;
    string line;

    while (getline(source, line)) {
        copy << line << endl;
        lineCount++;
    }

    cout << "Файл успешно скопирован." << endl;
    cout << "Количество скопированных строк: " << lineCount << endl;
    return 0;
}
*/
/* 5)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("input.txt");
    char ch;
    int count = 0;

    while (file.get(ch)) {
        count++;
    }

    cout << "Количество символов в файле: " << count << endl;
    return 0;
}
*/
/* 6)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("output.txt");
    string line;

    cout << "Введите строки (пустая строка завершает ввод):" << endl;
    while (getline(cin, line) && !line.empty()) {
        file << line << endl;
    }

    cout << "Данные записаны в файл output.txt." << endl;
    return 0;
}
*/
/* 7)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("numbers.txt");
    int num, count = 0, sum = 0;

    while (file >> num) {
        count++;
        sum += num;
    }

    cout << "Количество чисел: " << count << endl;
    cout << "Сумма: " << sum << endl;
    cout << "Среднее: " << (count ? (double)sum / count : 0) << endl;
    return 0;
}
*/
/* 8)
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file1("file1.txt"), file2("file2.txt");
    string line1, line2;
    bool identical = true;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            identical = false;
            break;
        }
    }

    if (identical && file1.eof() && file2.eof())
        cout << "Файлы идентичны." << endl;
    else
        cout << "Файлы различаются." << endl;

    return 0;
}
*/
/* 9)
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("temperature_data.txt");
    ofstream output("report.txt");
    map<string, vector<double>> data;
    string line;

    while (getline(input, line)) {
        stringstream ss(line);
        string sensor;
        double temp;
        ss >> sensor >> temp;
        data[sensor].push_back(temp);
    }

    for (auto& [sensor, temps] : data) {
        double min = *min_element(temps.begin(), temps.end());
        double max = *max_element(temps.begin(), temps.end());
        double avg = accumulate(temps.begin(), temps.end(), 0.0) / temps.size();

        output << fixed << setprecision(1);
        output << sensor << ": min = " << min << ", max = " << max << ", avg = " << avg << endl;
    }

    cout << "Отчёт о температурных данных сохранён в report.txt" << endl;
    return 0;
}
*/
/* 10)
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("power_log.txt");
    ofstream output("energy_report.txt");
    map<string, vector<double>> devices;
    string line;

    while (getline(input, line)) {
        stringstream ss(line);
        string timestamp, device;
        double power;
        ss >> timestamp >> device >> power;
        devices[device].push_back(power);
    }

    output << fixed << setprecision(2);
    for (auto& [device, values] : devices) {
        int count = values.size();
        double total = accumulate(values.begin(), values.end(), 0.0);
        double average = total / count;

        output << device << ": measurements = " << count
            << ", total = " << total << " kWh"
            << ", average = " << average << " kW" << endl;
    }

    cout << "Анализ завершён. Результаты сохранены в energy_report.txt" << endl;
    return 0;
}
*/
/* 11)
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
    ifstream input("vibration_log.txt");
    ofstream output("vibration_report.txt");
    vector<double> vibrations;
    double value;

    while (input >> value) {
        vibrations.push_back(value);
    }

    // Фильтрация значений
    vector<double> filtered;
    copy_if(vibrations.begin(), vibrations.end(),
        back_inserter(filtered),
        [](double x) { return x > 0.05; });

    // Статистика
    double sum = accumulate(vibrations.begin(), vibrations.end(), 0.0);
    double avg = sum / vibrations.size();
    double min = *min_element(filtered.begin(), filtered.end());
    double max = *max_element(filtered.begin(), filtered.end());

    output << "Количество измерений: " << vibrations.size() << endl;
    output << "Фильтрованные значения (>0.05): ";
    for (double v : filtered) output << v << " ";
    output << endl << "Среднее значение: " << avg << endl;
    output << "Минимум: " << min << endl;
    output << "Максимум: " << max << endl;

    cout << "Анализ вибрационных данных завершён. Отчёт сохранён в vibration_report.txt" << endl;
    return 0;
*/