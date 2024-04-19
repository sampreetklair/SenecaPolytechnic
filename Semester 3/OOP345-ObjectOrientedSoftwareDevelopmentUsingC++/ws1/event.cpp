// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// -----------------------------------------------------------

#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"
using namespace std;
namespace seneca{
  size_t g_sysClock = 0;

  Event::~Event(){
    if (e_Desc != nullptr) {
      delete[] e_Desc;
      e_Desc = nullptr;
    }
  }


  Event::Event(const Event &src){
    *this = src;
  }


  Event& Event::operator=(const Event &src){
    if (this != &src) {
      this->e_Time = src.e_Time;
      
      if (this->e_Desc != nullptr) 
      {
        delete[] this->e_Desc;
        this->e_Desc = nullptr;
      }

      if (src.e_Desc != nullptr && src.e_Desc[0] != '\0') 
      {
        this->e_Desc = new char[strlen(src.e_Desc) + 1];
        strcpy(this->e_Desc, src.e_Desc);
      }
    }


    return *this;
  }


  void Event::display() const 
  {
    static size_t _counter = 1;
    unsigned int hh = 0u, mm = 0u, ss = 0u;

    hh = e_Time / 3600;
    mm = e_Time / 60 % 60;
    ss = e_Time % 60;

    cout << setw(2) << setfill(' ') << _counter++ << ". ";

    if (e_Desc == nullptr || e_Desc[0] == '\0')
      cout << "| No Event |" << endl;
    else {
      cout << setw(2) << setfill('0') << hh << ":" << setw(2) << mm << ":" << setw(2) << ss << " => " << e_Desc << endl;
    }

  }


  void Event::set(const char *_desc) 
  {
    if (e_Desc != nullptr) 
    {
      delete[] e_Desc;
      e_Desc = nullptr;
    }

    if (_desc != nullptr && _desc[0] != '\0') 
    {
      e_Desc = new char[strlen(_desc) + 1];
      strcpy(e_Desc, _desc);
      e_Time = seneca::g_sysClock;
    }
    else
      e_Time = 0;
  }

}

