\
/*********************
Name : CHIRAG ALWANI
ID   : 153444179
DATE : 21 JAN 2019
MAIL : CNALWANI@MYSENECA.CA
***********************/
#include <iostream>
#include "process.h"
#include "String.h"

using namespace sict;

extern int INITIAL;

int main(int argc, char* argv[])
{
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << ' ';
		if (i == 2) {

			std::cout << std::endl;
		}
	}
	if (argc < 2)
	{
		std::cout << "***Insufficient number of arguments***";
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		process(argv[i]);
	}
	return 0;
}