#include <iostream>
#include "Admin.h"
#include <cstring>
Admin::~Admin(){
    listBook.clear();
    listCollection.clear(); 
}
Admin::Admin(std::string userName, std::string password, std::string phone, std::string fullname,accessibilityType AL )
    :  Registered(userName,password,phone,fullname,AL){}
void Admin::addBook( Book *b){
    listBook.push_back(b);
}
void Admin::removeBook( Book *b) {
   try{
    if(listBook.empty())
        throw"Empty list to delete";
    else{
        for(int i = 0 ; i < listBook.size(); i++){
            if(listBook[i]->getSeNum() == b->getSeNum()){
                listBook.erase(listBook.begin() + i);
                for(int j = i;j < listBook.size(); j++){
                    listBook[j] = listBook[j+1];
                }
                listBook[listBook.size()] = nullptr;
                std::cout << "Remove successfully\n";
                return;
            }

        }
    }
   }
   catch (const char *error){
        std::cout << "Error!\n" <<  error << "\n";
   }
}
void Admin::EditBook(std::string SE){
    try{
    if(listBook.empty())
        throw"Empty list to delete";
        
    else{
        for(int i = 0 ; i < listBook.size(); i++){
            if(listBook[i]->getSeNum() == SE){
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
                while(!exitMenu)
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
                        listBook[i]->setTittle(T);
                        break;
                    }
                    case 2:
                    {
                        std::string SE;
                        std::cout << "New serial number: ";
                        getline(std::cin, SE);
                        listBook[i]->setSerialNum(SE);
                        break;
                    }
                    case 3:
                    {
                        std::string a;
                        std::cout << "New author: ";
                        getline(std::cin, a);
                        listBook[i]->setAuthor(a);
                        break;
                    }
                    case 4:
                    {
                        int p;
                        std::cout << "New page number: ";
                        std::cin >> p;
                        listBook[i]->setPageNum(p);
                        break;
                    }
                    case 5:
                    {
                        int fp;
                        std::cout << "New free page number: ";
                        std::cin >> fp;
                        listBook[i]->setFreePage(fp);
                        break;
                    }
                    case 6:
                    {
                        int c;
                        std::cout << "New category: ";
                        std::cin >> c;
                        listBook[i]->setCategory(c);
                        break;
                    }
                    case 7:
                    {
                        if(listBook[i]->getVisibilityStatus() == true) {
                            std::cout << "Current VisibilityStatus: " << listBook[i]->getVisibilityStatus()<< "\n";
                            listBook[i]->setVisibilityStatus(false);
                        }
                        else {
                            listBook[i]->setVisibilityStatus(true);
                            std::cout << "New VisibilityStatus: " << listBook[i]->getVisibilityStatus()<< "\n";
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
void Admin::EditCollection(Collection *c)
{
    
}
void Admin::createCollection(Book b)
{
}
void Admin::deleteCollection(Collection *c){

}
void Admin::readBook(const Book &b){}
void Admin::displayBookList(){
    if(listBook.empty()){
        std::cout << "Empty list\n";
    }
    else{
        for(int i = 0 ;i < listBook.size(); i++){
            listBook[i]->display();
        }
    }
}
bool Admin::checkMemberExist(std::string username)
{
    for (int i = 0; i < MemberList.size(); i++) {
        if ( MemberList[i]->getU() == username){
            return true;
        }
    }
    return false;
}
void Admin::addMember(std::string username, std::string password, std::string phone, std::string fullname)
{
    if (checkMemberExist(username)) {
        std::cout << "Error: Member with username " << username << " already exists." << std::endl;
        return;
    }

    Member* newMember = new Member(username, password, phone, fullname);
    MemberList.push_back(newMember);
    std::cout << "New member with ID " << userCount << " has been added." << std::endl;
}
std::vector<Collection *> Admin::listCollection{};
std::vector <Member *> Admin::MemberList{};


