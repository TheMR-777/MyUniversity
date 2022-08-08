#include <iostream>
using namespace std;
struct node
{
    string elsa;
    node* next;
};
class OOPloop
{
   node* head;
   node* tail;
    
   public:
   OOPloop()
{
   head=NULL;
   tail=NULL;
  
}   
   void add_node(string grey)
   {
       node* temp= new node;
       
          temp->elsa=grey;
          temp->next=NULL;
            if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->next=temp;
        tail=temp;
      }
        
        
   }
     void display()
        {
         node *point;
         point = head;
          while(point!=NULL)
           {
		   cout << point->elsa << " ";
           point = point->next;
        	}
        }
   
   
};
int main()
{
   OOPloop O;
   O.add_node("No-Quizes");
   O.add_node("No-Assignment");
   O.add_node("No-Viva");
   
    O.display();
}
