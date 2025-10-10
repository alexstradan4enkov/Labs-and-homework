/* 1)
#include <cmath>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int i, j, n, m, num[101][101], a[101][101], b[101][101], c[101][101], d[101][101];//берем с запасом
	cout << "введите количество строк: ";
	cin >> n;
	cout << "введите количество столбцов: ";
	cin >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << "введите эелемент: " << endl;
			cin >> num[i][j];
		}
	}
	int k = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			a[i][j] = num[j][i];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			b[i][j] = num[n - 1 - j][m - 1 - i];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			c[i][j] = num[i][m - 1 - j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			cout << c[i][j] << "\t";
		}
		cout << endl;
	}


	cout << endl;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			d[i][j] = num[n - 1 - i][j];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			cout << d[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "элементы матрицы: " << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			cout << num[i][j] << "\t";
		}
		cout << endl;
	}
	int w = 0, e = 0, r = 0, t = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (num[i][j] == a[i][j]) {
				w++;
			}
			if (num[i][j] == b[i][j]) {
				e++;
			}
			if (num[i][j] == c[i][j]) {
				r++;
			}
			if (num[i][j] == d[i][j]) {
				t++;
			}
		}
		cout << endl;
	}
	if (w == (m * n)) {
		cout << "матрицы num и a  совпадают";
	}
	if (e == (m * n)) {
		cout << "матрицы num и b  совпадают";
	}
	if (r == (m * n)) {
		cout << "матрицы num и c  совпадают";
	}
	if (t == (m * n)) {
		cout << "матрицы num и d  совпадают";
	}
	return 0;
}
*/
/* 2)
#include <iostream>
#using namespace std;

	int main() {
		int n;
		cin >> n;

		int matrix[50][50]; // максимальный размер 50 на 50

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}

		// первая строка
		int tgs = 0;
		for (int j = 0; j < n; j++) {
			tgs += matrix[0][j];
		}

		// проверяем суммы строк
		for (int i = 1; i < n; i++) {
			int row_sum = 0;
			for (int j = 0; j < n; j++) {
				row_sum += matrix[i][j];
			}
			if (row_sum != tgs) {
				cout << "NO" << endl;
				return 0;
			}
		}

		// проверяем суммы столбцов
		for (int j = 0; j < n; j++) {
			int col_sum = 0;
			for (int i = 0; i < n; i++) {
				col_sum += matrix[i][j];
			}
			if (col_sum != tgs) {
				cout << "NO" << endl;
				return 0;
			}
		}

		// проверяем главную диагональ
		int main_diag_sum = 0;
		for (int i = 0; i < n; i++) {
			main_diag_sum += matrix[i][i];
		}
		if (main_diag_sum != tgs) {
			cout << "NO" << endl;
			return 0;
		}

		// проверяем побочную диагональ
		int sdg = 0;
		for (int i = 0; i < n; i++) {
			sdg += matrix[i][n - 1 - i];
		}
		if (sdg != tgs) {
			cout << "NO" << endl;
			return 0;
		}

		// если все проверки пройдены
		cout << "YES" << endl;
		cout << tgs << endl;

		return 0;
	}
*/
/* 3)
#include <iostream>
	using namespace std;

	int main() {
		int n, m;
		cin >> n >> m;

		int a[100][100];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		int count = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// проверяем тип A
				int min_in_row = 1;
				int max_in_col = 1;

				for (int k = 0; k < m; k++) {
					if (a[i][k] < a[i][j]) {
						min_in_row = 0;
						break;
					}
				}

				for (int k = 0; k < n; k++) {
					if (a[k][j] > a[i][j]) {
						max_in_col = 0;
						break;
					}
				}

				if (min_in_row && max_in_col) {
					cout << "A " << a[i][j] << " " << i + 1 << " " << j + 1 << endl;
					count++;
				}

				// проверяем тип B
				int max_in_row = 1;
				int min_in_col = 1;

				for (int k = 0; k < m; k++) {
					if (a[i][k] > a[i][j]) {
						max_in_row = 0;
						break;
					}
				}

				for (int k = 0; k < n; k++) {
					if (a[k][j] < a[i][j]) {
						min_in_col = 0;
						break;
					}
				}

				if (max_in_row && min_in_col) {
					cout << "B " << a[i][j] << " " << i + 1 << " " << j + 1 << endl;
					count++;
				}
			}
		}

		if (count == 0) {
			cout << "NONE" << endl;
		}

		return 0;
	}
*/
/* 4)
#include <iostream>
	using namespace std;

	int main() {
		int n;
		cin >> n;
		int a[100][100];

		int num = 1;
		int top = 0, bottom = n - 1, left = 0, right = n - 1;

		while (num <= n * n) {
			// Вправо
			for (int j = left; j <= right; j++) {
				a[top][j] = num++;
			}
			top++;

			// Вниз
			for (int i = top; i <= bottom; i++) {
				a[i][right] = num++;
			}
			right--;

			// Влево
			for (int j = right; j >= left; j--) {
				a[bottom][j] = num++;
			}
			bottom--;

			// Вверх
			for (int i = bottom; i >= top; i--) {
				a[i][left] = num++;
			}
			left++;
		}

		// Вывод матрицы
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}

		return 0;
	}
*/
/*
5)
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int top = 0, bottom = n - 1, left = 0, right = m - 1;

	while (top <= bottom && left <= right) {
		// вправо по верхней строке
		for (int j = left; j <= right; j++) {
			cout << a[top][j] << " ";
		}
		top++;

		// вниз по правому столбцу
		for (int i = top; i <= bottom; i++) {
			cout << a[i][right] << " ";
		}
		right--;

		// влево по нижней строке (если есть)
		if (top <= bottom) {
			for (int j = right; j >= left; j--) {
				cout << a[bottom][j] << " ";
			}
			bottom--;
		}

		// вверх по левому столбцу (если есть)
		if (left <= right) {
			for (int i = bottom; i >= top; i--) {
				cout << a[i][left] << " ";
			}
			left++;
		}
	}

	return 0;
}
*/
/*
 6)
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int r = 0;
	int b = 0;
	int x = 0;
	int y = 0;
	int a[2][3] = { { 2,3,13 },
					{ 5,-1,9 }
	};
	n = ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0]));
	r = ((a[0][2] * a[1][1]) - (a[0][1] * a[1][2]));
	b = ((a[0][0] * a[1][2]) - (a[0][2] * a[1][0]));
	x = r / n;
	y = b / n;
	cout << "x= " << x << ", y= " << y;
	return 0;
}
*/
/*
 7)
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int dx = 0;
	int dy,dz = 0;
	int x = 0;
	int y,z  = 0;
	int a[3][4] = { {1,1,1,6 },
					{ 2,-1,3,14},
					{-1,4,-1,2}
	};
	n = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
		- a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
		+ a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

	dx = a[0][3] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])	- a[0][1] * (a[1][3] * a[2][2] - a[1][2] * a[2][3])	+ a[0][2] * (a[1][3] * a[2][1] - a[1][1] * a[2][3]);
	dy = a[0][0] * (a[1][3] * a[2][2] - a[1][2] * a[2][3]) - a[0][3] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][3] - a[1][3] * a[2][0]);
	dz= a[0][0] * (a[1][1] * a[2][3] - a[1][3] * a[2][1]) - a[0][1] * (a[1][0] * a[2][3] - a[1][3] * a[2][0]) + a[0][3] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
	x = dx / n;
	y = dy / n;
	z = dz / n;
	cout << "x= " << x << ", y= " << y << ", z= " << z;
	return 0;
}
*/
/* 
 8)
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int dx = 0;
	int dy, dz = 0;
	int x = 0;
	int y, z = 0;
	int a[3][4] = { {3,-1,2,5 },
					{2,4,-1,6 },
					{1,-3,1,4 }
	};
	n = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
		- a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
		+ a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

	dx = a[0][3] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][3] * a[2][2] - a[1][2] * a[2][3]) + a[0][2] * (a[1][3] * a[2][1] - a[1][1] * a[2][3]);
	dy = a[0][0] * (a[1][3] * a[2][2] - a[1][2] * a[2][3]) - a[0][3] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][3] - a[1][3] * a[2][0]);
	dz = a[0][0] * (a[1][1] * a[2][3] - a[1][3] * a[2][1]) - a[0][1] * (a[1][0] * a[2][3] - a[1][3] * a[2][0]) + a[0][3] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
	x = dx / n;
	y = dy / n;
	z = dz / n;
	cout << "x= " << x << ", y= " << y << ", z= " << z;
	return 0;
}
*/