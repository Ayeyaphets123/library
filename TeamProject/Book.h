#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Library.h"
class Book
{
    private:
        std::string Tittle;
        std::string serialNumber;
        std::string author;
        int pageNumber;
        int freePageReading;
        int category;
        bool visibilityStatus;
        bool borrowedStatus;
    public:
        Book();
        Book(std::string T, std::string S, std::string A, int P, int FP, int C, bool VS, bool BS);
        ~Book() {}
        Book &operator =(const Book &b);
        Book (const Book *b);
        void setTittle(std::string);
        void setSerialNum( std::string);
        void setAuthor(std::string);
        void setPageNum(int);
        void setFreePage(int);
        void setCategory(int);
        void setVisibilityStatus(bool);
        void setBorrowedStatus(bool);
        std::string getT() const;
        std::string getSeNum() const;
        std::string getAuthor() const;
        int getPageNum() const;
        int getFreePage() const;
        int getCategory() const;
        bool getVisibilityStatus() const;
        bool getBorrowedStatus() const;
        void display();
};

#endif