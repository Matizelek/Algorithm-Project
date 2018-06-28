#pragma once
#include <vector>
using namespace std;

class Bulbs11
{
	bool first;
	int solution, actualSize, sizeVec, lastTurnOn, lastLightOn,vectorSize,MaxVec,number,arrayRange,size;
	vector<int> N;
	vector<char> turnOn;
	char sign;
	//vector<bool> lightOn;
public:
	Bulbs11();
	~Bulbs11();
	void Algorithm(vector<int>& N);
	bool check(int i );
	void resizeVector(int size);
	int initBulbs();
	void MenuBox();
	int putArray();
};

