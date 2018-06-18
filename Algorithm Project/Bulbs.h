#pragma once

using namespace std;
class Bulbs
{
	char sign;
	int arrayRange;
	int size, N, number;
	bool first;
	int *A = new int [size];
	int solution;
public:
	Bulbs();
	~Bulbs();
	int initBulbs();
	void MenuBox();
	void algorithm(int *A);
	int putArray();
};

