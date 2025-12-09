/* 1)
#include <iostream>
#include <chrono>

// функция для вычисления суммы всех чисел от 1 до n
long long calculate_sum(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    // устанавливаем локаль для русских символов
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "=== измерение времени выполнения функции ===\n";

    int n;
    std::cout << "введите число n: ";
    std::cin >> n;

    // засекаем время перед выполнением функции
    // используем высокоточные часы для измерения
    auto start_time = std::chrono::high_resolution_clock::now();

    // выполняем вычисление суммы
    long long result = calculate_sum(n);

    // засекаем время после выполнения
    auto end_time = std::chrono::high_resolution_clock::now();

    // вычисляем разницу между конечным и начальным временем
    // конвертируем разницу в миллисекунды
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // выводим результаты
    std::cout << "\nрезультат вычисления: сумма чисел от 1 до " << n << " = " << result << std::endl;
    std::cout << "время выполнения: " << duration.count() << " миллисекунд\n";

    return 0;
}
*/
/* 2)
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // устанавливаем локаль для русских символов
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "=== таймер обратного отсчёта ===\n";

    int seconds;
    std::cout << "введите количество секунд: ";
    std::cin >> seconds;

    std::cout << "\nтаймер запущен!\n";

    // цикл обратного отсчёта
    for (int i = seconds; i > 0; i--) {
        // выводим оставшееся время с правильным склонением
        std::cout << "осталось: " << i << " секунд";

        // добавляем правильное окончание для русского языка
        if (i % 10 == 1 && i % 100 != 11) {
            std::cout << "а";
        }
        else if (i % 10 >= 2 && i % 10 <= 4 && (i % 100 < 10 || i % 100 >= 20)) {
            std::cout << "ы";
        }

        std::cout << std::endl;

        // приостанавливаем выполнение программы на 1 секунду
        // используем стандартную функцию задержки
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // выводим сообщение об окончании времени
    std::cout << "время вышло!\n";

    return 0;
}
*/
/* 3)
* #include <iostream>
#include <chrono>

int main() {
    // устанавливаем локаль для русских символов
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    
    std::cout << "=== конвертер времени ===\n";
    
    long long total_seconds;
    std::cout << "введите количество секунд: ";
    std::cin >> total_seconds;
    
    // конвертируем секунды в часы
    // 1 час = 3600 секунд
    auto hours_duration = std::chrono::seconds(total_seconds);
    auto hours = std::chrono::duration_cast<std::chrono::hours>(hours_duration);
    
    // вычисляем оставшиеся секунды после вычитания часов
    long long remaining_seconds = total_seconds - hours.count() * 3600;
    
    // конвертируем оставшиеся секунды в минуты
    auto minutes_duration = std::chrono::seconds(remaining_seconds);
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(minutes_duration);
    
    // вычисляем оставшиеся секунды после вычитания минут
    long long final_seconds = remaining_seconds - minutes.count() * 60;
    
    // выводим результат
    std::cout << "\nрезультат преобразования:\n";
    
    // определяем правильную форму слов для русского языка
    std::string hour_form, minute_form, second_form;
    
    // форма для часов
    if (hours.count() % 10 == 1 && hours.count() % 100 != 11) {
        hour_form = "час";
    } else if (hours.count() % 10 >= 2 && hours.count() % 10 <= 4 && 
               (hours.count() % 100 < 10 || hours.count() % 100 >= 20)) {
        hour_form = "часа";
    } else {
        hour_form = "часов";
    }
    
    // форма для минут
    if (minutes.count() % 10 == 1 && minutes.count() % 100 != 11) {
        minute_form = "минута";
    } else if (minutes.count() % 10 >= 2 && minutes.count() % 10 <= 4 && 
               (minutes.count() % 100 < 10 || minutes.count() % 100 >= 20)) {
        minute_form = "минуты";
    } else {
        minute_form = "минут";
    }
    
    // форма для секунд
    if (final_seconds % 10 == 1 && final_seconds % 100 != 11) {
        second_form = "секунда";
    } else if (final_seconds % 10 >= 2 && final_seconds % 10 <= 4 && 
               (final_seconds % 100 < 10 || final_seconds % 100 >= 20)) {
        second_form = "секунды";
    } else {
        second_form = "секунд";
    }
    
    // выводим отформатированный результат
    std::cout << hours.count() << " " << hour_form << " "
              << minutes.count() << " " << minute_form << " "
              << final_seconds << " " << second_form << std::endl;
    
    return 0;
}
*/
/* 1)
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

int main() {
    // включаем поддержку русских букв
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "=== сравнение времени работы сортировок ===\n";

    // создаем массив из 10000 случайных чисел
    const int SIZE = 10000;
    std::vector<int> original(SIZE);

    // заполняем случайными числами
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10000);

    std::cout << "создаю массив из " << SIZE << " чисел...\n";
    for (int i = 0; i < SIZE; i++) {
        original[i] = dist(gen);
    }
    std::cout << "массив готов!\n\n";

    // --- пузырьковая сортировка ---
    std::vector<int> arr1 = original;
    std::cout << "пузырьковая сортировка... ";

    auto start = std::chrono::high_resolution_clock::now();

    // сортируем пузырьком
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << duration.count() << " мс\n";

    // --- сортировка вставками ---
    std::vector<int> arr2 = original;
    std::cout << "сортировка вставками... ";

    start = std::chrono::high_resolution_clock::now();

    // сортируем вставками
    for (int i = 1; i < SIZE; i++) {
        int key = arr2[i];
        int j = i - 1;

        while (j >= 0 && arr2[j] > key) {
            arr2[j + 1] = arr2[j];
            j--;
        }
        arr2[j + 1] = key;
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << duration.count() << " мс\n";

    // --- быстрая сортировка ---
    std::vector<int> arr3 = original;
    std::cout << "быстрая сортировка... ";

    start = std::chrono::high_resolution_clock::now();

    // используем стандартную быструю сортировку
    std::sort(arr3.begin(), arr3.end());

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << duration.count() << " мс\n";

    std::cout << "\n=== результаты ===\n";
    std::cout << "на массиве из " << SIZE << " элементов:\n";
    std::cout << "1. пузырьковая - самая медленная (O(n²))\n";
    std::cout << "2. вставками - быстрее пузырьковой (O(n²))\n";
    std::cout << "3. быстрая - самая быстрая (O(n log n))\n";

    // проверяем, что массивы отсортированы
    bool sorted1 = true, sorted2 = true, sorted3 = true;
    for (int i = 1; i < SIZE; i++) {
        if (arr1[i] < arr1[i - 1]) sorted1 = false;
        if (arr2[i] < arr2[i - 1]) sorted2 = false;
        if (arr3[i] < arr3[i - 1]) sorted3 = false;
    }

    std::cout << "\nпроверка сортировки:\n";
    std::cout << "пузырьковая: " << (sorted1 ? "✓ правильно" : "✗ ошибка") << "\n";
    std::cout << "вставками: " << (sorted2 ? "✓ правильно" : "✗ ошибка") << "\n";
    std::cout << "быстрая: " << (sorted3 ? "✓ правильно" : "✗ ошибка") << "\n";

    return 0;
}
*/
/* 2)
#include <iostream>
#include <chrono>

int main() {
    // включаем поддержку русских букв
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "=== конвертер секунд в часы, минуты, секунды ===\n";

    long long total_seconds;
    std::cout << "введите количество секунд: ";
    std::cin >> total_seconds;

    // используем chrono для конвертации
    auto seconds_duration = std::chrono::seconds(total_seconds);

    // конвертируем в часы
    auto hours = std::chrono::duration_cast<std::chrono::hours>(seconds_duration);

    // находим оставшиеся секунды после вычитания часов
    auto remaining_after_hours = seconds_duration - hours;

    // конвертируем оставшееся время в минуты
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(remaining_after_hours);

    // находим оставшиеся секунды
    auto seconds = remaining_after_hours - minutes;

    // получаем числовые значения
    long long h = hours.count();
    long long m = minutes.count();
    long long s = seconds.count();

    // выводим результат
    std::cout << "\nрезультат: ";

    // определяем правильные окончания
    if (h > 0) {
        if (h == 1) std::cout << h << " час ";
        else if (h >= 2 && h <= 4) std::cout << h << " часа ";
        else std::cout << h << " часов ";
    }

    if (m > 0) {
        if (m == 1) std::cout << m << " минута ";
        else if (m >= 2 && m <= 4) std::cout << m << " минуты ";
        else std::cout << m << " минут ";
    }

    if (s > 0 || total_seconds == 0) {
        if (s == 1) std::cout << s << " секунда";
        else if (s >= 2 && s <= 4) std::cout << s << " секунды";
        else std::cout << s << " секунд";
    }

    std::cout << "\n\n";

    // альтернативный простой способ (без chrono)
    std::cout << "=== простой способ (без chrono) ===\n";

    long long simple_hours = total_seconds / 3600;
    long long simple_minutes = (total_seconds % 3600) / 60;
    long long simple_seconds = total_seconds % 60;

    std::cout << "часов: " << simple_hours << "\n";
    std::cout << "минут: " << simple_minutes << "\n";
    std::cout << "секунд: " << simple_seconds << "\n";

    return 0;
}
*/
