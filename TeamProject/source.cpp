#include <iostream>
#include <string>
#include "GlobalVar.cpp"
#include "User.cpp"
#include "Registered.cpp"
#include "Admin.cpp"
#include "Member.cpp"
#include "Guest.cpp"
#include "Book.cpp"


int main()
{
    Admin * ptr = new Admin("admin123","admin123","0913046458","Lam tan Dai");
    Book * b[3] = {
        new Book("america","123456","lam tan dai",300,10,1,true, false),
        new Book("robot","234567","king",432,10,2,true, false),
        new Book("cooking","345676","queen",200,10,1,true, false)

    };
    for(int i = 0 ;i < 3; i++){
        ptr->addBook(b[i]);
    }
    ptr->displayBookList();
    ptr->searchBookSerialNum("123456");
    std::cout << "Enter your ";
    ptr->addMember("member123","admin123","00000000","Le quang anh");
    ptr->addMember("member123","admin123","00000000","Le quang anh");
return 0;
}
