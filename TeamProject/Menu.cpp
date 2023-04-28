#include "Menu.h"
#include <iostream>
Menu::Menu(){
    Name = "Default menu";
    description = "default des";
    subMenu.clear();
    
}
Menu::Menu(std::string n, std::string d, int action ){
    setName(n);
    setDes(d);
    Action = action;
}
Menu::~Menu(){
    if(subMenu.empty()){
        for(int i = 0 ;  i < subMenu.size(); i++){
        if(subMenu[i])
            delete subMenu[i];
        }
        subMenu.clear();
    }
}
void Menu::setName(std::string n){
    Name = n;
}
std::string Menu::getname()const{
    return Name;
}
void Menu::setDes(std::string d){
    description = d;
}
std::string Menu::getDes() const{
    return description;
}
void Menu::addSubMenu(Menu *m){
    subMenu.push_back(m);
}
void Menu::setAction(int a){
    if(a > 0) Action = a;
}
int Menu::getAction() const{
    return Action;
}
        
void Menu::displayMenu(){
    std::cout << "\n===" << Name << "===\n";
    std::cout << description << "\n";
    for(int i = 0 ; i < subMenu.size(); i++)
    {
        std::cout << i + 1 << ". " << subMenu[i]->getname() << "\n";
    } 
}
int Menu::chooseOption(){

    while(true){
    std::cout << "Choose option: \n";
    int option;
    std::cin >> option;
    try{
        if(std::cin.fail()){
                throw "Invalid input";
        }
        else if(option < 0 || option > subMenu.size()){
            throw "Menu out of range";
        }
        else{
            return option;
        }
    }
    catch(const char* error){
        std::cin.ignore();
        std::cin.clear();
        std::cout << "Error! " << error << "\n";
    }
    }

}
Menu* Menu:: getSubMenu (int index)
{
    if(index > 0 && index < subMenu.size())
    {
        return subMenu[--index];
    }
    else{
        return nullptr;
    }
}

