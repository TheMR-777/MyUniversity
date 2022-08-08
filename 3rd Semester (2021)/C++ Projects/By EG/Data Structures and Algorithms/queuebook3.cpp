#include<iostream>
using namespace std;


int n;
 
void addcirqueue (int cq [],int* rear,int val,int *front)
 
{
if((*rear+1)%n==*front)
{
    cout<<"Queue is full";
}
else
{
*rear=(*rear+1)%n;
cq[*rear]=val;
}
}
  int deletecirqueue(int cq[],int *front,int *rear)
{
int v1;
if(*front!=*rear)
{
*front=(*front+1)%n;
v1=cq[*front];
return v1;
}
else
{
    cout<<"Queue is empty";
    return 0;
}
}
 void showcirqueue(int cq[],int *front,int *rear)
{
int j;
j=*front;
cout<<"Contents"; 
while(j!=*rear)
{
  j=(j+1)%n;
  cout<<" "<<cq[j];  
  }
}


int main()
{
int cq [35];
int ch,front,rear,val;
cout<<"Enter the size of the circular queue\n";
 cin>>n;
front=rear=0; 
do
{
    cout<<"\nMenu for circular queue operation";
    cout<<"\n 1.Add\n 2.Delete\n 3.Show\n";
    cout<<"\nEnter u r choice\n";
switch(ch)
{
case 1:
{
    cout<<"Enter the value to be added\n";
    cin>>val;
addcirqueue(cq,&rear,val,&front);
break;
}
case 2:
{
val=deletecirqueue(cq,&front,&rear);
if(val!=0)
{
    cout<<"The deleted value is %d"<<val;
}
break;
}
case 3:
{
showcirqueue(cq,&front,&rear);
break;
}
default:
{
    cout<<"error\n";
}
}
}
while (ch<4);
}

