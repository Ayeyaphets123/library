#include "Member.h"

Member::Member( std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType Medium) 
    : Registered(userName,password,phone, fullname, Medium)
{}

Member::~Member()
{
    if(!borrowedList.empty()){
        for(int i = 0 ; i < borrowedList.size(); i++){
            if(borrowedList[i]) 
                delete borrowedList[i];
        }
    }
    borrowedList.clear();

    if(!subscribedCollectionList.empty()){
        for(int i = 0 ; i < subscribedCollectionList.size(); i++){
            if(!subscribedCollectionList[i]->getBookList().empty()){
                for(int j = 0 ; j < subscribedCollectionList[i]->getBookList().size(); j++){
                    if(subscribedCollectionList[i]->getBookList()[j])
                        delete subscribedCollectionList[i]->getBookList()[j];
                }
            }
            delete subscribedCollectionList[i];
        }
    }
    subscribedCollectionList.clear();
}

void Member::borrowBook(Book *b)
{
}
void Member::returnBook(Book *b){
    
}
void Member::subscribeCollection(Collection *BS ){
    
}
void Member::unSubscribeCollection( Collection *BS ){
    
}
void Member::displayCollectionList(bool ){
    
}
void Member::displayBorrowedList(){
    
}
void Member::readBook(const Book *b){}

std::vector<Book *> Member::getBorrowedBookList() const
{
    return borrowedList;
}

std::vector<Collection *> Member::getSubscribedCollectionList() const
{
    return subscribedCollectionList;
}

void Member::deleteBookInBorrowList(std::string N)
{   
    if(borrowedList.empty()){
        std::cout << "Empty list to delete book\n";

    }
    else{
        for(int i = 0; i < borrowedList.size(); i++ ){
            if(N == borrowedList[i]->getT()){
                delete borrowedList[i];
                for(int j = i ; j < borrowedList.size(); j++){
                    *borrowedList[j] = * borrowedList[j+1];
                }
                delete borrowedList[borrowedList.size() -1];
                borrowedList.resize(borrowedList.size() -1);
                std::cout << "delete successfully\n";
                return;
            }
        }
    }
    std::cout << "Not found the book to delete\n";
}

void Member::deleteBookInSubscribedCollection(std::string N)
{
    if(subscribedCollectionList.empty()){
        std::cout << "Empty collection to delete Book\n";
    }
    else{
        for(int i = 0 ; i < subscribedCollectionList.size(); i++){
            if(!subscribedCollectionList[i]->getBookList().empty()){
                for(int j = 0 ; j < subscribedCollectionList[i]->getBookList().size(); j++){
                    if(subscribedCollectionList[i]->getBookList()[j]->getT() == N){
                        delete subscribedCollectionList[i]->getBookList()[j];
                        for(int k = j ; k < subscribedCollectionList[i]->getBookList().size(); k++){
                            *subscribedCollectionList[i]->getBookList()[j] = subscribedCollectionList[i]->getBookList()[j+1];
                        }
                        delete subscribedCollectionList[i]->getBookList()[subscribedCollectionList[i]->getBookList().size() - 1];
                        subscribedCollectionList[i]->getBookList().resize(subscribedCollectionList[i]->getBookList().size() - 1);
                        return;
                    }
                }
            }
        } 
    }
    std::cout << "there is no book in Collection to delete\n";
}

