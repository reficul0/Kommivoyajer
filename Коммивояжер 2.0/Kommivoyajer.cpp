#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Kommivoyajer.h"


bool Kommivoyajer::FIndNewCombinationOfWay()
{
	if (tableOfCitisIx && countOfCity > 0)
	{
		int var(0), i(0), j(0);

		for (i = countOfCity - 2; i >= 0 && (tableOfCitisIx[i] >= tableOfCitisIx[i + 1]); --i);
		if (i == -1)
		{
			return false;
		}
		for (j = countOfCity - 1; (j > i) && (tableOfCitisIx[i] >= tableOfCitisIx[j]); --j);

		var = tableOfCitisIx[i];
		tableOfCitisIx[i] = tableOfCitisIx[j];
		tableOfCitisIx[j] = var;

		for (int k(i + 1), i(0); i < countOfCity - k - 1; ++i)
		{
			var = tableOfCitisIx[k + i];
			tableOfCitisIx[k + i] = tableOfCitisIx[countOfCity - 2 - i];
			tableOfCitisIx[countOfCity - 1 - i] = var;
		}
		return true;
	}
	return false;
}
void Kommivoyajer::NewSqrMatrixAndRandValue()
{
	srand(time(NULL));
	try
	{
		if (countOfCity < 2)
			throw 'e';
		if (tableOfRoad = new int*[countOfCity])
		{
			for (int i(0); i < countOfCity; i++)
				if (!(tableOfRoad[i] = new int[countOfCity]))
					throw true;

			for (int i(0); i < countOfCity; i++)
				for (int j(0); j < countOfCity; j++)
					if (i == j)
						tableOfRoad[i][j] = 0;
					else
						tableOfRoad[i][j] = rand() % 100 + 1;
		}
		throw true;
	}
	catch (const bool&)
	{
		puts("Memory leack");
	}
	catch (const char &e)
	{
		puts("The matrix pointer already points to the memory area");
	}

}
int Kommivoyajer::GetMinimalWay()
{
	minWay = 0;

	minWay += tableOfRoad[startCityIx - 1][tableOfCitisIx[0] - 1];
	for (int i(1); i < countOfCity - 1; i++)
		minWay += tableOfRoad[tableOfCitisIx[i - 1] - 1][tableOfCitisIx[i] - 1];
	minWay += tableOfRoad[tableOfCitisIx[countOfCity - 2] - 1][startCityIx - 1];

	for (int i(0); i < countOfCity - 1; i++)
		printf("%d", tableOfCitisIx[i]);
	puts("");

	bool newWay(true);
	do
	{
		newWay = FIndNewCombinationOfWay();
		if (!newWay)
			break;
		for (int i(0); i < countOfCity - 1; i++)
			printf("%d", tableOfCitisIx[i]);
		puts("");

		int var = 0;

		var += tableOfRoad[startCityIx - 1][tableOfCitisIx[0] - 1];
		for (int i(1); i < countOfCity - 1; i++)
			var += tableOfRoad[tableOfCitisIx[i - 1] - 1][tableOfCitisIx[i] - 1];
		var += tableOfRoad[tableOfCitisIx[countOfCity - 2] - 1][startCityIx - 1];

		if (var < minWay)
			minWay = var;
	} while (newWay);

	return minWay;
}

void Kommivoyajer::PrintATableOfRoad()
{
	for (int i(0); i < countOfCity + 1; i++)
		printf("%d\t", i);
	printf("\n");
	for (int i(0); i < countOfCity; ++i)
	{
		printf("%d", i + 1);
		for (int j(0); j < countOfCity; ++j)
		{
			printf("\t%d", tableOfRoad[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void Kommivoyajer::PrintAMinimalWay()
{
	printf("Minimal way from sity %d is : %d\n", startCityIx, minWay);
}

Kommivoyajer::Kommivoyajer(int countOfCity, int startCityIx)
{
	try
	{
		if (startCityIx <= countOfCity && startCityIx > 0)
		{
			if (countOfCity <= 0)
			{
				tableOfRoad = nullptr;
				tableOfCitisIx = nullptr;
				Kommivoyajer::countOfCity = 0;
				Kommivoyajer::startCityIx = 0;
			}
			else if (countOfCity > 0)
			{
				Kommivoyajer::countOfCity = countOfCity;
				Kommivoyajer::startCityIx = startCityIx;
				NewSqrMatrixAndRandValue();

				try
				{
					if (!(tableOfCitisIx = new int[countOfCity - 1]))
						throw true;
					for (int i(0), j(1); i < countOfCity - 1; ++i)
					{
						if (j == startCityIx)
							++j;
						tableOfCitisIx[i] = j;
						++j;
					}
				}
				catch (const bool & b)
				{
					puts("Memory Leack");
				}
			}
		}
		else
			throw 'e';
	}
	catch (const char &c)
	{
		puts("Invalid parametrs");
	}
}
Kommivoyajer::~Kommivoyajer()
{
	if (tableOfRoad)
	{
		for (int i(0); i < countOfCity; ++i)
		{
			if (tableOfRoad[i])
				delete[] tableOfRoad[i];
		}
		delete[] tableOfRoad;
	}
	if (tableOfCitisIx)
		delete[] tableOfCitisIx;
}