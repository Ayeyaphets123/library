#include "Guest.h"
Guest::Guest() : User(){
    setID(countID);
    countID++;
}
Guest::~Guest(){}

void Guest::Register( std::string username, std::string password, std::string phone, std::string fullname)
{
    
}
void Guest::setID(int id){
    if(id > 0) ID = id;
}
int Guest::getID() const{
    return ID;
}
void Guest::readBook(const Book *b) 
{

}
int Guest::countID = 0;