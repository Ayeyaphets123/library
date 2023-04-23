#include "Member.h"

Member::Member(int ID, std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType Medium) 
    : Registered(ID, userName,password,phone, fullname, Medium)
{}

void Member::borrowBook(const Book &b)
{
}
void Member::returnBook(const Book &b){
    
}
void Member::subscribeCollection(const BookCollection &BS ){
    
}
void Member::unSubscribeCollection(const BookCollection &BS ){
    
}
void Member::displayCollectionList(bool ){
    
}
void Member::displayBorrowedList(){
    
}