/*********************
* Name: CHIRAG ALWANI
* iD : 153444179
* DATE : FEb 14
* EMAIL : CNALWANI@MYSENECA.CA
**********************/
#include <iostream>
#include <utility>
#include "Notifications.h"

namespace sict
{
	Notifications::Notifications()
	{

		OBJ = nullptr;
		maxofaddress = 0;
		numofaddress = 0;
	}
	Notifications::Notifications(int Max_ele)
	{
		if (Max_ele > 0)
		{
			OBJ = new const Message*[Max_ele];
			maxofaddress = Max_ele;
			numofaddress = 0;
		}
		else
		{
			Notifications();
		}

	}
	Notifications::Notifications(const Notifications& src)
	{
		*this = src;

	}
	Notifications& Notifications::operator=(const Notifications& src)
	{
		if (this != &src)
		{
			delete[] OBJ;

			this->maxofaddress = src.maxofaddress;

			this->numofaddress = src.numofaddress;

			if (OBJ != nullptr)
			{
				this->OBJ = src.OBJ;
			}

			OBJ = new const Message*[src.maxofaddress];
			for (int i = 0; i < src.numofaddress; i++)
			{
				this->OBJ[i] = src.OBJ[i];
			}

		}
		return *this;

	}
	Notifications::Notifications(Notifications&& other)
	{

		*this = std::move(other);
	}
	Notifications& Notifications::operator<<(Notifications&& other)
	{
		if (this != &other)
		{
			this->OBJ = other.OBJ;
			this->maxofaddress = other.maxofaddress;
			this->numofaddress = other.numofaddress;

			other.OBJ = nullptr;
			other.maxofaddress = 0;
			other.numofaddress = 0;

		}
		return *this;
	}
	Notifications::~Notifications()
	{
		delete[] OBJ;
		OBJ = nullptr;
	}
	Notifications& Notifications::operator+=(const Message& msg)
	{
		if (this->numofaddress < this->maxofaddress)
		{
			this->OBJ[numofaddress + 1] = &msg;
			numofaddress++;
		}
		return *this;
	}
	Notifications& Notifications::operator-=(const Message& msg)
	{
		bool value = false;
		int i = 0;
		for (int i = 0; i < numofaddress; i++)
		{
			if (this->OBJ[i] == &msg)
			{
				value = true;
			}
		}
		if (value)
		{
			for (; i < numofaddress; i++)
			{
				OBJ[i - 1] = OBJ[i];

				if (numofaddress)
				{
					OBJ[numofaddress - 1] = nullptr;
					numofaddress--;
				}
			}
		}		
		return *this;
	}
	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < numofaddress; i++)
		{
			if (this->OBJ[i] != nullptr)
			{
				this->OBJ[i]->display(os);
			}
		}
	}
	size_t Notifications::size() const
	{
		return this->numofaddress;
	}

	std::ostream& operator<<(std::ostream& os, const Notifications& obj)
	{
		obj.display(os);
		return os;
	}
}

