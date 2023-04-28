#ifndef BC_H
#define BC_H
#include <iostream>
#include "Book.h"
#include <vector>

class Collection 
{
    private:
        int CollectionID;
        std::string CollectionName;
        std::vector<Book *> BookList;
        Book *HelpSearchBook(std::string);
        void HelpDeleteBook(std::string);
        static int CollectionCountID;
    public:
        Collection() : CollectionID(0), CollectionName(" "){
            BookList.clear();
            CollectionCountID++;
        }
        Collection(std::string CoName);
        Collection(const Collection &BC);
        ~Collection();
        
        void setCoID(int);
        void setCoName(std::string);
        void addBookToCollection(Book *b);
        void displayCollection(bool signal);
        void displaySubscriber();
        void deleteBook(std::string);

        int getCoID() const;
        std::string getCoName() const;
        std::vector<Book *> getBookList() const;

    
};


#endif