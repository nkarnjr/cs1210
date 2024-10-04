/*********************************************************
* Summary:	Determine whether a given set of inputs is a 
*				magic square for Zylabs Lab 5.18
* Author:	Nathan Karn	
* Created:	10/4/2024
*
********************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {

	int squareOrder;
	int columnSum = 0;
	int rowSum = 0;
	int diagonalSum1 = 0;
	int diagonalSum2 = 0;
	string magicSquare = "";
	bool numbersPresent = true;
	bool rowCheck = true;
	bool columnCheck = true;
	bool diagonalCheck = true;

	cout << "What is the order of the square to be tested: ";
	cin >> squareOrder;
	int squareArray [squareOrder] [squareOrder];
	int magicSum = (pow(squareOrder,3) + squareOrder) / 2;
	int checkSum = magicSum * squareOrder;

	cout << "\nPlease enter the " << squareOrder * squareOrder << " values for the magic square in row major order: ";
	for (int i = 0; i < squareOrder; ++i) {
		rowSum = 0;
		for (int j = 0; j < squareOrder; ++j) {
			cin >> squareArray [i] [j];
			checkSum -= squareArray [i] [j];
			
			rowSum += squareArray [i] [j];
		}
		if (rowSum != magicSum) {
			rowCheck = false;
		}
	}
	if (checkSum != 0) {
		numbersPresent = false;
	}

	for (int i = 0; i < squareOrder; ++i) {
		columnSum = 0;
		for (int j = 0; j < squareOrder; ++j) {
			columnSum += squareArray [j] [i];
		}
		if (columnSum != magicSum) {
			columnCheck = false;
		}

		diagonalSum1 += squareArray [i] [i];
		{	int k = squareOrder - 1;
			diagonalSum2 += squareArray [i] [k];
			--k;
		}
	}
	
	if (diagonalSum1 != magicSum || diagonalSum2 != magicSum) {
		diagonalCheck = false;
	}

	if (numbersPresent == false || rowCheck == false || columnCheck == false || diagonalCheck == false) {
		magicSquare = "not ";
	}

	cout << "\nThe square: \n";
	for (int i = 0; i < squareOrder; ++i) {
		for (int j = 0; j < squareOrder; ++j) {
			cout << "     ";
			if (squareArray [i] [j] > 9) {
			cout << "\010";
			}
			cout << squareArray [i] [j];
		}
		cout << endl;
	}

	cout << "\nThe given matrix is " << magicSquare << "a magic square.\n";
	if (numbersPresent == false) {
		cout << "Not all expected numbers are present.\n";
	}
	else if (rowCheck == false) {
		cout << "Row sums differ.\n";
	}
	else if (columnCheck == false) {
		cout << "Column sums differ.\n";
	}
	else if (diagonalCheck == false) {
		cout << "Diagonal sums differ.\n";
	}
	
	return 0;
}
