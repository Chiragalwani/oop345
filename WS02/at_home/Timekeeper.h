/******************
*NAME: CHIRAG ALWANI
*ID#: 153444179
*EMAIL: CNALWANI@MYSENECA.CA
*DATE: 25 jan 2019
********************/
#ifndef SICT_TIMEKEEPER_H_
#define SICT_TIMEKEEPER_H_

#include <iostream>
#include <chrono>

namespace sict
{
	const int MAX = 10;

	class TimeKeeper
	{

		//char record[MAX];

		static int counter;

		std::chrono::steady_clock::time_point mt_start;
		std::chrono::steady_clock::time_point end;


		struct
		{
			const char* message;
			const char* unit;
			std::chrono::steady_clock::duration duration;

		}record[MAX];

	public:

		TimeKeeper();
		void start();
		void stop();
		void recordEvent(const char *description);
		std::ostream& report(std::ostream& os);
		~TimeKeeper();

	};
}

#endif // !SICT_TIMEKEEPER_H_
