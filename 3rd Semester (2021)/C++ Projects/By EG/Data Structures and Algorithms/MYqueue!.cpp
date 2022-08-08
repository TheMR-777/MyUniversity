// C++ program to implement a queue using an array 
#include <iostream> 
using namespace std; 
 
struct Queue 
{ 
    int front=0, rear=0, queue[5];  
     
    
    
    void queueEnqueue(int &data) 
    { 
        // check queue is full or not 
        if (rear==5)
         { 
            cout<<("\nQueue is full\n"); 
            return; 
        } 
  
        // insert element at the rear 
        else 
        { 
            queue[rear] = data; 
            rear++; 
        } 
        return; 
    } 
  
    // function to delete an element 
    // from the front of the queue 
    void queueDequeue() 
    { 
        // if queue is empty 
        if (front == rear)
         { 
            cout<<"\nQueue is  empty\n"; 
           
        } 
  
          
        else { 
            for (int i = 0; i < (rear - 1); i++)
             { 
                 front=front++;
                cout<< queue[front] <<" the element deleted"<<endl; 
            } 
  
            // decrement rear 
            rear--; 
        } 
         
    } 
  
    // print queue elements 
    void queueDisplay() 
    { 
        int i; 
        if (front == rear)
         { 
            cout<<("\nQueue is Empty\n"); 
             
        } 
       else
       {
          // traverse front to rear and print elements 
        for (i = front; i < rear; i++)
        { 
            cout <<" element #"<<i+1<<" "<<  queue[i] ; 
        }  
       }
       
        
         
    } 
  
    // print front of queue 
    void queueFront() 
    { 
        if (front == rear)
         { 
            cout<< "Queue is Empty" <<endl;     
        } 
        else
        {
              cout<< "Front Element is: " <<queue[front] <<endl; 
        }
        
       
          
    } 
}; 
  
// Driver code 
int main() 
{ 
     int choice ; 
    Queue q;
    do{
    cout<<"------------------------------------------------------------------------------------"<<endl; 
  cout<<"  |             which operation you want to perform on your queue                    |"<<endl;
  cout<<"  |     1- EnQueue    2- DeQueue    3- Display Queue    4- show front   5- Quit      |"<<endl;
  cout<<"  |                        please select your choice                                 |"<<endl;
    cout<<"------------------------------------------------------------------------------------"<<endl;
   
    cin>> choice;
     switch ((choice))
     {
     case 1:
     { 
        
    for (int i = 0; i < 5; i++)
    {
         cout<<" please Enter the value "<<i+1<<" " ;
        int value;
        cin>>value;
        q.queueEnqueue(value);
    }
         break;
     }
     case 2:
     {
           q.queueDequeue() ;
           break;
     }
     case 3:
     {
        q.queueDequeue();
         break;
     }
     case 4:
     {
         q.queueFront();
         break;
     }
      case 5:
     {
          cout<<"EXited"<<endl;
         break;
     }
     default:
     {
         cout<<"invalid input"<<endl;
     }
         
     }
      
}
while(choice!=5 );
}
    
    
     
     
   