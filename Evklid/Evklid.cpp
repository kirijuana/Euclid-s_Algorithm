﻿// Evklid.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int *U = new int[2];
	int *V = new int[2];
	int *T = new int[2];
	int a = 0, n = 0, b = 0;
	cout << "a = b mod(n)" << "\n";
	cout << "Введите 3 числа: a, b и n: " << "\n";
	cin >> a >> b >> n;


	// вычисление НОД'а (Алгоритм Евклида)

	int a_1 = a, b_1 = n, k = 0, ost_1 = 1, ost = 1, NOD = 0;
	if (a > n)
	{
		a_1 = a;
		b_1 = n;
	}
	else
	{
		a_1 = n;
		b_1 = a;
	}
	if (a_1 % b_1 == 0)
	{
		ost_1 = b_1;
	}
	else
	{
		do
		{
			ost_1 = ost;
			k = a_1 / b_1;
			ost = a_1 - b_1 * k;
			a_1 = b_1;
			b_1 = ost;


		} while (ost != 0);
	}
	NOD = ost_1;
	cout << "НОД введенных чисел равен: " << NOD << "\n";

	// Расширенный алгоритм Евклида

	if (a > n)
	{
		U[0] = a;
		U[1] = 0;
		V[0] = n;
		V[1] = 1;
	}
	else
	{
		U[0] = n;
		U[1] = 0;
		V[0] = a;
		V[1] = 1;
	}

	
	int D = 0, q = 0;
	while (V[0] != 0)
	{
		D = T[1];
		q = U[0] / V[0];
		T[0] = U[0] % V[0];
		T[1] = U[1] - q * V[1];
		U[0] = V[0];
		U[1] = V[1];
		V[0] = T[0];
		V[1] = T[1];
		if (a % n == 0 || n % a == 0)
		{
			D = U[0];
		}
		
	}
	int x = b * D;
	if (x < 0)
	{
		x += n;
	}
	cout << "НОД = " << NOD << "=> решения: " "\n";
	for (int i = 1; i <= 4; i++)
	{
		cout << i << ". " << x << " + " << i << " * "  << n << " = " << x+i*n << "\n";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.