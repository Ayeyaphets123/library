#include "Book.h"
#ifndef BC_H
#define BC_H
#include "Member.h"
class BookCollection : public Book
{
    private:
        int CollectionID;
        std::string CollectionName;
        Book *BookList;
        Member *subscribedUser;
    public:
        BookCollection() : CollectionID(0), CollectionName(" "), BookList(nullptr), subscribedUser(nullptr){}
        BookCollection(int ID,int NumBook, std::string CoName, Book *list);
        BookCollection(const BookCollection &BC);
        ~BookCollection();
        void setBookList(Book *list, int NumBook);
        void setCoID(int);
        void setCoName(std::string);
        void setNumberOfBook(int);
        void setBook(Book b, int index);
        int getCoID() const;
        int getNumberOfBook() const;
        std::string getCoName() const;
        Book *getBookList() const;
        Book getBook(int index) const;

};


#endif