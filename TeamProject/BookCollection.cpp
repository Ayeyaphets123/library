#include "BookCollection.h"
Collection::Collection(int ID, std::string CoName)
{
    setCoID(ID);
    setCoName(CoName);
    BookList.clear();
}
Collection::~Collection()
{
    if(BookList.empty()){
        for(int i = 0 ;i <  BookList.size(); i++){
            delete BookList[i];
        }
        BookList.clear();
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
void Collection::displayCollection(bool signal){
    if(BookList.empty())
    std::cout << "Empty list to show book!\n";
    else{  
        std::cout << "List Book\n";
        std::cout << "Id " << CollectionID << "\n" << "\t" << "Collection name: " << CollectionName << "\n";
        if(signal)
            for(int i = 0 ; i <  BookList.size(); i++){
                std::cout << i + 1 << ". " << BookList[i]->getT() << "\n";
            }
        
    }
}

void Collection::deleteBook(std::string N)
{
    HelpDeleteBook(N);
}
void Collection::HelpDeleteBook(std::string N)
{
    if(BookList.empty())
    {
        std::cout << "Empty Collection to delete\n";
    }
    else{
        for(int i = 0 ; i < BookList.size(); i++){
            if(N == BookList[i]->getT()){
                BookList.erase(BookList.begin() + i);
                for(int j = i; j < BookList.size(); j++){
                    BookList[j] = BookList[j + 1];

                }
                std::cout << "Delete successfully\n";
                return;
            }

        }
        std::cout << "Book " << N << " is not found to delete in the collection\n";
    }

}
