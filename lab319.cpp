/*
	Summary: Subtract the gray value from 
            RGB codes for Zylabs Lab 3.19
	Author:  Nathan Karn
	Created: September 6, 2024
*/
#include <iostream>
using namespace std;

int main() {

	int valRed;
	int valGreen;
	int valBlue;

	cin >> valRed;
	cin >> valGreen;
	cin >> valBlue;

	if (valRed < valGreen) {

		if (valRed < valBlue) {

			valGreen -= valRed;
			valBlue -= valRed;
			valRed = 0;
			
			cout << valRed << " " << valGreen << " " << valBlue << "\n";
		}

		else {

			valRed -= valBlue;
 			valGreen -= valBlue;
 			valBlue = 0;
 
 			cout << valRed << " " << valGreen << " " << valBlue << "\n";
		}
	}

	else if (valGreen < valBlue) {

		valRed -= valGreen;
 		valBlue -= valGreen;
		valGreen = 0;

		cout << valRed << " " << valGreen << " " << valBlue << "\n";
	}
	
	else {
 
		valRed -= valBlue;
		valGreen -= valBlue;
		valBlue = 0;
 
		cout << valRed << " " << valGreen << " " << valBlue << "\n";
   }

	return 0;
}
