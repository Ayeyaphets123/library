#include <iostream>
#include "Admin.h"
#include <cstring>
Admin::~Admin(){
    
    // delete BookList in library
    for(int i = 0 ;i <listCollection.size(); i++){
        if(listCollection[i]) 
            for(int j = 0 ; j < listCollection[i]->getBookList().size(); i++){
                if(listCollection[i]->getBookList()[j]) 
                    delete listCollection[i]->getBookList()[j];
            }
        delete listCollection[i];
    }
        listCollection.clear();

    for(int i = 0 ;i <MemberList.size(); i++){

        // if(!MemberList[i]){ 
        //     for(int j = 0 ; j < MemberList[i]->getBorrowedBookList().size(); j++){
        //         if(MemberList[i]->getBorrowedBookList()[j])
        //             delete MemberList[i]->getBorrowedBookList()[j];
        //     }
        //     //delete BookList in Collection -> delete the collection -> delete Member has the collections
        //     for(int j = 0 ; j < MemberList[i]->getSubscribedCollectionList().size(); j++){
        //         if( MemberList[i]->getSubscribedCollectionList()[j]){
        //             for(int k = 0 ; k < MemberList[i]->getSubscribedCollectionList()[j]->getBookList().size() ;k++){
        //                 if(MemberList[i]->getSubscribedCollectionList()[j]->getBookList()[k])
        //                     delete MemberList[i]->getSubscribedCollectionList()[j]->getBookList()[k];
        //             }
        //         }
        //         delete MemberList[i]->getSubscribedCollectionList()[j];
        //     }
        // }
        // delete MemberList[i];
        MemberList[i]->~Member();
    }
    MemberList.clear();
}
Admin* Admin::CreatAdmin()
{   
    std::cout << "Username: ";
    std::string u;
    getline(std::cin,u);
    std::cout << "\n";
    std::cout << "Password: ";
    std::string p;
    getline(std::cin,p);
    std::cout << "Phone: ";
    std::string phone;
    getline(std::cin,phone);
    std::cout << "Full name: ";
    std::string fn;
    getline(std::cin, fn);
    Admin * newAd = new Admin(u,p,phone,fn);
    std::cout << "Create new Admin account successfully\n";
    return newAd;
}
Admin::Admin(std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType AL)
    : Registered(userName, password, phone, fullname, AL) {}

void Admin::addBook(Library *lib, Book *b){
    lib->listBook.push_back(b);
    std::cout << "Add book successfully\n";
}

