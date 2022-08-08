#include<iostream>
#include<ctime>
using namespace std;

struct NOSE    
{
     string S_data;
     NOSE* S_next;

    // constructor
    NOSE( string &data, NOSE*  Address= nullptr) : S_data(data) , S_next(Address){}
    NOSE( string &&data, NOSE*  Address= nullptr) : S_data(data) , S_next(Address){}


};

// class strange 
 class Queer      // Queer means strange as this class will link many noses :)) 
 {
      private: 
     NOSE* front;
     NOSE* rear;
     NOSE* iter;
    
     

     // if nose is empty or not
     
    public: 
    bool isEmpty()
     {
         if(front==nullptr && rear==nullptr)
         {
             return true;
         }
         else 
         {
         return false;
         }
     }
     // a clean nose
      Queer(): front(nullptr), rear(nullptr){}

       

    void AddMucus(string S)
    {
       NOSE* nostril= new NOSE(S);

       // linking many noses 

       if(rear==nullptr)
       {
          front=rear=nostril;
           
       }
       else
       {
           rear->S_next=nostril;
           rear=nostril;
       }
       
       
    }
    int show ()
    {
        int size=0;
        if (isEmpty())
        {
            cout<<"\n----------Teller is free----------: "<<endl;
            
        }
        else
        {
             iter=front;
             cout<<" TELLER HAS PERSON(S) HERE: ";
         while(iter!= nullptr)
          {
            cout<<" "<<iter->S_data;
            iter=iter->S_next;
            size++;
          }
         
        } 
         return size;
    }

     

     

     
 };

 class Time
 {
     private:
     int hour, min; 
     public:
     Time(int r = 0, int i =0) :hour(r),min(i) {}
      
    // This is automatically called when '-' is used with 
    // between two Complex objects 
    Time operator - (Time const &obj) 
    { 
         Time diff; 
         diff.hour = hour - obj.hour; 
         diff.min = min - obj.min; 
         if(diff.min<0)
         {
             diff.min=60+diff.min;
             diff.hour=0;
         }
         if(diff.hour<0)
         {
           diff.hour=12+diff.hour;
         }
         return diff; 
    } 

    void Avg(Time &t1,Time &t2,Time &t3, Time&t4)
    {
       Time A;
       A.hour= t1.hour+t2.hour+t3.hour+t4.hour;
       A.min= t1.min+t2.min+t3.min+t4.min;
       cout<<" average time taken per customer is: "<<A.hour/4 <<":"<<A.min/4;

    }

     void print() 
	{ 
	    cout << hour << ":" << min << endl; 
	} 
 };

 int main()
 {
        Queer Q1,Q2,Q3,Q4;
        Time ti1,ti2,ti3,ti4,A;
       int ask,size,time,T;
       for(int i=0; i<4; i++)
       {
     cout<<"---------------------------------------------------"<<endl;
     cout<<" WELCOME TO MY BANK THERE ARE FOUR TELLERS: "<<endl;
     cout<<" TELLER [ 1 ] IS TO OPEN THE ACCOUNT."<<endl;
     cout<<" TELLER [ 2 ] IS TO WITHDRAW MONEY."<<endl;
     cout<<" TELLER [ 3 ] IS TO ISSUE DEBTS."<<endl;
     cout<<" TELLER [ 4 ] IS TO SOLVE TRANSACTION ISSUES."<<endl;
     cout<<"---------------------------------------------------"<<endl;
     cout<<endl<<endl;
     cout<<"             **************************              "<<endl<<endl;

     
      cout<< "========To which teller you want to go======= ";
      cin>>ask;
      switch (ask)
      {
      case 1: 
      {
         
          size=Q1.show();
          if(size!=0)
          {
          cout<<"\n--------------------------------------------"<<endl;
           
          cout<<"    your position is:   "<< size+1 << endl;
          cout<<"\n--------------------------------------------"<<endl;
          }
          else
          {
               cout<< "   you are the 1st customer     "<<endl;
          }
          string name;
          cout<<" plz tell your name: ";
          cin>>name;
           Q1.AddMucus(name);
           cout<<endl;
           Time T1(12,30),T2(12,36);
             ti1 = T2-T1;
           cout<<" the time taken by the customer: ";
           ti1.print();

          
           break;   
      }
      case 2:
      {
           
          size=Q2.show();
          if(size!=0)
          {
          cout<<"\n--------------------------------------------"<<endl;
          
          cout<<"    your position is:   "<< size+1 << endl;
          cout<<"\n--------------------------------------------"<<endl;
          }
          else
          {
               cout<< " you are the 1st customer     "<<endl;
          }
             string name;
          cout<<" plz tell your name: ";
          cin>>name;
           Q1.AddMucus(name);
           cout<<endl;
            
           Time T1(3,30),T2(4,0);
             ti2 = T2-T1;
           cout<<" the time taken by the customer: ";
            ti2.print();
          break;
      }
      case 3:
      {
          
          size=Q3.show();
          if(size!=0)
          {
          cout<<"\n--------------------------------------------"<<endl;
          
          cout<<"    your position is:   "<< size+1 << endl;
          cout<<"\n--------------------------------------------"<<endl;
          }
          else
          {
               cout<< " you are the 1st customer     "<<endl;
          }
            string name;
          cout<<" plz tell your name: ";
          cin>>name;
           Q1.AddMucus(name);
           cout<<endl;
           Time T1(12,55),T2(1,0);
             ti3 = T2-T1;
           cout<<" the time taken by the customer: ";
           ti3.print();
          break;
      }
      case 4:
      {
           
          size=Q4.show();
          if(size!=0)
          {
          cout<<"--------------------------------------------"<<endl;
         
          cout<<"    your position is:   "<< size+1 << endl;
          cout<<"--------------------------------------------"<<endl;
          }
          else
          {
               cout<< " you are the 1st customer     "<<endl;
          }
             string name;
          cout<<" plz tell your name: ";
          cin>>name;
           Q1.AddMucus(name);
           cout<<endl;
           Time T1(2,30),T2(2,38);
             ti4 = T2-T1;
           cout<<" the time taken by the customer: " ;
           ti4.print();
          break;
      }
 
      default:
      {
          cout<<"wrong input: "<<endl;
      }
           
      } 
     }
     A.Avg (ti1,ti2,ti3,ti4);
     

      
 }