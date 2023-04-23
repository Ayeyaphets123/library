#include "Book.h"
#ifndef USER_H
#define USER_H
enum accessibilityType {HIGH, MEDIUM, LOW};
class User
{
    public:
        User() : accessibilityLevel(LOW) {}
        User(accessibilityType AL);
        virtual ~User() {}
        //void readFreeBook(const Book &b) const; //con can ha`m nay khong nhi?
        void searchByTittle(std::string t) const;
        void searchBySerial(std::string s) const;
        void setAccessibilityLevel(accessibilityType t);
        accessibilityType getAccessibilityLevel() const;
        virtual void readBook(const Book &b) = 0;
    private:
        accessibilityType accessibilityLevel;
};

#endif
