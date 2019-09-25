/*********************
Name : CHIRAG ALWANI
ID   : 153444179
DATE : 21 JAN 2019
MAIL : CNALWANI@MYSENECA.CA
***********************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "String.h"

namespace sict
{
	int INITIAL = 3;

	String::String(const char *string) {

		int length = strlen(string);
		if (string != NULL)
		{
			str = new char[length + 1];
			strcpy(str, string);

		}
		else
		{
			str = nullptr;
		}
	}
	String::~String()
	{

		delete[] str;
	}
	void String::display(std::ostream& os) const {

		os << str;
	}
	std::ostream& operator<<(std::ostream& os, String& str) {

		os << INITIAL << ": ";
		str.display(os);
		INITIAL++;
		return os;
	}

}