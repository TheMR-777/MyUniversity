#include <iostream>
#define Log(x) cout << x << endl
using namespace std;


// Topic
// =====
// Interface in C++
// consisting pure virtual functions

// How to run the Code
// ===================
// Please try not to use the "Run" Button above to run the code
// repl.it uses clang compiler, and this code is based on MinGW & MSVC
// Copy and paste the following command into the Right Terminal (without "//")
// clear && g++ 'Presentation/Coding Tutorials/08.cpp' && ./a.out && rm a.out
// Then press Enter to Execute the executable file
// Have a Nice Coding


class Interface
{
    virtual void Get_Name() = 0;
    virtual void Get_Mail() = 0;
    virtual void Get_Roll() = 0;
};

class Student : public Interface
{
    string name;
    string e_mail;
    int roll;

    public:

        Student(string&& s, string&& m, int&& r)
            : name(s), e_mail(m), roll(r) {}

        void Get_Name() override
        {
            Log("Name of Student           : " << name);
        }

        void Get_Mail() override
        {
            Log("E_Mail address of Student : " << e_mail);
        }

        void Get_Roll() override
        {
            Log("Roll Number of Student    : " << roll);
        }
};


int main()
{
    // Dealing with Student #1

        Log("");
        Student A("EG", "random.mail.gray@provider.host", 512);
        A.Get_Name(); A.Get_Mail(); A.Get_Roll();


    // Dealing with Student #2

        Log("");
        Student B("VO", "random.mail.red@provider.host", 377);
        B.Get_Name(); B.Get_Mail(); B.Get_Roll();


    // Dealing with Student #3

        Log("");
        Student C("MR", "random.mail.777@provider.host", 707);
        C.Get_Name(); C.Get_Mail(); C.Get_Roll();
}