#include<iostream>
using namespace std;
class Test{
public:
 Test(int i)
 
 {
 	cout<<"the value assgned to me is: "<<i<<endl;
 }
};
int main(){
 Test array[2] = {Test(61),Test(47)};// array of objects and initializing the array of objects
 return 0;
} 
