/*1)#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int num[3][2];
	for (int i = 0; i < 3; i++) {
		cout << "введите x: ";
		cin >> num[i][0];
		cout << "введите y: ";
		cin >> num[i][1];
	}
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "-я пара x,y: " << "(" << num[i][0] << "," << num[i][1] << ")" << endl;
	}
	float s = 0.5 * abs((num[0][0] * (num[1][1] - num[2][1])) + (num[1][0] * (num[2][1] - num[0][1])) + (num[2][0] * (num[0][1] - num[1][1])));

	cout << "площадь равна: " << s;
	return 0;
}
*/

/* 2)#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[4][2];
	for (int i = 0; i < 4; i++) {
		cout << "введите x: ";
		cin >> n[i][0];
		cout << "введите y: ";
		cin >> n[i][1];
	}
	for (int i = 0; i < 4; i++) {
		cout <<" x:" << n[i][0] << " y:" << n[i][1];
	}
	float s = sqrt(pow((n[1][0] - n[0][0]), 2) + pow((n[1][1] - n[0][1]), 2)) + sqrt(pow((n[2][0] - n[1][0]), 2) + pow((n[2][1] - n[1][1]), 2)) + sqrt(pow((n[3][0] - n[2][0]), 2) + pow((n[3][1] - n[2][1]), 2)) + sqrt(pow((n[0][0] - n[3][0]), 2) + pow((n[0][1] - n[3][1]), 2));
	cout << "периметр: " << s;




	return 0;
}
*/
/*3)#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[3][2];
	for (int i = 0; i < 3; i++) {
		cout << "введите x: ";
		cin >> n[i][0];
		cout << "введите y: ";
		cin >> n[i][1];
	}
	for (int i = 0; i < 3; i++) {
		cout << " x:" << n[i][0] << " y:" << n[i][1];
	}
	float x = (n[0][0] + n[1][0] + n[2][0])/3;
		float y = (n[0][1] + n[1][1] + n[2][1])/3;
		cout << " x центра масс: " << x<<endl;
		cout << " y центра масс: " << y << endl;
	return 0;
}
*/
/*4)#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[4][2];
	for (int i = 0; i < 4; i++) {
		cout << "введите x: ";
		cin >> n[i][0];
		cout << "введите y: ";
		cin >> n[i][1];
	}
	for (int i = 0; i < 4; i++) {
		cout << " x:" << n[i][0] << " y:" << n[i][1];
	}
	float s = sqrt(pow((sqrt(pow((n[1][0] - n[0][0]), 2) + pow((n[1][1] - n[0][1]), 2))), 2) + pow((sqrt(pow((n[2][0] - n[1][0]), 2) + pow((n[2][1] - n[1][1]), 2))), 2));
	cout << " диагональ прямоугольника = " << s;


	return 0;
}
*/
/*5)#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[3][2];
	for (int i = 0; i < 3; i++) {
		cout << "введите x: ";
		cin >> n[i][0];
		cout << "введите y: ";
		cin >> n[i][1];
	}
	for (int i = 0; i < 3; i++) {
		cout << " x:" << n[i][0] << " y:" << n[i][1];
	}
	float s = (n[1][0] - n[0][0]) * (n[2][1] - n[0][1]) - (n[1][1] - n[0][1]) * (n[2][0] - n[0][0]);
	if (s == 0) {
		cout << " три точки лежат на одной прямой";
	}
	else{
		cout << " - три точки НЕ лежат на одной прямой";
	}
	return 0;
}
*/
/* задания к сем 3 1)
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	cout << "введите длину последовательности: ";
	int n = 0;
	cin >> n;
	int* m = new int(n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		cout << "введите член посл-ти: " << endl;
		cin >> m[i];
	}
	for (int i = 0; i < n; i++) {
		if (m[i] > (pow(2, i + 1))) {
			k = k + 1;
		}
	}
	cout << k;
	return 0;
}
*/
/* 8)
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[2][2];
	for (int i = 0; i < 2; i++) {
		cout << "введите x: ";
		cin >> n[i][0];
		cout << "введите y: ";
		cin >> n[i][1];
	}
	for (int i = 0; i < 2; i++) {
		cout << " x:" << n[i][0] << " y:" << n[i][1];
	}
	int x = n[1][0] - n[0][0];
	int y = n[1][1] - n[0][1];
	float l = sqrt(pow(x, 2) + pow(y, 2));
	cout << " длина отрезка= " << l;
	return 0;
}
*/
/* ЗАДАЧИ К СЕМ 2)
#include <iostream>
#include <vector>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	cout << "введите длину последовательности: ";
	int n = 0;
	cin >> n;
	int* m = new int(n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		cout << "введите член посл-ти: " << endl;
		cin >> m[i];
	}
	int b = 0;
	for (int i = 0; i < n; i++) {
		if (m[i] % 2 == 0) {
			k = k + 1;
		}
		else {
			if (b < m[i]) {
				b = m[i];

			}

		}
	}

	cout << k<<"," << b;
	return 0;
}
*/
/*зад к сем 3)
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[15];
	for (int i = 0; i < 15; i++) {
		cout << "введите член посл-ти: ";
		cin >> n[i];
	}
	cout << " члены посл-ти:";
	for (int i = 0; i < 15; i++) {
		cout << n[i] << ",";


	}
	cout << endl;	
	int b = 0;
	for (int i = 0; i < 15; i++) {
		if (b < n[i]) {
			b = n[i];

		}

	}
	int c = 0;
	for (int i = 0; i < 15; i++) {
		if (b==n[i]) {
			c = n[i];
			n[i] = n[14];
			n[14] = c;

		}

	}
	int a = b;
	for (int i = 0; i < 15; i++) {
		if (n[i]<a){
			a = n[i];


		

		}

	}
	int v = 0;
	for (int i = 0; i < 15; i++) {
		if (a == n[i]) {
			v = n[i];
			n[i] = n[0];
			n[0] = v;

		}

	}
	for (int i = 0; i < 15; i++) {
		cout << "" << n[i] << ",";

	}
	return 0;
}
*/
/*зад к сем 4)
#include <iostream>
#include <vector>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	cout << "введите длину последовательности: ";
	int n = 0;
	cin >> n;
	int m[15];
	int k = 0;
	for (int i = 0; i < n; i++) {
		cout << "введите член посл-ти: " << endl;
		cin >> m[i];
	}
	int b = 0;
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (b < m[i]) {
			b = m[i];
			r = i+1;

		}
	}
		int c = 0;
		int a = b;
	for (int i = 0; i < n; i++) {
		if (m[i]<a) {
			a = m[i];
			c = i+1;
			}
		

		}
	int s = 0;
	if (r < c) {
		 s = a * b;
	}
		cout <<r << "," << c << "," << s;
	return 0;
}
*/
/*6)
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int a[2], b[2], c[2], d[2];

	cout << "Введите координаты 4 точек (x1 y1 x2 y2 x3 y3 x4 y4): ";
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1] >> d[0] >> d[1];
 
	int s1 = (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
	int s2 = (b[0] - a[0]) * (d[1] - a[1]) - (b[1] - a[1]) * (d[0] - a[0]);
	int s3 = (d[0] - c[0]) * (a[1] - c[1]) - (d[1] - c[1]) * (a[0] - c[0]);
	int s4 = (d[0] - c[0]) * (b[1] - c[1]) - (d[1] - c[1]) * (b[0] - c[0]);

	bool n = false;

	// Общий случай пересечения  
	if (s1 * s2 < 0 && s3 * s4 < 0) {
		n = true;
	}
	// Частные случаи (отрезки лежат на одной прямой)
	else {
		// Проверяем, лежит ли точка c на отрезке ab  
		if (s1 == 0 && c[0] >= min(a[0], b[0]) && c[0] <= max(a[0], b[0])
			&& c[1] >= min(a[1], b[1]) && c[1] <= max(a[1], b[1])) {
			n = true;
		}
		// Проверяем, лежит ли точка d на отрезке ab  
		else if (s2 == 0 && d[0] >= min(a[0], b[0]) && d[0] <= max(a[0], b[0])
			&& d[1] >= min(a[1], b[1]) && d[1] <= max(a[1], b[1])) {
			n = true;
		}
		// Проверяем, лежит ли точка a на отрезке cd  
		else if (s3 == 0 && a[0] >= min(c[0], d[0]) && a[0] <= max(c[0], d[0])
			&& a[1] >= min(c[1], d[1]) && a[1] <= max(c[1], d[1])) {
			n = true;
		}
		// Проверяем, лежит ли точка b на отрезке cd  
		else if (s4 == 0 && b[0] >= min(c[0], d[0]) && b[0] <= max(c[0], d[0])
			&& b[1] >= min(c[1], d[1]) && b[1] <= max(c[1], d[1])) {
			n = true;
		}
	}

	cout << (n ? "Отрезки пересекаются" : "Отрезки не пересекаются");
	return 0;
}
*/
/*зад к сем 5)
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[10];
	for (int i = 0; i < 10; i++) {
		cout << "введите член посл-ти: ";
		cin >> n[i];
	}
	cout << " члены посл-ти:";
for (int i = 0; i < 10; i++) {
		cout << n[i] << ",";


	}
	cout << endl;
	int b = 0;
	for (int i = 0; i < 10; i++) {
		if (b < n[i]) {
			b = n[i];

		}

	}
	int c = 0;
		if (n[9] == b) {
			c = n[9];


		}
	int a = b;
	for (int i = 0; i < 10; i++) {
		if (n[i] < a) {
			a = n[i];




		}

	}
	int v = 0;
	if (a == n[4]) {
		v = n[4];
	}
	
	cout << (c + v) / 2;
	return 0;
}
*/
/*зад к сем 6)
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[15];
	for (int i = 0; i < 15; i++) {
		cout << "введите член посл-ти: ";
		cin >> n[i];
	}
	cout << " члены посл-ти:";
	for (int i = 0; i < 15; i++) {
		cout << n[i] << ",";


	}
	cout << endl;
	int b = 0;
	for (int i = 0; i < 15; i++) {
		if (b < n[i]) {
			b = n[i];

		}

	}

	int a = b;
	for (int i = 0; i < 15; i++) {
		if (n[i] < a) {
			a = n[i];




		}

	}
	int c = 0;
	int v = 0;
	if ((a == n[1]) && (n[0] == b)) {
		for (int i = 0; i < 15; i++) {
			n[i] = n[i] / 2;
		}
	}

	cout << " члены посл-ти:";
	for (int i = 0; i < 15; i++) {
		cout << n[i] << ",";
	}
		return 0;
	}
	*/
