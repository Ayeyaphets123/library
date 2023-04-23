#include "Admin.h"
#include <iostream>
#include <cstring>
Admin::~Admin(){
    if(listBook) delete [] listBook;
    if(listCollection) delete [] listCollection; 
}
Admin::Admin( int ID, std::string userName, std::string password, std::string phone, std::string fullname,accessibilityType AL )
    :  Registered(ID,userName,password,phone,fullname, AL){}
void Admin::addBook(Book &b){
    
}
void Admin::showBook(Book &b){
    
}
void Admin::hideBook(Book &b){
  
}
void Admin::removeBook(Book &b) {
   
}
void Admin::Edit(Book &b){
    
    }
void Admin::createCollection(Book b){
    
}
void Admin::deleteCollection(BookCollection &c){

}

int Admin::getBS() const{
    return NumberOfBookOfLibrary;
}
int Admin::getCS() const{
    return NumberOfCollection;
}

int Admin::NumberOfBookOfLibrary = 0;
int Admin::NumberOfCollection= 0;
Book*Admin::listBook = nullptr;
BookCollection *Admin::listCollection = nullptr;