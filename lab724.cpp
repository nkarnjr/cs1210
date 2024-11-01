/*********************************************************
* Summary:	Convert from Decimal to Binary using functions for Zylabs Lab 7.24
*
* Author:	Nathan Karn Jr.
* Created:	November 1, 2024
*
********************************************************/

#include <iostream>
#include <string>

using namespace std;

string intToReverseBinary(int integerValue) {
	string binary = "";
	while (integerValue > 0) {
		if (integerValue % 2 == 0) {
			binary.append("0");
		}
		else {
			binary.append("1");
		}
		integerValue /= 2;
	}
	return binary;
}

string stringReverse(string userString) {
	string binary = "";
	string temp = "";
	for (int i = userString.size() - 1; i >= 0; --i) {
		temp = userString.at(i);
		binary.append(temp);
	}
	return binary;
}

int main() {
	int inputValue;
	
	cin >> inputValue;
	cout << stringReverse(intToReverseBinary(inputValue)) << endl;

   return 0;
}
