#include <iostream>
using namespace std;

struct Person
{
	int integer;
    float s_float;
    string s_string;
};

void* operator new(size_t size)
{
	cout << "Allocated : " << size << " bytes\n";
	return malloc(size);
}

void operator delete(void* mem, size_t size)
{
    cout << "Freed : " << size << " bytes" << endl;
    free(mem);
}



int main()
{
    // Allocating INT on HEAP

        int &i = *(new int(10));

    // Allocating FLOAT on HEAP

        float &f = *(new float(17.77));

    // Allocating STRING on HEAP

        string &s = *(new string("Test String"));

	// Allocating Object on HEAP
	
		Person &Me_on_HEAP = *(new Person());

    // Deleting Everything

        delete &i; delete &f; delete &s; delete &Me_on_HEAP;
}