/*********************
* Name: CHIRAG ALWANI
* iD : 153444179
* DATE : FEb 14
* EMAIL : CNALWANI@MYSENECA.CA
**********************/

#include <iostream>
#include <string>
#include "Message.h"

using namespace std;

namespace sict
{
	Message::Message()
	{
		user_ = '\0';
		tweet_ = '\0';
		reply_ = '\0';
	}
	Message::Message(const std::string& str)
	{
		size_t past_end = std::string::npos;
		size_t reply_begin = str.find('@');
		size_t tweet_begin;
		if (reply_begin != past_end)
		{
			tweet_begin = str.find(' ', reply_begin);
		}
		else
		{
			tweet_begin = str.find(' ');
		}
		if (tweet_begin != past_end)
		{
			if (reply_begin != past_end)
			{
				user_ = str.substr(0, reply_begin - 1);

				reply_ = str.substr(reply_begin + 1, tweet_begin - reply_begin);
			}
			else
			{
				user_ = str.substr(0, tweet_begin);
			}
			tweet_ = str.substr(tweet_begin + 1);

		}
	}
	bool Message::empty() const
	{
		if (user_.size() < 1 && reply_.size() < 1 && tweet_.size() < 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Message::display(std::ostream& os) const
	{
		if (!empty()) {

			os << ">User :" << user_ << std::endl;

			if (reply_.size() > 0)
			{
				os << "Reply :" << reply_ << std::endl;
			}
			os << "Tweet :" << tweet_ << std::endl;
		}


	}
}
