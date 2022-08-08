# include <iostream>
#include <string>
using namespace std;
  
struct Node
{
    string S_data;
    Node* S_next;
    Node (string &UserValue, Node* Address=nullptr): S_data(UserValue), S_next(Address){}
    Node (string &&UserValue, Node* Address=nullptr): S_data(UserValue), S_next(Address){}
    

};
 class List
 {
    Node* head;
    Node* tail;
    public:
    
    List()
    {
        head=nullptr;
        tail=nullptr;
    }
    void insert(string i)
    {
        Node* node=new Node(i);

     if(head==nullptr)
     {
         head = node;
         tail=node;
         node=nullptr;
     }

     else
      {
          (*(tail)).S_next= node; 
           tail=node;
           node=nullptr;
      }
    }

   void display()
   {
       Node* iter;
       iter=head;
       while(iter!=nullptr)
       {
           cout<< " "<< iter->S_data;
           iter=iter->S_next;
       }
   } 
 };
 
int main()
{
    cout<<"My list contents are: ";
    List L;
    L.insert("thank");
    L.insert("you");
    L.insert("so");
    L.insert("much");
    L.insert("MR_brother");
    L.display();

}