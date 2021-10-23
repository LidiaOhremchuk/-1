#include <iostream>
#include "Function.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	string filename;
	double c;
	int n=0;
	double* a;
	for (int i = 0; i < argc; i++) {
		cout << argv[i]<<" ";
	}
	cout << argc;
	if (argc < 2){
		cout << "Введите путь к файлу с которого считать данные(Пример hello.txt): ";
		cin >> filename;
		ifstream in(filename);
			if (in.is_open()) {
				while (!in.eof()) {
					in >> c;
					n++;
				}
			}
		in.seekg(0, ios::beg);
		in.clear();
			a = new double[n];
			for (int i = 0; i < n; i++) {
				in>>a[i];

			}
		in.close();
	}
	else {
		n = argc - 1;
	//Массив вещественных чисел
		a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = atof(argv[i + 1]);
		}
	}
	cout << "Вещественные числа: ";
	print(a, n);

	//Отделение дробной части от целой
	double* drob = new double[n];
	for (int i = 0; i < n; i++) {
		drob[i] = a[i] - (int)a[i];
	}

	//Сортировка чисел по дробной части
	sortirovka(drob,a,n,krit);
	cout << endl;
	cout << "Отсортированная дробная часть чисел: ";
	print(drob, n);
	cout << "\nОтсортированные числа по дробной части: ";
	print(a, n);

	//Вывод количества чисел и среднего арифметического.
	double sered=kolvo(a, n);
	cout << "\nКоличество элементов: " << n << endl;
	cout << "Среднее арифметическое: " << sered << endl;

	//Сохранение в файл
	string filename2;
	cout << "Введите название файла в который хотите сохранить результат: ";
	cin >> filename2;
	ofstream out;
	out.open(filename2);
	if (out.is_open()) {

		//
		out << "Отсортированная дробная часть чисел: ";
		for (int i = 0; i < n; i++) {
			out << drob[i] << " ";
		}
		out << "\nОтсортированные числа по дробной части: ";
		for (int i = 0; i < n; i++) {
			out << a[i] << " ";
		}

		//
		out << "\nКоличество элементов: " << n << endl;
		out << "Среднее арифметическое: " << sered << endl;

	}
	delete[]a;
}
