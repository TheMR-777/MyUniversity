#include <iostream> 
#include <memory>
using namespace std;

struct Profile
{
    string name;
    int age;

    ~Profile()
    {
        cout << "Destructor Called" << endl;
    }
};



void Print5(unique_ptr<Profile> rcv)
{
    cout << rcv->name << " " << rcv->age << endl;
}

void Print4(unique_ptr<Profile> rcv)
{
    cout << rcv->name << " " << rcv->age << endl;
    Print5( move(rcv) );
}

void Print3(unique_ptr<Profile> rcv)
{
    cout << rcv->name << " " << rcv->age << endl;
    Print4( move(rcv) );
}

void Print2(unique_ptr<Profile> rcv)
{
    cout << rcv->name << " " << rcv->age << endl;
    Print3( move(rcv) );
}

void Print1(unique_ptr<Profile> rcv)
{
    cout << rcv->name << " " << rcv->age << endl;
    Print2( move(rcv) );
}



int main()
{
    // Init

        // unique_ptr<Profile> student (new Profile());

        unique_ptr<Profile> student = make_unique<Profile>();
        student->name = "MR_777";
        student->age = 19;

    // Throwing in Function

        Print1( move( student ) );
}