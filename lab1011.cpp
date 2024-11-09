/*********************************************************
* Summary: 
*
* Author:	Nathan Karn Jr.
* Created:	November 8, 2024
*
********************************************************/

#include <iostream>
#include <vector>

using namespace std;

void printChange(int amt, const vector<int>& d, int currDenom) {
	
	if (currDenom > d.size() - 1) {
		return;
	}
	else if (amt >= d.at(currDenom)) {
		cout << amt / d.at(currDenom) << " @ " << d.at(currDenom) << endl;
		amt %= d.at(currDenom);
		currDenom++;
		printChange(amt, d, currDenom);
	}
	else {
		cout << 0 << " @ " << d.at(currDenom) << endl;
		currDenom++;
		printChange(amt, d, currDenom);
	}
}

int main() {
   vector<int> denominations = {100, 50, 25, 10, 5, 1};
   int amt = 0;

   // cout << "What amount (in cents) would you like to make change for? ";
   cin  >> amt;

   printChange(amt, denominations, 0);

   return 0;
}
