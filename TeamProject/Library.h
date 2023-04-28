#ifndef LB_H
#define LB_H
#include <vector>
#include "Book.h"
class Library
{
private:

    std::vector<Book *> listBook;
    void HelpRemoveBook(std::string);
    Book *HelpSeachBookT(std::string);
    Book *HelpSeachBookSE(std::string);
    Book *HelpSeachBookSE(std::string, int &index);

public:
    Library()
    {
        listBook.clear();
    }
    ~Library();
    void searchBookTittle(std::string);
    void searchBookSerialNum(std::string);

    friend class Admin;
};
#endif