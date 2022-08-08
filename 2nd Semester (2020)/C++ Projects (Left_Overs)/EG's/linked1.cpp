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
          temp->next=head;
          head=temp;
        
   }
     void display()
        {
         node *point;
         point = head;
         do
           {
		   cout << point->elsa << " ";
           point = point->next;
		   }
		 
          
       while(point->next!=NULL); 
   
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
