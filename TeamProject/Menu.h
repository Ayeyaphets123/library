#include <string>
#include <vector>
#ifndef MENU_H
#define MENU_H
class Menu
{
    private:
        std::string Name;
        std::string description;
        std::vector<Menu*> subMenu;
        int Action;
    public:
        Menu();
        Menu(std::string n, std::string d, int action = -1);
        ~Menu();
        void setName(std::string);
        std::string getname()const;
        void setDes(std::string);
        std::string getDes() const;
        void displayMenu();
        void addSubMenu(Menu *m);
        int chooseOption();
        Menu * getSubMenu (int index);
        void setAction(int);
        int getAction() const;
        
};

#endif