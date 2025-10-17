/*1)
#include <iostream>
#include <cstring>  // для strlen
#include <cctype>   // для tolower

using namespace std;

int main() {
    const int size = 256;
    char input[size];

    cout << "введите строку для проверки: ";
    cin.getline(input, size);

    int left = 0;
    int right = strlen(input) - 1;
    bool isPalindrome = true;

    while (left < right && isPalindrome) {
        while (left < right && input[left] == ' ') {
            left++;
        }
        while (left < right && input[right] == ' ') {
            right--;
        }

        if (tolower(input[left]) != tolower(input[right])) {
            isPalindrome = false;
        }

        left++;
        right--;
    }

    if (isPalindrome) {
        cout << "строка является палиндромом" << endl;
    }
    else {
        cout << "строка НЕ является палиндромом" << endl;
    }

    return 0;
}
*/

/* 2)
#include <iostream>
#include <cstring>  // для strlen
#include <cctype>   // для tolower
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    const int size = 7;
    char str[size];

    cout << "введите строку для проверки: ";
    cin.getline(str, size);
    int c = 0;
    char f[size];
    for (int i = 0; str[i] != '\0'; i++) {
        bool isUnique = true;

        for (int j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            c++;
        }
    }
    cout << c;
    return 0;
}
*/
/* 3)
#include <iostream>
#include <cstring>  // для strlen
#include <cctype>   // для tolower
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    const int size = 10;
    char str[size];

    cout << "введите строку для проверки: ";
    cin.getline(str, size);
    int c = 0;
    char f[size];
    for (int i = 0; i < size; i++) {
        if str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0' {
            str[i] == ' '
        }
    }
    cout << str;
    return 0;
}
*/
/* 4)
#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string A, B;

    cout << "введите строку A: ";
    cin >> A;
    cout << "введите строку B: ";
    cin >> B;

    bool allCharsFound = true;

    for (int i = 0; i < B.size(); i++) {
        char currentChar = B[i];
        bool charFound = false;

        for (int j = 0; j < A.size(); j++) {
            if (A[j] == currentChar) {
                charFound = true;
                break;
            }
        }

        if (!charFound) {
            allCharsFound = false;
            break;
        }
    }
    if (allCharsFound) {
        cout << "да" << endl;
    }
    else {
        cout << "нет" << endl;
    }
    return 0;
}
*/

/* 5)#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string A;

    cout << "введите строку A: ";
    cin >> A;

    int c = 0;
    int d = 0;
    for (int i = 0; i < A.size(); i++) {
        if ((toupper(A[i]) == 'A') || (toupper(A[i]) == 'E') || (toupper(A[i]) == 'I') || (toupper(A[i]) == 'Y') || (toupper(A[i]) == 'O') || (toupper(A[i]) == 'U')) {
            c++;
        }
        else {
            d++;
        }
    }
    cout << "гласных: " << c << ", согласных: " << d;
    return 0;
}
*/
/* 6)
#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string text;
    int shift;
    cout << "текст: ";
    getline(cin, text);
    cout << "сдвиг: ";
    cin >> shift;

    for (char& c : text) {
        if (c >= 'A' && c <= 'Z') {
            // заглавные буквы
            c = (c - 'A' + shift) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            // cтрочные буквы
            c = (c - 'a' + shift) % 26 + 'a';
        }
    }
    cout << text << endl;

    return 0;
}
*/
/* 7)
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    setlocale(LC_ALL, "RU");
    cout << "введите строку: ";
    cin >> input;
    string result = "";
    int count = 1;
    char currentChar = input[0];

    for (int i = 1; i < input.length(); i++) {
        if (input[i] == currentChar) {
            count++;
        }
        else {
            result += currentChar;
            result += to_string(count);

            currentChar = input[i];
            count = 1;
        }
    }
    result += currentChar;
    result += to_string(count);

    cout << result << endl;

    return 0;
}
*/
/* 8)
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string text;
    setlocale(LC_ALL, "RU");
    cout << "введите текст: ";
    getline(cin, text);
    bool newSentence = true;

    for (int i = 0; i < text.length(); i++) {
        if (newSentence && isalpha(text[i])) {
            text[i] = toupper(text[i]);
            newSentence = false;
        }
        else if (!newSentence) {
            text[i] = tolower(text[i]);
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            newSentence = true;
            while (i + 1 < text.length() && text[i + 1] == ' ') {
                i++;
            }
        }
    }

    cout << text << endl;

    return 0;
}
*/
/* 9)
#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string s1, s2;
    cout << "введите первую строку: ";
    cin >> s1;
    cout << "введите вторую строку: ";
    cin >> s2;

    int m = s1.length();
    int n = s2.length();

    int dp[100][100] = { 0 }; 

    int maxLen = 0;     
    int endIndex = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (s1[i] == s2[j]) {
                if (i > 0 && j > 0) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = 1;
                }
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }
     if (maxLen > 0) {
        string result = s1.substr(endIndex - maxLen + 1, maxLen);
        cout << "самая длинная общая подстрока: \"" << result << "\"" << endl;
    }
    else {
        cout << "общих подстрок не найдено" << endl;
    }

    return 0;
}
*/
/* 10)
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;

    cout << "введите предложение: ";
    getline(cin, input);

    string result = "";
    string word = "";

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            if (!word.empty()) {
                for (int j = word.length() - 1; j >= 0; j--) {
                    result += word[j];
                }
                word = "";
            }
            result += ' ';
        }
        else {
            word += input[i];
        }
    }

    if (!word.empty()) {
        for (int j = word.length() - 1; j >= 0; j--) {
            result += word[j];
        }
    }

    cout << "результат: " << result << endl;

    return 0;
}
*/
/* 11)
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int k;

    // Ввод данных
    cout << "введите строку: ";
    cin >> str;
    cout << "введите k: ";
    cin >> k;

    int n = str.length();

    cout << "подстроки длины " << k << " с уникальными символами:" << endl;
    for (int i = 0; i <= n - k; i++) {
        string substring = str.substr(i, k);
        bool allUnique = true;

        for (int j = 0; j < k && allUnique; j++) {
            for (int m = j + 1; m < k; m++) {
                if (substring[j] == substring[m]) {
                    allUnique = false;
                    break; 
                }
            }
        }

        if (allUnique) {
            cout << substring << endl;
        }
    }

    return 0;
}
*/