void Admin::removeBook(Library *lib) {
   try{
    if(lib->listBook.empty())
        throw"Empty list to delete";
    else{
        std::cout << "Book's name to search: ";
        std::string BN;
        getline(std::cin,BN);

        lib->HelpRemoveBook(BN);

        for(int i =0 ;i < listCollection.size(); i++){
            listCollection[i]->deleteBook(BN);
        }

        for(int i = 0 ; i < MemberList.size(); i++){
            MemberList[i]->deleteBookInBorrowList(BN);
            MemberList[i]->deleteBookInSubscribedCollection(BN);
        }
    }
    }
    catch (const char *error){
        std::cout << "Error!\n" <<  error << "\n";
    }
}
void Admin::EditBook(Library *lib,std::string SE){
    try{
    if(lib->listBook.empty())
        throw"Empty list to delete";
        
    else{
        for(int i = 0 ; i < lib->listBook.size(); i++){
            if(lib->listBook[i]->getSeNum() == SE){
                std::cout << "Edit Menu\n";
                std::cout << "1.Tittle\n";
                std::cout << "2.SerialNumber\n";
                std::cout << "3.Author\n";
                std::cout << "4.PageNumber\n";
                std::cout << "5.FreePageReading\n";
                std::cout << "6.Category\n"
                          << "7.visibilityStatus\n"
                          << "8.Exit Edit Mode\n";
            bool exitMenu = false;          
                while(exitMenu)
                {
                std::cout << "Choose option: ";
                int option;
                std::cin >> option;

                try{
                if(std::cin.fail()){
                        throw "Invalid input";
                }
                else if(option < 0 || option > 8){
                    throw "Menu out of range";
                }
                else{
                    switch(option){
                    {
                    case 1:
                        std::string T;
                        std::cout << "New Title: ";
                        getline(std::cin, T);
                        lib->listBook[i]->setTittle(T);
                        break;
                    }
                    case 2:
                    {
                        std::string SE;
                        std::cout << "New serial number: ";
                        getline(std::cin, SE);
                        lib->listBook[i]->setSerialNum(SE);
                        break;
                    }
                    case 3:
                    {
                        std::string a;
                        std::cout << "New author: ";
                        getline(std::cin, a);
                        lib->listBook[i]->setAuthor(a);
                        break;
                    }
                    case 4:
                    {
                        int p;
                        std::cout << "New page number: ";
                        std::cin >> p;
                        lib->listBook[i]->setPageNum(p);
                        break;
                    }
                    case 5:
                    {
                        int fp;
                        std::cout << "New free page number: ";
                        std::cin >> fp;
                        lib->listBook[i]->setFreePage(fp);
                        break;
                    }
                    case 6:
                    {
                        int c;
                        std::cout << "New category: ";
                        std::cin >> c;
                        lib->listBook[i]->setCategory(c);
                        break;
                    }
                    case 7:
                    {
                        if(lib->listBook[i]->getVisibilityStatus() == true) {
                            std::cout << "Current VisibilityStatus: " << lib->listBook[i]->getVisibilityStatus()<< "\n";
                            lib->listBook[i]->setVisibilityStatus(false);
                        }
                        else {
                            lib->listBook[i]->setVisibilityStatus(true);
                            std::cout << "New VisibilityStatus: " << lib->listBook[i]->getVisibilityStatus()<< "\n";
                        }
                        break; 
                    }
                    case 8:
                    {   
                        std::cout << "Back to main menu\n";
                        exitMenu = true;
                    }
                    }
                }
                }
                catch(const char * invalid){
                    std::cout << "Error: " << invalid << "\n";
                }
                }
            return ;
            }
        }
    }
    }
    catch (const char *error){
        std::cout << "Error!\n" <<  error << "\n";
   }
}
void Admin::EditCollection(Library *lib)
{   
    std::cout << "Search for your collection needed to edit\n";
    std::cout << "Enter collection's name to delete: \n";
    std::string name;
    getline(std::cin, name);
    for(int i = 0 ; i < listCollection.size(); i++)
    {
        if(listCollection[i]->getCoName() == name){
            std::cout << "Edit Menu: \n"
                      << "1.ID\n"
                      << "2.Name\n"
                      << "3.Add new book\n"
                      << "4.Remove book\n"
                      << "5.Exit\n";
            bool out = false;
            while(out){
                int option;
                std::cout << "Choose option: ";
                std::cin >> option;
                try{
                    if(option < 1 || option > 5){
                        throw " Option is out of range\n";
                    }
                    else if(std::cin.fail()){
                        throw "Invalid input\n";
                    }
                    else{
                        switch (option)
                        {
                        {case 1:
                            int id;
                            std::cout << "New Co's Id: ";
                            std::cin >> id;
                            listCollection[i]->setCoID(id);
                            break;
                        }
                        {case 2:
                            std::string newN;
                            std::cout << "New Co's name: ";
                            getline(std::cin, newN);
                            listCollection[i]->setCoName(newN);
                            break;
                        }
                        {case 3:
                            std::cout << "Enter name of book you want to add: ";
                            std::string bookName;
                            
                            
                        }
                        }
                    }
                }
                catch(const char * err){
                    std::cout << "Error: " << err << "\n";
                }
            }
        }
        else{
            std::cout << "The collection to be edited is not found\n";
        }
    }
    
}
void Admin::createCollection()
{
    std::cout << "Enter Collection's name: ";
    std::string name;
    getline(std::cin, name);
    Collection * C = new Collection(name);
    listCollection.push_back(C);
}
void Admin::deleteCollection(){
    std::cout << "Enter Collection's name to delete: ";
    std::string name;
    getline(std::cin, name);
    for(int i = 0 ; i < listCollection.size(); i++){
        if(name == listCollection[i]->getCoName()){
            if(!listCollection[i]->getBookList().empty()){
                for(int j = 0 ; j < listCollection[i]->getBookList().size(); j++){
                    if(listCollection[i]->getBookList()[j])
                        delete listCollection[i]->getBookList()[j];
                }
            }
            listCollection[i]->getBookList().clear();
    
        }
    }
}
void Admin::readBook(const Book *b){
}
void Admin::displayBookList(Library *lib){
    if(!lib->listBook.empty()){
        std::cout << "Empty list\n";
    
        for(int i = 0 ;i < lib->listBook.size(); i++){
            lib->listBook[i]->display();
        }
    }
}
std::vector <Member *> Admin::MemberList{};
std::vector <Collection *> Admin::listCollection{};


