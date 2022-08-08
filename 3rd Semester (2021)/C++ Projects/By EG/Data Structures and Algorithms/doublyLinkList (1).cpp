# include <iostream>
#include <string>
using namespace std;
  
struct Node
{
    string S_data;
    Node* S_next;
    Node*S_previous;
    Node (string &UserValue, Node* AddressB=nullptr,Node* AddressA=nullptr): S_data(UserValue), S_next(AddressB),S_previous(AddressA){}
    Node (string &&UserValue, Node* AddressB=nullptr,Node* AddressA=nullptr): S_data(UserValue), S_next(AddressB),S_previous(AddressA){}
    
   
   
};
 class List
 {
    Node* head;
    Node* tail;
    Node* backLink;
    Node* iter;
    Node* m_excluder;

    void iteration(int & index)
    {
         for(int a=1; a<(index); a++)
       {
         iter=iter->S_next;
       }
       
    }
   void iteration(int &&index)
    {
          iteration(index);
    }
  

    public:
    
    List() : head(nullptr),tail(nullptr),backLink(nullptr) {}
    // adding nodes
    void add(string &d)
    {
        Node* node=new Node(d);

     if(head==nullptr)
     {
        head= tail=node;  
     }

     else
      {
          (*(tail)).S_next= node; 
          (*(node)).S_previous=tail;
           tail=node;      
      }
    }
    void add(string &&d)
    {
       add(d);
    }

 // insert node at any position

    void insert (string &b, int &it)
    { 
        iter=head;  
        iteration(it-1);

        Node* node=new Node(b, iter->S_next,iter); 
         iter->S_next->S_previous=node;
         iter->S_next=node;
           
    }
   void insert (string &&b, int &&it)
    {
        insert ( b,it);
    }

     void insert_after()
    {
        // constructor recieving r value will be called
        Node* node=new Node("i-did", head); 

        head->S_previous=node;
        head=node;
    }
  
     void display()
   {
      iter=head;
       while(iter!=nullptr)
       {
           cout<< " "<< iter->S_data;
           iter=iter->S_next;
       }
       cout<<endl;
       cout<<"reverse order: ";
        cout<<endl;
        iter=tail;
    while(iter!=nullptr)
       {
           cout<< " "<< iter->S_data;
           iter=iter->S_previous;
       }
   } 

   // remove list 
    void clear_all()
  {
     
     iter=head;
       while(iter!=nullptr)
       {
            m_excluder=iter->S_next;
            iter->S_next=( m_excluder)->S_next;
           delete m_excluder;
           iter=iter->S_previous;
       }
        cout<<endl;
        cout<<" All list cleared: ";
  }

     // clear list from anywhere
     
   void clear_List(int &ind)
    {
           iter=head;
         if (ind==1)
       {  
            m_excluder=iter;
            head=iter->S_next;
            delete m_excluder;
          
       }
       else
       {
             iteration( ind);
             
            m_excluder=iter->S_next;
            iter->S_next->S_previous= m_excluder->S_previous;
            iter->S_next->S_next= m_excluder->S_next;
            iter->S_next=m_excluder->S_next;
           delete m_excluder;
          
       }
         
    }
    void clear_List(int &&ind)
    {
      clear_List(ind);
    }
 
 };
int main()
{
   
   
    cout<<"My list contents are: "<<endl;
    List L;
    L.add("thank");
    L.add("you");
    L.add("so");
    L.add("much");
    L.add("Mr-brother");
    L.insert("MG",5);
    L.insert_after();
    L.clear_List(4);
    L.display();
    L.clear_all();
    
   

}