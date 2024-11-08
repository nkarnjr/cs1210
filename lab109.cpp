/*********************************************************
* Summary:	Take in two number inputs and create a number
*		pattern using a recursive function for Zylabs Lab 10.9
*
* Author:	Nathan Karn Jr.
* Created:	November 7, 2024
*
********************************************************/

#include <iostream>

using namespace std;

void printNumPattern(int startNum, int incrementNum);

int main() {
   int num1;
   int num2;

   cin >> num1;
   cin >> num2;
   printNumPattern(num1, num2);
   
   return 0;
}

void printNumPattern(int startNum, int incrementNum) {
	if (startNum >= 0) {
		cout << startNum << " ";
		printNumPattern(startNum - incrementNum, incrementNum);
	}
	else if (startNum < 0) {
		cout << startNum << " ";
		return;
	}
	
	cout << startNum << " ";
}
