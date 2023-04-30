#ifndef ADMIN_H
#define ADMIN_H
#include "Library.h"
#include "Registered.h"
#include "BookCollection.h"
#include "Member.h"
#include <vector>

class Admin : public Registered
{
    private:
        static std::vector <Member *> MemberList;
        static std::vector <Collection *> listCollection;
        
    public:
        Admin(): Registered(High){}
        Admin(std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType AL = High);
        ~Admin();
        
        static Admin* CreatAdmin();
        static void addBook(Library *lib, Book *b);
        static void removeBook(Library *lib);
        static void EditBook(Library *lib);
        static void EditCollection(Library *lib);
        static void createCollection();
        static void deleteCollection(); 

        std::vector <Member *> getMemberList() const;
        std::vector <Collection *> getCollectionList() const;

        void readBook( const Book *b); 
        
        void displayCollectionList();

        void addMember(Member*);
        void showListMember();

        Collection * HelpSearchCollection(std::string);
        void PersonalInformation();
};
#endif