#include <iostream>
#include <iomanip>
#include <vector>
/*
Input the question for the user to answer.
returns:
true for yes
false for no
asks again if any form of yes or no was not inputed
*/
bool choiceYN(std::string);
/*
Asks user for a word. If user inputs more then one
word,asks the user for another word.
returns inputed word
*/
std::string choiceWord(std::string);
/*
Takes in a list of questions
Assigns questions 0-# of questions
returns input of an int
filters non-int inputs
*/
int choiceList(std::vector<std::string>);
/*
Checks if inputed char is a number 0-9
return true if it is
*/
bool checkIfInt(char);
/*
returns checkInInt(char) for both inputs
*/
bool checkIfInt(char, char);
int UserIntInRange(int, int);