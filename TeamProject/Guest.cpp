#include "Guest.h"
Guest::Guest() : User(){
    setID(countID);
    countID++;
}
Guest::~Guest(){}

Member* Guest::Register()
{
    std::string US, PS, phone, FN;
    std::cout << "Enter Your UserName account: ";
    std::cin >> US;
    std::cout << "Enter Your PassWord account: ";
    std::cin >> PS;
    std::cout << "Enter your phone Number: ";
    std::cin >> phone;
    std::cout << "Enter your fullname: ";
    std::cin >> FN;
    Member * newM = new Member (US,PS,phone,FN);
    std::cout << "Register successfully! Please Login in the Main Menu." << std::endl;
    return newM;
}
void Guest::setID(int id){
    if(id > 0) ID = id;
}
int Guest::getID() const{
    return ID;
}
void Guest::readBook(const Book *b) 
{
    if(b->getVisibilityStatus() == true)
        std::cout << "Guest are allowed to read " << b->getFreePage() << " free pages of this book\n";      
    else
        std::cout << "member are not allowed to read this Book\n";
}
int Guest::countID = 0;