#include <iostream>
#include "User.h"
void User::searchBookTittle(std::string tittle) const {
   if(listBook.empty()){
        std::cout << "Empty library\n";
   }
   else{
        for(int i = 0; i < listBook.size(); i++ ){
            if(listBook[i]->getT() == tittle){
                std::cout << "The book is found\n";
                listBook[i]->display();
                return;
            }
        }
   }
}
void User::searchBookSerialNum(std::string SEnumber) const {
    if(listBook.empty()){
            std::cout << "Empty library\n";
    }
    else{
            for(int i = 0; i < listBook.size(); i++ ){
                if(listBook[i]->getSeNum() == SEnumber){
                    std::cout << "The book is found\n";
                    listBook[i]->display();
                    return;
                }
            }
    }
}
void User::setAccessibilityLevel(accessibilityType lv) {
    if(lv > 0) accessibilityLevel = lv;
   
}
User::accessibilityType User::getAccessibilityLevel() const
{
    return accessibilityLevel;
}

