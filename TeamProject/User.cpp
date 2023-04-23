#include "User.h"
User::User(accessibilityType AL){
    setAccessibilityLevel(AL);
}
void User::readFreeBook(const Book &b) const{
    if(accessibilityLevel == High){

    }
}
void User::searchBookTittle(std::string tittle) const {
    
    
}
void User::searchBookSerialNum(std::string SEnumber) const {


}
void User::setAccessibilityLevel(accessibilityType lv) {
    if(lv > 0) accessibilityLevel = lv;
    else {
        throw "Invalid accessibilityLevel!\n";
    }
}
User::accessibilityType User::getAccessibilityLevel() const
{
    return accessibilityLevel;
}
