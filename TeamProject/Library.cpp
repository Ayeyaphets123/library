#include "Library.h"
Library::~Library(){
    if(!listBook.empty()){
        for(int i = 0 ; i < listBook.size(); i++){
            if(listBook[i])
                delete listBook[i];
        }
        }
    listBook.clear();
}
void Library::searchBookTittle()
{   
    int index;
    std::cout << "Enter book Tittle to search: ";
    std::string T;
    std::cin>>T;
    if(HelpSeachBookT(T,index)){
        HelpSeachBookT(T,index)->display();
    }
    else{
        std::cout << "Book " << T << " not found\n";
    }

}
Book *Library::HelpSeachBookSE(std::string SE)
{
    if(!listBook.empty()){
        for(int  i = 0; i < listBook.size(); i++){
            if(listBook[i]->getSeNum() == SE){
                Book * b = new Book();
                *b = *listBook[i];
                return b;
            }
        }
    }
    return nullptr;
}
void Library::searchBookSerialNum()
{   
    std::cout << "Enter book Serial Number to search: ";
    std::string SE;
    std::cin>>SE;
    if(HelpSeachBookSE(SE)){
        HelpSeachBookSE(SE)->display();
    }
    else{
        std::cout << "Book " << SE << " not found\n";
    }
}
void Library::displayListBook()
{
    if(!listBook.empty()){
        for(int i = 0 ;i < listBook.size(); i++){
            listBook[i]->display();
        }
    }
    else{
        std::cout << "Library is empty\n";
    }
}
Book *Library::HelpSeachBookT(std::string name, int &index)
{
    if(!listBook.empty()){
        for(int  i = 0; i < listBook.size(); i++){
            if(listBook[i]->getT() == name){
                index = i;
                listBook[i];
                return listBook[i];
            }
        }
    }
    return nullptr;
}
void Library::HelpRemoveBookInLibrary(std::string T)
{
    int index;
    if(HelpSeachBookT(T,index)){
        if(index != listBook.size() -1){
        for(int j = index ; j < listBook.size()-1 ; j++){
                *listBook[j] = *listBook[j+1];
        }
        }
        delete listBook[listBook.size() -1];
        listBook.resize(listBook.size() -1);
        std::cout << "Remove successfully in list library\n";
        return;
    }
    else{
    std::cout << "The book is not in the list to delete\n";
    }
    
    
}
