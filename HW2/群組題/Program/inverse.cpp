#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void error() {
	cout << "inverse matrix not existed !" << endl;
}
void first(int i, int m, double** arr, double** arr_1) { // set leading one
	double tmp;
	int j;
	tmp = arr[i][i];
	for (j = 0; j < m; j++) {
		arr[i][j] = arr[i][j] / tmp;
		arr_1[i][j] = arr_1[i][j] / tmp;
	}
}
void zero(int i, int m, double** arr, double** arr_1) { 
	int j, k;
	double tmp;
	for (j = 0; j < m; j++) {
		if (j == i)
			continue;
		tmp = -1 * arr[j][i];
		for (k = 0; k < m; k++) {
			arr[j][k] = arr[j][k] + (tmp * arr[i][k]);
			arr_1[j][k] = arr_1[j][k] + (tmp * arr_1[i][k]);
		}
	}
}
void gauss_jordan(int m, double** arr, double** arr_1) {
	int i, j;
	double tmp;
	for (i = 0; i < m; i++) {
		if (arr[i][i] == 0) {
			if (i == (m - 1)) {
				break;
			}
			else {
				for (j = 0; j < m; j++) {
					arr[i][j] = arr[i][j] + arr[i + 1][j];
					arr_1[i][j] = arr_1[i][j] + arr_1[i + 1][j];
				}
				first(i, m, arr, arr_1);
				zero(i, m, arr, arr_1);
			}
		}
		else {
			first(i, m, arr, arr_1);
			zero(i, m, arr, arr_1);
		}
	}
}
int main() {
	int m, n; // row column
	int i, j; // for loop usage
	cout << "Please enter how many rows: ";
	cin >> m;
	cout << "Please enter how many columns: ";
	cin >> n;
	if (m != n) {
		error();
		return 0;
	}
	double** arr; // set two dimensions array
	double** arr_1; // set two dimensions inverse matrix array
	arr = new double* [m];
	arr_1 = new double* [m];
	for (i = 0; i < m; i++) {
		arr[i] = new double[n];
		arr_1[i] = new double[n];
	}
	for (i = 0; i < m; i++) { // input matrix
		for (j = 0; j < n; j++) {
			cout << "Please enter the value of row " << i + 1 << " column " << j + 1 << ": ";
			cin >> arr[i][j];
			arr_1[i][j] = 0; // set initial value of inverse matrix
		}
		arr_1[i][i] = 1; // set initial value of inverse matrix
	}
	cout << "----------Input matrix----------" << endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	gauss_jordan(m, arr, arr_1);
	if (arr[m - 1][m - 1] == 0) {
		error();
		return 0;
	}
	cout << "------------Inverse matrix------------" << endl;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			if (arr_1[i][j] == -0) // -0 to 0
				arr_1[i][j] = fabs(arr_1[i][j]);
			cout << fixed << setprecision(3) << arr_1[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) { // clear memory
		delete[] arr[i];
		delete[] arr_1[i];
	}
	delete[] arr;
	delete[] arr_1;
	return 0;
}
