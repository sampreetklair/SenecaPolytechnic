// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "LabelMaker.h"
using namespace std;
namespace sdds
{
	LabelMaker::LabelMaker(int noOfLabels)
	{
		if (noOfLabels < 1)
		{
			cout << "You can only input greater than zero" << endl;
			noOfLabels = 0;
		}
		else
		{
			this->noOfLabels = noOfLabels;
			labels = new Label[noOfLabels];
		}
	}
	void LabelMaker::readLabels()
	{
		if (noOfLabels > 0)
		{
			cout << "Enter ";
			cout << noOfLabels;
			cout << " labels:" << endl;

			for (int i = 0; i < noOfLabels; i++)
			{
				cout << "Enter label number " << i + 1 << endl;
				labels[i].readLabel();
			}
		}
	}
	void LabelMaker::printLabels()
	{
		for (int i = 0; i < noOfLabels; i++)
		{
			labels[i].printLabel();
			cout << endl;
		}
	}
	LabelMaker::~LabelMaker()
	{
		delete[] labels;
		labels = nullptr;
	}
}