#include "Member.h"

Member::Member( std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType Medium) 
    : Registered(userName,password,phone, fullname, Medium)
{}

void Member::borrowBook(const Book &b)
{
}
void Member::returnBook(const Book &b){
    
}
void Member::subscribeCollection(Collection BS ){
    
}
void Member::unSubscribeCollection( Collection BS ){
    
}
void Member::displayCollectionList(bool ){
    
}
void Member::displayBorrowedList(){
    
}
void Member::readBook(const Book &b){}