#include "UIHelper.h"
#include <limits>
void dividingLine(int length, char symbol)
{
	dividingLine(length, symbol, std::cout);
}
void dividingLine(int length, char symbol, std::ostream& out)
{
	out << dividingLineReturn(length, symbol);
}
std::string dividingLineReturn(int length, char symbol)
{
	std::string out = "";
	for (int i = 0; i < length; i++)
	{
		out += symbol;
	}
	out += "\n";
	return out;
}
void header(std::string heading, int length, char symbol)
{
	system("cls");
	dividingLine(length, symbol);
	std::cout << std::setw((length+heading.size()) / 2) << heading << std::endl;
	dividingLine(length, symbol);
}
void headerNoCls(std::string heading, int length, char symbol)
{
	dividingLine(length, symbol);
	std::cout << std::setw((length+heading.size()) / 2) << heading << std::endl;
	dividingLine(length, symbol);
}void header(std::string heading, int length, char symbol, std::ostream& out)
{
	dividingLine(length, symbol, out);
	out << std::setw((length+heading.size()) / 2) << heading << std::endl;
	dividingLine(length, symbol, out);
}
void waitTillEnter()
{
	std::cout << "Press Enter to Continue" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
std::string divindingLineReturn2Char(int number_of_char1_between_char2, char char1, int number_of_char2, char char2)
{
	std::string returnVal= "";
	for (int i = 0; i < number_of_char2 - 1; i++)
	{
		returnVal += char2;
		for (int j = 0; j < number_of_char1_between_char2; j++)
		{
			returnVal += char1;
		}
	}
	returnVal += char2;
	returnVal+="\n";
	return returnVal;
}