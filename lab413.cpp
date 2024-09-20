/*
	Summary: Convert from a correctly typed numerical string to a integer for Zylabs Lab 4.12
	Author:	Nathan Karn
	Created: September 18, 2024
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string userStr;
	int userNum = 0;
	int count = 0;
	int i;

   cin >> userStr;
	
	for (i = 0; i < userStr.size(); ++i) {
	
		if ((isdigit(userStr.at(i)) != true) && (userStr.at(i) != ',')) {
			cout << "no 0" << endl;
			return 1;
		}
		if (userStr.at(i) == ',') { 
			count = count + 1;
	
			if (((userStr.find(',', i + 1) < i + 4) || (userStr.find(',', i + 1) > i + 4)) && (i + 4 < userStr.size())) {
				cout << "no 0" << endl;
				return 2;
			}
			if (count == 1 && i >= 4) { 
				cout << "no 0" << endl;
				return 3;
			}
			userStr.replace(i, 1, "");
		}
		}
		
	for (int i = 0; i < userStr.size(); ++i) {
		
		switch (userStr.at(i)) {
		
			case 48:
				break;
		
			case 49:
				userNum = userNum + (1 * pow(10, (userStr.size() - 1 - i)));
				break;
		
			case 50:
				userNum = userNum + (2 * pow(10, (userStr.size() - 1 - i)));
				break;
		
			case 51:
				userNum = userNum + (3 * pow(10, (userStr.size() - 1 - i)));
				break;
		
			case 52:
				userNum = userNum + (4 * pow(10, (userStr.size() - 1 - i)));
				break;
		
			case 53:
				userNum = userNum + (5 * pow(10, (userStr.size() - 1 - i)));
				break;
		
			case 54:
				userNum = userNum + (6 * pow(10, (userStr.size() - 1 - i)));
				break;
		
			case 55:
				userNum = userNum + (7 * pow(10, (userStr.size() - 1 - i)));
				break;
		
			case 56:
				userNum = userNum + (8 * pow(10, (userStr.size() - 1 - i)));
				break;
		
			case 57:
				userNum = userNum + (9 * pow(10, (userStr.size() - 1 - i)));
				break;
	}
	}	
	cout << "yes " << userNum << endl;

  	return 0;
}
