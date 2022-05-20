#include <iostream>
#include <string>
#include <clocale>
using namespace std;

class Matrix {
private:
	int rows, columns;
	int **arr;
public:

	Matrix() {
		rows = 0;
		columns = 0;
		arr = new int* [rows];
	}
	
	Matrix(int **_arr, int _rows, int _columns) {
		arr = _arr;
		rows = _rows; // здесь надо расчитать (или там две "с"? я не знаю.... три часа ночи...) длину массива но мне лень
		columns = _columns;
	}

	~Matrix() {
		cout << "вызван деструктор\n";
	}

	void setMatrix() {
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
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	int **getArr() {
		return arr;
	}
	
	int getRows() {
		return rows;
	}

	int getColumns() {
		return columns;
	}
};

Matrix sum(Matrix mat1, Matrix mat2) {
	int rows = mat1.getRows();
	int columns = mat1.getColumns();
	int** Sum = new int *[rows];
	for (int i = 0; i < rows; i++) {
		Sum[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			Sum[i][j] = mat1.getArr()[i][j] + mat2.getArr()[i][j];
		}
	}
	return Matrix(Sum, rows, columns);
}

int main() {
	setlocale(LC_CTYPE, "rus");
	Matrix mat;
	mat.setMatrix();
	mat.getMatrix();
	Matrix _mat;
	_mat.setMatrix();
	_mat.getMatrix();
	Matrix Sum = sum(mat, _mat);
	Sum.getMatrix();
	Matrix *matt = new Matrix();
	delete matt;

	return 0;
}