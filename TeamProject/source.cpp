#include <iostream>
#include <string>
#include "Library.cpp"
#include "User.cpp"
#include "Registered.cpp"
#include "Admin.cpp"
#include "Member.cpp"
#include "Guest.cpp"
#include "Book.cpp"
#include "Menu.cpp"
#include "BookCollection.cpp"

enum Action
{      
    Admin_action,
    Member_action,
    Guest_action,
    Out,
    search_Book,
    add_book ,
    remove_book, 
    edit_book,
    create_collection,
    edit_collection,
    delete_Collection,

    read_Book,
    borrow_Book,
    return_Book,
    subscribe_Collection,
    un_Subscribe_Collection,
    display_Collection_List,
    display_Borrowed_List,

    read_free_book,
    become_Member
};


int main()
{   
    Library * lib = new Library();
    Admin * ptr = new Admin("admin123","admin123","0913046458","Lam tan Dai");
    Book * b[3] = {
        new Book("America","123456","lam tan dai",300,10,1,true, false),
        new Book("robot","234567","king",432,10,2,true, false),
        new Book("cooking","345676","queen",200,10,1,true, false)
    };
    // std::cout << "Enter your new book name: ";
    // // std::string BN;
    // // std::string Tittle;
    // //     std::string serialNumber;
    // //     std::string author;
    // //     int pageNumber;
    // //     int freePageReading;
    // //     int category;
    // //     bool visibilityStatus;
    // //     bool borrowedStatus;
    // Book * newB = new Book(x,y,z,);
    // ptr->addBook(lib,newB);


    ptr->addBook(lib,b[0]);
    ptr->addBook(lib,b[1]);
    ptr->addBook(lib,b[2]);


    Member * m[3] = {
        new Member("member1", "member1", "0367995350","hung"),
        new Member("member2", "member2", "0912458718", "long"),
        new Member("member3", "member3", "9785784638", "thinh")
    };

    ptr->addMember(m[0]);
    ptr->addMember(m[1]);
    ptr->addMember(m[2]);
    ptr->createCollection();
    ptr->EditCollection(lib);


    std::string bname = "cooking";
    int index;
    if(lib->HelpSeachBookT(bname,index)){
        if(lib->HelpSeachBookT(bname,index)->getBorrowedStatus() == false){
            m[0]->borrowBook(lib->HelpSeachBookT(bname,index));
            lib->HelpSeachBookT(bname,index)->setBorrowedStatus(true);
            // ...
        }
    } 
    std::string Cname;
    std::cout << "Enter Collection's name to search: ";
    std::cin >> Cname;
        if(ptr->HelpSearchCollection(Cname)){
            m[0]->subscribeCollection(ptr->HelpSearchCollection(Cname));
        }
        else{
            std::cout << "The collection is not found\n";
        }
    m[0]->displayCollectionList();
    ptr->removeBook(lib);
return 0;
}


