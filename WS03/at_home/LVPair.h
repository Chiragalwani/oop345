/********************
*Name : CHIRAG ALWANI
*MAIL : CNALWANI@MYSENECA.CA
*ID : 153444179
*DATE : 5 FEB 2019
**********************/
#ifndef SICT_LVPAIR_H_
#define SICT_LVPAIR_H_

#include <iostream>

namespace sict
{
	template<typename L, typename V>
	class LVPair
	{
		L label;
		V value;

	public:
		LVPair() : label{}, value{}
		{}

		LVPair(const L& label_, const V& value_)
		{

			label = label_;
			value = value_;

		}

		L getLabel() const 
		{ 

				return this->label; 

		}

		V getValue() const 
		{ 

				return this->value; 

		}

		virtual void display(std::ostream& os) const
		{
			os << this->label << " : " << this->value << std::endl;

		}
	};
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}
	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		static V initial_value;
		static size_t minwidth;

	public:
		SummableLVPair()
		{}
		SummableLVPair(const L& label, const V& v) : LVPair<L, V> (label, v)
		{
			if (label.size() > minwidth)
			{
				minwidth = label.size();
			}
		}
		static const V& getInitialValue()
		{
			return initial_value;
		}
		V sum(const L& label, const V& sum) const
		{

			V result = LVPair<L, V>::getValue() + sum;
			return result;

		}
		virtual void display(std::ostream& os) const
		{
			os.setf(std::ios::left);
			os.width(minwidth);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}
	};
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const
	{
		return (value + " " + LVPair<std::string, std::string>::getValue());
	}
}
#endif // !SICT_LVPAIR_H

