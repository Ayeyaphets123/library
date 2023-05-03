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
        static std::vector <Admin *> listAdmin;
        
    public:
        Admin(): Registered(High){}
        Admin(std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType AL = High);
        ~Admin();
        static Admin* CreatAdmin();

        static void addBook(Library *lib, Book *b);
        static void removeBook(Library *lib);
        static void EditBook(Library *lib);
        void readBook( const Book *b);

        static void EditCollection(Library *lib);
        static void createCollection();
        static void deleteCollection(); 
        void displayCollectionList(accessibilityType accessibilityLevel);
 
        void addMember(Member *);
        void addCollection(Collection *);
        void showListMember();

        Collection * HelpSearchCollection(std::string);
        Member *getMember(std::string, std::string) const;
        void PersonalInformation();
        
        void logout();
        
        std::vector <Member *> getMemberList() const;
        std::vector <Collection *> getCollectionList() const;
};
#endif