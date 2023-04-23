#include "User.h"
#include "Member.h"
#ifndef GUEST_H
#define GUEST_H
class Guest : public User
{
    private:
        static int countID;
        int ID;
    public:
        Guest();
        ~Guest(){}
        void Register(int ID,std::string username,std::string password,std::string phone,std::string fullname);
        void setID(int);
        int getID() const;
        void readBook(const Book &b) ;
};
#endif