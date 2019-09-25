/******************
*NAME: CHIRAG ALWANI
*ID#: 153444179
*EMAIL: CNALWANI@MYSENECA.CA
*DATE: 25 jan 2019
********************/
#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;

namespace sict
{

	Text::Text()
	{
		strfile = nullptr;
		ptrsize = 0;
	}
	Text::Text(const char* str)
	{

		std::string size;		 // string for finding size 
		ifstream file;  // creating object for reading

		file.open(str);

		int count = 0;

		if (!file.is_open())
		{
			Text();
		}
		else
		{
			while (getline(file, size));
			{
				ptrsize++;
			}
			strfile = new string[ptrsize];

			file.clear();
			file.seekg(0, ios::beg);

			for (std::size_t i = 0; i < ptrsize; i++)
			{
				getline(file, strfile[i]);
			}
		}
		file.close();
	}
	Text::Text(const Text& src)					// copy constructor 
	{
		this->strfile = nullptr;
		*this = src;
	}

	Text& Text::operator=(const Text& src)		// copy assignment 
	{
		if (this != &src)
		{
			delete[] strfile;
			this->ptrsize = src.ptrsize;

			if (src.strfile != nullptr)
			{
				strfile = new string[ptrsize];

				for (std::size_t i = 0; i < ptrsize; i++)
				{
					this->strfile[i] = src.strfile[i];
				}
			}
			return *this;
		}
	}
	Text::~Text()
	{
		delete[] strfile;
	}
	std::size_t Text::size() const
	{
		return ptrsize;
	}

}