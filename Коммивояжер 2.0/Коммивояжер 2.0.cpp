// ������������������_������������_1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Kommivoyajer.h"


int main()
{
	int countOfCitis(NULL), startCity(NULL), minWay(NULL);

	puts("Enter count of citis : ");
	scanf("%d", &countOfCitis);

	puts("Enter index of start city : ");
	scanf("%d", &startCity);

	Kommivoyajer kom(countOfCitis, startCity);
	puts("");
	kom.PrintATableOfRoad();
	kom.GetMinimalWay();
	kom.PrintAMinimalWay();

	return 0;
}

