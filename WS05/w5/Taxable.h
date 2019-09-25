/****************
*Name: Chirag Alwani
*ID#: 153444179
*Date: 21 FEB 2019
*Mail: cnalwani@myseneca.ca
*******************/

#ifndef SICT_TAXABLE_H_
#define SICT_TAXABLE_H_

namespace sict
{

	class Taxable
	{
		float taxRate;

		public:
			Taxable(float tax_rate)
			{
				taxRate = tax_rate;

			}
			float operator()(float price)
			{
				return price + taxRate;
		
			}
	};
}
#endif // !SICT_TAXABLE_H_


