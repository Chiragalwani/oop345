/******************
*Name: Chirag Alwani
*ID#: 153444179
*Mail: cnalwani@myseneca.ca
*Date: 15 March 2019
********************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"
#include "iProduct.h"
#include "Product.h"

extern int FW;

namespace sict
{

	Sale::Sale(const char* file)
	{

		if (file != nullptr)
		{
			std::string data;
			size_t count = 0;

			std::ifstream f;
		
			f.open(file);

			if (f.is_open())
			{
				while (std::getline(f, data))
				{
					count++;
				}
				f.clear();
				f.seekg(0, std::ios::beg);

				for (size_t i = 0; i < count; i ++ )
				{
					products.push_back(readRecord(f));
				}
				f.close();
			}
			else
			{
				throw "cannot be open file";
			}
		}
	}
	void Sale::display(std::ostream& os) const
	{
	
		double total = { 0.0 };
		os << std::fixed << std::setprecision(2);
		os << "\nProduct No" << std::setw(FW) << "Cost" << std::endl;

		for (auto i : products)
		{
			total += i->price();
			os << *i << std::endl;
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;

	}

}



