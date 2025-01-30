

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca{

  extern size_t g_sysClock;
  class Event{
    size_t e_Time  { 0 };
    char  *e_Desc  { nullptr };
  public:
    Event() { };
    ~Event();
    Event(const Event &src);
    Event &operator=(const Event &src);
    void display() const;
    void set(const char *_desc = nullptr);

  };
  
}

#endif