/*************************
*Name: Chirag Alwani
*Date: April 4
*Mail: cnalwani@myseneca.ca
*id#: 153444179
*************************/
#ifndef SICT_SECUREDATA_H
#define SICT_SECUREDATA_H
#include <iostream>

namespace sict
{

	class Cryptor 
	{
	
	public:
		char operator()(char in, char key) const
		{ 
			return in ^ key; 
		}
	
	};
	
	void converter(char*, char, int, const Cryptor&);

	class SecureData 
	{

		private:
			char* text;
			std::ostream* ofs;
			int nbytes;
			bool encoded;
			void code(char);
	
	public:
			SecureData(const char*, char, std::ostream*);

			SecureData(const SecureData&) = delete;

			SecureData& operator=(const SecureData&) = delete;

			void display(std::ostream&) const;

			void backup(const char*);

			void restore(const char*, char);

			~SecureData();


	};

	std::ostream& operator<<(std::ostream&, const SecureData&);
}
#endif