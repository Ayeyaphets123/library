#include "BookCollection.h"
Collection::Collection( std::string CoName)
{
    setCoID(CollectionCountID);
    setCoName(CoName);
    if(!BookList.empty()){
        for(int i =0  ; i < BookList.size() ;i++){
            if(BookList[i]) delete BookList[i];
        }

    }
    BookList.clear();
    std::vector<Book *> BookList{};
    CollectionCountID++;
}
Collection::~Collection()
{
    if(!BookList.empty()){
        for(int i = 0 ;i <  BookList.size(); i++){
            if(BookList[i]) 
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
std::vector<Book *> Collection::getBookList() const
{
    return BookList;
}
void Collection::addBookToCollection(Book *b)
{
    BookList.push_back(b);
}
void Collection::displayCollection(){
    if(!BookList.empty()){
        std::cout << "List Book\n";
        std::cout << "Id " << CollectionID << "\n"  << "Collection name: " << CollectionName << "\n";

        for(int i = 0 ; i <  BookList.size(); i++){
                std::cout << i + 1 << ". " << BookList[i]->getT() << "\n";
        }
    }
}

void Collection::deleteBook(std::string N)
{
    if(!BookList.empty())
        for(int i = 0 ; i < BookList.size(); i++){
            if(N == BookList[i]->getT()){
                if(i != BookList.size() -1){

                    for(int j = i; j < BookList.size() - 1; j++){
                        
                        *BookList[j] = *BookList[j + 1];
                    }
                }
                delete BookList[BookList.size() - 1];
                BookList.resize(BookList.size() -1);
                std::cout << "Delete successfully\n";
                return;
            }
        }
    
}
Book *Collection::HelpSearchBook(std::string name)
{
    if(!BookList.empty()){
        for(int i = 0 ; i < BookList.size(); i++){
            if(name == BookList[i]->getT()){
                Book * b = new Book();
                *b = *BookList[i];
                return b;
            }
        }
        return nullptr;
    }
}

int Collection::CollectionCountID = 1;


