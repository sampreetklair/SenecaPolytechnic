// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "Label.h"
using namespace std;
namespace sdds
{

	Label::Label() {
		const char default_frame[9] = "+-+|+-+|";
		strcpy(frameString, default_frame);
		m_content = nullptr;
	}
	Label::Label(const char* frameArg)
	{
		strcpy(frameString, frameArg);
		m_content = nullptr;
	}
	Label::Label(const char* frameArg, const char* content)
	{
		strcpy(frameString, frameArg);
		int strLength = strlen(content);

		if (strLength < 71) {
			m_content = new char[strLength + 1];
			strcpy(m_content, content);
		}
		else
		{
			m_content = nullptr;
		}
	}
	Label::~Label()
	{
		clear();
	}
	std::istream& Label::readLabel()
	{
		char content[70 + 1];
		clear();
		cout << "> ";
		cin.get(content, 71);
		cin.ignore(10000, '\n');
		m_content = new char[strlen(content) + 1];
		strcpy(m_content, content);
	
		return cin;
	}
	std::ostream& Label::printLabel()const
	{
		if (m_content) {
			int len = strlen(m_content);
			int i;
			cout << frameString[0];
			for (i = 0; i < len + 2; i++) {
				cout << frameString[1];
			}
			cout << frameString[2] << endl;

			cout << frameString[7];
			cout.fill(' ');
			cout.width(len + 3);
			cout << frameString[3] << endl;

			cout << frameString[7];
			cout << " " << m_content << " " << frameString[3] << endl;

			cout << frameString[7];
			cout.fill(' ');
			cout.width(len + 3);
			cout << frameString[3] << endl;

			cout << frameString[6];
			for (i = 0; i < len + 2; i++) {
				cout << frameString[5];
			}
			cout << frameString[4];
		}

		return cout;
	}
	void Label::clear()
	{
		if (m_content != nullptr)
		{
			if (m_content[0] != '0')
			{
				delete[] m_content;
				m_content = nullptr;
			}
		}
	}
	Label& Label::text(const char* content)
	{
		if (content) {
			int len = strlen(content);

			if (len <= 70) {
				this->m_content = new char[len + 1];
				strcpy(this->m_content, content);
			}
		}
		return *this;
	}

}