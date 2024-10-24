/*********************************************************
* Summary: Find the given reference in the Old Testament for Zylabs Lab 6.6
*
* Author: Nathan Karn Jr. 
* Created: October 21, 2024
*
********************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
   
   string book;
	string chapter;
	string verse;
	string referenceCheck;
	string referenceOut;
	string psalmsCheck = "CHAPTER ";
	int verseLength;
	bool bookExists = false;
	bool chaptExists = false;
	bool verseExists = false;
	bool escape = false;

	cout << "Please enter the reference of the verse you would like" << endl;
	cout << "The Book: ";
	getline(cin, book);
	cout << "The Chapter: ";
	cin >> chapter;
	cout << "The Verse: ";
	cin >> verse;
	cout << endl;
	verseLength = verse.size();
	
	for (int i = 0; i < (book.size()); ++i) {
		book.at(i) = toupper(book.at(i));
	}

	if (book == "PSALM") {
		book.append("S");
	}

	ifstream inFS;
	inFS.open("OT.txt");
	getline(inFS, referenceCheck);
	
	while (!inFS.fail() && !escape) {
	
		if (referenceCheck == ("THE BOOK OF " + book)) {
			bookExists = true;
			escape = true;
		}
		getline(inFS, referenceCheck);
	}
	

	if (bookExists == false) {
		cout << book << " does not exist in the Old Testament" << endl;
		inFS.close();
		escape = true;
	}
	if (book == "PSALMS") {
		psalmsCheck = "PSALM ";
	}

	if (escape && bookExists) {
		escape = false;
		
		while (!inFS.fail() && !escape && !inFS.eof()) {
		
			if (referenceCheck == (psalmsCheck + chapter)) {
				chaptExists = true;
				escape = true;
			}
			else if (referenceCheck.size() < 12) {
			}
			else if (referenceCheck.substr(0, 12) == ("THE BOOK OF ")) {
				escape = true;
			}
			getline(inFS, referenceCheck);
		}
	
		if (chaptExists == false) {
			cout << psalmsCheck << chapter << " does not exist in " << book << endl;
			inFS.close();
		}
	}
	
	if (escape && chaptExists) {
		escape = false;

		while (!inFS.fail() && !escape && !inFS.eof()) {
		
			if (referenceCheck.size() == 0) {
				escape = true;
			}
			else if (referenceCheck.size() < verseLength) {
				getline(inFS, referenceCheck);
			}
			else if (referenceCheck.substr(0, verseLength) == verse) {
				verseExists = true;
				escape = true;
			}
			else if (referenceCheck.size() < 8) {
				getline(inFS, referenceCheck);
			}
			else if (referenceCheck.substr(0, 8) == (psalmsCheck)) {
				escape = true;
			}
			else {
				getline(inFS, referenceCheck);
			}
		}

		if (verseExists == false) {
			cout << "Verse " << verse << " does not exist in " << book << " " << chapter << endl;
			inFS.close();
		}
	}

	if (escape && verseExists) {
		referenceOut = referenceCheck;
	
		while(!inFS.eof() && !(isdigit(referenceCheck.at(0)))) {
			getline(inFS, referenceCheck);
			referenceOut.append(referenceCheck);
		}
		
		cout << book << " " << chapter << endl << referenceOut << endl;
		inFS.close();

		ofstream outFS;
		outFS.open("verses.txt", ios::app);
		outFS << book << " " << chapter << endl << referenceOut << endl;
		outFS.close();
	}

   return 0;
}
