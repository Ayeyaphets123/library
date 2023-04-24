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
        Collection() : CollectionID(0), CollectionName(" "){
            BookList.clear();
           
        }
        Collection(int ID, std::string CoName);
        Collection(const Collection &BC);
        ~Collection();
        void setCoID(int);
        void setCoName(std::string);
        int getCoID() const;
        std::string getCoName() const;

        void addBookToCollection(Book *b);
        void displayCollection();
        void displaySubscriber();

};


#endif