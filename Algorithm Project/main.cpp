#include <iostream>
#include <conio.h>					// for getch();

#include"GreatestNumber.h"

using namespace std;

void initMenuBox()
{
	cout << "Choose Algorithm: \n";
	cout << "1. Greatest Posible Number from Imput Number \n";

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
			GreatestNumber init;
			init.initGreatestNumber();
			break;
		}
		default:
			break;


		}
	} while (sign != 27 );

	return 0;
}