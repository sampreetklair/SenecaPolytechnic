// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include <iostream>
#include <cstring>
#include "Student.h"

namespace sdds 
{
    void Student::setEmpty(){
        m_name = nullptr;
        m_age = 0;
    }
    Student::operator bool() const
    
    {
        return m_name && m_name[0] != '\0';
    
    }

    void Student::alocpy(char*& destination, const char* source)
    
    {
        if (source && source[0] != '\0') 
        {
            delete[] destination;
            destination = nullptr;
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
       
        }
        else
       
        {
            destination = nullptr;
      
        }
 
    }

    Student::Student() {

    };

    Student::Student(const char* name, size_t age) 
    {
        if (name && name[0] != '\0') {
            alocpy(m_name, name);
            m_age = age;
     
        }
        else{
            setEmpty();
     
        }


    }

    Student::Student(const Student& stu) 
    {
        operator=(stu);

    }

    Student& Student::operator=(const Student& stu) 
    {
        if (this != &stu) 
        {
            alocpy(m_name, stu.m_name);
            m_age = stu.m_age;
        
        }
     
        return *this;
    
    }

    Student::~Student() 
    {
 
        delete[] m_name;
 
    }

    void Student::display() const 
    {
        if (m_name) 
        {
            std::cout << "Name: " << m_name << std::endl;
            std::cout << "Age: " << m_age << std::endl;
      
        }


    }


}