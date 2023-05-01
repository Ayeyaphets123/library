#ifndef LB_H
#define LB_H
#include <vector>
#include "Book.h"
class Library
{
private:

    std::vector<Book *> listBook;

public:
    Library()
    {   
        listBook.clear();
    }
    ~Library();

    Book *HelpSeachBookSE(std::string);
    Book *HelpSeachBookT(std::string, int &index);

    void searchBookTittle();
    void searchBookSerialNum();

    void HelpRemoveBookInLibrary(std::string);

    void displayListBook();
    friend class Admin;
};
#endif