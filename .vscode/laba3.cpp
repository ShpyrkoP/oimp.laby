#include <iostream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;
int matrix(vector<vector<int>>& a, int i, int j, int n) {
	if (j < n) {
		return a[i][j];
	}
	else {
		return -a[i][j - n];
	}
}
int character(vector<vector<int>>& a, int j, int i, int rows, int n) {
	int sum = 0;
		for (i = 0; i < rows; ++i) 
		{
			sum += abs(matrix(a,i,j,n));
		}
		return sum;
	}
int main()
{
	int rows = 0, cols = 0, b = 0, n = 0;
	cout << "Enter the number of elements in a row (n<=10): ";
	cin >> b;
	if (b > 10) {
		cout << endl << "The number of rows mustn't be greater than 10" << endl;
		return 0;
	};
	rows = b;
	cout << "Enter the number of elements in a column(n<=5): ";
	cin >> n;	
	if (n > 5) {
		cout << endl << "The number of columns shouln't be greater than 5" << endl;
		return 0;
	};
	cols = 2 * n;
	vector<vector<int>> a(rows, vector<int>(n));		
	uniform_int_distribution<int> u(-10,10);				//заполнение матрицы будет происходить случайными числами
	default_random_engine e;	
	e.seed(time(0));
	cout << endl << "Not sorted matrix:" << endl;
	for (int i = 0; i < rows; ++i) {                   
		for (int j = 0; j < n; ++j) {
			a[i][j] = u(e);
		}
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrix(a, i, j, n) << "\t";
		}
		cout << endl;
	}
	//новые векторы, чтобы сортировать отдельно взятые столбцы, а не все элементы сразу
	//кркт для 2характеристики столбца, индекс для счета номера столбца (это была подсказка от иишки)
		vector<int> index(cols);			   
		vector<int> chrct(cols);
		int i = 0;
			for (int j = 0; j < cols; ++j)
			{
				chrct[j] = character(a, j, i, rows, n);
				index[j] = j;
			}
		//сортировка массива пузырьком
		int temp;
		int temp_id;
		for (int i = 0; i < cols-1; ++i) {
			for (int j = 0; j < cols-1; ++j) {
				if (chrct[j] < chrct[j + 1]) {
					temp = chrct[j];
					chrct[j] = chrct[j + 1];
					chrct[j + 1] = temp;
					temp_id = index[j];
					index[j] = index[j + 1];
					index[j + 1] = temp_id;
				}
			}
		}
		cout <<endl << "Sorted matrix: " << endl;
		for (int i = 0; i < rows; ++i){
			for (int j = 0; j < cols; ++j) {
				cout << matrix(a, i, index[j], n) << "\t";
			}
			cout << endl;
			}
	return 0;
}