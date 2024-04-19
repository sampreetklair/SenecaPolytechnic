// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include <iostream>
#include <cstring>
#include "Graduate.h"

namespace sdds{
    
    void Graduate::setEmpty() 
    {
        m_thesis = nullptr;
        m_supervisor = nullptr;
    }

    Graduate::Graduate() {

    }

    Graduate::Graduate(const char* name, size_t age, const char* thesis, const char* supervisor)
        : Student(name, age) 
        
        {
        setEmpty();
        alocpy(m_thesis, thesis);
        alocpy(m_supervisor, supervisor);
    }

    Graduate::~Graduate() 
    
    {
        delete[] m_thesis;
        delete[] m_supervisor;
    
    }

    Graduate::Graduate(const Graduate& src) : Student(src) 
    
    {
        setEmpty();
        operator=(src);
    
    }

    Graduate& Graduate::operator=(const Graduate& gra) 
    
    {
        if (this != &gra) {
            Student::operator=(gra);
            alocpy(m_thesis, gra.m_thesis);
            alocpy(m_supervisor, gra.m_supervisor);
      
        }
        return *this;
   
    }

    void Graduate::display() const 
    {

        Student::display();

        if (m_thesis != nullptr && m_supervisor != nullptr) 
        {
            std::cout << "Thesis Title: " << m_thesis << std::endl;
            std::cout << "Supervisor: " << m_supervisor << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
     
        }


    }


}