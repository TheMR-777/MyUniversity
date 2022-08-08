#include<iostream>
#include<cstring>
using namespace std;
// Assignment operator overloading concept
  // Command to run this :
// clear && g++ 'Concepts/2.8.cpp' && ./a.out && rm a.out
class String
{
	int size;
	char* bufferPtr;

public:

	String()
  {
    bufferPtr = NULL;
    size = 0;
  } // default constructor

	String(char*); // overloaded constructor
	String& operator = (const String&); //copy constructor & assignment operator overloading

};

String::String(char* ptr) {
	if (ptr != NULL) {
		size = strlen(ptr);
		bufferPtr = new char[size + 1];
		strcpy(bufferPtr, ptr);
		cout << "the value of the obj is: " << bufferPtr << endl;
	}
	else {
		bufferPtr = NULL;
		size = 0;
	}
}

String& String :: operator = (const String& rhs) 
{
	size = rhs.size;
	delete[] bufferPtr;
	if (rhs.size != 0) {
		bufferPtr = new char[rhs.size + 1];
		strcpy(bufferPtr, rhs.bufferPtr);
		cout << " 1st obj=2nd obj=: " << bufferPtr << endl;

	}
	else bufferPtr = NULL;
	return *this;
}


int main()
{
	String str1("ABC");
	String str2("DEF");
	str1 = str2;
	return 0;
}




