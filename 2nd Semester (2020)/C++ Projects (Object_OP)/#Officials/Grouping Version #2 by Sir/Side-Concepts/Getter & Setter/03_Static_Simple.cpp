#include <iostream> 
using namespace std;

class Profile
{
    
    string f_name;
    string l_name;
    int age;

    public:
        
    // Static Count

        static int my_size;

        Profile()
        {
            my_size++;
            cout << "Instance Created. Current Size : " << my_size << endl;
        }

        ~Profile()
        {
            my_size--;
            cout << "Instance Destructed. Current Size : " << my_size << endl;
        }
};


// Static Initialization
    
    int Profile::my_size = 0;



int main()
{
    // Initialization

        Profile MG;
        Profile EG;
        Profile FG;
        Profile MR;

    // Checking for Size :

        cout << endl;
        cout << "Size after Instantiation : " << Profile::my_size << endl;
        cout << endl;
    // Destruction 1-by-1
}