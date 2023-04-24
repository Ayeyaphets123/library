#include "BookCollection.h"

Collection::Collection(int ID, std::string CoName){
    setCoID(ID);
    setCoName(CoName);
    BookList.clear();
    subscribedUser.clear();
}
Collection::~Collection()
{
    if(BookList.empty()){
        for(int i = 0 ;i <  BookList.size(); i++){
            delete BookList[i];
        }
        BookList.clear();
    }
    if(subscribedUser.empty()){
        for(int i = 0 ;i <  subscribedUser.size(); i++){
            delete subscribedUser[i];
        }
        subscribedUser.clear();
    }
}
void Collection::setCoID(int ID){
    if(ID > 0) CollectionID = ID;
    else return;
}
void Collection::setCoName(std::string N){
    CollectionName = N;
}
std::string Collection::getCoName() const{
    return CollectionName;
}
void Collection::addBookToCollection(Book *b){
    BookList.push_back(b);
}
void Collection::displayCollection(){
    if(BookList.empty())
    std::cout << "Empty list to show book!\n";
    else{  
        std::cout << "List Book\n";
        for(int i = 0 ; i < BookList.size();i++){
            std::cout << BookList[i]->getT() << "\n";
        }
    }
}
void Collection::displaySubscriber()
{
    if(subscribedUser.empty()){
        std::cout << "No one subscribe the Collection " << CollectionName << "\n";
    }
    else{
        std::cout << "Subscriber list\n";
        for(int i = 0 ; i < subscribedUser.size(); i++){
            std::cout << subscribedUser[i]->getF() << "\n";
        }
    }
}



