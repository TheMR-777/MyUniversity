#include <iostream>
#include <stdlib.h>
using namespace std;
/*Program to demonstrate simple multiple inheritance*/
class Fish
{
public:
 void swim(){
 cout<<"\n In method swim";
 }
};
class Woman
{
public:
 void walk(){
 cout<<"\n In method walk"<<endl;
 }
};
class Mermaid : public Woman,public Fish
{
};
int main( )
{
Mermaid mermaid;
/*This Mermaid object will have two implicit objects one of Fish class and one of
Woman class*/
mermaid.swim();
mermaid.walk();
system("PAUSE");
return 0;
}