/*зад к сем 7)
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[15];
	for (int i = 0; i < 15; i++) {
		cout << "введите член посл-ти: ";
		cin >> n[i];
	}
	cout << " члены посл-ти:";
	for (int i = 0; i < 15; i++) {
		cout << n[i] << ",";


	}
	cout << endl;
	int b = 0;
	for (int i = 0; i < 15; i++) {
		if (b < n[i]) {
			b = n[i];

		}

	}

	int y = 0;
	int a = b;
	for (int i = 0; i < 15; i++) {
		if (n[i] < a) {
			a = n[i];
		}
	}
	for (int i = 0; i < 15; i++) {
		if (n[i] == a) {
			y = i;

		}

	}
	for (int i = 0; i < 15; i++) {
		if (i < y) {
			n[i] = 0;
		}
	}

	cout << " члены посл-ти:";
	for (int i = 0; i < 15; i++) {
		cout << n[i] << ",";
	}
	return 0;
}
*/
/*зад к сем 8)
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n[10];
	for (int i = 0; i < 10; i++) {
		cout << "введите член посл-ти: ";
		cin >> n[i];
	}
	cout << " члены посл-ти:";
	for (int i = 0; i < 10; i++) {
		cout << n[i] << ",";


	}
	cout << endl;
	int b = 0;
	for (int i = 0; i < 10; i++) {
		if (b < n[i]) {
			b = n[i];

		}

	}
	int a = b;
	for (int i = 0; i < 10; i++) {
		if (n[i] < a) {
			a = n[i];




		}

	}
	int v = 0;
	if ((a == n[4]) && (n[1] == b)) {
		for (int i = 0; i < 10; i++) {
			if (i > 4) {
				n[i] = b;
			}
		}
	}
	cout << " члены посл-ти:";
	for (int i = 0; i < 10; i++) {
		cout << n[i] << ",";


	}
	return 0;
}
*/
/*7)
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int p[][2] = { {1,1},{4,1},{2,4} };
	int n = 3, t[] = { 2,2 };
	bool in = false;

	for (int i = 0, j = n - 1; i < n; j = i++) {
		if ((p[i][1] > t[1]) != (p[j][1] > t[1]) &&
			t[0] < (p[j][0] - p[i][0]) * (t[1] - p[i][1]) / (p[j][1] - p[i][1]) + p[i][0])
			in = !in;
	}

	cout << (in ? "внутри" : "снаружи");
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int num[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "введите элемент " << i + 1 << ": ";
		cin >> num[i];
	}
	cout << "элементы массива: ";
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << ",";
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = sum + num[i];
	}
	cout << "сумма элементов: " << sum << endl;
	int min = num[0];
	for (int i = 0; i < 10; i++) {
		if (min > num[i]) {
			min = num[i];
		}
	}cout << "минимальный элемент: " << min << endl;
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 9; i++) {
			if (num[i] > num[i + 1]) {
				int h = num[i];
				num[i] = num[i + 1];
				num[i + 1] = h;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << ",";
	}
	return 0;
}
*/
/*9)
#include <iostream>
using namespace std;

int main() {
	double poly1[4][2] = {
		{1, 1},  
		{3, 1},   
		{3, 3}, 
		{1, 3}  
	};

	double poly2[4][2] = {
		{2, 2}, 
		{4, 2}, 
		{4, 4}, 
		{2, 4}   
	};

	
	bool intersect_x = false;
	bool intersect_y = false;

	// Проверяем пересечение по оси X
	double min1_x = poly1[0][0], max1_x = poly1[0][0];
	double min2_x = poly2[0][0], max2_x = poly2[0][0];

	// Находим min и max X для первого многоугольника
	for (int i = 0; i < 4; i++) {
		if (poly1[i][0] < min1_x) min1_x = poly1[i][0];
		if (poly1[i][0] > max1_x) max1_x = poly1[i][0];
	}

	// Находим min и max X для второго многоугольника  
	for (int i = 0; i < 4; i++) {
		if (poly2[i][0] < min2_x) min2_x = poly2[i][0];
		if (poly2[i][0] > max2_x) max2_x = poly2[i][0];
	}

	// Проверяем пересечение по X
	if (max1_x >= min2_x && max2_x >= min1_x) {
		intersect_x = true;
	}

	// Проверяем пересечение по оси Y
	double min1_y = poly1[0][1], max1_y = poly1[0][1];
	double min2_y = poly2[0][1], max2_y = poly2[0][1];

	// Находим min и max Y для первого многоугольника
	for (int i = 0; i < 4; i++) {
		if (poly1[i][1] < min1_y) min1_y = poly1[i][1];
		if (poly1[i][1] > max1_y) max1_y = poly1[i][1];
	}

	// Находим min и max Y для второго многоугольника
	for (int i = 0; i < 4; i++) {
		if (poly2[i][1] < min2_y) min2_y = poly2[i][1];
		if (poly2[i][1] > max2_y) max2_y = poly2[i][1];
	}

	// Проверяем пересечение по Y
	if (max1_y >= min2_y && max2_y >= min1_y) {
		intersect_y = true;
	}

	// Если пересекаются и по X и по Y - многоугольники пересекаются
	if (intersect_x && intersect_y) {
		cout << "многоугольники ПЕРЕСЕКАЮТСЯ" << endl;
	}
	else {
		cout << "многоугольники НЕ пересекаются" << endl;
	}

	return 0;
}
*/