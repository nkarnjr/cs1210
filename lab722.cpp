/*********************************************************
* Summary:	Determine coins needed for exact change for Zylabs Lab 7.22
*
* Author:	Nathan Karn Jr.
* Created:	November 1, 2024
*
********************************************************/

#include <iostream>
#include <vector> 

using namespace std;

void exactChange(int userTotal, vector<int>& coinVals) {
	vector<int> coinWorth = {1, 5, 10, 25};

	for (int i = 3; i >= 0; --i) {
		coinVals[i] = userTotal / coinWorth[i];
		userTotal %= coinWorth[i];
	}
}

int main() {
	int inputVal;
	vector<int> coinVals(4);
	vector<string> coinNames = {" nickel", " dime", " quarter"};
   
	cin >> inputVal;

	if (inputVal == 0) {
		cout << "no change";
	}
	else {
		exactChange(inputVal, coinVals);
	
		for (int i = 0; i < 4; ++i) {
			if (i == 0 && coinVals[i] > 1) {
				cout << coinVals [i] << " pennies\n";
			}
			else if (i == 0) {
				cout << coinVals[i] << " penny\n";
			}
			else if (coinVals [i] > 1) {
				cout << coinVals[i] << coinNames[i-1] << "s\n";
			}
			else if (coinVals [i] > 0) {
				cout << coinVals[i] << coinNames[i-1] << endl;
			}
		}
	}
   return 0;
}
