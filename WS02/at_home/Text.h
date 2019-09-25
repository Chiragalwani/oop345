/******************
*NAME: CHIRAG ALWANI
*ID#: 153444179
*EMAIL: CNALWANI@MYSENECA.CA
*DATE: 25 jan 2019
********************/

#ifndef SICT_TEXT_H_
#define SICT_TEXT_H_

namespace sict
{

	class Text
	{

	private:

		std::string* strfile;
		std::size_t ptrsize;

	public:

		Text();
		Text(const char* str);

		Text(const Text&);			    // copy constr
		Text& operator=(const Text&);   // copy assignment oper
		~Text();
		std::size_t size() const;



	};
}
#endif // !SICT_TEXT_H_
