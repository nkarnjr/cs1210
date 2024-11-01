/*********************************************************
* Summary:	Determine how many days are in February for a given year for Zylabs Lab 7.25
*
* Author:	Nathan Karn Jr.
* Created:	November 1, 2024
*
********************************************************/

#include <iostream>

using namespace std;

int daysInFeb(int userYear) {
	int days = 28;
	if (userYear % 100 == 0 && userYear % 400 == 0) {
		days = 29;
	}
	else if (userYear % 100 != 0 && userYear % 4 == 0) {
		days = 29;
	}
	return days;
}

int main() {
   int userYear;
	
	cin >> userYear;
	cout << userYear << " has ";
	cout << daysInFeb(userYear) << " days in February." << endl;

   return 0;
}
