/*********************
Name : CHIRAG ALWANI
ID   : 153444179
DATE : 21 JAN 2019
MAIL : CNALWANI@MYSENECA.CA
***********************/
#ifndef SICT_STRING_H
#define SICT_STRING_H

namespace sict
{
	
	class String
	{
		char *str;
	public:

		String(const char*);
		~String();
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, String&);
}
#endif // !W1_STRING_H
