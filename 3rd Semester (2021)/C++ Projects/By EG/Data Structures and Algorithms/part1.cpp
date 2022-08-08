#include<iostream>
using namespace std;
class  signup
{   string username,login_pass,pass,email,confirm_email,confirm_pass,login_username;
    int x;
public :
    void enter_data()
    {   cout<<"Enter Username:";
        cin>>username;
        cout<<"Enter Email:";
        cin>>email;
        cout<<"Enter Email again:";
        cin>>confirm_email;
        cout<<"Enter Passowrd:";
        cin>>pass;
        cout<<"Enter Password again:";
        cin>>confirm_pass;
        if(email==confirm_email || pass==confirm_pass)
        {   cout<<"Account created successfully\n";

        }
        else
        {   cout<<"Password or email donot match  enter Again \n";
            enter_data();
        }

    }
    void login()
    {
        cout<<"Enter username or Email :\n";
        cin>>login_username;
        
        cout<<"Enter Password \n";
        cin>>login_pass;
        if( login_username==username || login_username==email && login_pass==pass)
        {
        }
        else
        {   cout<<" Invalid Email or Username\n";
recheck:
            cout<<" Create new account  or login ";
            cout<<"Enter 1 to create new account\n";
            cout<<"Enter 2 to login exiting account\n";

            cin>>x;
            {
                if(x=1)
                {
                    enter_data();
                }
                else if(x=2)
                {   login();
                }
                else
                {
                    cout<<"Invalid Choice  Choose again ";
                    goto recheck;
                }


            }

        }
    }
};
int main()
{
    cout << "Hello,World!\n";
    signup L1;
    {   L1.login();
    }
    return 0;
}