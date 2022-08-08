 #include<iostream>
#include<stdlib.h>
using namespace std;

//   tree TREE

struct TREE
{
    int data;

    TREE* R_Child;
    TREE* L_Child;

    TREE(int& Data, TREE* R_Add = nullptr, TREE* L_Add = nullptr) : data(Data), R_Child(R_Add), L_Child(L_Add) {}
    TREE(int&& Data, TREE* R_Add = nullptr, TREE* L_Add = nullptr) : data(Data), R_Child(R_Add), L_Child(L_Add) {}
};

class BTinaryTree
{
    TREE* Root;
    TREE* Sub_Parent;

    void pre_order_traversal(TREE* root)
    {
        if (root != nullptr)
        {
            cout << root->data << " ";
            pre_order_traversal(root->L_Child);
            pre_order_traversal(root->R_Child);
            cout << endl;
        }
    }

    void inorder(TREE *root) 
   {
      if (root != nullptr) 
         {
            inorder(root->L_Child);
             cout<<root->data<<" ";
            inorder(root->R_Child);
            
         }
   } 

   void Post_order(TREE* node) 
{ 
    if (node != nullptr) 
        
  {
      
     Post_order(node->L_Child); 
     Post_order(node->R_Child); 
      cout << node->data << " ";
  } 
} 

    void DEL(TREE* del)
    {

        if (del != nullptr)
        {

            DEL(del->L_Child);
            DEL(del->R_Child);
            cout << del->data;
            free(del);
            cout << " freed!!" << endl;

        }

    }

public:
    BTinaryTree() : Root(nullptr), Sub_Parent(nullptr) {}



    void Insert(int& data)
    {
        TREE* NT = new TREE(data);

        //if tree is empty, create Root TREE
        if (Root == nullptr)
        {
            Root = Sub_Parent = NT;

        }
        //go to L_ of the tree  
        
              //go to left of the tree  
    else if(data!=Root->data)
    {
       
       if(data <   Sub_Parent->data)
   
          {
             if(  Sub_Parent->data==data)
             {
                cout<<"data duplicated!! "<<data<<endl;
             }
            //insert to the left
            if(  Sub_Parent->L_Child == nullptr) 
            {
                   Sub_Parent->L_Child = NT;
                   Sub_Parent =Sub_Parent->L_Child;
                
            }
             
         }

       //go to right of the tree
          
           else 

         {
            if(  Sub_Parent->data==data)
             {
                cout<<"data duplicated!! "<<data<<endl;
             }
            if(data > Sub_Parent->data) 
            {
            //insert to the right
            if(  Sub_Parent->R_Child == nullptr)
             {
                 Sub_Parent->R_Child = NT;
                 Sub_Parent=  Sub_Parent->R_Child;
                
             }
            }
            

         }
        
 }
 else
 {
    cout<<"data duplicated!! "<<data<<endl;
 }
}
void Insert(int&& data)
{
      Insert(data);
}

// display function
 void Traversal_Pre ()
{
   if(Root==nullptr)
   {
      cout<<"Empty Tree :("<<endl;
   }
   else
   {
      cout<<"pre-orderd traversal"<<endl;
       pre_order_traversal(Root);
        cout<<endl;
   }
}
 void Traversal_In()
{
   if (Root==nullptr)
   {
       cout<<"Empty Tree :("<<endl;
   }
   else
   {
       cout<<"In-orderd traversal"<<endl;
        inorder(Root);
        cout<<endl;
   }  
}
 
 void Traversal_Post()
 {
    if (Root==nullptr)
   {
       cout<<"Empty Tree :("<<endl;
   }
   else
   {
       cout<<"Post-orderd traversal"<<endl;
        Post_order(Root);
         cout<<endl;
   }  
 }

    void Delete()
    {
        if (Root == nullptr)
        {
            cout << "Empty Tree :(" << endl;
        }
        else
            DEL(Root);

    }


     bool search(int &data)
    {
         TREE* iter = Root;
         cout << "Visiting elements: "<<endl;
        if (iter->data == data)
        {
            return true;
        }
        else
        {
            while (data != iter->data && (iter->L_Child != nullptr && iter->R_Child != nullptr))
            {
                //go to left tree
                if (iter->data > data)
                {
                    iter = iter-> L_Child;
                    if (iter->data == data)
                    {
                        return  true;
                    }
                }
                //else go to right tree
                else if (iter->data < data)
                {
                    iter = iter->R_Child;
                    if (iter->data == data)
                    {
                        return true;
                    }
                }

            }
            return false;

        }
    }

    bool search(int &&data)
    {
         search(data);
    }
};





int main()
{

    cout<<"+----------------------------------------------------------------+"<<endl;
    cout<<"|    This Program has 6 functions of a BINARY TREE               |"<<endl;
    cout<<"|         1-           INSERTION                                 |"<<endl;
    cout<<"|         2-           Traversal_Pre_order                       |"<<endl;
    cout<<"|         3-           Traversal_In_order                        |"<<endl;
    cout<<"|         4-           Traversal_Post_order                      |"<<endl;
    cout<<"|         5-           Search                                    |"<<endl;
    cout<<"|         6-           Delete                                    |"<<endl;
    cout<<"+----------------------------------------------------------------+"<<endl;
    BTinaryTree BT;
    cout<<endl<<endl;
    cout<<"          ***********************************          "<<endl;
    cout<<"                 INSERTION FUNCTION                    "<<endl;
    for (int a = 0; a < 5; a++)
    {
        int i;
        cout << "Insert the element "<<"#"<<a+1<<" ";
        cin >> i;
        BT.Insert(i);
        cout << endl;
    }
      cout<<"       ***************************************          "<<endl;
      cout<<"            PRE-ORDER-TRAVERSAL FUNCTION                "<<endl;
      cout<<endl;
      BT.Traversal_Pre();
      cout<<endl;
      cout<<"       ***************************************          "<<endl;
      cout<<"            IN-ORDER-TRAVERSAL FUNCTION                "<<endl;
      cout<<endl;
      BT.Traversal_In();
      cout<<"       ***************************************          "<<endl;
      cout<<"            POST-ORDER-TRAVERSAL FUNCTION                "<<endl;
      cout<<endl;
      BT.Traversal_Post();
      cout<<endl;
        int search;
        cout<<"       *******************************     "<<endl;
        cout<<"            SEARCH FUNCTION                "<<endl;
        cout << "plz enter element to be searched..." << endl;
        cin >> search;
        cout<<endl;
        bool GOT = BT.search(search);
        if ( GOT == false)
        {
            cout << "element not found! " << endl;
        }
        else
        {
            cout << "element found! " << search << endl;
        }
        cout<<endl;
        cout<<"      *******************************     "<<endl;
        cout<<"            DELETE FUNCTION                "<<endl;
        BT.Delete();
    system("pause");

        main();
}