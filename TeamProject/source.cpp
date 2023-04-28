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
    ptr->addBook(lib,b[0]);
    ptr->addBook(lib,b[1]);
    ptr->addBook(lib,b[2]);
    ptr->displayBookList(lib);
    ptr->createCollection();
    ptr->EditCollection(lib);
    ptr->displayCollectionList();
return 0;
}


