/******************
*Name: Chirag Alwani
*ID#: 153444179
*Mail: cnalwani@myseneca.ca
*Date: 15 March 2019
********************/
#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_
#include "iProduct.h"

namespace sict
{
	

	class Product : public iProduct
	{
		int product_No;
		double cost;
		
	public:

		Product();
		Product(int, double);
		double price() const;
		void display(std::ostream& os) const;


	};
	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);

	class TaxableProduct : public Product
	{
		enum {HST, PST} tax;
		static double rate[2];

		public:
				TaxableProduct(unsigned, double, char);
				double price() const;
				void display(std::ostream& os) const;
	};
	
}

#endif // !SICT_PRODUCT_H_

