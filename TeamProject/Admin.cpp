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
        std::cin.ignore();
        std::cout << "Book's name to search: ";
        std::string BN;
        getline(std::cin,BN);

        // delete in library
        lib->HelpRemoveBookInLibrary(BN);
        // delete in listCollection in Admin
        if(!listCollection.empty()){
            for(int i =0 ;i < listCollection.size(); i++){
                listCollection[i]->deleteBook(BN);
            }
        }

        // delete in MemberList
        if(!MemberList.empty()){
        for(int i = 0 ; i < MemberList.size(); i++){
            MemberList[i]->deleteBookInCollection(BN);
        }
    }
    }
    }
    catch (const char *error){
        std::cout << "Error!\n" <<  error << "\n";
    }
}
void Admin::EditBook(Library *lib){
    try{
    if(lib->listBook.empty())
        throw"Empty list to delete";
        
    else{
        std::string BN;
        std::cout << "Enter book's name to edit: \n";
        std::cin >> BN;
        if(!lib->listBook.empty()){
        for(int i = 0 ; i < lib->listBook.size(); i++){
            if(lib->listBook[i]->getT() == BN){
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
            bool T_signal = false;
            bool SE_signal = false;
            bool A_signal = false;
            bool P_signal = false;
            bool FP_signal = false;
            bool C_signal = false;
            bool VS_signal = false;
            std::string T;
            std::string SE;
            std::string A;
            int P;
            int FP;
            int C;
                while(exitMenu == false)
                {
                std::cout << "Choose option: ";
                int option;
                std::cin >> option;
                std::cin.ignore();
                try{
                if(std::cin.fail()){
                        throw "Invalid input";
                }
                else if(option < 0 || option > 8){
                    throw "Menu out of range";
                }
                else{
                    switch(option){
                    {case 1:
                    
                        std::cout << "New Title: ";
                        getline(std::cin, T);
                        lib->listBook[i]->setTittle(T);
                        T_signal = true;
                        break;
                    }
                    case 2:
                    {
                        
                        std::cout << "New serial number: ";
                        getline(std::cin, SE);
                        lib->listBook[i]->setSerialNum(SE);
                        SE_signal = true;
                        break;
                    }
                    case 3:
                    {
                        std::cout << "New author: ";
                        getline(std::cin, A);
                        lib->listBook[i]->setAuthor(A);
                        A_signal = true;
                        break;
                    }
                    case 4:
                    {
                        std::cout << "New page number: ";
                        std::cin >> P;
                        std::cin.ignore();
                        lib->listBook[i]->setPageNum(P);
                        P_signal = true;
                        break;
                    }
                    case 5:
                    {
                        std::cout << "New free page number: ";
                        std::cin >> FP;
                        std::cin.ignore();
                        lib->listBook[i]->setFreePage(FP);
                        FP_signal = true;
                        break;
                    }
                    case 6:
                    {
                        
                        std::cout << "New category: ";
                        std::cin >> C;
                        std::cin.ignore();
                        lib->listBook[i]->setCategory(C);
                        C_signal = true;
                        break;
                    }
                    case 7:
                    {   
                        std::cout << "Current VisibilityStatus: ";
                        if(lib->listBook[i]->getVisibilityStatus()){
                            std::cout << "Available to watch\n";
                            lib->listBook[i]->setVisibilityStatus(false);
                        }
                        else {
                            std::cout << "This book is hided\n";
                            lib->listBook[i]->setVisibilityStatus(true);
                        }

                        std::cout << "New VisibilityStatus: ";

                        if(lib->listBook[i]->getVisibilityStatus()){
                            std::cout << "Available to watch\n";
                        }
                        else {
                            std::cout << "This book is hided\n";
                        }
                        VS_signal = true;
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
            if(!listCollection.empty()){
                for(int i = 0 ;i < listCollection.size(); i++){
                    if(!listCollection[i]->getBookList().empty()){
                        for(int k = 0 ; k < listCollection[i]->getBookList().size(); k++){
                            if(BN == listCollection[i]->getBookList()[k]->getT()){
                                
                            }
                        }
                    }
                }
            }
            if(!MemberList.empty()){
                for(int  i = 0 ; i < MemberList.size(); i++){
                    MemberList[i]->HelpEditBook(BN,T_signal ,A_signal ,SE_signal ,P_signal ,C_signal ,FP_signal ,VS_signal ,T, A, SE, P, C, FP);
                }   
            }
            exitMenu = false;  
            T_signal = false;
            SE_signal = false;
            A_signal = false;
            P_signal = false;
            FP_signal = false;
            C_signal = false; 
            VS_signal = false;
            return ;
            }
        }
    }
    else{
        std::cout << "The collection is not found\n";
    }
    }
    }
    catch (const char *error){
        std::cout << "Error!\n" <<  error << "\n";
   }
}
void Admin::EditCollection(Library *lib)
{   
    
    std::cout << "\n\n------------------------\n";
    std::cout << "EditCollection Mode\n";
    std::cout << "Enter collection's name to edit: ";
    std::string name;
    std::cin >> name;
    if(!listCollection.empty()){
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
            bool Name_signal = false;
            bool ID_signal = false;
            int id;
            std::string newN;
            std::string AddBookName;
            std::string DeleteBookName;
            while(out == false){
                int option;
                std::cout << "Choose option: ";
                std::cin >> option;
                std::cin.ignore();
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
                            std::cout << "New Co's Id: ";
                            std::cin >> id;
                            std::cin.ignore();
                            listCollection[i]->setCoID(id);
                            ID_signal = true;
                            break;
                        }
                        {case 2:
                            std::cout << "New Co's name: ";
                            std::cin.ignore();
                            getline(std::cin, newN);
                            listCollection[i]->setCoName(newN);
                            Name_signal = true;
                            break;
                        }
                        {case 3:
                            // struggle facing to book not found
                            std::cout << "Enter name of book you want to add into the Collection: ";
                            std::cin >> AddBookName;
                            int index;
                            // if(lib->HelpSeachBookT(bookName)!= nullptr){
                                if(!listCollection[i]->getBookList().empty()){
                                    listCollection[i]->displayCollection();
                                }
                                Book *b = new Book();
                                *b = *lib->HelpSeachBookT(AddBookName,index);
                                if( b != nullptr){
                                    listCollection[i]->addBookToCollection(b);
                                    std::cout << "Add book successfully in the Collection\n";
                                    if(!MemberList.empty()){
                                        for(int i = 0 ; i < MemberList.size(); i++){
                                            if(!MemberList[i]->getCollectionList().empty()){
                                                for(int j = 0 ; j < MemberList[i]->getCollectionList().size(); j++){
                                                    if(listCollection[i]->getCoName() == MemberList[i]->getCollectionList()[j]->getCoName()){
                                                        MemberList[i]->getCollectionList()[j]->addBookToCollection(b);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else{
                                    std::cout << "Book not found to add into the Collection\n";
                                }
                                if(!listCollection[i]->getBookList().empty()){
                                    listCollection[i]->displayCollection();
                                }
                            break;
                        }
                        {
                        case 4:
                            if(!listCollection[i]->getBookList().empty()){
                                listCollection[i]->displayCollection();
                                std::cout << "Enter name of book you want to delete: ";
                                std::cin >> DeleteBookName;
                                listCollection[i]->deleteBook(DeleteBookName);
                                listCollection[i]->displayCollection();
                                if(!MemberList.empty()){
                                    for(int i = 0 ;i < MemberList.size(); i++){
                                        if(!MemberList[i]->getCollectionList().empty()){
                                            for(int j = 0 ; j < MemberList[i]->getCollectionList().size(); j++){
                                                if(listCollection[i]->getCoName() == MemberList[i]->getCollectionList()[j]->getCoName()){
                                                    MemberList[i]->getCollectionList()[j]->deleteBook(listCollection[i]->getCoName());
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else{
                                std::cout << "This Collection has no Book to delete\n";
                            }
                            break;
                        }
                        {
                            case 5:
                                std::cout << "Exit Edit Collection Mode\n";
                                out = true;
                                break;

                        }
                        }
                    }
                }
                catch(const char * err){
                    std::cout << "Error: " << err << "\n";
                }
            }
        if(!MemberList.empty()){
            for(int i = 0 ; i < MemberList.size(); i++){
                if(!MemberList[i]->getCollectionList().empty()){
                    for(int j = 0 ; j <MemberList[i]->getCollectionList().size(); j++){
                        if(listCollection[i]->getCoName() == MemberList[i]->getCollectionList()[j]->getCoName()){
                            MemberList[i]->getCollectionList()[j]->HelpEdiCollection(Name_signal, ID_signal, newN, id);

                        }
                    }
                }
            }
        }
        }
    }
    }
    else{
        std::cout << "No Collection to edit\n";
    }
    std::cout << "------------------------\n";
    
}
void Admin::createCollection()
{   
    
    std::cout << "\n\n------------------------\n";
    std::cout << "CreateCollection Mode\n";
    std::cout << "Enter Collection's name: ";
    std::string name;
    std::cin >> name;
    Collection * C = new Collection(name);
    listCollection.push_back(C);
    std::cout << "Exit CreateCollection Mode\n";
    std::cout << "------------------------\n\n";

}
void Admin::deleteCollection(){
    
    std::cout << "\n\n------------------------\n";
    std::cout << "deleteCollection Mode\n";
    std::cout << "Enter Collection's name to delete: ";
    std::string name;
    std::cin >> name;
    if(!listCollection.empty()){
        for(int i = 0 ; i < listCollection.size(); i++){
            if(name == listCollection[i]->getCoName()){
                listCollection[i]->~Collection();
                std::cout << "Delete Collection successfully\n";
                return;
        }
        std::cout << "Delete collection successfully\n";
    }
    }
    else{
        std::cout << "Empty list collection to delete\n";
    }
    std::cout << "Exit deleteCollection Mode\n";
    std::cout << "------------------------\n\n";

}
void Admin::readBook(const Book *b){}

void Admin::displayCollectionList()
{   
    if(!listCollection.empty()){
        for(int  i = 0 ; i < listCollection.size(); i++){
            listCollection[i]->displayCollection();
        }
    }
    else{
        std::cout << "No Collection to display\n";
    }
   
}
void Admin::showListMember()
{
    if(!MemberList.empty()){
        for(int i = 0 ;i < MemberList.size(); i++){
            MemberList[i]->PersonalInformation();
            MemberList[i]->displayCollectionList();
        }
    }
    else{
        std::cout << "Member list is empty\n";
    }
}

Collection *Admin::HelpSearchCollection(std::string N)
{
    if(!listCollection.empty()){
        for(int i = 0 ; i < listCollection.size(); i++){
            if(N == listCollection[i]->getCoName()){
                return listCollection[i];
            }
        }
    }
    else{
        return nullptr;
    }
}

void Admin::PersonalInformation()
{

}

void Admin::logout()
{
    std::cout << "Log out from Admin\n";
}

void Admin::addMember(Member * m)
{
    MemberList.push_back(m);
}

std::vector<Member *> Admin::MemberList{};
std::vector <Collection *> Admin::listCollection{};
std::vector <Member *> Admin::getMemberList() const{
    return MemberList;
}
std::vector <Collection *> Admin::getCollectionList() const{
    return listCollection;
}

