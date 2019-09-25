/*********************
* Name: CHIRAG ALWANI
* iD : 153444179
* DATE : FEb 14
* EMAIL : CNALWANI@MYSENECA.CA
**********************/
#include <iostream>
#include "Message.h"
#include "MessagePack.h"

namespace sict
{

	MessagePack::MessagePack()
	{

		msgObj = nullptr;
		NoObj = 0;

	}
	MessagePack::MessagePack(Message** msgArray, int No_elm)
	{
		if (No_elm > 0 && msgArray != nullptr)
		{

			msgObj = new Message[No_elm];

			for (int i = 0; i < No_elm; i++)
			{
				if (!msgArray[i]->empty())
				{
					msgObj[i] = *msgArray[i];
				
				}
				else
				{
					msgObj[i] = Message();
				}
				NoObj++;
			}
		}
	}

	MessagePack::MessagePack(const MessagePack& src)
	{
		*this = src;
	}

	MessagePack& MessagePack::operator=(const MessagePack& src)
	{
		delete[] msgObj;
		msgObj = nullptr;

		if (this != &src)
		{
			this->NoObj = src.NoObj;

			msgObj = new Message[src.NoObj];

			for (int i = 0; i < NoObj; i++)
			{
				msgObj[i] = src.msgObj[i];

			}
		}
		return *this;
	}

	MessagePack::MessagePack(MessagePack&& other)
	{
		*this = std::move(other);
	}

	MessagePack& MessagePack::operator=(MessagePack&& other)
	{

		if (this != &other)
		{
			delete[] msgObj;

			this->msgObj = other.msgObj;
			other.msgObj = nullptr;

			this->NoObj = other.NoObj;
			other.NoObj = 0;
		}
		return *this;
	}
	void MessagePack::display(std::ostream& os) const
	{
			for (int i = 0; i < NoObj; i++)
			{
				if (!msgObj[i].empty())
				{
					this->msgObj[i].display(os);

				}
			}
	}

	size_t MessagePack::size() const
	{
		return this->NoObj;
	}

	MessagePack::~MessagePack()
	{

		delete[] msgObj;
		msgObj = nullptr;
	}
	std::ostream& operator<<(std::ostream& os, const MessagePack& obj)
	{
		obj.display(os);
		return os;
	}

}

