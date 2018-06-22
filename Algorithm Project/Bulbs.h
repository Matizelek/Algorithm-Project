#pragma once
#include <vector>;

using namespace std;
class Bulbs
{
	char sign;
	int arrayRange;
	int size, N, number;
	bool first;
	vector <int> A;
	// int *A = new int[size];
	int solution;
public:
	Bulbs();
	~Bulbs();
	int initBulbs();
	void MenuBox();
	void algorithm(vector <int> &A);
	int putArray();
};

