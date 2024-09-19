/*
	Summary: Count a character's appearances in a
				string for Zylabs Lab 4.11
	Author:	Nathan Karn
	Created: September 18, 2024
*/
#include <iostream>
#include <string>
using namespace std;

int main() {

	char inputChar;
	string inputString;
	int count = 0;

	cin >> inputChar;
	getline(cin, inputString);

	for (int i = 0; i < inputString.size(); ++i) {
		if (inputString.at(i) == inputChar) {
			++count;
		}
	}
	
	if (count != 1) {
		cout << count << " " << inputChar << "'s\n";
	}
	else {
		cout << count << " " << inputChar << endl;
	}
	
	return 0;
}
