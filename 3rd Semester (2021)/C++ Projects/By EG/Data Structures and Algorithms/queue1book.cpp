#include<iostream>
using namespace std;
#define size 5 // Size of the queue
int front=-1,rear=-1;
int queue[size];
int i,j;
 
void insert(int item) //Add item to Queue
{
if(rear==(size-1))
{
 cout<<"Queue overflow";

}
else
{
rear++;
queue[rear]=item;
}

 
}

void show() // Display Queue items
{
if (front==rear)
{
cout<<"Empty queue";
return;
}
if(front <rear)
{
 cout<<"Elements in the queue are\n";
for(i=front+1;i<=rear;i++)
{
 cout<<" "<<queue[i];
}
}
}

void del() //Remove item from Queue
{
int v;
 
if(front==rear)
{
cout<<"Queue is empty";
}
else
{
   front=front+1;
   v=queue[front];
 cout<<"Element deleted from q is <<"<<v;
}
}


 
int main()
{
    //int front=-1,rear=-1;
  
    int ch,v;
 
 
 do
 {
 cout<<"Select the Menu operation\n";
 cout<<"\n1.InsertQueue\n2.DeleteQueue\n3.Show\n4.Quit\n";
 cout<<"Enter your choice\n";
 cin>>ch;
 switch(ch)
 {
 case 1:
 {cout<<"Enter the value\t";
 cin>>v;
  
insert(v);
break;
 }
case 2:
{
  del();
   break;
}
case 3:
{
show();
break;
}
default:
{
    cout<<"error";
}
}
}
while(ch<4);
 
}

 
