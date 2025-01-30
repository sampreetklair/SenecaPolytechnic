

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include<iostream>


namespace sdds
 {
	class Menu
	 {
		char* m_options;
	public:
		Menu(const char* options);
		unsigned int run() const;
		~Menu();
	
	
	};
}

#endif 


#pragma once
