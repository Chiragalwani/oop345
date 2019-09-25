/******************
*Name: Chirag Alwani
*ID#: 153444179
*Mail: cnalwani@myseneca.ca
*Date: 15 March 2019
********************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Product.h"

extern int FW;

namespace sict
{
	Product::Product()
	{

		product_No = 0;
		cost = 0.0;

	}
	Product::Product(int pronum_, double cost_)
	{

		product_No = pronum_;
		cost = cost_;

	}
	double Product::price() const
	{
		
		return cost;

	}
	void Product::display(std::ostream& os) const {

		os << std::setw(FW) << product_No << std::setw(FW) << cost;
	}


	double TaxableProduct::rate[2] { 0.13,0.08 };


	TaxableProduct::TaxableProduct(unsigned no, double price, char c) : Product(no, price)
	{

		switch (c)
		{
		
			case 'H': tax = HST;
			break;
			case 'P': tax = PST;
			break;
			default: throw "tax status undefined";

		}
	}

	double TaxableProduct::price() const
	{
		return Product::price() * (1.0 + rate[tax]);
	}
		
	void TaxableProduct::display(std::ostream& os) const
	{

		Product::display(os);
		
		os << (tax == HST ? " HST" : tax == PST ? " PST" : "");

	}


	iProduct* readRecord(std::ifstream& file)
	{

		iProduct* product = nullptr;
		size_t productnum;
		double productcost;
		char tax;

		file >> productnum >> productcost;

		if (file.get() != '\n')

			file >> tax;
		
		else
		
			tax = ' ';

		if (file.good())
		{
			if (tax != ' ')
			{
				product = new TaxableProduct(productnum, productcost, tax);

			}
			else
			{
				product = new Product(productnum, productcost);

			}
		}
		return product;
	}
	std::ostream& operator<<(std::ostream& os, const iProduct& p)
	{

		p.display(os);
		return os;

	}


}





