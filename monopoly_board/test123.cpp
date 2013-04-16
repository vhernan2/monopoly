#include <string>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include <fstream>
#include <cstring>

using namespace std;

int main() {

	string input;

	ifstream dataFile ("image_folder.txt");

	int count = 0;
	int numPlayers = 4;

	string names[numPlayers];

	while(dataFile.is_open()){
		while(dataFile.good() && (count < numPlayers)){
			getline(dataFile, input);
			names[count] = input;
			count++;
		}
		dataFile.close();
	}

	cout << names[1] << endl;

}

