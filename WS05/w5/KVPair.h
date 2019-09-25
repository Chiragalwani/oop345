/****************
*Name: Chirag Alwani
*ID#: 153444179
*Date: 21 FEB 2019
*Mail: cnalwani@myseneca.ca
*******************/
#ifndef SICT_KVPAIR_H_
#define SICT_KVPAIR_H_
#include  <iostream>
#include <iomanip>

using namespace std;

extern int fieldWidth;

namespace sict
{
	template<typename K, typename V>
	class KVPair
	{
		K key;
		V value;

	public:

		KVPair() : key{0}, value{0}
		{
		}
		KVPair(const K& key_, const V& value_)
		{
			key = key_;
			value = value_;
		}
		template<typename F>
		void display(std::ostream& os, F f) const
		{
			
		/*	os << left << setw(fieldWidth) 
				<< key << " : " << std::right << setw(fieldWidth) << value 
				<< setw(fieldWidth) << f(value) << endl;*/
			
			os << std::left << std::setw(fieldWidth)
				<< key << " " << ":" << " " << std::right << std::setw(fieldWidth) << value
				<< std::setw(fieldWidth) << f(value) << std::endl;

		}
	};
}

#endif // !SICT_KVPAIR_H_
