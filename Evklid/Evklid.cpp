#include "pch.h"
#include <iostream>

using namespace std;

int main()
{

	
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
	// добавил
	a = a / NOD;
	b = b / NOD;
	n = n / NOD; //
	
	
	int *U = new int[2];
	int *V = new int[2];
	int *T = new int[2];
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
	x = x % n;
	if (x < 0)
	{
		x += n;
	}
	
	cout << "НОД = " << NOD << "=> решения: " "\n";
	
	// исправил
	for (int i = 0; i < NOD; i++)
	{
		cout << i + 1 << ". " << x << " + " << i << " * "  << n << " = " << x+i*n << "\n";
	}

	system("pause");
}

