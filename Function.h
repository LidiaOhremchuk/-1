#pragma once
#include <functional>

using namespace std;

void print(double* a, int n); // ����� �������

bool krit(double a, double b); //�������� ��� ���������� 

void sortirovka(double* matrix, double* matrix1,int n, function<bool(double, double)>);//����������

double kolvo(double* matrix, int n);//������� ��������������
