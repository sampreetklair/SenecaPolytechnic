// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
namespace sdds{
    class Student
    
    {
        char* m_name{ nullptr };
        int m_age{ 0 };
        void setEmpty();
    protected:
        operator bool()const;
        void alocpy(char*& destination, const char* source);
    public:
        Student();
        Student(const char* name, size_t age);
        Student(const Student& student);
        Student& operator=(const Student& student);
        virtual ~Student();
        void display() const;
  
    };

}
#endif // SDDS_STUDENT_H