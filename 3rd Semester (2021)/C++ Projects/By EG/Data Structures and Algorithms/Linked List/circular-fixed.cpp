# include <iostream>
#include <string>
using namespace std;

struct Node
{
    string S_data;
    Node* S_next;
    Node(string& UserValue, Node* Address = nullptr) : S_data(UserValue), S_next(Address) {}
    Node(string&& UserValue, Node* Address = nullptr) : S_data(UserValue), S_next(Address) {}

};
class List
{

    Node* last;
    Node* iter;


    void iteration(int& index)
    {
        for (int a = 1; a < (index); a++)
        {
            iter = iter->S_next;
        }

    }
    void iteration(int&& index)
    {
        iteration(index);
    }


public:

    List() : last(nullptr) {}

    void add(string& i)
    {
        Node* node = new Node(i);

        if (last == nullptr)
        {
            last = node;
            last->S_next = node;
        }
        else
        {
            node->S_next = last->S_next;
            last->S_next = node;
            last = last->S_next;
        }

    }
    void add(string&& i)
    {
        add(i);
    }
    // insert node somewhere between head and tail

    void insert(string b, int it)
    {

        iter = last->S_next;

        iteration((it - 1));

        Node* node = new Node(b, (iter->S_next)->S_next);
        iter->S_next = node;



    }
    // insert node before head
    void insert_after()
    {
        // constructor recieving r value will be called
        Node* node = new Node("i-did", last->S_next);
        last->S_next = node;
    }

    void display()
    {
        iter = last->S_next;
        do
        {
            cout << " " << iter->S_data;
            iter = iter->S_next;
        } 
        while (iter != last->S_next);
    }

    // clear list from anywhere

   /* void clear_List(int &ind)
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
             iter->S_next=( m_excluder)->S_next;
            delete m_excluder;

        }

     }
     void clear_List(int &&ind)
     {
       clear_List(ind);
     }

  // clear all

   void clear_all()
   {

      iter=head;
        while(iter!=tail->S_next)
        {
             m_excluder=iter->S_next;
             iter->S_next=( m_excluder)->S_next;
            delete m_excluder;
            iter=iter->S_next;
        }
        cout<<" All list cleared: ";
   }

   // swaping of nodes
    void swape(int &F, int &R)
    {
      string temp;
          m_excluder= iter=head;
              iteration(F);
              temp=iter->S_data;

          for(int a=0; a<(R); a++)
        {
          m_excluder=m_excluder->S_next;
        }
              iter->S_data=m_excluder->S_data;
              m_excluder->S_data=temp;

   }




   void swape(int &&F, int &&R)
     {
       swape(F,R);
     }
     */
};
int main()
{
    int index;

    cout << "My list contents are: " << endl;
    List L;
    L.add("thank");
    L.add("you");
    L.add("so");
    L.add("much");
    L.add("Kashif");
    // L.insert("Sir",5);
    /* L.insert_after();
     L.swape(1,5);
     L.clear_List(1);
     */
    L.display();
    //L.clear_all();


}