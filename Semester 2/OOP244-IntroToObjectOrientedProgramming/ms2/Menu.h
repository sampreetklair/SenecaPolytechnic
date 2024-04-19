// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef MENU_H
#define MENU_H

namespace sdds 
{

    class Menu 
    {
    private:
        char* menuContent;
        unsigned int numOptions;

    public:
        Menu(const char* content);
        ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        unsigned int run();
    };
    

}

#endif // MENU_H