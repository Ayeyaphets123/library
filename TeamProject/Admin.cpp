#include <iostream>
#include "Admin.h"
#include <cstring>
Admin::~Admin(){
    listBook.clear();
    listCollection.clear(); 
}
Admin::Admin( int ID, std::string userName, std::string password, std::string phone, std::string fullname,accessibilityType AL )
    :  Registered(ID,userName,password,phone,fullname,AL){}
void Admin::addBook( Book *b){
    listBook.push_back(b);
}
void Admin::showBook( Book *b){
    b->setVisibilityStatus(true);
}
void Admin::hideBook( Book *b){
    b->setVisibilityStatus(false);
}
void Admin::removeBook( Book *b) {
   
}
void Admin::Edit(Book *b){
    
    }
void Admin::createCollection(Book b){
    
}
void Admin::deleteCollection(Collection *c){

}
void Admin::readBook(const Book &b){}
std::vector<Collection *> Admin::listCollection{};
Book * Admin::searchBookTT(std::string T) const{
    for(int i = 0; i < listBook.size();i++){
        if(T == listBook[i]->getT()){
            Book * b = listBook[i];
            return b;
        }
    }
    return nullptr;
}
void Admin::displayBookList(){
    if(listBook.empty()){
        std::cout << "Empty list\n";
    }
    else{
        for(int i = 0 ;i < listBook.size(); i++){
            listBook[i]->display();
        }
    }
}
