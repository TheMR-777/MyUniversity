#include<iostream>
using namespace std;
#define Work(c) cout << c << endl

    // Sub Class

class Room
{

public:

	int chairs;
    Room (int c)
    {
    	chairs=c;
	}
    
      
};
    
    // Master Class

class House
{
    public:
       int tables;
       Room r(3);
       House(int t)
       {
           tables=t;
       }
       void show()
       {
           Work("No of tables are: "<< tables);
           cout<<"No of chairs are: "<< r(3).chairs;
        
       }
};    


    // main part

int main()
{
    House H(3);
    H.show();

}

