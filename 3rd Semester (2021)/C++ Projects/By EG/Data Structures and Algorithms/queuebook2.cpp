 #include<iostream>
using namespace std;
struct queue
{
int v1;
 queue *link;
};

struct queue * addqueue(struct queue *rear,int val);
struct queue * deletequeue(struct queue *front ,int *val);
void showqueue(struct queue *front);
int main()
{
 queue *front,*rear;
int val,ch;
front=rear=NULL;
do
{
 cout<<"\n Menu for queue operation";
 cout<< "\n 1.Add\n 2.Delete\n 3.Show\n 4.Exit" ;
 cout<<"\nEnter ur choice\n" ;
 cin>>ch;
switch(ch)
{
case 1:
{
 cout<<"Enter the value to be added\n";
 cin>>val;
rear=addqueue(rear,val);
if(front==NULL) front=rear;
break;
}
case 2:
{
front=deletequeue(front,&val);
if(val!=-1)
 cout<<"The deleted value is %d"<<val;
if(front==NULL)
rear=front;
break;
}
case 3:
{
showqueue(front);
break;
}
default: 
{
    cout<<"invalid input\n";
}
}
}while(ch<4);
 
}
struct queue *addqueue(struct queue *rear,int val) //Add item to Queue
{
  queue *w=new queue();
 
w->v1=val;
w->link=NULL;
if(rear!=NULL)
rear->link=w;
rear=w;
return(rear);
}
struct queue *deletequeue(struct queue *front ,int *val) //Remove item
{
struct queue *w;
if(front==NULL)
{
 cout<<"\n Sorry Queue is empty";
*val=-1;
}
else
{
w=front;
front=front->link;
*val=w->v1;
}
return front;
}
void showqueue(struct queue *front) // Display Queue items
{
struct queue *p;
p=front;
 cout<<"\nThe contents of queue is\n";
while(p!=NULL)
{
 cout<<p->v1;
  p=p->link;
}
}
