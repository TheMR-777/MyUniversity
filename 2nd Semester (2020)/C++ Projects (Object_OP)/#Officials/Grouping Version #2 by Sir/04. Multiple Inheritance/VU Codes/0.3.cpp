#include <iostream>
#include <stdlib.h>
using namespace std;
/*Program to demonstrate simple multiple inheritance*/
class Fish
{
public:
 void eat(){
 cout<<"\n In Fish eat method ";
 }
};
class Woman
{
public:
 void eat(){
 cout<<"\n In Woman eat method \n"<<endl;
 }
};
class Mermaid : public Woman,public Fish
{
 public:

 void eat()
 {
 
 cout<<"\n In Mermaid eat method "<<endl;
 cout<<"\n Explicity calling Woman eat method...."<<endl;

 Woman::eat();// eat methode of woman class

 }

};
int main ()
{
Mermaid mermaid;
/*This Mermaid object will have two implicit objects one of Fish class and one of
Woman class*/
mermaid.eat();
/*Calling Mermaid eat method*/
system("PAUSE");
return 0;
}
 
