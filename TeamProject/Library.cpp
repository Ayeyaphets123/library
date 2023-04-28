#include "Library.h"
Library::~Library(){
    for(int i = 0 ; i < listBook.size(); i++){
        if(listBook[i])
            delete listBook[i];
    }
    listBook.clear();
}

Book *Library::HelpSeachBookT(std::string T)
{   
    for(int  i = 0; i < listBook.size(); i++){
        if(listBook[i]->getT() == T){
            return listBook[i];
        }
    }
    return nullptr;
}

void Library::searchBookTittle(std::string T)
{   
    int index;
    if(HelpSeachBookT(T)){
        HelpSeachBookT(T)->display();
    }
    else{
        std::cout << "Book " << T << " not found\n";
    }

}
Book *Library::HelpSeachBookSE(std::string SE)
{
    for(int  i = 0; i < listBook.size(); i++){
        if(listBook[i]->getSeNum() == SE){
            Book * b = new Book();
            *b = *listBook[i];
            return b;
        }
    }
    return nullptr;
}
void Library::searchBookSerialNum(std::string SE)
{   
    int index;
    if(HelpSeachBookSE(SE)){
        HelpSeachBookT(SE)->display();
    }
    else{
        std::cout << "Book " << SE << " not found\n";
    }
}
Book *Library::HelpSeachBookSE(std::string SE, int &index){
    for(int  i = 0; i < listBook.size(); i++){
        if(listBook[i]->getSeNum() == SE){
            index = i;
            return listBook[i];
        }
    }
    return nullptr;
}
void Library::HelpRemoveBook(std::string SE)
{
    // for(int  i = 0; i < listBook.size(); i++){
    //     if(listBook[i]->getSeNum() == SE){
    //             delete listBook[i];
    //             for(int j = i;j < listBook.size(); j++){
    //                 *listBook[j] = *listBook[j+1];
    //             }
    //             delete listBook[listBook.size() -1];
    //             listBook.resize(listBook.size() -1);
    //             std::cout << "Remove successfully\n";
    //             return;
    //     }
    // }
    int index;
    if(HelpSeachBookSE(SE,index)){
        delete HelpSeachBookSE(SE,index);
        for(int j = index ; j < listBook.size(); j++){
                *listBook[j] = *listBook[j+1];
        }
                delete listBook[listBook.size() -1];
                listBook.resize(listBook.size() -1);
                std::cout << "Remove successfully\n";
                return;
    }
    else{
    std::cout << "The book is not in the list to delete\n";
    }
}
