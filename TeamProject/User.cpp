#include <iostream>
#include "User.h"
void User::setAccessibilityLevel(accessibilityType lv) {
    if(lv > 0) accessibilityLevel = lv;
   
}
User::accessibilityType User::getAccessibilityLevel() const
{
    return accessibilityLevel;
}

