#include <iostream>
#include <conio.h>					// for getch();

#include"GreatestNumber.h"
#include "Bulbs.h"

using namespace std;

void initMenuBox()
{
	cout << "Main Menu\n";
	cout << "Choose Algorithm: \n";
	cout << "1. Greatest Posible Number from Imput Number \n";
	cout << "2. Bulb light on with specific order \n";
	
	
	
	cout << "\n\nESC. Exit Program \n";

}

int main()
{
	char sign = NULL;
	do {
		system("cls");
		initMenuBox();
		sign = _getch();			//taking first key without press enter;


		switch (sign)
		{
		case '1':
		{
			GreatestNumber<int> init;
			init.initGreatestNumber();
			init.~GreatestNumber();
			break;
		}
		case '2':
		{
			Bulbs init;
			init.initBulbs();
			init.~Bulbs();
			break;
		}
		default:
			break;


		}
	} while (sign != 27 );

	return 0;
}