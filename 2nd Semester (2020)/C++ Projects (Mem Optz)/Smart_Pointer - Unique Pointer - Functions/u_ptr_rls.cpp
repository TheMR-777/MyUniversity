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

void Print(Profile *rcv)
{
    cout << rcv->name << " " << rcv->age << endl;
}

int main()
{
    // Init

        unique_ptr<Profile> student = make_unique<Profile>();
        student->name = "MR_777";
        student->age = 19;

    // Throwing in Function

        Print( student.release() );
}