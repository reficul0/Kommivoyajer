#pragma once
#ifndef _KOMMIVOYAJER_H_
#define _KOMMIVOYAJER_H_

class Kommivoyajer
{
	int **tableOfRoadVal, *arrayOfCitisIx, countOfCity, startCityIx, minWay;
	bool FIndNewCombinationOfWayDiykstra();
	void NewSqrMatrixAndRandValue();
public:
	void PrintAArrayOfCitisIx();
	void PrintATableOfRoadVal();
	void CalculateMinimalWay();
	void PrintAKommovoyajerObj();

	int ReturnAMinimalWay()
	{
		return minWay;
	}
	friend std::ostream& operator<<(std::ostream &os, Kommivoyajer &obj);

	Kommivoyajer(int countOfCity = 0, int startCityIx = 0);
	~Kommivoyajer();
};
#endif // !_KOMMIVOYAJER_H_