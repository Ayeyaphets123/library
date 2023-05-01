#ifndef BC_H
#define BC_H
#include <iostream>
#include "Book.h"
#include <vector>
class Collection 
{
    private:
        int CollectionID;
        std::string CollectionName;
        std::vector<Book *> BookList;
        
    public:
        
        static int CollectionCountID;
        Collection() : CollectionID(0), CollectionName(" "){
            BookList.clear();
        }
        Collection(std::string CoName);
        Collection(const Collection &BC);
        Collection &operator=(const Collection &BC);
        ~Collection();
        
        void setCoID(int);
        void setCoName(std::string);
        void addBookToCollection(Book *b);

        void displayCollection( );
        
        std::string deleteBook(std::string);

        int getCoID() const;
        std::string getCoName() const;
        std::vector<Book *> getBookList() const;

        Book *HelpSearchBook(std::string, int &index);
        void HelpEdiCollection( bool N_signal, bool ID_signal, std::string NewCoName, int newID);
        void HelpEditBook(std::string bookName, bool T_signal, bool A_signal ,bool SE_signal,bool P_signal ,bool C_signal ,bool FP_signal ,bool VS_signal, std::string T, std::string A, std::string SE, int P, int C, int FP);
       
    
};


#endif