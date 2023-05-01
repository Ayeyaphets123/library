#include "Book.h"
#include <iostream>
Book::Book()
    : Tittle(" "), serialNumber(" "), author(" "), pageNumber(0), freePageReading(0),category(0), visibilityStatus(false), borrowedStatus(false){}
Book::Book(std::string T, std::string S, std::string A, int P, int FP, int C, bool VS, bool BS){
    setTittle(T);
    setSerialNum(S);
    setAuthor(A);
    setPageNum(P);
    setFreePage(FP);
    setCategory(C);
    setVisibilityStatus(VS);
    setBorrowedStatus(BS);
}
Book &Book::operator=(const Book &b)
{
    if(this == &b){
        return *this;
    }
    else{
        this->~Book();
        this->setAuthor(b.getAuthor());
        this->setTittle(b.getT());
        this->setSerialNum(b.getSeNum());
        this->setCategory(b.getCategory());
        this->setPageNum(b.getPageNum());
        this->setBorrowedStatus(b.getBorrowedStatus());
        this->setFreePage(b.getFreePage());
        this->setVisibilityStatus(b.getVisibilityStatus());
        return *this;
    }
}
Book::Book(const Book *b)
{
    Book * newB = new Book();
    newB->setAuthor(b->getAuthor());
    newB->setTittle(b->getT());
    newB->setSerialNum(b->getSeNum());
    newB->setCategory(b->getCategory());
    newB->setPageNum(b->getPageNum());
    newB->setBorrowedStatus(b->getBorrowedStatus());
    newB->setFreePage(b->getFreePage());
    newB->setVisibilityStatus(b->getVisibilityStatus());
}
void Book::setTittle(std::string T)
{
    Tittle = T;
}
void Book::setSerialNum(std::string S){
    serialNumber = S;
}
void Book::setAuthor(std::string A){
    author = A;
}
void Book::setPageNum(int P){
    if(P > 0) pageNumber = P;
    else return;
}
void Book::setFreePage(int FP){
    if(FP > 0 && FP < pageNumber) freePageReading = FP;
    else return; 
}
void Book::setCategory(int C){
    if(C > 0)
        category = C;
}
void Book::setVisibilityStatus(bool V){
    visibilityStatus = V;
}
void Book::setBorrowedStatus(bool B){
    borrowedStatus = B;
}
std::string Book::getT() const{
    return Tittle;
}
std::string Book::getSeNum() const{
    return serialNumber;
}
std::string Book::getAuthor() const{
    return author;
}
int Book::getPageNum() const{
    return pageNumber;
}
int Book::getFreePage() const{
    return freePageReading;
}
int Book::getCategory() const{
    return category;
}
bool Book::getVisibilityStatus() const{
    return visibilityStatus;
}
bool Book::getBorrowedStatus() const{
    return borrowedStatus;
}

void Book::display()
{   
    std::cout << "============\n";
    std::cout << "Tittle: " << Tittle << "\n"
              << "serialNumber: " << serialNumber << "\n"
              << "author: " << author << "\n"
              << "pageNumber: " << pageNumber << "\n"
              << "freePageReading: " << freePageReading << "\n"
              << "category: " << category << "\n"
              << "visibilityStatus: " << visibilityStatus << "\n"
              << "borrowedStatus: " << borrowedStatus << "\n";
    std::cout << "============\n";

}
