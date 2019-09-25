/******************
*NAME: CHIRAG ALWANI
*ID#: 153444179
*EMAIL: CNALWANI@MYSENECA.CA
*DATE: 25 jan 2019
********************/
#include <iostream>
#include <iomanip>
#include <chrono>
#include "Timekeeper.h"

namespace sict
{

	int TimeKeeper::counter = 0;

	TimeKeeper::TimeKeeper() : mt_start{ }, end{ }
	{


	}
	void TimeKeeper::start()
	{
		mt_start = std::chrono::steady_clock::now();

	}
	void TimeKeeper::stop()
	{
		end = std::chrono::steady_clock::now();

	}
	void TimeKeeper::recordEvent(const char* description)
	{
		if (counter < MAX)
		{
			record[counter].message = description;
			record[counter].duration = end - mt_start;
			counter++;

		}

	}
	std::ostream& TimeKeeper::report(std::ostream& os)
	{
		os << "\nExecution Time:" << std::endl;

		for (int i = 0; i < counter; i++)
		{
			os << record[i].message << std::setw(6) << std::chrono::duration_cast<std::chrono::milliseconds>(record[i].duration).count() << " " << record[i].unit << std::endl;
			return os;

		}
	}
	TimeKeeper::~TimeKeeper()
	{

	}


}