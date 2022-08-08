#include <iostream> 
#include <thread>
using namespace std;


static bool is_Finished = false;
void The_Function()
{
	using namespace std::literals::chrono_literals;

	while (!is_Finished)
	{
		cout << "Press ENTER to stop the Loop ..." << endl;
		this_thread::sleep_for(0.5s);
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