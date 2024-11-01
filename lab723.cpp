/*********************************************************
* Summary:	Sort a vector of numbers in descending order for Zylabs Lab 7.23
*
* Author:	Nathan Karn Jr.
* Created:	November 1, 2024
*
********************************************************/

#include <iostream>
#include <vector>

using namespace std;

void sortVector(vector<int>& myVec) {
	int compVal;
	
	for (int i = 0; i < myVec.size(); ++i) {
		for (int j = 0; j < myVec.size(); ++j) {
			if (myVec[i] > myVec[j]) {
				compVal = myVec[i];
				myVec[i] = myVec[j];
				myVec[j] = compVal;
			}
		}
	}
}

int main() {
   int numInputs;
	cin >> numInputs;
	
	vector<int> myVec(numInputs);
	
	for (int i = 0; i < numInputs; ++i) {
		cin >> myVec[i];
	}
	
	sortVector(myVec);

	for (int i = 0; i < numInputs; ++i) {
		cout << myVec[i] << ",";
	}
	cout << endl;
	
   return 0;
}
