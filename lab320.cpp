/*
	Summary: Convert the abbreviations in a statement
            to their corresponding phrases for Zylabs
            Lab 3.20
	Author:  Nathan Karn
	Created: September 7, 2024
*/
#include <iostream>
using namespace std;

int main () {

	string origText, expandedText;
   int    choice;

   cout << "Enter text:" << endl;
   getline(cin, origText);
   cout << "You entered: " << origText << endl;

   expandedText = origText;
   
   cout << "Which abbreviation do you want to replace (enter a number)\n";
   cout << "  1. BFF\n  2. IDK\n  3. JK\n  4. TMI\n  5. TTYL\n  6. Quit Program\n  > ";
   cin  >> choice;
   while (choice >= 1 && choice <= 5) {
      string abbr = "";
      string phrase = "";
      int    len = 0;
      bool   abbrPresent = false;
      
      switch (choice) {

         case 1:
				abbr = "BFF";
				phrase = "best friend forever";
				len = 3;
				abbrPresent = true;
				break;
			
			case 2:
				abbr = "IDK";
				phrase = "I don't know";
				len = 3;
				abbrPresent = true;
				break;

			case 3:
				abbr = "JK";
				phrase = "just kidding";
				len = 2;
				abbrPresent = true;
				break;

			case 4:
				abbr = "TMI";
				phrase = "too much information";
				len = 3;
				abbrPresent = true;
				break;

			case 5:
				abbr = "TTYL";
				len = 4;
				phrase = "talk to you later";
				abbrPresent = true;
				break;
			
			default:
				break;
      }
      
      if (abbrPresent) {
         expandedText.replace(expandedText.find(abbr), len, phrase);
      }
      
      cout << "  > ";
      cin  >> choice;
   }

   cout << endl << "Expanded: " << expandedText << endl;

   return 0;
}
