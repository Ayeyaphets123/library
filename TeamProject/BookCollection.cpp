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
Collection::Collection(const Collection &BC)
{
    Collection * C = new Collection();
    C->BookList.clear();
    if(!BC.BookList.empty()){
        for(int i = 0 ;i < BC.BookList.size(); i++){
            *C->BookList[i] = *BC.BookList[i];
        }
    }
}
Collection &Collection::operator=(const Collection &BC)
{   
    std::cout << "123\n";
    if( this == &BC){
        return *this;
    }
    else{
        this->~Collection();
        if(!BC.BookList.empty()){
            for(int i = 0 ;i < BC.BookList.size(); i++){
                if(BC.BookList[i]){
                    this->BookList[i]->setAuthor(BC.BookList[i]->getAuthor());
                    this->BookList[i]->setBorrowedStatus(BC.BookList[i]->getBorrowedStatus());
                    this->BookList[i]->setCategory(BC.BookList[i]->getCategory());
                    this->BookList[i]->setFreePage(BC.BookList[i]->getFreePage());
                    this->BookList[i]->setPageNum(BC.BookList[i]->getPageNum());
                    this->BookList[i]->setSerialNum(BC.BookList[i]->getSeNum());
                    this->BookList[i]->setTittle(BC.BookList[i]->getT());
                    this->BookList[i]->setVisibilityStatus(BC.BookList[i]->getVisibilityStatus());

                }
            }
        }
        return *this;
    }
    
}
Collection::~Collection()
{
    if(!BookList.empty()){
        for(int i = 0 ;i < BookList.size(); i++){
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
void Collection::HelpEdiCollection( bool N_signal, bool ID_signal, std::string NewCoName, int newID)
{
    if(N_signal){
        setCoName(NewCoName);
    }
    if(ID_signal){
        setCoID(newID);
    }
    
}
void Collection::HelpEditBook(std::string bookName, bool T_signal, bool A_signal, bool SE_signal, bool P_signal, bool C_signal, bool FP_signal, bool VS_signal, std::string T, std::string A, std::string SE, int P, int C, int FP)
{
    if(!BookList.empty()){
        for(int i = 0 ; i < BookList.size() ; i++){
            if(bookName == BookList[i]->getT()){
                if(T_signal){
                    BookList[i]->setTittle(T);
                }
                if(A_signal){
                    BookList[i]->setAuthor(A);
                    
                }
                if(SE_signal){
                    BookList[i]->setSerialNum(SE);
                    
                }
                if(P_signal){
                    BookList[i]->setPageNum(P);
                }
                if(C_signal){
                    BookList[i]->setCategory(C);
                    
                }
                if(FP_signal){
                    BookList[i]->setFreePage(FP);
                    
                }
                if(VS_signal){
                    if(BookList[i]->getVisibilityStatus() == true)
                        BookList[i]->setVisibilityStatus(false);
                    else BookList[i]->setVisibilityStatus(true);
                }
            }
        }
    }
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
                BookList[i]->display();
        }
    }
    else{
        std::cout << "Empty list to display\n";
    }
}
void Collection::deleteBook(std::string N)
{   
    std::cout << "\n--------------------------------\n";
    if(!BookList.empty()){
    for(int i = 0 ; i < BookList.size(); i++){
        if(N == BookList[i]->getT()){
            for(int j = i ; j < BookList.size() - 1; j++){
                *BookList[j] = *BookList[j+1];
            }
            delete BookList[BookList.size() -1];
            BookList.resize(BookList.size() -1);
            std::cout << "Delete Book in Collection successfully\n";
            return;
        }
    }
    std::cout << "The Book is not found to be deleted in The Collection\n";
    }
    else{
        std::cout << "Empty collection to delete\n";
    }
    std::cout << "--------------------------------\n";

}
int Collection::CollectionCountID = 1;


