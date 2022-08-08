#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // Initialization

        shared_ptr<int> sh_ptr = make_shared<int>(10);
        shared_ptr<int> sh_ptr_2 = sh_ptr;
    
    // Output

        cout << "Value of 1st Pointer : " << *sh_ptr << " , Total Pointers : " << sh_ptr.use_count() << endl;
        cout << "Value of 2nd Pointer : " << *sh_ptr_2 << " , Total Pointers : " << sh_ptr.use_count() << endl;
}