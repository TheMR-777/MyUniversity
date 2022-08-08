#include <iostream>
#include <string>
using namespace std;



class Mem_Tracker
{
	Mem_Tracker() {}
	Mem_Tracker(const Mem_Tracker& any) = delete;

	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;


	static Mem_Tracker& Get()
	{
		static Mem_Tracker s_Tracer;
		return s_Tracer;
	}

	uint32_t I_CurrentUsage()
	{
		return (TotalAllocated - TotalFreed);
	}

	void I_PrintCurrentUsage()
	{
		cout << "Curruntly Allocated : " << TotalAllocated - TotalFreed << " bytes in Memory\n";
	}

public:

	static uint32_t CurrentUsage()
	{
		return Get().I_CurrentUsage();
	}

	static void PrintCurrentUsage()
	{
		Get().I_PrintCurrentUsage();
	}


	friend void* operator new(size_t size);
	friend void operator delete(void* mem, size_t size);

};



struct Person
{
	int integer;
	float s_float;
	string s_string;
};

void* operator new(size_t size)
{
	Mem_Tracker::Get().TotalAllocated += size;
	cout << "Allocated : " << size << " bytes\n";
	return malloc(size);
}

void operator delete(void* mem, size_t size)
{
	Mem_Tracker::Get().TotalFreed += size;
	cout << "Freed : " << size << " bytes" << endl;
	free(mem);
}



int main()
{
	system("cls");
    
    // Allocating INT on HEAP

        int &i = *(new int(10));
        Mem_Tracker::PrintCurrentUsage();

	// Allocating FLOAT on HEAP

        float &f = *(new float(17.77f));
        Mem_Tracker::PrintCurrentUsage();

	// Allocating STRING on HEAP

        string &s = *(new string("Test String"));
        Mem_Tracker::PrintCurrentUsage();

	// Allocating Object on HEAP

        Person &Me_on_HEAP = *(new Person());
        Mem_Tracker::PrintCurrentUsage();

	// Deleting Everything

        delete &i; delete &f; delete &s; delete &Me_on_HEAP;
        Mem_Tracker::PrintCurrentUsage();
}