/******************
*Name: Chirag Alwani
*ID#: 153444179
*Mail: cnalwani@myseneca.ca
*Date: 15 March 2019
********************/
#ifndef SICT_SALE_H_
#define SICT_SALE_H_
#include <iostream>
#include <vector>
#include "iProduct.h"

namespace sict
{
	class Sale
	{
		std::vector<iProduct*> products;

	public:

	
		Sale(const char*);
		void display(std::ostream& os) const;
	};
}

#endif // !SICT_SALE_H
