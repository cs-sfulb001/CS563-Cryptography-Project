#include <string>
#include "Choices.h"

bool choiceYN(std::string question)
{
	while (true)
	{
		std::cout << question << " Yes/No " << std::endl;
		std::string userChoice = "";
		std::cin >> userChoice;
		if (userChoice.length() == 2 && (userChoice[0] == 'n' || userChoice[0] == 'N')
			&&(userChoice[1]=='o'||userChoice[1]=='O'))
		{
			return false;
		}
		else if (userChoice.length() == 3 && (userChoice[0] == 'y' || userChoice[0] == 'Y')
			&& (userChoice[1] == 'e' || userChoice[1] == 'E') && (userChoice[2] == 's'
				|| userChoice[2] == 'S'))
		{
			return true;
		}
	}
}
std::string choiceWord(std::string question)
{
	std::cin.ignore(INT_MAX);
	while (true)
	{
		std::cout << question << std::endl;
		std::string word = "";
		std::getline(std::cin, word);
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == ' ')
			{
				std::cout << "Input must be one word" << std::endl;
				break;
			}
			if (i == word.length() - 1)
			{
				return word;
			}
		}
	}
}
int choiceList(std::vector<std::string> questions)
{
	while (true)
	{
		for (int i = 0; i < questions.size(); i++)
		{
			std::cout << i << ". " << questions[i] << std::endl;
		}
		std::string input = "";
		std::getline(std::cin, input);
		if (input.size()==1&&checkIfInt(input[0]) && questions.size() < 10)
		{
			std::cin.clear();
			return (input[0]-48);
		}
		else if (input.size()==2&&questions.size() < 100 && checkIfInt(input[0], input[1]))
		{
			std::cin.clear();
			return ((int)input[0]-48)*10+((int)input[1]-48);
		}
		else
		{
			std::cout<<"That is not a vailid input. Input a number less than "<<questions.size()<< std::endl;
		}
	}
	
}
bool checkIfInt(char input)
{
	if ((int)input <= 57&&(int)input>=48)
		return true;
	return false;
}
bool checkIfInt(char input1, char input2)
{
	return checkIfInt(input1) && checkIfInt(input2);
}
int UserIntInRange(int min, int max)
{
	while (true)
	{
		std::cout << "Input a value between " << min << " and " << max << std::endl;
		int input = min - 1;
		std::cin >> input;
		if (input >= min && input <= max)
		{
			return input;
		}
		std::cout << "That is not in the range." << std::endl;
	}
}