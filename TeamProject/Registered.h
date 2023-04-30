#ifndef RG_H
#define RG_H
#include "User.h"
class Registered : public User
{
    private:
        int ID;
        std::string username;
        std::string password;
        std::string phone;
        std::string fullname;

    public:
        static int userCount;
        Registered(accessibilityType AL) : User(AL), ID(0), username(" "), password(" "), phone(" "), fullname(" "){
            userCount++;
        }
        Registered(std::string U, std::string Pass,std::string Phone , std::string F, accessibilityType AL);
        void setID(int ID);
        void setU(std::string);
        void setPass(std::string);
        void setPhone(std::string);
        void setF(std::string);
        int getId() const;
        std::string getU() const;
        std::string getPhone() const;
        std::string getP() const;
        std::string getF() const;
        void login(int, std::string U, std::string P);
        void logout();   

        virtual void PersonalInformation() = 0;
        
};
#endif