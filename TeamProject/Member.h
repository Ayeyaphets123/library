#ifndef MEMBER_H
#define MEMBER_H
#include "User.h"
#include "Registered.h"
#include "BookCollection.h"
#include "Book.h"
#include <vector>
class Member : public Registered
{
    private:
        int startTear;
        int EndYear;
        std::vector <Book *> borrowedList;
        std::vector <Collection *> subscribedCollectionList;
    public:
        Member() : Registered(Medium),startTear(0), EndYear(0){
                borrowedList.clear();
                subscribedCollectionList.clear();
        }
        Member(int ID, std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType AL = Medium);
        ~Member(){};
        void borrowBook(const Book &b);
        void returnBook(const Book &b);

        void subscribeCollection( Collection BS);
        void unSubscribeCollection(Collection BS);

        void displayCollectionList(bool);
        void displayBorrowedList();

        void readBook(const Book &b);

        void setStartYear();
        void setEndYear();
        int getStartYear() const;
        int getEndYear() const;
};

#endif