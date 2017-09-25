#pragma once
#ifndef _KOMMIVOYAJER_H_
#define _KOMMIVOYAJER_H_


class Kommivoyajer
{
	int **tableOfRoad, *tableOfCitisIx, countOfCity, startCityIx, minWay;
	bool FIndNewCombinationOfWay();
	void NewSqrMatrixAndRandValue();
public:
	void PrintATableOfRoad();
	void PrintAMinimalWay();
	int GetMinimalWay();

	Kommivoyajer(int countOfCity = 0, int startCityIx = 0);
	~Kommivoyajer();
};
#endif // !_KOMMIVOYAJER_H_