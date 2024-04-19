// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 28th January, 2024
// -----------------------------------------------------------


#include <fstream>
#include "StringSet.h"
using namespace std;
namespace seneca {
  StringSet::StringSet(const char *_filename) {
    if (_filename) {
      ifstream readFile(_filename);
      string _temp;

      if (readFile) 
      {
        while (getline(readFile, _temp, ' '))
          ++s_CurRecord;
        s_str = new string[s_CurRecord];
        readFile.clear();
        readFile.seekg(0, std::ios::beg);
        int i = 0;
        while (getline(readFile, s_str[i], ' '))
          ++i;
      }
    }
  }

  StringSet::~StringSet() 
  {
    if (s_str)
      delete[] s_str;
  }

  StringSet::StringSet(const StringSet &src) {
    *this = src;
  }

  StringSet& StringSet::operator=(const StringSet &src) {
    if (this != &src) {
      if (this->s_str) {
        delete[] s_str;
        s_str = nullptr;
      }
      this->s_CurRecord = src.s_CurRecord;
      this->s_str = new string[s_CurRecord];
      for (auto i = 0u; i < s_CurRecord; ++i)
        this->s_str[i] = src.s_str[i];
    }

    return *this;
  }

  StringSet::StringSet(StringSet &&src) 
  {
    *this = std::move(src);
  }

  StringSet& StringSet::operator=(StringSet &&src) 
  {
    if (this != &src) 
    {

      if (this->s_str) 
      {
        delete[] s_str;
        s_str = nullptr;
      }

        this->s_CurRecord = src.s_CurRecord;
        src.s_CurRecord = 0u;

        this->s_str = src.s_str;
        src.s_str = nullptr;
    }

    return *this;
  }

  size_t StringSet::size() const 
  {
    return s_CurRecord;
  }

  std::string StringSet::operator[](size_t src) const 
  {
    string _copy = "";

    if (src < s_CurRecord)
      _copy = s_str[src];

    return _copy;
 
  }
  
}