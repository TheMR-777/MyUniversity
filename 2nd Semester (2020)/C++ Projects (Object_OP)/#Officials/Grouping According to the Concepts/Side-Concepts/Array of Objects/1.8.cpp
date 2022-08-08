#include<iostream>
using namespace std;
//array of object concept
 // Command to run this :
// clear && g++ 'Concepts/1.8.cpp' && ./a.out && rm a.out
 class Test
 {

public:
int 	a=0;
 Test(int i)
 {
 	cout<<" array of object hold value: "<< i<<endl;
 }
};
int main(){
 Test array[2] = {Test(47),Test(61)};// initializing thr array of object
 return 0;
} 
