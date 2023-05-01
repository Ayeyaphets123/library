#include "Member.h"

Member::Member(std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType Medium) 
    : Registered(userName,password,phone, fullname, Medium)
{
    setStartYear();
    setEndYear();
    Collection * C = new Collection("Your Borrowed List\n");
    CollectionList.push_back(C);
}

Member::~Member()
{
    if(!CollectionList.empty()){
        for(int i = 0 ; i < CollectionList.size(); i++){
            if(!CollectionList[i]->getBookList().empty()){
                for(int j = 0 ; j < CollectionList[i]->getBookList().size(); j++){
                    if(CollectionList[i]->getBookList()[j])
                        delete CollectionList[i]->getBookList()[j];
                }
            }
            delete CollectionList[i];
        }
    }
    CollectionList.clear();
}

void Member::borrowBook(Book *b)
{
    CollectionList[0]->addBookToCollection(b);
}
std::string Member::returnBook(){
    std::cout << "\n\n-------------------\n";
    std::cout << "Enter book's name to return back to library: ";
    std::string bookName;
    std::cin >> bookName;
    std::string mess = CollectionList[0]->deleteBook(bookName);
    std::cout << "Exit returnBook Mode\n";
    std::cout << "-------------------\n";
    if(mess != "not found"){
        return mess;
    }
    else{
        return "not found";
    }
    
}
void Member::displayBorrowList()
{
    if(!CollectionList[0]->getBookList().empty())
        {
            for(int i = 0 ; i < CollectionList[0]->getBookList().size(); i++){
                std:: cout << CollectionList[0]->getBookList()[i]->getT() << "\n";
            }
        }
    else{
        std::cout << "You have not borrowed any Book\n";
    }
}
void Member::subscribeCollection(Collection *BS)
{
    CollectionList.push_back(BS);
}
void Member::unSubscribeCollection(){
    std::cout << "Enter Collection's name to unsubscribe: ";
    std::string CN;
    std::cin >> CN;
    if(!CollectionList.empty()){
        for(int i = 0 ; i < CollectionList.size(); i++){
            if(CN == CollectionList[i]->getCoName()){
                if(i != CollectionList.size() -1){
                    for(int j = i; j < CollectionList.size() -1 ; j++){
    
                        *CollectionList[j] = *CollectionList[j+1];
                        
                    }
                }
                CollectionList[CollectionList.size() - 1]->~Collection();
                CollectionList.resize(CollectionList.size() - 1);
                std::cout << "Unsubscribe successfully\n";
                return;
        }
    }
        std::cout << "The Collection is not found for unsubscribing \n";
    }
    else{
        std::cout << "You have not subscribe any collection to unsubscribe\n";
    }

}
void Member::displayCollectionList(){
    if(!CollectionList.empty()){
        for(int i = 0 ; i < CollectionList.size(); i++){
            CollectionList[i]->displayCollection();
        }
    }
}
void Member::readBook(const Book *b){
    if(b->getVisibilityStatus() == true)
        std::cout << "Member are reading " << b->getT() << "\n";    
    else{
        std::cout << "Member are not allowed to read this Book\n";
    }
}

void Member::setStartYear()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    startYear = 1900 + ltm->tm_year;
}
void Member::setEndYear()
{
    EndYear = startYear + 1 ;
}
std::vector<Collection *> Member::getCollectionList() const
{
    return CollectionList;
}
void Member::deleteBookInCollection(std::string N)
{   
    std::cout << "\n--------------------------------\n";
    std::cout << "Delete book in CollectionList Member " << getF() << "\n";
    if(!CollectionList.empty()){
            for(int i =0 ;i < CollectionList.size(); i++){
                CollectionList[i]->deleteBook(N);
            }
        }
        else{
            std::cout << "No collection to delete book\n";
        }
    std::cout << "--------------------------------\n";

}
void Member::PersonalInformation()
{
    std::cout << "Member Personal Information\n"
              << "ID: " << getId() << "\n"
              << "Username: " << getU() << "\n"
              << "Password: " << getP() << "\n"
              << "Phone Number: " << getPhone() << "\n"
              << "Start Year: " << startYear << "\n"
              << "EndYear: " << EndYear << "\n";
              
}
void Member::HelpEditCollection(std::string CoName, bool N_signal, bool ID_signal,std::string NewCoName, int newID)
{
    if(!CollectionList.empty()){
        for(int i = 0 ; i < CollectionList.size(); i++){
            if(CoName == CollectionList[i]->getCoName()){
                CollectionList[i]->HelpEdiCollection(N_signal, ID_signal, NewCoName, newID);
            }
        }
    }
}
void Member::HelpEditBook(std::string BookName, bool T_signal, bool A_signal, bool SE_signal, bool P_signal, bool C_signal, bool FP_signal, bool VS_signal, std::string T, std::string A, std::string SE, int P, int C, int FP)
{
    if(!CollectionList.empty()){
        for(int i = 0 ; i < CollectionList.size(); i++){
            CollectionList[i]->HelpEditBook(BookName, T_signal,  A_signal , SE_signal, P_signal , C_signal , FP_signal , VS_signal,  T,  A,  SE,  P,  C,  FP);
        }
    }
    
}

void Member::logout()
{
    std::cout << "Log out from Member\n";
}
