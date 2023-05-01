#ifndef MEMBER_H
#define MEMBER_H
#include "User.h"
#include "Registered.h"
#include "BookCollection.h"
#include "Book.h"
#include <ctime>
#include <vector>
class Member : public Registered
{
    private:
        int startYear;
        int EndYear;

        std::vector <Collection *> CollectionList;

    public:
        Member() : Registered(Medium),startYear(0), EndYear(0){
                
                CollectionList.clear();
        }
        Member(std::string userName, std::string password, std::string phone, std::string fullname, accessibilityType AL = Medium);
        ~Member();
        void borrowBook(Book *b);

        void returnBook();

        void subscribeCollection(Collection *S);

        void unSubscribeCollection();

        void displayCollectionList();

        void readBook(const Book *b);

        void setStartYear();
        void setEndYear();

        int getStartYear() const;
        int getEndYear() const;

        
        std::vector <Collection *> getCollectionList() const;

        void deleteBookInCollection(std::string);

        void PersonalInformation();

        void HelpEditCollection(std::string CoName, bool N_signal, bool ID_signal, std::string NewCoName, int newID);
        void HelpEditBook(std::string BookName, bool T_signal, bool A_signal ,bool SE_signal,bool P_signal ,bool C_signal ,bool FP_signal ,bool VS_signal, std::string T, std::string A, std::string SE, int P, int C, int FP);

        void logout();
};

#endif