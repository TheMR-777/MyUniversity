#include <iostream> 
using namespace std;

int main()
{
    try
    {
        int i;
        cin >> i;

        if (i>50)
        {
            cout << "Pass" << endl;
        }
        else
        {
            throw i;
        }  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}