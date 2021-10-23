#include <iostream>
#include <functional>

using namespace std;
//Вывод чисел
void print(double* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
//критерий для второго задания
bool krit(double a, double b) {
	if (a >= b) {
		return true;
	}
	else {
		return false;
	}
}
//Сортировка по дробной части
void sortirovka(double* matrix,double *matrix1,int n, function<bool(double, double)>) {
	double help,help1;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (krit(matrix[i], matrix[j])) {
				help = matrix[j];
				matrix[j] = matrix[i];
				matrix[i] = help;

				help1 = matrix1[j];
				matrix1[j] = matrix1[i];
				matrix1[i] = help1;
			}
		}

	}
}

//Подсчёт среднего арифметического
double kolvo(double* matrix, int n) {
	double sum = 0;
	double sered;
	for (int i = 0; i < n; i++) {
		sum += matrix[i];
	}
	return sered = sum / n;
}