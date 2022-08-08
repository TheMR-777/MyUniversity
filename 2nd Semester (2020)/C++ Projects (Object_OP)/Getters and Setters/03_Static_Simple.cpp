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

        Profile ahmed;
        Profile hammad;
        Profile random;

    // Checking for Size :

        cout << "Size after Instanciation : " << Profile::my_size << endl;

    // Destruction 1-by-1
}