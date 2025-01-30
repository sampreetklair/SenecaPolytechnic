
#include <iostream>
#include <iomanip>
#include "Movie.h"
using namespace std;
namespace seneca {
  const std::string& Movie::title() const {
    return m_title;
  }

  Movie::Movie(const std::string& strMovie) {
    if (!strMovie.empty()) {
      string _tempStr = strMovie;
      int _tempIdx = 0u;

      auto removeSpace = [=](string &src) {
        if (src[0] == ' ')
          src.erase(0, src.find_first_not_of(' '));
        else
          src.erase(src.find_last_not_of(' ') + 1);
      };

      removeSpace(_tempStr);
      _tempIdx = _tempStr.find(',');
      m_title = _tempStr.substr(0, _tempIdx);
      removeSpace(m_title);
      _tempStr.erase(0, _tempIdx + 1);

      removeSpace(_tempStr);
      _tempIdx = _tempStr.find(',');
      m_year = std::stoi(_tempStr.substr(0, _tempIdx));
      _tempStr.erase(0, _tempIdx + 1);

      removeSpace(_tempStr);
      removeSpace(_tempStr);
      m_description = _tempStr;
    }
  }

  std::ostream &operator<<(std::ostream &os, const Movie &src) {
    os << setw(40) << std::right << src.m_title << " | ";
    os << std::left << setw(4) << src.m_year << " | " << src.m_description << endl;

    return os;

  }

  
}