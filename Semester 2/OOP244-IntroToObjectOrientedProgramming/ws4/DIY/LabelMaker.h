
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"

namespace sdds
{
	class LabelMaker
	{
		int noOfLabels;
		Label* labels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}

#endif
