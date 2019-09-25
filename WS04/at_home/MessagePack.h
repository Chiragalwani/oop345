/*********************
* Name: CHIRAG ALWANI
* iD : 153444179
* DATE : FEb 14
* EMAIL : CNALWANI@MYSENECA.CA
**********************/

#ifndef SICT_MESSAGEPACK_H_
#define SICT_MESSAGEPACK_H_

#include <iostream>
//#include "Message.h"


namespace sict
{	

	class MessagePack
	{
		Message* msgObj;
		size_t NoObj;

	public:
		MessagePack();

		MessagePack(Message**, int);

		MessagePack(const MessagePack&);

		MessagePack& operator=(const MessagePack&);

		MessagePack(MessagePack&&);

		MessagePack& operator=(MessagePack&&);

		void display(std::ostream& os) const;

		~MessagePack();

		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, const MessagePack&);

}


#endif 