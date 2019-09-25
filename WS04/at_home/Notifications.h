/*********************
* Name: CHIRAG ALWANI
* iD : 153444179
* DATE : FEb 14
* EMAIL : CNALWANI@MYSENECA.CA
**********************/

#ifndef SICT_NOTIFICATIONS_H_
#define SICT_NOTIFICATIONS_H_

#include <iostream>
#include "Message.h"

namespace sict
{
	class Notifications
	{
		const Message** OBJ;
		int maxofaddress;
		int numofaddress;
	public:
		Notifications();					// Defual Consrt
		Notifications(int Max_ele);			// argu-Constr


		Notifications(const Notifications&);  // Copy Constr
		
		Notifications& operator=(const Notifications&); // Copy Assignment
		Notifications(Notifications&&);			// Move Constr
		Notifications& operator<<(Notifications&&); // Move Assignment
		~Notifications();					// Destructor
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;

	};
	std::ostream& operator<<(std::ostream& os, const Notifications& obj);
}


#endif

