#include<iostream>
#include<string>
using namespace std;
bool password()
{ 

    string pass; 
    bool op;
    int i=0 , u=0 , l=0 , n=0;
    cin >> pass;
    if (pass.size() > 8)
    {
        for(i=0 ; i < pass.size() ; i++)
        {
            if(pass[i]>='A'&& pass[i]<='Z')
            {
                u++;
                i++;
            } 
        }

        if(u != 0)
        {
            for(i=0; i<pass.size(); i++)
            {
                if(pass[i]>='a'&& pass[i]<='z')
                {
                    l++;
                    i++;
                } 
            }
        
            if (l != 0)
            {
                for(i=0; i<pass.size(); i++)
                {
                    if(pass[i]>='0' && pass[i]<='9')
                    { 
                        n++;
                        i++;
                    }
                }

                if(n!=0)
                {
                    return op=true;
                }  
                else
                {
                    cout<<"Rule 4 is violated\n";
                    cout<<"--------------------\n";
                    cout<<"plz enter correct  password\n";
                    password();
                }

            }
            else
            {
                cout<<"Rule 3 is violated\n";
                cout<<"--------------------\n";
                cout<<"plz enter correct  password\n";
                password();
            }

        }
        else
        {
            cout<<"Rule 2 is violated\n";
            cout<<"--------------------\n";
            cout<<"plz enter correct  password\n";
            password();
        }

    }

    else
    {
        cout<<"Rule 1 is violated\n";
        cout<<"--------------------\n";
        cout<<"plz enter correct sized password\n";
        password();
    }


} 
 
   

  
   
      
      
    

 
int main()
{
    bool b;
    cout<<"plz enter the password\n";
    cout<<"------------------------\n";
    cout<<"plz follow the rules while deciding the passworsd\n";
    cout<<"------------------------\n";
    cout<<" Rule 1:: password must be equal to or greater then 8 characters\n";
    cout<<"------------------------\n";
    cout<<"Rule 2:: password must include one upercase alphabet\n";
    cout<<"------------------------\n";
    cout<<"Rule 3:: password must contain one lowercase alphabet\n";
    cout<<"------------------------\n";
    cout<<"Rule 4:: password must contain an integer value\n";
    cout<<"------------------------\n";


    cout<<"plz enter the password\n";

    b=  password();
    if(b==true)
    {
        cout<<"can we do work on file access??\n";











        cout << endl;
        cout << "Yes!, Now we R ready to move Forward!" << endl;
        cout << "By the Way ..." << endl;
        cout << "The Algorithm is way beyond Perfect!" << endl;
        cout << "I'll give U 100/100 on it!" << endl;
        cout << "U amazed me with your Unique Algorithm!" << endl;
        cout << "Seriously Great JOB ...!!!" << endl;
        cout << "I'm currently working on the same Project, it isn't completed yet." << endl;
        cout << "But, we can use this bool FUNCTION as our Base in Checking the Password." << endl;
    }
}