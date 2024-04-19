// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_
namespace sdds 
{
    class Status 
    {
        char* Description{};
        int Codigo{};
    public:
        Status(const char* desc = nullptr);
        Status(const Status& S);
        Status& operator=(const Status& S);
        ~Status();
        Status& operator=(int statusCode);
        Status& operator=(const char* desc);
        operator int() const;
        operator const char* ()const;
        operator bool() const;
        Status& clear();
        std::ostream& display(std::ostream& ostr)const;
    
    };

    std::ostream& operator<<(std::ostream& ostr, const Status& S);

}

#endif // !SDDS_STATUS_H_