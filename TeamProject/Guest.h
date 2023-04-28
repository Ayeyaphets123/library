#ifndef GUEST_H
#define GUEST_H
#include "Admin.h"
#include "Member.h"
class Guest : public User
{
    private:
        static int countID;
        int ID;
        
    public:
        Guest();
        ~Guest();
        void Register(std::string username,std::string password,std::string phone,std::string fullname);
        void setID(int);
        int getID() const;
        void readBook(const Book *b);
};
#endif