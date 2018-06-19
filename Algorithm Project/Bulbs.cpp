#include <windows.h> 
#include <iostream>
#include <conio.h>


#include "Bulbs.h"

using namespace std;

Bulbs::Bulbs()
{
	solution = 0;
	size = 0;
	first = false;
	arrayRange = 0;
}


Bulbs::~Bulbs()
{
}

void Bulbs::MenuBox()
{
	cout << "Algorithm Bulbs light on with specific order and when bulbs before ale light on too. \n";
	cout << "Choose task: \n";
	cout << "1. Enter a table  \n";
	cout << "2. See egsample \n";
	cout << "3. Back to Main Menu \n";
}

void Bulbs::algorithm( int *A)
{
	//A[23] = { 2, 1, 3, 5, 4, 11, 23, 15, 19, 13, 8, 7, 22, 12, 6, 9, 21, 18, 20, 10, 14, 17, 16 }, N = 23;;
	//int A[9] = { 1, 3, 2, 5, 6, 4, 8, 9, 7 }, N = 9;
	//int A[6] = { 3,2,1,4,6, 5 }, N = 6;
	//int A[3] = { 1, 3, 2 }, N = 3;
	N = size;
	size = 0;

	for (int i = 0; i<N; i++)
	{
		if (A[i] == 1)
		{
			int a = 0;
			first = true;
			for (int j = 0; j <= i; j++)
			{
				if (((A[a] - 1 == A[j]) && (A[a] != 1)) || (A[a] == 1))
				{
					size++;
					a++;
					j = 0;
				}
			}
			if ((size == i + 1) && (size != 0))
			{
				solution++;
			}
		}

		else if ((A[i] != 1) && (first == true))
		{
			size = 0;
			int a = 0;
			for (int j = 0; j <= i; j++)
			{
				if (((A[a] - 1 == A[j]) && (A[a] != 1)) || (A[a] == 1))
				{
					size++;
					if (a < i)
					{
						a++;
						j = -1;
					}
				}
			}
			if ((size == i + 1) && (size != 0))
			{
				solution++;
			}
		}
	}
	cout << "\nSolution : " << solution << "\n";
	cin.ignore();

}

int Bulbs::putArray()
{
	system("cls");
	cout << "Put size of the array from 1 to 100: \n";
	cin >> arrayRange;
	do {
		number = NULL;
		system("cls");
		cout << "Range: "<< arrayRange << "\nPut number from 1 to "<<arrayRange<<"\n";
		cout << "Only one number at time, and press enter to Apply.\n";
		cout << "Numbers can't repeate \n";
		cout << "Actuall size of array : "<< size <<"\n";
		
		for(int i = 0;i<size;i++)
		{
			cout << A[i] << "\t";
			if (i % 5 == 4) cout << "\n";

		}
		cout << "\n";
		cin.clear();
		cin >> number;

		if(number >= 1 && number <= arrayRange)
		{
			A[size] = number;// -48;
			size++;
			continue;
		}
		else 
		{
			cout << "Somethings wrong!\nTry again.";
			continue;
		}
	} while(size != arrayRange);
	return 0;
}


int Bulbs::initBulbs()
{
	do {

		system("cls");
		MenuBox();

		sign = _getch();

		switch (sign)
		{
		case('1'):
			system("cls");
			putArray();
			algorithm(A);
			cin.ignore();
			break;
		case('2'):
			system("cls");
			cout << "EGSAMPLES:\n";
			cout << "A[9] = { 1, 3, 2, 5, 6, 4, 8, 9, 7 }\n";
			int Aeg1[9] = { 1, 3, 2, 5, 6, 4, 8, 9, 7 };
			solution = 0;
			size = 9;
			algorithm(Aeg1);
			cout << "A[23] = { 2, 1, 3, 5, 4, 11, 23, 15, 19, 13, 8, 7, 22, 12, 6, 9, 21, 18, 20, 10, 14, 17, 16}\n";
			int Aeg2[23] = { 2, 1, 3, 5, 4, 11, 23, 15, 19, 13, 8, 7, 22, 12, 6, 9, 21, 18, 20, 10, 14, 17, 16 };
			solution = 0;
			size = 23;
			algorithm(Aeg2);
			cin.ignore();
			break;
		}
	} while (sign != '3' && sign != 27);

	return solution;
}




