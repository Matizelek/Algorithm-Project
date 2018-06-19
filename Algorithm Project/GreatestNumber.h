#pragma once
#include <string>
#include <sstream>    
#include <iostream>
#include <conio.h>

using namespace std;


//////////////###HEAD

template<typename T>
class GreatestNumber
{	
	char sign;
	T number, solution, size, temp ;
	string tab;
	
public:
	GreatestNumber();
	~GreatestNumber();
	T initGreatestNumber();
	void MenuBox();
	void algorithm(T);
	bool check(T);
};


//////////////////

template<typename T>
GreatestNumber<T>::GreatestNumber()
{
	number = NULL;
	solution = 0;
	size = 0;
	temp = 0;
	tab = "0";
}


template<typename T>
GreatestNumber<T>::~GreatestNumber()
{
}

template<typename T>
void GreatestNumber<T>::MenuBox()
{
	cout << "Algorithm Greatest Posible number from Input \n";
	cout << "Choose task: \n";
	cout << "1. Enter a number \n";
	cout << "2. See egsample \n";
	cout << "3. Back to Main Menu \n";
}



template<typename T>//, typename K>
bool GreatestNumber<T>::check(T number)
{
	if (number < 10000 && number > 0)	return true;
	else
	{
		number = NULL;
		return false;
	}
}



template<typename T>
void GreatestNumber<T>::algorithm(T number)
{

	if (check(number) == true)
	{

		if (number > 9999) size = 5;
		else if (number < 9999 && number > 999) size = 4;
		else if (number < 999 && number > 99) size = 3;
		else if (number < 99 && number > 9) size = 2;
		else if (number < 9 && number > 0) size = 1;


		ostringstream ss;
		ss << number;
		tab = ss.str();


		for (T i = 0; i < size; i++)
		{
			for (T j = 0; j < size - 1; j++)
			{
				if (tab[j] < tab[j + 1])
				{
					temp = tab[j];
					tab[j] = tab[j + 1];
					tab[j + 1] = temp;
				}
			}

		}

		solution = stoi(tab);


		cout << "\n\nSOLUTION : \n" << solution << "\n";
		cin.ignore();
	}
	else
	{
		system("cls");

		cout << "Wrong Number!  Try again.\n Number from 0 to 10 000.\n";
		cin >> number;
		algorithm(number);
	}


}


template<typename T>
T GreatestNumber<T>::initGreatestNumber()
{
	do {

		system("cls");
		MenuBox();

		sign = _getch();

		switch (sign)
		{
		case('1'):
			system("cls");
			cout << "Put number from 0 to 10 000 :\n";
			cin >> number;
			algorithm(number);
			cin.ignore();
			break;
		case('2'):
			system("cls");
			cout << "EGSAMPLE:\n";
			cout << "2835\n";
			algorithm(2835);
			cin.ignore();
			break;
		}
	} while (sign != '3' && sign != 27);
	return solution;
}
