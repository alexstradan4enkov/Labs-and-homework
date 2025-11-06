/* 
1)
#include <iostream>
using namespace std;
void swapPointers(int** a, int** b) {
	int *c = *a;
	*a = *b;
	*b = c;
}
int main() {
	int x = 10;
	int y = 20;
	int *p1 = &x;
	int* p2 = &y;
	swapPointers(&p1, &p2);
	cout << " p1= " << *p1 << " p2= " << *p2;
	return 0;
}
*/
/* 2,3)
#include <iostream>
using namespace std;
int** create(int n, int m) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	return arr;
}
void fill(int** arr, int n, int m) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = k % 100;
			k++;
		}
		cout << endl;
	}
}
void printa(int** arr, int n, int m) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
	}
}
void del(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
int main() {
	int n, m;
	cout << "type n and m: ";
	cin >> n;
	cin >> m;
	int** arr = create(n, m);
	fill(arr, n, m);
	cout << "array: ";
	printa(arr, n, m);
	del(arr, n);
	return 0;
}
*/
/* 4)
#include <iostream>
using namespace std;
int** transpose(int** matrix, int n, int m) {
	int** result = new int* [m];
	for (int i = 0; i < m; i++) {
		result[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[j][i] = matrix[i][j];
		}
	}
	return result;
}
void printa(int** arr, int n, int m) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
	}
}
int** create(int n, int m) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	return arr;
}
int main() {
	int n = 2, m = 3;
	int** matrix = create(n, m);
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = k++;
		}
	}
	printa(matrix, n, m);
	cout << endl;
	int** transposed = transpose(matrix, n, m);
	printa(transposed, m, n);

	return 0;
}
*/
/* 5)
#include <iostream>
using namespace std;

void sortRowsBySum(int** arr, int rows, int cols) {
	int* sums = new int[rows];

	for (int i = 0; i < rows; i++) {
		sums[i] = 0;
		for (int j = 0; j < cols; j++) {
			sums[i] += *(*(arr + i) + j);
		}
	}

	// сортировка пузырьком с перестановкой указателей
	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < rows - i - 1; j++) {
			if (sums[j] > sums[j + 1]) {
				// меняем местами указатели на строки
				int* tempPtr = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tempPtr;

				// меняем местами суммы
				int tempSum = sums[j];
				sums[j] = sums[j + 1];
				sums[j + 1] = tempSum;
			}
		}
	}

	delete[] sums;
}

int main() {
	const int rows = 4, cols = 3;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		*(arr + i) = new int[cols];
		for (int j = 0; j < cols; j++) {
			*(*(arr + i) + j) = (i * cols + j) * 2 + 1;
		}
	}

	cout << "исходный массив:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
	sortRowsBySum(arr, rows, cols);

	cout << "после сортировки по сумме:" << endl;
	for (int i = 0; i < rows; i++) {
		int sum = 0;
		for (int j = 0; j < cols; j++) {
			cout << *(*(arr + i) + j) << " ";
			sum += *(*(arr + i) + j);
		}
		cout << " (сумма: " << sum << ")" << endl;
	}

	for (int i = 0; i < rows; i++) {
		delete[] * (arr + i);
	}
	delete[] arr;

	return 0;
}
int summ(int* r, int m) {
	int sum = 0;
	for (int j = 0; j < m; j++) {
		sum += r[j];
	}
	return sum;
}
*/
/* 6)
#include <iostream>
using namespace std;

int sumElements(int** arr, int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += *(*(arr + i) + j);
		}
	}
	return sum;
}

int main() {

	const int n = 3, m = 5;

	// cоздаем и заполняем массив
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		*(arr + i) = new int[m];
		for (int j = 0; j < m; j++) {
			*(*(arr + i) + j) = i * m + j + 1;
		}
	}

	cout << "массив 3x5:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}

	int sum = sumElements(arr, n, m);
	cout << "сумма всех элементов: " << sum << endl;

	// oсвобождаем память
	for (int i = 0; i < n; i++) {
		delete[] * (arr + i);
	}
	delete[] arr;

	return 0;
}
*/
/* 7)
#include <iostream>
#include <cstring>
using namespace std;

void sortWords(char** words, int count) {
	// сортировка пузырьком
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (strcmp(*(words + j), *(words + j + 1)) > 0) {
				// меняем местами указатели
				char* temp = *(words + j);
				*(words + j) = *(words + j + 1);
				*(words + j + 1) = temp;
			}
		}
	}
}

int main() {

	const int wordCount = 7;
	const char* initialWords[] = { "banana", "apple", "cherry", "date", "elderberry", "fig", "grape" };

	// cоздаем массив строк
	char** words = new char* [wordCount];
	for (int i = 0; i < wordCount; i++) {
		int len = strlen(initialWords[i]);
		*(words + i) = new char[len + 1];
		strcpy(*(words + i), initialWords[i]);
	}

	cout << "исходные слова:" << endl;
	for (int i = 0; i < wordCount; i++) {
		cout << *(words + i) << " ";
	}
	cout << endl;

	// сортируем слова
	sortWords(words, wordCount);

	cout << "после сортировки:" << endl;
	for (int i = 0; i < wordCount; i++) {
		cout << *(words + i) << " ";
	}
	cout << endl;

	// освобождаем память
	for (int i = 0; i < wordCount; i++) {
		delete[] * (words + i);
	}
	delete[] words;

	return 0;
}
*/
/* 8)
#include <iostream>
using namespace std;

double** allocatePlate(int n, int m) {
	double** plate = new double* [n];
	for (int i = 0; i < n; i++) {
		*(plate + i) = new double[m];
		for (int j = 0; j < m; j++) {
			*(*(plate + i) + j) = 20.0;
		}
	}
	return plate;
}

void freePlate(double** plate, int n) {
	for (int i = 0; i < n; i++) {
		delete[] * (plate + i);
	}
	delete[] plate;
}

void updateTemperature(double** plate, int n, int m) {
	// создаем временную копию для новых температур
	double** newPlate = allocatePlate(n, m);

	// устанавливаем нагреватель в центре
	int centerX = n / 2, centerY = m / 2;
	*(*(newPlate + centerX) + centerY) = 100.0;

	// обновляем температуры для всех точек кроме нагревателя и границ
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (i == centerX && j == centerY) continue;

			double sum = *(*(plate + i - 1) + j) +
				*(*(plate + i + 1) + j) +
				*(*(plate + i) + j - 1) +
				*(*(plate + i) + j + 1);
			*(*(newPlate + i) + j) = sum / 4.0;
		}
	}

	// копируем новые значения обратно
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(*(plate + i) + j) = *(*(newPlate + i) + j);
		}
	}

	freePlate(newPlate, n);
}

int main() {
	const int n = 5, m = 5, iterations = 5;

	double** plate = allocatePlate(n, m);

	cout << "начальное распределение температуры:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(plate + i) + j) << " ";
		}
		cout << endl;
	}

	// выполняем итерации
	for (int k = 0; k < iterations; k++) {
		updateTemperature(plate, n, m);
	}

	cout << "после " << iterations << " итераций:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(plate + i) + j) << " ";
		}
		cout << endl;
	}

	freePlate(plate, n);

	return 0;
}
*/
/* 9)
#include <iostream>
#include <cmath>
using namespace std;

double** createWeights(int n, int m) {
	double** weights = new double* [n];
	for (int i = 0; i < n; i++) {
		*(weights + i) = new double[m];
		for (int j = 0; j < m; j++) {
			*(*(weights + i) + j) = 0.1 * (i + 1) * (j + 1) - 0.5;
		}
	}
	return weights;
}

void normalizeWeights(double** weights, int n, int m) {
	for (int i = 0; i < n; i++) {
		double sum = 0.0;
		for (int j = 0; j < m; j++) {
			sum += abs(*(*(weights + i) + j));
		}

		if (sum > 1.0) {
			for (int j = 0; j < m; j++) {
				*(*(weights + i) + j) /= sum;
			}
		}
	}
}

double* forward(double** weights, double* inputs, int n, int m) {
	double* outputs = new double[n];

	for (int i = 0; i < n; i++) {
		outputs[i] = 0.0;
		for (int j = 0; j < m; j++) {
			outputs[i] += *(*(weights + i) + j) * *(inputs + j);
		}
	}

	return outputs;
}

int main() {

	const int n = 3, m = 4;

	double** weights = createWeights(n, m);

	cout << "матрица весов до нормализации:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(weights + i) + j) << " ";
		}
		cout << endl;
	}

	normalizeWeights(weights, n, m);

	cout << "матрица весов после нормализации:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(weights + i) + j) << " ";
		}
		cout << endl;
	}

	double* inputs = new double[m];
	for (int i = 0; i < m; i++) {
		*(inputs + i) = (i + 1) * 0.1;
	}

	cout << "входные данные:" << endl;
	for (int i = 0; i < m; i++) {
		cout << *(inputs + i) << " ";
	}
	cout << endl;

	double* outputs = forward(weights, inputs, n, m);

	cout << "выходы нейронов:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "нейрон " << i << ": " << outputs[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] * (weights + i);
	}
	delete[] weights;
	delete[] inputs;
	delete[] outputs;

	return 0;
}
*/
/* 10)
#include <iostream>
using namespace std;

void printMatrix(int** load, int n, int t) {
	cout << "матрица нагрузок:" << endl;
	cout << "узел\\время";
	for (int j = 0; j < t; j++) {
		cout << " " << j;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "узел " << i << ": ";
		for (int j = 0; j < t; j++) {
			cout << *(*(load + i) + j) << "% ";
		}
		cout << endl;
	}
}

double* averageLoadPerNode(int** load, int n, int t) {
	double* averages = new double[n];

	for (int i = 0; i < n; i++) {
		double sum = 0.0;
		for (int j = 0; j < t; j++) {
			sum += *(*(load + i) + j);
		}
		averages[i] = sum / t;
	}

	return averages;
}

void normalizeLoad(int** load, int n, int t) {
	double* averages = averageLoadPerNode(load, n, t);

	for (int i = 0; i < n; i++) {
		if (averages[i] > 80.0) {
			double loadToRedistribute = averages[i] * 0.1;
			double loadPerNode = loadToRedistribute / (n - 1);

			for (int j = 0; j < t; j++) {
				if (*(*(load + i) + j) > 80) {
					*(*(load + i) + j) -= loadToRedistribute;

					for (int k = 0; k < n; k++) {
						if (k != i) {
							*(*(load + k) + j) += loadPerNode;
						}
					}
				}
			}
		}
	}

	delete[] averages;
}

int findCriticalInterval(int** load, int n, int t) {
	int maxSum = 0;
	int criticalInterval = 0;

	for (int j = 0; j < t; j++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += *(*(load + i) + j);
		}

		if (sum > maxSum) {
			maxSum = sum;
			criticalInterval = j;
		}
	}

	return criticalInterval;
}

int main() {
	
	int n, t;
	cout << "введите количество узлов и интервалов: ";
	cin >> n >> t;

	int** load = new int* [n];
	for (int i = 0; i < n; i++) {
		*(load + i) = new int[t];
	}

	cout << "введите нагрузку для каждого узла по интервалам:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "узел " << i << ": ";
		for (int j = 0; j < t; j++) {
			cin >> *(*(load + i) + j);
		}
	}

	printMatrix(load, n, t);

	double* averages = averageLoadPerNode(load, n, t);
	cout << "\nсредняя нагрузка на узлах:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "узел " << i << ": " << averages[i] << "%" << endl;
	}

	normalizeLoad(load, n, t);
	cout << "\nпосле нормализации:" << endl;
	printMatrix(load, n, t);

	int critical = findCriticalInterval(load, n, t);
	cout << "\nкритический интервал: " << critical << endl;

	for (int i = 0; i < n; i++) {
		delete[] * (load + i);
	}
	delete[] load;
	delete[] averages;

	return 0;
}
*/