#include <iostream>
using namespace std;



struct Mem_Tracker
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage()
    {
        return ( TotalAllocated - TotalFreed );
    }

    void PrintCurrentUsage()
    {
        cout << "Curruntly Allocated : " << TotalAllocated - TotalFreed << " bytes in Memory\n";
    }
}; static Mem_Tracker s_Tracer;



struct Person
{
	int integer;
    float s_float;
    string s_string;
};

void* operator new(size_t size)
{
	s_Tracer.TotalAllocated += size;
    cout << "Allocated : " << size << " bytes\n";
	return malloc(size);
}

void operator delete(void* mem, size_t size)
{
    s_Tracer.TotalFreed += size;
    cout << "Freed : " << size << " bytes" << endl;
    free(mem);
}



int main()
{
    // Allocating INT on HEAP

        int &i = *(new int(10));
        s_Tracer.PrintCurrentUsage();

    // Allocating FLOAT on HEAP

        float &f = *(new float(17.77));
        s_Tracer.PrintCurrentUsage();

    // Allocating STRING on HEAP

        string &s = *(new string("Test String"));
        s_Tracer.PrintCurrentUsage();

	// Allocating Object on HEAP
	
		Person &Me_on_HEAP = *(new Person());
        s_Tracer.PrintCurrentUsage();

    // Deleting Everything

        delete &i; delete &f; delete &s; delete &Me_on_HEAP;
        s_Tracer.PrintCurrentUsage();
}