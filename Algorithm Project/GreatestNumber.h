#pragma once
#include <string>

using namespace std;

class GreatestNumber
{	
	char sign;
	int number, solution, size, temp ;
	string tab;
	
public:
	GreatestNumber();
	~GreatestNumber();
	int initGreatestNumber();
	void MenuBox();
	void algorithm(int);
	bool check(int);
};

