#include <iostream>
#include <string>
#include <clocale>
using namespace std;

class Matrix {
private:
	int rows, columns;
	int** arr;
public:

Matrix() {
	rows = 0;
	columns = 0;
	arr = new int* [rows];
}

~Matrix() {
	cout << "вызван деструктор\n";
}

void setMatrix() {
	//cout << "setMatrix is on proccess\n";
	cout << "enter rows count: ";
	cin >> rows;
	cout << "enter columns count: ";
	cin >> columns;

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[columns];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = rand() % 20;
		}
	}
}

void getMatrix() {
	//cout << "getMatrix is on proccess\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

};


int main() {
	setlocale(LC_CTYPE, "rus");
	Matrix mat;
	mat.setMatrix();
	mat.getMatrix();
	Matrix *matt = new Matrix();
	delete matt;

	return 0;
}
