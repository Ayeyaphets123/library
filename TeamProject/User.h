#ifndef USER_H
#define USER_H
#include "GlobalVar.h"
class User
{
    public:
        enum accessibilityType
        {
            Low = 1,
            Medium,
            High
        };
        User() : accessibilityLevel(Low){}
        User(accessibilityType AL) {
            setAccessibilityLevel(AL);
        }
        virtual ~User(){}
        void searchBookTittle(std::string) const;
        void searchBookSerialNum(std::string) const;
        void setAccessibilityLevel(accessibilityType);
        accessibilityType getAccessibilityLevel() const;
        virtual void readBook(const Book &b) = 0;
    private:
        accessibilityType accessibilityLevel;
};
#endif
