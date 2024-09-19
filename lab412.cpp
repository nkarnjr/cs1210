/*
	Summary: Convert postivie integers to
				binary for Zylabs Lab 4.12
	Author:	Nathan Karn
	Created: September 18, 2024
*/
#include <iostream>
using namespace std;

int main() {

	int inputVal = 0;
	int remainderInt;
	string remainderStr;
	string binaryStr = "";

	cin >> inputVal;	

	while (inputVal > 0) {
		remainderInt = inputVal % 2;
		inputVal /= 2;

		if (remainderInt == 1) {
			remainderStr = "1";
		}
		else if (remainderInt == 0) {
			remainderStr = "0"; 
		}

		binaryStr = remainderStr + binaryStr;
	}

	cout << binaryStr << endl;	

	return 0;
}
