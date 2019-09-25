// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.cpp
// Chris Szalwinski
// 2019/01/08
/*********************
Name : CHIRAG ALWANI
ID   : 153444179
DATE : 21 JAN 2019
MAIL : CNALWANI@MYSENECA.CA
***********************/

#include <iostream>
#include "String.h"
#include "String.h"

namespace sict 
{	
	void process(const char* str) 
	{
		String a = String(str);
		std::cout << a << std::endl;
	}
}
