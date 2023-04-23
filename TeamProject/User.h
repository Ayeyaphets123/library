#include "Book.h"
#ifndef USER_H
#define USER_H
class User
{
    public:
        enum accessibilityType
        {
            High = 1,
            Medium,
            Low
        };
        User() : accessibilityLevel(Low) {}
        User(accessibilityType AL);
        virtual ~User() {}
        void readFreeBook(const Book &b) const;
        void searchBookTittle(std::string) const;
        void searchBookSerialNum(std::string) const;
        void setAccessibilityLevel(accessibilityType);
        accessibilityType getAccessibilityLevel() const;
        virtual void readBook(const Book &b) = 0;
    private:
        accessibilityType accessibilityLevel;

};

#endif