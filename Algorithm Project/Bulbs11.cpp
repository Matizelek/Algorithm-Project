#include <iostream>
#include <conio.h>

#include "Bulbs11.h"

using namespace std;


Bulbs11::Bulbs11()
{
	first = false;
	solution = 0;
	actualSize = 0;
	lastLightOn = 0;
	vectorSize = 0;
	MaxVec = 0;

}


Bulbs11::~Bulbs11()
{
}

void Bulbs11::MenuBox()
{
		cout << "Algorithm Bulbs light on with specific order and when bulbs before ale light on too. \n";
		cout << "Choose task: \n";
		cout << "1. Enter a table  \n";
		cout << "2. See egsample \n";
		cout << "3. Back to Main Menu \n";
}

int Bulbs11::putArray()
{
	system("cls");
	cout << "Put size of the array from 1 to 100: \n";
	cin >> arrayRange;
	do {
		number = NULL;
		system("cls");
		cout << "Range: " << arrayRange << "\nPut number from 1 to " << arrayRange << "\n";
		cout << "Only one number at time, and press enter to Apply.\n";
		cout << "Numbers can't repeate \n";
		cout << "Actuall size of array : " << size << "\n";

		for (int i = 0; i<size; i++)
		{
			cout << N[i] << "\t";
			if (i % 5 == 4) cout << "\n";

		}
		cout << "\n";
		cin.clear();
		cin >> number;

		if (number >= 1 && number <= arrayRange)
		{
			N.push_back(number);
			size++;
			continue;
		}
		else
		{
			cout << "Somethings wrong!\nTry again.";
			continue;
		}
	} while (size != arrayRange);
	return 0;
}

void Bulbs11::resizeVector(int size)
{
	if (size > vectorSize) {
		for (auto j = vectorSize; j <= size; j++) {
			turnOn.push_back('0');
		}

		vectorSize = size;
	}
}

bool Bulbs11::check(int i)
{
	if (turnOn[i - 1] == '1' || i == 1) {

		if (lastLightOn == (i - 1)) {
			return true;
		}
		else if (lastLightOn < i - 1) {
			if (check(i - 1) || i - 1 == 1) {
				return true;
			}
		}
	}

	return false;
}


void Bulbs11::Algorithm(vector<int> &N)
{

	for( auto i : N){
		resizeVector(i);
	 if(i == 1)	{
		 first = true;
		 turnOn[i] = '1';
		 actualSize++;
		 if(turnOn[actualSize] == '1')	 
			 if (check(actualSize)) {
				 lastLightOn = actualSize;
				 cout << "i: " << i << "\n";
				 solution++;
				 actualSize = 0;
				 continue;
			 }

		
	 }
	 else if (first == true) {
		 turnOn[i] = '1';
		 if (MaxVec < i) MaxVec = i;
		 if (check(MaxVec)) {
			 lastLightOn = i;
			 cout << "i: " << i << "\n";
				 solution++;
				 continue;
		 }
	 }
	 else {
		 turnOn[i] = '1';
		 actualSize++;
		 continue;
	 }
	}
	cout << "solution: " << solution << "\n";
	cin.ignore();
}

int Bulbs11::initBulbs()
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
			Algorithm(N);
			cin.ignore();
			break;
		case('2'):
			system("cls");
			cout << "EGSAMPLES:\n";
			cout << "N[9] = { 1, 3, 2, 5, 6, 4, 8, 9, 7 }\n";
			vector <int> Aeg1 = { 1, 3, 2, 5, 6, 4, 8, 9, 7 };
			solution = 0;
			Algorithm(Aeg1);
			cin.ignore();
			break;
		}
	} while (sign != '3' && sign != 27);

	return solution;
}

