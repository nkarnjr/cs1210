/*********************************************************
* Summary:	Remove any non-alphabetic character from a given input string for Zylabs Lab 7.26
*
* Author:	Nathan Karn Jr.
* Created:	November 1, 2024
*
********************************************************/

#include <iostream>
#include <string>

using namespace std;

string removeNonAlpha(string userString) {
	for (int i = userString.size() - 1; i >= 0; --i) {
		if (!isalpha(userString.at(i))) {
			userString.replace(i, 1, "");
		}
	}
	return userString;
}

int main() {
   string userString;
   
	getline (cin, userString);

	cout << removeNonAlpha(userString) << endl;

   return 0;
}
