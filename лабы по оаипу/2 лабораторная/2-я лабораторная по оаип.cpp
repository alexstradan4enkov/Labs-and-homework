/*#include <iostream>
using namespace std;
int main() {
	char c[100];
	char a[10][20];
	cout << "type ten words: ";
	cin.getline(c, 100);
	int b = 0;
	int d = 0;
	for (int i = 0; c[i]; i++) {
		if (c[i] == 32) {
			a[b][d] = '\0';
			b++;
			d = 0;
		}
		else {
			a[b][d] = c[i];
			d++;
		}
		a[b][d] = '\0';
	}
	cout << "words: " << endl;
	for (int j = 0; j <= b; j++) {
		cout << a[j]<< endl;

	}
	int k = 0;
	for (int i = 0; i < b+1; i++) {
		if (a[i][0] == 'a') {
			k++;

		}
	}
	int minl = 20;
	for (int i = 0; i < 10; i++) {
		int l = strlen(a[i]);
		if (l<minl) {
			minl = l;

		}
	}
	cout << "words begin 'a': " << k;
	cout << ", length shortest word: "<<minl;
	int lastw = b;
	int counta = 0;
	for (int i = 0; a[lastw][i]; i++) {
		if ((a[lastw][i] == 'a') || (a[lastw][i] == 'A')) {
			counta++;
		}
	}
	cout << ", 'a' in last word: " << counta << endl;
	for (int i = 0; i < b + 1; i++) {
		for (int j = 0; a[i][j]; j++) {
			a[i][j] = tolower(a[i][j]);

		}
	}
	cout << "words: " << endl;
	for (int j = 0; j <= b; j++) {
		cout << a[j] << endl;
	}
	int y = 0;
	for (int i = 0; i < b + 1; i++) {
		int len = strlen(a[i]);
		if (len > 0 && a[i][0] == a[i][len - 1]) {
			y++;
		}
	}
	cout << " couples with the same beginning and end: " <<y<< endl;

	return 0;
}
*/