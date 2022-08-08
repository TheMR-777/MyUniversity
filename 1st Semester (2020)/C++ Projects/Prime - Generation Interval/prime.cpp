#include <iostream>
using namespace std;

int main()
{
    int init, final, flag;
    prime:
    system("cls");
    cout << "Enter Range (intervals, seperated by SPACE): ";
    cin >> init >> final;
    
    
    cout << "Prime numbers b/w " << init << " and " << final << " are: ";
    
    while (init < final)
    {
        flag = 0;
        for(int i = 2; i <= init/2; ++i)
        {
            if(init % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
           	cout << init << " ";
		}
            
        init++;
    }
    
    cout << "\n\n\n\n" << endl;
    system("pause");
    goto prime;
}
