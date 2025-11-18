#include "StringManip.h"
#include <math.h>
/*
Splits input string into a vector of strings. Spaces are removed and used as a break point. Special chars are broke off on both sides. 
This+That = [This], [+], [That]
This and That = [This], [and], [That]
*/
std::vector<std::string> SplitString(std::string input)
{
	std::string word = "";
	std::vector <std::string> BrokenString;
	for (int i = 0; i < input.size(); i++)
	{
		if (word.size()==1&&((word[0] >= 21 && word[0] <= 47) || (word[0] >= 58 && word[0] <= 64) 
			|| (word[0] >= 91 && word[0] <= 96) || (word[0] >= 123 && word[0] <= 126))&&word[0]!=39)
		{
			BrokenString.push_back(word);
			word = "";
		}
		if (input[i] == ' '&&word!="")
		{
			BrokenString.push_back(word);
			word = "";
		}
		else if (((input[i] >= 21 && input[i] <= 47) || (input[i] >= 58 && input[i] <= 64)
			|| (input[i] >= 91 && input[i] <= 96) || (input[i] >= 123 && input[i] <= 126))&&input[i]!=39)
		{
			if (word != "")
				BrokenString.push_back(word);
			word = input[i];
			BrokenString.push_back(word);
			word = "";
		}
		else
		{
			word += input[i];
		}
		if (i + 1 == input.size()&&word!="")
			BrokenString.push_back(word);
	}
	return BrokenString;
}
/*
Spaces are the only indication of break points
This+That = [This+That]
*/
std::vector<std::string> SplitStringBySpaceOnly(std::string input)
{
	std::string word = "";
	std::vector <std::string> BrokenString;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ' '&&word!="")
		{
			BrokenString.push_back(word);
			word = "";
		}
		else
		{
			word += input[i];
		}
		if (i + 1 == input.size()&&word!="")
			BrokenString.push_back(word);
	}
	return BrokenString;
}
std::string RemovePunctuation(std::string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '.' || input[i] == ',' || input[i] == '?' || input[i] == '!' || input[i] == '"' || input[i] == ':'
			|| input[i] == ';' || input[i] == '~')
		{
			input.erase(i);
		}
	}
	return input;
}

int StringtoInt(std::string number)
{
	int numberInt = 0;
	bool neg = 0;
	if (number[0] == '-')
	{
		neg = 1;
		number.erase(number.begin());
	}
	for (int i = 0; i < number.size(); i++)
	{
		if(number[i]<58&&number[i]>47)
		numberInt += ((int)number[i] - 48) * pow(10,number.size()-1-i);
	}
	if (neg)
		numberInt *= -1;
	return numberInt;
}
double StringtoDouble(std::string number)
{
	
	int decimalSpot = -5;
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] == '.')
		{
			decimalSpot = i;
			number.erase(number.begin() + i);
			break;
		}
	}
	if (number.size() - decimalSpot == 0||decimalSpot==-5)
		return StringtoInt(number);
	return StringtoInt(number)/(pow(10., (number.size()-decimalSpot)));
}
bool hasDecimal(std::string number)
{
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] == '.')
			return true;
	}
	return false;
}
void removeParethese(std::vector<std::string>& words, std::vector<int>& keywords)//Order of Operation File instead
{
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == "(" || words[i] == ")")
		{
			words.erase(words.begin() + i);
			for (int j = 0; j < keywords.size(); j++)
			{
				if (keywords[j] > i)
				{
					//std::cout << "Moving keywords" << std::endl;
					keywords[j] = keywords[j] - 1;
					//std::cout << keywords[j] << std::endl;
				}
			}
		}
	}
}/*
 Function formats any word to have the first letter be a capital letter and the rest lower case.
 */
void stringFormatCapitalized(std::string& word)
{
	if (word[0] >= 97 && word[0] <= 122)
	{
		word[0] -= 32;
	}
	for (int i = 1; i < word.size(); i++)
	{
		if (word[i] >= 65 && word[i] <= 90)
		{
			word[i] += 32;
		}
	}
}

std::string fileNameFromPath(std::string path){
	std::string fileName="";
	for(int i = path.size() - 1; i>=0;i--){
		if(path[i]=='/'||path[i]=='\\'){
			return fileName;
		}
		fileName=path[i]+fileName;
	}
	return fileName;
}