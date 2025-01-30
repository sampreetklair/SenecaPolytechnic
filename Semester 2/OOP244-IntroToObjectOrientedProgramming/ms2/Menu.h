
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