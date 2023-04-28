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
        
    public:
        static int CollectionCountID;
        Collection() : CollectionID(0), CollectionName(" "){
            BookList.clear();
        }
        Collection(std::string CoName);
        Collection(const Collection &BC);
        ~Collection();
        
        void setCoID(int);
        void setCoName(std::string);
        void addBookToCollection(Book *b);
        void displayCollection();
        void displaySubscriber();
        void deleteBook(std::string);

        int getCoID() const;
        std::string getCoName() const;
        std::vector<Book *> getBookList() const;

        Book *HelpSearchBook(std::string);

    
};


#endif