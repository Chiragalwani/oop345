/****************
*Name: Chirag Alwani
*ID#: 153444179
*Date: 21 FEB 2019
*Mail: cnalwani@myseneca.ca
*******************/
#ifndef SICT_KVLIST_H_
#define SICT_KVLIST_H_

namespace sict
{
	template<typename T>
	class KVList
	{

		T* objList;
		size_t No_ele;
		size_t Cur_ele;

	public:
		KVList()
		{
			objList = nullptr;
			No_ele = 0;
			Cur_ele = 0;

		}
		KVList(int n)
		{
			if (n > 0)		// if(n > 0)
			{
				objList = new T[n];
			}
			else
			{ 
				KVList();
			}
		}
		KVList(KVList&& other)
		{

			if (this != &other)
			{
				delete[] objList;
				this->No_ele = other.No_ele;
				this->Cur_ele = other.Cur_ele;
				if (objList != nullptr)
				{
					this->objList = other.objList;
				}
				other.Cur_ele = 0;
				other.No_ele = 0;
				other.objList = nullptr;
			}
		}
		~KVList()
		{
			delete[] objList;

			objList = nullptr;
		}
		const T& operator[](size_t i) const
		{
			return objList[i];
		}
		template<typename F>
		void display(std::ostream& os, F f) const
		{
			for (size_t i = 0; i < No_ele; i++)
			{
				objList[i].display(os, f);
			}
		}
		void push_back(const T& t)
		{
			
			if (Cur_ele + 1 <= No_ele)
			{
				objList[Cur_ele] = t;

			}
			Cur_ele++;
		}
		KVList(const KVList&) = delete;
		KVList& operator=(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
	};
}
#endif // !SICT_KVLIST_H_
