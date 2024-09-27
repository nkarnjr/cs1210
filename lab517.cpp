/*
	Summary: Create a working game of Simon Says that employs strings for Zylabs Lab 5.17
	Author: Nathan Karn
	Created: September 25, 2024
*/
#include <iostream>                     // for I/O
#include <cstring>                      // for strlen()
#include <cstdlib>                      // for random numbers
#include <unistd.h>                     // for sleep()
#include "ZyLab.h"                      // for ZyLab Setup
using namespace std;

int main(int argc, char **argv) {

	const int DEFAULT_NUMBER_OF_ROUNDS = 15;
	int       numRounds = DEFAULT_NUMBER_OF_ROUNDS;

	// if a command line argument is given, use that string to init the
	// "random" sequence and set the number of rounds to play the game
	if (argc == 2) {
		numRounds = strlen(argv[1]);
	}

	string    s;                         // A string used to pause the game
	char      c;                         // The player's typed characters
	char     *seq = new char[numRounds]; // Sequence of numRounds colors to match
	char      colors[] = "RGBY";         // Allowable colors
	bool      lost = false;              // Indicates whether we win or lose
	int       round;                     // Indicates the current round

	// Initialize random number generator
	srand(time(0));

	// Determine the random color sequence using either argv[1] or
	// randomly determined letters from 'R', 'G', 'B', and 'Y'
	for (int j = 0; j < numRounds; j++) {
		seq[j] = (argc == 2) ? argv[1][j] : colors[rand() % 4];
	}

	// Wait until the player is ready
	cout << "Welcome to Simon, press enter to play .... ";
	getline(cin, s, '\n');

	system("clear");
	round = 1;
	string currSequence;
        
	for (int i = 0; i < numRounds; ++i) {
		
		currSequence = "";
                
		for (int j = 0; j < round; ++j) {
                        
			currSequence = currSequence + seq[j];
			cout << seq[j] << flush;
			sleep(1);
			cout << "\010." << flush;
		}

		cout << "\nPlease enter " << round << " characters to match: ";

		for (int k = 0; k < round; ++k) {
			
			cin >> c;
			
			if (c != seq[k]) {
				lost = true;
			}
			if (lost == true) {
				cout << "Awww, You Lost the Game...\n";
				cout << "The correct sequence was: " << currSequence << endl;
				return 1;
			}
		}
                
		system("clear");
		++round;
	}
        
	cout << "Congratulations! You Won the Game!\n";

	return 0;
}
