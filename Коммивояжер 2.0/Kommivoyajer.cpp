#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ostream>
#include <time.h>
#include "Kommivoyajer.h"

bool Kommivoyajer::FIndNewCombinationOfWay()
{
	if (arrayOfCitisIx && countOfCity > 1)
	{
		int var(0), i(0), j(0);

		for (i = countOfCity - 2; i >= 0 && (arrayOfCitisIx[i] >= arrayOfCitisIx[i + 1]); --i);
		if (i == -1)
		{
			return false;
		}
		for (j = countOfCity - 1; (j > i) && (arrayOfCitisIx[i] >= arrayOfCitisIx[j]); --j);

		var = arrayOfCitisIx[i];
		arrayOfCitisIx[i] = arrayOfCitisIx[j];
		arrayOfCitisIx[j] = var;

		for (int k(i + 1), i(0); i < countOfCity - k - 1; ++i)
		{
			var = arrayOfCitisIx[k + i];
			arrayOfCitisIx[k + i] = arrayOfCitisIx[countOfCity - 2 - i];
			arrayOfCitisIx[countOfCity - 2 - i] = var;
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
			return;

		if (tableOfRoadVal = new int*[countOfCity])
		{
			for (int i(0); i < countOfCity; i++)
				if ((tableOfRoadVal[i] = new int[countOfCity])==NULL)
					throw 1;

			for (int i(0); i < countOfCity; i++)
				for (int j(0); j < countOfCity; j++)
					if (i == j)
						tableOfRoadVal[i][j] = 0;
					else
						tableOfRoadVal[i][j] = rand() % 100 + 1;
		}
		else
			throw 0;
	}
	catch (const int &i)
	{
		if(i)
			puts("Memory leack when creating at array of pointers in tableOfRoadVal");
		else
			puts("Memory leack when creating at array of integer in tableOfRoadVal");
	}

}
void Kommivoyajer::CalculateMinimalWay()
{
	if (countOfCity > 1)
	{
		minWay += tableOfRoadVal[startCityIx - 1][arrayOfCitisIx[0] - 1];
		for (int i(1); i < countOfCity - 1; i++)
			minWay += tableOfRoadVal[arrayOfCitisIx[i - 1] - 1][arrayOfCitisIx[i] - 1];
		minWay += tableOfRoadVal[arrayOfCitisIx[countOfCity - 2] - 1][startCityIx - 1];

		printf("1 - "); PrintAArrayOfCitisIx(); int ix = 2;

		bool newWay(true);
		do
		{
			newWay = FIndNewCombinationOfWay();
			if (!newWay)
				break;

			printf("%d - ", ix); PrintAArrayOfCitisIx(); ++ix;

			int varMinWay = 0;

			varMinWay += tableOfRoadVal[startCityIx - 1][arrayOfCitisIx[0] - 1];
			for (int i(1); i < countOfCity - 1; i++)
				varMinWay += tableOfRoadVal[arrayOfCitisIx[i - 1] - 1][arrayOfCitisIx[i] - 1];
			varMinWay += tableOfRoadVal[arrayOfCitisIx[countOfCity - 2] - 1][startCityIx - 1];

			if (varMinWay < minWay)
				minWay = varMinWay;
		} while (newWay);
	}
}

std::ostream& operator<<(std::ostream &os, Kommivoyajer &obj)
{
	obj.PrintAArrayOfCitisIx();
	obj.PrintATableOfRoadVal();
	os << "Count of citis : " << obj.countOfCity << std::endl;
	os << "Start city index : " << obj.startCityIx << std::endl;
	os << "The minimum way : " << obj.minWay << std::endl;
	return os;
}

void Kommivoyajer::PrintAKommovoyajerObj() 
{
	PrintAArrayOfCitisIx();
	PrintATableOfRoadVal();
	printf("Count of citis : ",   countOfCity); printf("\n");
	printf("Start city index : ", startCityIx); printf("\n");
	printf("The minimum way : ",  minWay); printf("\n");
}
void Kommivoyajer::PrintATableOfRoadVal()
{
	if (tableOfRoadVal)
	{
		puts("Table of roads values :");
		for (int i(0); i < countOfCity + 1; i++)
			printf("%d\t", i);
		printf("\n");
		for (int i(0); i < countOfCity; ++i)
		{
			printf("%d", i + 1);
			for (int j(0); j < countOfCity; ++j)
			{
				printf("\t%d", tableOfRoadVal[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		puts("Matrix is't created.");
	}
}
void Kommivoyajer::PrintAArrayOfCitisIx()
{
	if (arrayOfCitisIx)
	{
		puts("Array of citis indexes :");
		for (int i(0); i < countOfCity-1; i++)
			printf("%d\t", arrayOfCitisIx[i]);
		printf("\n");
	}
	else
	{
		puts("Array is't created.");
	}
}

Kommivoyajer::Kommivoyajer(int countOfCity,int startCityIx)
{
	minWay = 0;

	if (countOfCity <= 0 || startCityIx <=0 || startCityIx > countOfCity)
	{
		puts("Invalid input. Object properties are set as default.");
		tableOfRoadVal = nullptr;
		arrayOfCitisIx = nullptr;
		Kommivoyajer::countOfCity = 0;
		Kommivoyajer::startCityIx = 0;
	}
	else
	{
		Kommivoyajer::countOfCity = countOfCity;
		Kommivoyajer::startCityIx = startCityIx;

		if (countOfCity == 1)
		{
			tableOfRoadVal	   = nullptr;
			arrayOfCitisIx = nullptr;
		}
		else
		{
			NewSqrMatrixAndRandValue();

			try
			{
				if (!(arrayOfCitisIx = new int[Kommivoyajer::countOfCity - 1]))
					throw true;
				for (int i(0), j(1); i < countOfCity - 1; ++i)
				{
					if (j == startCityIx)
						++j;
					arrayOfCitisIx[i] = j;
					++j;
				}
			}
			catch (const bool & b)
			{
				puts("Memory leack when creating at array of integer in arrayOfCitisIx");
			}
		}
}
}
Kommivoyajer::~Kommivoyajer()
{
	if (tableOfRoadVal)
	{
		for (int i(0); i < countOfCity; ++i)
			if (tableOfRoadVal[i])
				delete[] tableOfRoadVal[i];
		delete[] tableOfRoadVal;
	}
	if (arrayOfCitisIx)
		delete[] arrayOfCitisIx;
}