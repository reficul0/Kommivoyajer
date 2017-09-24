// ЗадачаКолливояжора_Лабораторная_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include <random>
#include <time.h>

bool FindNeWay(int *ind, int N)
{
	int var(0), i(0), j(0);

	for (i = N - 2; i >= 0 &&(ind[i] >= ind[i + 1]); i--);
	if (i == -1)
	{
		return false;
	}
	for (j = N - 1; (j > i) && (ind[i] >= ind[j]); j--);

	var = ind[i];
	ind[i] = ind[j];
	ind[j] = var;

	for (int j(i + 1), i(0); i<N - j - 1; i++)
	{
		var = ind[j + i];
		ind[j + i] = ind[N - 1 - i];
		ind[N - 1 - i] = var;
	}

	return true;
}
int** NewSqrMatrixAndRandValue(int N)
{
	int** mtrx(nullptr);
	srand(time(NULL));
	try
	{
		if (mtrx = new int*[N])
		{
			for (int i(0); i < N; i++)
			{
				if (!(mtrx[i] = new int[N]))
				{
					throw true;
				}
			}

			for (int i(0); i < N; i++)
				for (int j(0); j < N; j++)
				{
					mtrx[i][j] = rand() % 100 + 1;
				}
			return mtrx;
		}
		throw true;
	}
	catch (const bool&)
	{
		puts("Memory leack");
	}

}

int main()
{
	int citi(NULL), minWay(NULL), **tab(nullptr), var(NULL);

	puts("Enter count of citis :");
	scanf("%d", &citi);
	while (citi <= 0)
	{
		system("cls");
		puts("Wrong data, count of citi > 2 and <13");
		scanf("%d", &citi);
	}

	tab = NewSqrMatrixAndRandValue(citi);
	system("cls");

	for (int i(0); i < citi; i++)
	{
		for (int j(0); j < citi; j++)
		{
			printf("A[%d][%d]=%d ", i, j, tab[i][j]);
		}
		puts("");
	}

	int* ind = new int [citi];

	for (size_t i = 0; i < citi; i++)
	{
		ind[i] = i + 1;
	}

	for (int i(1); i < citi; i++)
	{
		minWay += tab[ind[i - 1] - 1][ind[i] - 1];

	}

	for (int i(0); i < citi; i++)
	{
		printf("%d", ind[i]);
	}
	puts("");

	bool neWay(true);
	do
	{
		neWay = FindNeWay(ind, 3);
		for (int i(0); i < citi; i++)
		{
			printf("%d", ind[i]);
		}
		puts("");

		var = 0;
		for (int i(1); i < citi; i++)
		{
			var += tab[ind[i - 1] - 1][ind[i] - 1];

		}
		if (var < minWay)
			minWay = var;
	} while (neWay);

	printf("%d", minWay);
	_getch();
	
	
	return 0;
}

