#ifndef SUB_H
#define SUB_H
#include <iostream>
#include <string>
using namespace std;

class SUB
{
	public:
		SUB();
		SUB(string, int, bool, int, int, int, bool);
		int getEffect();
		int getCardNum();
		bool getGOOJ();
		bool getGTJ();
		int getMove();
		int getPos();
		string getDescription();

	private:
		string description;
		int cardNum;
		bool GOOJ;		//get out of jail
		int moneyEffect;
		int newLocation;
		int move;
		bool GTJ;		//go to jail
};
#endif
		
