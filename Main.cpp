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
		cout << "������� ���� � ����� � �������� ������� ������(������ hello.txt): ";
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
	//������ ������������ �����
		a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = atof(argv[i + 1]);
		}
	}
	cout << "������������ �����: ";
	print(a, n);

	//��������� ������� ����� �� �����
	double* drob = new double[n];
	for (int i = 0; i < n; i++) {
		drob[i] = a[i] - (int)a[i];
	}

	//���������� ����� �� ������� �����
	sortirovka(drob,a,n,krit);
	cout << endl;
	cout << "��������������� ������� ����� �����: ";
	print(drob, n);
	cout << "\n��������������� ����� �� ������� �����: ";
	print(a, n);

	//����� ���������� ����� � �������� ���������������.
	double sered=kolvo(a, n);
	cout << "\n���������� ���������: " << n << endl;
	cout << "������� ��������������: " << sered << endl;

	//���������� � ����
	string filename2;
	cout << "������� �������� ����� � ������� ������ ��������� ���������: ";
	cin >> filename2;
	ofstream out;
	out.open(filename2);
	if (out.is_open()) {

		//
		out << "��������������� ������� ����� �����: ";
		for (int i = 0; i < n; i++) {
			out << drob[i] << " ";
		}
		out << "\n��������������� ����� �� ������� �����: ";
		for (int i = 0; i < n; i++) {
			out << a[i] << " ";
		}

		//
		out << "\n���������� ���������: " << n << endl;
		out << "������� ��������������: " << sered << endl;

	}
	delete[]a;
}
