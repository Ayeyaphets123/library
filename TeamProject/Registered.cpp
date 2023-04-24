#include "Registered.h"
#include <iostream>

Registered::Registered(int ID, std::string U, std::string Pass, std::string Phone, std::string F, accessibilityType AL) : User(AL)
{
    setID(ID);
    setU(U);
    setPass(Pass);
    setPhone(Phone);
    setF(F);
    userCount++;
}
void Registered::setID(int ID){
    if(ID > 0) this->ID = ID;
}
void Registered::setU(std::string U){
    username = U;
}
void Registered::setPass(std::string P){
    password = P;
}
void Registered::setPhone(std::string P){
    phone = P;
}
void Registered::setF(std::string F){
    fullname = F;
}
int Registered::getId() const{
    return ID;
}
std::string Registered::getU() const{
    return username;
}
std::string Registered::getPhone() const{
    return phone;
}
std::string Registered:: getP() const{
    return password;
}
std::string Registered::getF() const{
    return fullname;
}
void Registered::login(int lv, std::string user, std::string pass){
    
    
}
void Registered::logout(){

} 
int Registered::userCount =0;