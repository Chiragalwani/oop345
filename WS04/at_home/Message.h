/*********************
* Name: CHIRAG ALWANI
* iD : 153444179
* DATE : FEb 14
* EMAIL : CNALWANI@MYSENECA.CA
**********************/

#ifndef SICT_MESSAGE_H_
#define SICT_MESSAGE_H_

#include <iostream>
#include <string>

namespace sict
{

	class Message
	{
		std::string user_;
		std::string reply_;
		std::string tweet_;


	public:

		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;

	};
}
#endif // !SICT_NAMESPACE_H
