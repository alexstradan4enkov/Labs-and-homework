/*1
#include<iostream>;
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    int a = 0;
    cout << "введите значение в см:";
    cin >> a;

    int c = a / 100;
    int d = a % 100;

    cout << c << "m" << d << "cm" << endl;
    return 0;

}
*/
/*2
#include<iostream>;
using namespace std;
 int main() {
	setlocale(LC_ALL, "RU");
	int a = 0;
	cout << "введите длину:";
	cin >> a;
	int b = 0;
	cout << "введите ширину:";
	cin >> b;
	int c = a * b;
	cout <<"площадь:<< c << "??.?";
	return 0;

}
*/
/*3
#include<iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int a = 0;
	cout << "введите температуру в градусах Цельсия:";
	cin >> a;
	int b = a * 9 / 5 + 32;
	cout <<"температура в Фарингейтах:"<< b << "F";
	return 0;
}
*/
/*4
#include<iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int a;
	cout << "введите число:";
	cin >> a;
	if (a % 2==0) {
		cout << "число четное";
	}
	else {
		cout << "число нечетное";
	}
	return 0;
}*/
/*5
#include<iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int a;
	cout << "введите число:";
	cin >> a;
	if (a % 5 == 0 && a % 3 == 0) {
		cout << "число делится на 3 и5";
	}
	else if (a % 5 == 0) {
		cout << "число делится только на 5";
	}
	else if (a % 3 == 0) {
		cout << "делится только на 3";
	}
	else {		cout << "число не делится на 3 и на 5";
	}
	return 0;
}
*/
/*6
#include<iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int a = 0;
	cout << "введите свой возраст:";
	cin >> a;
	if (a < 0) {
		cout << "";
	}
	else if (a < 18&& a>0) {
		cout << "тебе меньше 18 лет";
	}
	else if (a >=18 && a <= 60) {
		cout << "ты старше 18, но младше 60;
	}
	else {
		cout << "ты старше 60";
	}
	return 0;
}
*/
/*7
#include<iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n = 0;
	cout << "введите число:";
	cin >> n;
	if (n < 1) {
		cout << "число должно быть больше 1";
	}

	for (int i = 1; i <= n; i++) {
		cout << i << "*" << i << "=" << i * i << endl;
	}
	return 0;
}
*/
/*
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	char c;
	int a = 0;

	cout << "введите строку: ";

	while (cin.get(c) && c != '\n') {

		if (c == 'a' || c == 'A' ||
			c == 'e' || c == 'E' ||
			c == 'i' || c == 'I' ||
			c == 'o' || c == 'O' ||
			c == 'u' || c == 'U') {
			a++;
		}
	}

		cout << "количество гласных букв: " << a << endl;

	return 0;
}
*/
/*9
#include<iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	int sum = 0;
	cout << "введите число:";
	cin >> n;
	if (n < 1) {
		cout << "число должно быть больше 1";
	}
	else {
		for (int i = 1; i <= n; i++) {

			if (i % 2 == 0 || i % 5 == 0) {
				sum += i;
			}
		}

		cout << "сумма чисел 1 до " << n << ", делящиеся на 2 или на 5:" << sum << endl;
	}
	return 0;
}
*/
/*10
#include<iostream>;
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	 double a;
	cout << "введите число:";
	cin >> a;
	if (a < 0) {
		cout << "число отрицательное";
	}
	else if (a == 0) {
		cout << "число равно 0";
	}
	else {
		cout << "число положительное";
	}
	return 0;
}
*/
/*11
#include <iostream>
using namespace std;

int main() {
	for (int i = 32; i <= 126; i++) {
		cout << i << " : " << (char)i << endl;
	}
	return 0;
}
*/