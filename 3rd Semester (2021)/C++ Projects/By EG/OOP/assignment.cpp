#include <iostream>
using namespace std;


class Vehicle
{    
   private:
    float  cost , Dimensions , fule , speed;
    int accomodation;
     public:

     void Get(float &&c, float &&d, float &&f, float &&s, int &&a)
     {
          cost=c;
         
          Dimensions=d;
          fule=f;
          speed=s;
          accomodation=a;
        cout<<" cost is: "<<cost<<endl;
        cout<<" it can carry "<<accomodation << "people"<<endl;
        cout<<" it has "<<speed << " horsepower engine"<<endl;


     }
  
};

class Car : public Vehicle
{
    int wheel;
    public:
    Car()
    {
        wheel=4;
    }
};
// class truck
class truck : public Car
{
    
    public:
      
    void t_Get(Vehicle &B)
    {
         B.Get(15000,15,30,500,18);
           cout<< " 4 wheels ABC breaks"<<endl;
          cout<<"tyre pressure monitoring"<<endl;
          cout<<"stability control"<<endl;
    }
};

// van class
class Van : public Car
{
    
    public:
     
    void v_Get(Vehicle& B)
    {
         B.Get(10000,15,25,730,18);
           cout<< " 4 wheels ABC breaks"<<endl;
           cout<<"tyre pressure monitoring\n";
          cout<<"stability control"<<endl;
    }
};
   class Boat : public Vehicle
{
    public:
    Boat()
    {
        cout<<"its a water Vehicle\n";
    }
};
// class sail-boat
class sail : public Boat
{
    
    public:
      
    void t_Get(Vehicle &B)
    {
         B.Get(5000,15,2,33,5);
         cout<<"it works by threasure"<<endl;
    }
};

//  class yatch-boat
class Yatch : public Boat
{
    
    public:
     
    void v_Get(Vehicle& B)
    {
          B.Get(25000,15,28,30,30);
         cout<<" it works on engine"<<endl;
    }
};
 
  class Aircraft : public Vehicle
{
    public:
    Aircraft()
    {
        cout<<"its a flying Vehicle\n";
    }
};
// class sail-boat
class hellicopter : public Aircraft
{
    
    public:
      
    void t_Get(Vehicle &B)
    {
         B.Get(5000,15,2,33,10);
         cout<<"stability control"<<endl;
    }
};

//  class yatch-boat
class UFO: public Aircraft
{
    
    public:
     
    void v_Get(Vehicle& B)
    {
          B.Get(25000,15,28,30,30);
          
    }
};


int main()
{
    // Initialization

        Vehicle A;
        cout<<"plz select the type of Vehicle"<<endl;
        int x;
        cout<< "plz enter [ 1 ] if you want Car type of Vehicle" <<endl;
         cout<< "plz enter [ 2 ] if you want Boat type of Vehicle" <<endl;
          cout<< "plz enter [ 3 ] if you want Aircraft type of Vehicle" <<endl;
          cin>>x;
          switch(x)
          {
            case 1:
            {
                Car C;
                int y;
                cout<<" plz select the type of car:"<<endl;
                cout <<" plz enter [1] to select van\n ";
                cout<<" plz enter [2] to select truck\n";
                cin>>y;
                if (y==1)
                {
                    cout<<"Van\n";
                    Van V;
                    V.v_Get(A);
                }
                else if (y==2)
                {
                    cout<<"truck\n";
                    truck T;
                    T.t_Get(A);
                }
                else
                {
                    cout<< " invalid input"<<endl;    
                }
                break;
            }
                
            

            case 2:
            {
                Boat C;
                int y;
                cout<<" plz select the type of boat:"<<endl;
                cout <<" plz enter [1] to select sail-boat\n ";
                cout<<" plz enter [2] to select yatch-boat\n";
                cin>>y;
                if (y==1)
                {
                    cout<<"sail\n";
                    sail s;
                    s.t_Get(A);
                }
                else if (y==2)
                {
                    cout<<"yatch\n";
                    Yatch Y;
                    Y.v_Get(A);
                }
                else
                {
                    cout<< " invalid input"<<endl;    
                }
                }
               break; 
            

            case 3:
            {
                Aircraft D;
                int y;
                cout<<" plz select the type of Air-craft:"<<endl;
                cout <<" plz enter [1] to helicopter\n ";
                cout<<" plz enter [2] to select UFO\n";
                cin>>y;
                if (y==1)
                {
                    cout<<"helicopter\n";
                    hellicopter s;
                    s.t_Get(A);
                }
                else if (y==2)
                {
                    cout<<"UFO\n";
                    UFO Y;
                    Y.v_Get(A);
                }
                else
                {
                    cout<< " invalid input"<<endl;    
                }
                break;
                }
                
            
            default :
            cout<<" invalid input"<<endl;
          }
}
    
         

         
        

       