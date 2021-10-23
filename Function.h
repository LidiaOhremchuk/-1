#pragma once
#include <functional>

using namespace std;

void print(double* a, int n); // вывод массива

bool krit(double a, double b); //Критерий для сортировки 

void sortirovka(double* matrix, double* matrix1,int n, function<bool(double, double)>);//Сортировка

double kolvo(double* matrix, int n);//Среднее арифметическое
