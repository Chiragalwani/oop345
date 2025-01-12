// Workshop 9 - Multi-Threading
// SecureData.cpp
// Chris Szalwinski after Cornel Barna
// 2019/03/19
/*************************
*Name: Chirag Alwani
*Date: April 4
*Mail: cnalwani@myseneca.ca
*id#: 153444179
*************************/
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace sict {

	void converter(char* t, char key, int n, const Cryptor& c) 
	{
		for (int i = 0; i < n; i++)
	
			t[i] = c(t[i], key);
	
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs) 
	{
	
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
		{

			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		}
			
		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const 
	{
	
		if (text && !encoded)
		{
			os << text << std::endl;

		}
		else if (encoded)
		{
			throw std::string("\n***Data is encoded***\n");
		}
		else
		{
			throw std::string("\n***No data stored***\n");
		}
			
	}

	void SecureData::code(char key) 
	{
		converter(text, key, nbytes, Cryptor());
	
		int part = nbytes / 3;

		auto thread1 = std::bind(converter, text + part * 2, key, nbytes - (part * 2), Cryptor());
		
		std::thread t1(thread1);

		auto thread2 = std::bind(converter, text + part, key, part, Cryptor());
		
		std::thread t2(thread2);

		converter(text, key, part, Cryptor());

		t1.join();
		
		t2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) 
	{
		if (!text)
	
			throw std::string("\n***No data stored***\n");
		
		else if (!encoded)
		
			throw std::string("\n***Data is not encoded***\n");
		
		else
		{
			// TODO: open a binary file for writing
			std::ofstream fout(file, std::ios::binary);

			if (!fout.good())
			{
				throw std::string("\n***Could not open file***\n");
			}

			// TODO: write data into the binary file
			//         and close the file
			fout.write(text, nbytes);

			fout.close();
		}
	}

	void SecureData::restore(const char* file, char key)
	{
	
		// TODO: open binary file for reading
		std::ifstream f(file, std::ios::binary);

		if (!f.good())
		{
			throw std::string("\n***Could not open file***\n");
		}

		f.seekg(0, f.end);
		
		nbytes = (int)f.tellg();
		
		f.seekg(0, f.beg);

		// TODO: - allocate memory here for the file content
		text = new char[nbytes];


		// TODO: - read the content of the binary file
		f.read(text, nbytes);

		f.close();


		*ofs << "\n" << nbytes << " bytes copied from binary file " << file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) 
	{
	
		sd.display(os);
		return os;
	
	}
}
