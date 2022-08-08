#include <iostream>
#include <string>
using namespace std;



class Tracer
{
	Tracer() {}
	Tracer(const Tracer& any) = delete;

	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;


	static Tracer& Get()
	{
		static Tracer s_Tracer;
		return s_Tracer;
	}

	uint32_t I_CurrentUsage()
	{
		return (TotalAllocated - TotalFreed);
	}

	void I_PrintCurrentUsage()
	{
		cout << "Curruntly Allocated : " << TotalAllocated - TotalFreed << " Bytes in Memory\n";
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

void* operator new(size_t size)
{
	Tracer::Get().TotalAllocated += size;
	cout << "Allocated : " << size << " Bytes\n";
	return malloc(size);
}

void operator delete(void* mem, size_t size)
{
	Tracer::Get().TotalFreed += size;
	cout << "Freed : " << size << " Bytes" << endl;
	free(mem);
}







struct Person
{
	int integer;
	float s_float;
	string s_string;
};

int main()
{
	system("cls");
	cout << "Currently Allocated : " << Tracer::CurrentUsage() << " Bytes in Memory" << endl;
    
    // Allocating INT on HEAP

        int &i = *(new int(10));
        Tracer::PrintCurrentUsage();

	// Allocating FLOAT on HEAP

        float &f = *(new float(17.77f));
        Tracer::PrintCurrentUsage();

	// Allocating STRING on HEAP

        string &s = *(new string("Test String"));
        Tracer::PrintCurrentUsage();

	// Allocating Object on HEAP

        Person &Me_on_HEAP = *(new Person{ 12, 17.5, "Test" });
        Tracer::PrintCurrentUsage();

	// Deleting Everything

        delete &i; delete &f; delete &s; delete &Me_on_HEAP;
        Tracer::PrintCurrentUsage();
}