/*********************************************************
* Summary:	Take in a number and a given character pattern from
		input and generate that pattern the given number of
		times using recursive functions for Zylabs Lab 10.10
*
* Author:	Nathan Karn Jr.
* Created:	November 8, 2024
*
********************************************************/

#include <iostream>
#include <string>

using namespace std;

void printPattern(int rows, string str, string chars, int nextChar = 1) {

	if (rows == 0) {
		return;
	}
	else if (nextChar >= chars.size() - 1) {
		nextChar = 1;
	}
	cout << str << endl;
	str.append(chars.substr(0, nextChar));
	nextChar++;
	rows--;
	printPattern(rows, str, chars, nextChar);
}

int main() {
   string pattern = "";
   int    iter = 0;

   // cout << "How many rows in your pattern? ";
   cin  >> iter;

   // cout << "What characters should be used in the pattern? ";
   cin  >> pattern;

   printPattern(iter, pattern.substr(0,1), pattern);

   return 0;
}
