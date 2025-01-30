
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H
#include <iostream>
#include <string>
namespace seneca {
  class StringSet {
    size_t s_CurRecord { 0u };
    std::string *s_str { nullptr };
  public:
    StringSet() {}
    StringSet(const char *_filename);           
    ~StringSet();
    StringSet(const StringSet &src);           
    StringSet &operator=(const StringSet &src); 
    StringSet(StringSet &&src);                 
    StringSet &operator=(StringSet &&src);      
    size_t size() const;
    std::string operator[](size_t) const;

  };

}
#endif //! SDDS_STRINGSET_H