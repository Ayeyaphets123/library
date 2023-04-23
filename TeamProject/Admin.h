#ifndef ADMIN_H
#define ADMIN_H
#include "Registered.h"
#include "BookCollection.h"
#include "Book.h"
class Admin : public Registered
{
    private:
        static int NumberOfBookOfLibrary;
        static int NumberOfCollection;
        static Book * listBook ;
        static BookCollection * listCollection;
    public:
        Admin(): Registered(High){}
        Admin(int ID, std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType AL = High);
        ~Admin();
        static void addBook(Book &b);
        static void showBook(Book &b);
        static void hideBook(Book &b);
        static void removeBook(Book &b);
        static void Edit(Book &b);
        static void createCollection(Book b);
        static void deleteCollection(BookCollection &c);
        int getBS() const;
        int getCS() const;  
        void readBook(const Book&b);  
};
#endif