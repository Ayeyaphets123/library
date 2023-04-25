#ifndef ADMIN_H
#define ADMIN_H
#include "Registered.h"
#include "BookCollection.h"
#include "Member.h"
#include "Book.h"
#include <vector>

class Admin : public Registered
{
    private:
        static std::vector <Collection *> listCollection;
    protected:
        static std::vector <Member *> MemberList;
    public:
        Admin(): Registered(High){}
        Admin(std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType AL = High);
        ~Admin();
        void addBook(Book *b);
        void removeBook(Book *b);
        void EditBook(std::string SeNum);
        void EditCollection(Collection *c);
        void createCollection(Book b);
        void deleteCollection(Collection *c);
        int getBS() const;
        int getCS() const;  
        void readBook(const Book &b); 
        Book * searchBookSE(std::string) const;
        void displayBookList();
        bool checkMemberExist(std::string username);
        void addMember(std::string username, std::string password, std::string phone, std::string fullname);
};
#endif