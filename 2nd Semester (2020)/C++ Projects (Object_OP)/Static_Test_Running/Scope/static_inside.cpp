#include <iostream> 
using namespace std;

class Profile
{
    static int size;

    public :

        Profile()
        {
            size++;
        }
        ~Profile()
        {
            size--;
        }

        static int my_size()
        {
            return size;
        }
};

int Profile::size = 0;

int main()
{
    Profile Me;
    cout << Me.my_size() << endl;

    Profile ahmed , zubair , bilal;
    cout << Profile::my_size();
}