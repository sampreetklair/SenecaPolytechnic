// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 16th February, 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <iostream>
#include <string>
namespace seneca {
  const int STR_SIZE = 6;
  class SpellChecker {
    std::string m_badWords[STR_SIZE]  {};
    std::string m_goodWords[STR_SIZE] {};
    size_t m_replaceCount[STR_SIZE]   {};
  public:
    SpellChecker() {}
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& out) const;

  };


}

#endif