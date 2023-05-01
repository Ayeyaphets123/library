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

int main()
{   

    // m[0]->displayCollectionList();
    // ptr->removeBook(lib);

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

    Collection* sampleCollection = new Collection();
    sampleCollection->addBookToCollection(b[0]);
    sampleCollection->addBookToCollection(b[1]);
    sampleCollection->addBookToCollection(b[2]);

    Guest* guest = new Guest();
    Member * m[3] = {
        new Member("member1", "member1", "0367995350","hung"),
        new Member("member2", "member2", "0912458718", "long"),
        new Member("member3", "member3", "9785784638", "thinh")
    };

    ptr->addMember(m[0]);
    ptr->addMember(m[1]);
    ptr->addMember(m[2]);
    // ptr->createCollection();
    // ptr->EditCollection(lib);


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


    // ptr->displayBookList(lib);
    // ptr->createCollection();
    // ptr->createCollection();
    // ptr->createCollection();
    // ptr->EditCollection(lib);
    // ptr->EditCollection(lib);
    // ptr->displayCollectionList();

    bool quit = false;
    while (!quit) {
        system("cls");
        cout << "Main menu" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Member" << endl;
        cout << "3. Guest" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter you choice: ";
        cin >> choice;

        switch(choice) {
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
                                        ptr->displayCollectionList();
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
                    }
                }
                break;
            }
            // case 2:
            //     {
            //         system("cls");
            //     // ptr->login();
            //     bool memberQuit = false;
            //     while (!memberQuit) {
            //         cout << "Member Menu" << endl;
            //         cout << "1. Search Book" << endl;
            //         cout << "2. Read Book" << endl;
            //         cout << "3. Register" << endl;
            //         cout << "4. Log out" << endl;

            //         int memberChoice;
            //         cout << "Enter your choice: ";
            //         cin >> memberChoice;
                
            //         switch(memberChoice){
            //             case 1:
            //             {   
            //                 system("cls");
            //                 break;
            //             }
            //             case 2:
            //             {   
            //                 system("cls");
            //                 int index;
            //                 cin.ignore();
            //                 string bookName;
            //                 cout << "Here are some books in the sample collection: " << endl;
            //                 sampleCollection->displayCollection();
            //                 cout << endl;
            //                 cout << "Pick a book: ";
            //                 getline(cin, bookName);
            //                 guest->readBook(lib->HelpSeachBookT(bookName, index));
            //                 break;
            //             }
            //             case 3:
            //             {
            //                 system("cls");
            //                 string serialNumber;
            //                 cout << "Enter serial number of book that you want to edit: ";
            //                 cin >> serialNumber;
            //                 ptr->EditBook(lib, serialNumber);
            //                 break;
            //             }
            //             case 4:
            //             {
            //                 system("cls");
            //                 ptr->displayBookList(lib);
            //                 break;
            //             }
            //             case 5:
            //             {
            //                 memberQuit = true;
            //                 break;
            //             }
            //             // default:
            //             //     cout << "Invalid choice" << endl;
            //         }
            //     }
            //     break;
            //     }
            case 4:
                //exit
                exit(0);
            // default:
            //     cout << "Invalid choice" << endl;
        }
    }

return 0;
}


