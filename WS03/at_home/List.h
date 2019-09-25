/********************
*Name : CHIRAG ALWANI
*MAIL : CNALWANI@MYSENECA.CA
*ID : 153444179
*DATE : 5 FEB 2019
**********************/

#ifndef SICT_LIST_H_
#define SICT_LIST_H_

#include <iostream>

namespace sict
{

	template<typename T, int N>
	class List
	{
		T ar[N];
		size_t No_ele = 0;

	public:

		size_t size() const
		{
			return No_ele;
		}
		const T& operator[](size_t i) const
		{
			return i < N ? ar[i] : ar[N - 1];
		}
		void operator+=(const T& t)
		{
			if (No_ele < N - 1)
			{
				ar[No_ele] = t;

				No_ele++;
			}
		}
	};
	template<typename T, typename L, typename V, int N>
	class LVList  : public List<T, N>
	{

	public:
		V accumulate(const L& label) const
		{
			
			SummableLVPair<L, V> summable;

			V sum_elements = summable.getInitialValue();

			for (size_t i = 0; i < ((List<T, N>&)*this).size(); i++)
			{
				if (label == ((List<T, N>&)*this)[i].getLabel())
				{

					sum_elements = ((List<T, N>&)*this)[i].sum(label, sum_elements);

				}
			}
			return sum_elements;
		}
	};
}
#endif // !SICT_LIST_H_

