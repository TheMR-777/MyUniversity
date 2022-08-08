#include <iostream> 
#include <memory>
using namespace std;

int main()
{
    {
        // Scoped Work

        unique_ptr<int> i_data (new int(10));
        cout << *i_data << " " << &i_data << endl;
    }

    // cout << *i_data << " " << &i_data << endl;
}