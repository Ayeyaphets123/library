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
using namespace std;
int main()
{   

    Library * lib = new Library();
    Admin * ptr = new Admin("admin123","admin123","0913046458","Lam tan Dai");
    Book * b[10] = {
        new Book("America","123456","lam tan dai",300,10,1,true,false),
        new Book("robot","234567","king",432,10,2,true, false),
        new Book("cooking","345676","queen",200,10,1,true, false),
        new Book("card","345676","queen",200,10,1,true, false),
        new Book("computer","345676","queen",200,10,1,true, false),
        new Book("plastic","345676","queen",200,10,1,true, false),
        new Book("ocean","345676","queen",200,10,1,true, false),
        new Book("building","345676","queen",200,10,1,true, false),
        new Book("animal","345676","queen",200,10,1,true, false),
        new Book("electricity","345676","queen",200,10,1,true, false),
    };
    for(int i = 0 ; i < 10; i++){
        ptr->addBook(lib,b[i]);
    }

    // Collection* sampleCollection = new Collection("Sample Book Collection");
    // sampleCollection->addBookToCollection(b[0]);
    // sampleCollection->addBookToCollection(b[1]);
    // sampleCollection->addBookToCollection(b[2]);

    Collection * C[3] = {
        new Collection("C1"),
        new Collection("C2"),
        new Collection("C3")
       
    };
    for(int i = 0 ; i < 3; i++){
        Book *NB1 = new Book();
        *NB1 = *b[i];
        C[i]->addBookToCollection(NB1);
        Book *NB2 = new Book();
        *NB2 = *b[i+1];
        C[i]->addBookToCollection(NB2);
    }
    // ptr->addCollection(sampleCollection);
    for(int i = 0 ; i < 3; i++){
        ptr->addCollection(C[i]);
    }

    // std::cout << "list Collection size: " << ptr->getCollectionList().size() << "\n";
    Guest* guest = new Guest();
    Member * m[1] = {
        new Member("member1", "member1", "0367995350","hung"),
        
    };

    ptr->addMember(m[0]);
    // ptr->createCollection();
    // ptr->EditCollection(lib);

    // std::string bookBorrowed;
    // std::cout << "Enter Book to borrowed ";
    // std::cin >> bookBorrowed;
    // int index;
    // if(lib->HelpSeachBookT(bookBorrowed,index)){
    //     if(lib->HelpSeachBookT(bookBorrowed,index)->getBorrowedStatus() == false){
    //         m[0]->borrowBook(lib->HelpSeachBookT(bookBorrowed,index));
    //         lib->HelpSeachBookT(bookBorrowed,index)->setBorrowedStatus(true);
    //         // ...
    //     }
    //     else{
    //         std::cout << "This book has been borrowed\n";
    //     }
    // } 
    // else{
    //     std::cout << "the Book is not found\n";
    // }
    // m[0]->displayCollectionList();
    // std::cout << "Enter Book to borrowed ";
    // std::cin >> bookBorrowed;
    // if(lib->HelpSeachBookT(bookBorrowed,index)){
    //     if(lib->HelpSeachBookT(bookBorrowed,index)->getBorrowedStatus() == false){
    //         m[1]->borrowBook(lib->HelpSeachBookT(bookBorrowed,index));
    //         lib->HelpSeachBookT(bookBorrowed,index)->setBorrowedStatus(true);
    //         // ...
    //     }
    //     else{
    //         std::cout << "This book has been borrowed\n";
    //     }
    // } 
    // else{
    //     std::cout << "the Book is not found\n";
    // }
    
    // std::cout << "Enter Collection's name to search: ";
    // std::cin >> Cname;
    //     if(ptr->HelpSearchCollection(Cname)){
    //         m[1]->subscribeCollection(ptr->HelpSearchCollection(Cname));
    //     }
    //     else{
    //         std::cout << "The collection is not found\n";
    //     }
         
    // std::cout << "Enter Collection's name to search: ";
    // std::cin >> Cname;
    //     if(ptr->HelpSearchCollection(Cname)){
    //         m[2]->subscribeCollection(ptr->HelpSearchCollection(Cname));
    //     }
    //     else{
    //         std::cout << "The collection is not found\n";
    //     }

    // lib->displayListBook();
    // ptr->EditCollection(lib);
    // ptr->EditCollection(lib);
    // ptr->EditCollection(lib);
    // ptr->showListMember();
    // ptr->displayCollectionList(ptr->getAccessibilityLevel());
    

    bool quit = false;
    while (!quit) {
        system("cls");
        cout << "Main menu" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Member" << endl;
        cout << "3. Guest" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
            switch(choice){
            case 1:
            {   
                system("cls");
                ptr->login();
                system("cls");
                bool adminQuit = false;
                while (!adminQuit) {
                    
                    cout << "Admin Menu" << endl;
                    cout << "1. BOOK" << endl;
                    cout << "2. COLLECTION" << endl;
                    cout << "3. MEMBER" << endl;
                    cout << "4. ADMIN" << endl;
                    cout << "5. LOG OUT" << endl;

                    int adminChoice;
                    cout << "Enter your choice: ";
                    cin >> adminChoice;
                    switch(adminChoice){
                        case 1:
                        {  
                            bool bookChoice = false;
                            while (!bookChoice){
                                cout << "1. Display Library Book" << endl;
                                cout << "2. Add Book" << endl;
                                cout << "3. Remove Book" << endl;
                                cout << "4. Edit Book" << endl;
                                cout << "5. Exit" << endl;

                                int BC;
                                cout << "Enter your choice: ";
                                cin >> BC;
                        
                                switch(BC){
                                    case 1:
                                    {
                                        system("cls");
                                        lib->displayListBook();
                                        break;
                                    }
                                    case 2:
                                    {
                                        system("cls");
                                        string BN, title, serialNumber, author;
                                        int pageNumber, freePageReading, category;
                                        bool visibilityStatus, borrowedStatus;

                                        cin.ignore();
                                        cout << "Enter book title: ";
                                        getline(cin, title);

                                        cout << "Enter book serial number: ";
                                        getline(cin, serialNumber);

                                        cout << "Enter book author: ";
                                        getline(cin, author);

                                        cout << "Enter number of pages: ";
                                        cin >> pageNumber;

                                        cout << "Enter number of free pages for reading: ";
                                        cin >> freePageReading;

                                        cout << "Enter book category (1 for Culture, 2 for Science, 3 for Fiction ): ";
                                        cin >> category;

                                        cout << "Enter visibility status (0 for hidden, 1 for visible): ";
                                        cin >> visibilityStatus;

                                        cout << "Enter borrowed status (0 for not borrowed, 1 for borrowed): ";
                                        cin >> borrowedStatus;

                                        Book * newB = new Book(title,serialNumber,author,pageNumber,freePageReading,category,visibilityStatus,borrowedStatus);
                                        ptr->addBook(lib,newB);
                                        break;
                                    }
                                    case 3: 
                                    {
                                        system("cls");
                                        ptr->removeBook(lib);
                                        break;
                                    }
                                    case 4:
                                    {
                                        system("cls");
                                        ptr->EditBook(lib);
                                        break;
                                    }
                                    case 5:
                                    {
                                        bookChoice = true;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            bool collectionChoice = false;
                            while (!collectionChoice){
                                cout << "1. Display Collection List" << endl;
                                cout << "2. Create Collection" << endl;
                                cout << "3. Edit Collection" << endl;
                                cout << "4. Delete Collection" << endl;
                                cout << "5. Exit" << endl;

                                int CC;
                                cout << "Enter your choice: ";
                                cin >> CC;

                                switch(CC){
                                    case 1:
                                    {
                                        system("cls");
                                        ptr->displayCollectionList(ptr->getAccessibilityLevel());
                                        break;
                                    }
                                    case 2:
                                    {
                                        system("cls");
                                        ptr->createCollection();
                                        break;
                                    }
                                    case 3: 
                                    {
                                        system("cls");
                                        ptr->EditCollection(lib);
                                        break;
                                    }
                                    case 4:
                                    {
                                        system("cls");
                                        ptr->deleteCollection();
                                        break;
                                    }
                                    case 5:
                                    {
                                        collectionChoice = true;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            bool memberChoice = false;
                            while (!memberChoice){
                                cout << "1. Display Member List" << endl;
                                cout << "2. Exit" << endl;

                                int MC;
                                cout << "Enter your choice: ";
                                cin >> MC;

                                switch(MC){
                                    case 1:
                                    {
                                        system("cls");
                                        ptr->showListMember();
                                        break;
                                    }
                                    case 2:
                                    {
                                        memberChoice = true;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                           bool adminChoice = false;
                            while (!adminChoice){
                                cout << "1. Create Admin" << endl;
                                cout << "2. Exit" << endl;

                                int AC;
                                cout << "Enter your choice: ";
                                cin >> AC;

                                switch(AC){
                                    case 1:
                                    {
                                        system("cls");
                                        ptr->CreatAdmin();
                                        break;
                                    }
                                    case 2:
                                    {
                                        adminChoice = true;
                                        break;
                                    }
                                    default:
                                    {
                                        cout << "Invalid Choice!" << endl;
                                        break;
                                    }
                                }
                            }
                            break;  
                        }
                        case 5:
                        {
                            ptr->logout();
                            adminQuit = true;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid Choice!" << endl;
                            break;
                        }
                    }
                    }    
                break;
            }
            case 2:
                {
                system("cls");
                ptr->login();
                bool memberQuit = false;
                while (!memberQuit) {
                    cout << "Member Menu" << endl;
                    cout << "1. BOOK" << endl;
                    cout << "2. COLLECTION" << endl;
                    cout << "3. LOG OUT" << endl;

                    int memberChoice;
                    cout << "Enter your choice: ";
                    cin >> memberChoice;
                
                    switch(memberChoice){
                        case 1:
                        {   
                            bool bookChoice = false;
                            while (!bookChoice){
                                cout << "1. Search Book by Title" << endl;
                                cout << "2. Search Book by Serial Number" << endl;
                                cout << "3. Display Borrowed List" << endl;
                                cout << "4. Borrow Book" << endl;
                                cout << "5. Return Book" << endl;
                                cout << "6. Read Book" << endl;
                                cout << "7. Exit" << endl;

                                int BC;
                                cout << "Enter your choice: ";
                                cin >> BC;

                                switch(BC){
                                    case 1:
                                    {
                                        system("cls");
                                        lib->searchBookTittle();
                                        break;
                                    }
                                    case 2:
                                    {
                                        system("cls");
                                        lib->searchBookSerialNum();
                                        break;

                                    }
                                    case 3:
                                    {
                                        system("cls");
                                        m[0]->displayBorrowList();
                                        break;
                                    }
                                    case 4:
                                    {   
                                       std::cout << "Enter Book to borrowed: ";
                                       std::string bookBorrowed;
                                       std::cin >> bookBorrowed;
                                       int index;
                                        if(lib->HelpSeachBookT(bookBorrowed,index)){
                                            Book * b = new Book();
                                            *b = *lib->HelpSeachBookT(bookBorrowed,index);
                                            if(b != nullptr){
                                                if(b->getBorrowedStatus() == false){
                                                    m[0]->borrowBook(b);
                                                    lib->HelpSeachBookT(bookBorrowed,index)->setBorrowedStatus(true);
                                                    b->setBorrowedStatus(true);
                                                    // ...
                                                }
                                                else{
                                                    std::cout << "This book has been borrowed\n";
                                                }
                                            } 
                                        }
                                        else{
                                            std::cout << "the Book is not found\n";
                                        } 
                                        break;
                                    }
                                    case 5:
                                    {
                                        system("cls");
                                        std::string mess = m[0]->returnBook();
                                        if(mess != "not found"){
                                            int index;
                                            lib->HelpSeachBookT(mess,index)->setBorrowedStatus(false);
                                        }
                                        break;
                                    }
                                    case 6:
                                    {
                                        system("cls");
                                        std::cout << "Enter BookName that you want to read  ";
                                        std::string readBook;
                                        std::cin >> readBook;
                                        Book * b = new Book();
                                        int index;
                                        *b = *lib->HelpSeachBookT(readBook,index);
                                        if(b){
                                            m[0]->readBook(b); 
                                        } 
                                        else{
                                            std::cout << "the Book is not found\n";
                                        } 
                                        break;
                                    }
                                    case 7:
                                    {
                                        bookChoice = true;
                                        break;
                                    }
                                    default:
                                    {
                                        cout << "Invalid Choice!" << endl;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            bool collectionChoice = false;
                            while (!collectionChoice){
                                cout << "1. Display Library Collection List" << endl;
                                cout << "2. Display Your SubscribeCollection List" << endl;
                                cout << "3. Subscribe Collection" << endl;
                                cout << "4. Unsubscribe Collection" << endl;
                                cout << "5. Exit" << endl;
                        
                                int CC;
                                cout << "Enter your choice: ";
                                cin >> CC;

                                switch(CC){
                                    case 1:
                                    {
                                        system("cls");
                                        ptr->displayCollectionList(m[0]->getAccessibilityLevel());
                                        break;
                                    }
                                    case 2:
                                    {
                                        system("cls");
                                        m[0]->displayCollectionList();
                                        break;
                                    }
                                    case 3: 
                                    {
                                        system("cls");
                                        std::string Cname;
                                        std::cout << "Enter Collection's name to search: ";
                                        std::cin >> Cname;
                                        if(ptr->HelpSearchCollection(Cname)){
                                            m[0]->subscribeCollection(ptr->HelpSearchCollection(Cname));
                                        }
                                        else{
                                            std::cout << "The collection is not found\n";
                                        }
                                        break;
                                    }
                                    case 4:
                                    {
                                        system("cls");
                                        m[0]->unSubscribeCollection();
                                        break;
                                    }
                                    case 5:
                                    {
                                        collectionChoice = true;
                                        break;
                                    }
                                    default:
                                    {
                                        cout << "Invalid Choice!" << endl;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            m[0]->logout();
                            memberQuit = true;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid Choice!" << endl;
                            break;
                        }
                    }
                }
                break;
                }
            case 3:
                {
                    system("cls");
                    bool guestQuit = false;
                    while(!guestQuit)
                    { 
                        cout << "Guest Menu" << endl;
                        cout << "1. Search Book by Title" << endl;
                        cout << "2. Search Book by Serial Number" << endl;
                        cout << "3. Read Book" << endl;
                        cout << "4. Register" << endl;
                        cout << "5. Exit" << endl;

                        int guessChoice;
                        cout << "Enter your choice:";
                        cin >> guessChoice;

                        switch(guessChoice)
                        {
                            case 1:
                            {
                                system("cls");
                                lib->searchBookTittle();
                                break;
                            }
                            case 2:
                            {
                                system("cls");
                                lib->searchBookSerialNum();
                                break;
                            }
                            case 3:
                            {
                                system("cls");
                                std::cout << "Enter BookName that you want to read  ";
                                std::string readBook;
                                std::cin >> readBook;
                                Book * b = new Book();
                                int index;
                                *b = *lib->HelpSeachBookT(readBook,index);
                                if(b)
                                {
                                    guest->readBook(b); 
                                }
                                else
                                {
                                    std::cout << "the Book is not found\n";
                                }
                                break;
                            }
                            case 4:
                            {
                                system("cls");
                                ptr->addMember(guest->Register());
                                guestQuit = true;
                                break;
                            }
                            case 5:
                            {
                                guestQuit = true;
                                break;
                            }
                            default:
                            {
                                cout << "Invalid Choice!" << endl;
                                break;
                            }
                        }
                    }
                    break;
                }
            case 4:
                quit = true;
                exit(0);
            default:
            {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
return 0;
}


