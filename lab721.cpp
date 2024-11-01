/*********************************************************
* Summary: Flip a coin for Zylabs lab 7.21
*
* Author:	Nathan Karn
* Created:	October 31, 2024
*
********************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

string coinFlip() {
	string coinFace = "Heads";
	int coinSide = rand() % 2;

	if (coinSide == 0) {
		coinFace = "Tails";
	}
	return coinFace;
}
	

int main() {
   int countFlips;
   
   srand(2);  // Unique seed

   cin >> countFlips;
	for (int i = 0; i < countFlips; ++i) {
		cout << coinFlip() << endl;
	}

   return 0;
}
