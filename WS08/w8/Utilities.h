/*************************
*Name: Chirag Alwani
*Date: March 29
*Mail: cnalwani@myseneca.ca
*id#: 153444179
*************************/
#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H


#include "List.h"
#include "Element.h"

namespace sict 
{

	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif