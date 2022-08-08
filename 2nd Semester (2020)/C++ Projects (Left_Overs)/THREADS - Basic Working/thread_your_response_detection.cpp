#include <iostream> 
#include <thread>
using namespace std;


static bool is_Finished = false;
void The_Function()
{
	while (!is_Finished)
	{
		cout << "Press any key to stop the Loop" << endl;
	}
}



int main()
{
	// Initializing The Thread

	    thread The_Work(The_Function);

	// Waiting for user response

	    cin.get();

	// Stopping the Thread

	    is_Finished = 1;

	// Varifying if the Loop Stopped

		The_Work.join();
        cout << "YES, The Loop stopped!" << endl;
        cin.get();
}