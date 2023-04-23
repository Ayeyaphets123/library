#include "User.cpp"
#include "Admin.cpp"
#include "Member.cpp"
#include "Guest.cpp"
int main()
{
    User * ptr[3] = {
        new Admin(),
        new Member(),
        new Guest()
    };
return 0;
}