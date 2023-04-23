#include "BookCollection.h"
BookCollection::BookCollection(int ID,int NumBook, std::string CoName, Book *list){
    setCoID(ID);
    setCoName(CoName);
    setBookList(list, ID);
}
BookCollection::~BookCollection()
{
    if(BookList != nullptr) delete [] BookList;
}

void BookCollection::setBookList(Book *list, int NumBook){
   
}
void BookCollection::setCoID(int ID){
    if(ID > 0) CollectionID = ID;
    else return;
}
void BookCollection::setCoName(std::string N){
    CollectionName = N;
}
std::string BookCollection::getCoName() const{
    return CollectionName;
}
Book *BookCollection::getBookList() const{
    return BookList;
}
