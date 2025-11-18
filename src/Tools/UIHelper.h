#pragma once
#include <iostream>
#include <iomanip>
#include <string>
void dividingLine(int, char);
std::string dividingLineReturn(int, char);
void dividingLine(int, char, std::ostream&);
void header(std::string, int, char);
void header(std::string, int, char, std::ostream&);
void headerNoCls(std::string, int, char);
void waitTillEnter();
std::string divindingLineReturn2Char(int, char, int, char);