#include "Member.h"

Member::Member( std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType Medium) 
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
    CollectionList[0]->getBookList().push_back(b);
}
void Member::returnBook(){
    std::cout << "\n\n-------------------\n";
    std::cout << "Enter book's name to return back to library: ";
    std::string bookName;
    std::cin >> bookName;
    if(!CollectionList[0]->getBookList().empty()){
        for(int i = 0; i < CollectionList[0]->getBookList().size(); i++ ){
            if(bookName == CollectionList[0]->getBookList()[i]->getT()){
                delete CollectionList[0]->getBookList()[i];
                for(int j = i ; j < CollectionList[0]->getBookList().size(); j++){
                    *CollectionList[0]->getBookList()[j] = *CollectionList[0]->getBookList()[j+1];
                }
                delete CollectionList[0]->getBookList()[CollectionList[0]->getBookList().size() -1];
                CollectionList[0]->getBookList().resize(CollectionList[0]->getBookList().size() -1);
                std::cout << "return successfully\n";
                return;
            }
        }
        std::cout << "Book not found to return\n";
    }
    else{
        std::cout << "Empty borrow list to return book\n";
    }
    std::cout << "Exit returnBook Mode\n";
    std::cout << "-------------------\n";
}
void Member::subscribeCollection(Collection *BS ){
    CollectionList.push_back(BS);
}
void Member::unSubscribeCollection(){
    std::cout << "Enter Collection's name to unsubscribe: ";
    std::string CN;
    std::cin >> CN;
    if(!CollectionList.empty()){
        for(int i = 1 ; i < CollectionList.size(); i++){
            if(CN == CollectionList[i]->getCoName()){
                CollectionList[i]->~Collection();
                std::cout << "Unsubscribe successfully\n";
                return;
            }
        }
        std::cout << "The Collection is not found\n";
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
void Member::readBook(const Book *b){}

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
