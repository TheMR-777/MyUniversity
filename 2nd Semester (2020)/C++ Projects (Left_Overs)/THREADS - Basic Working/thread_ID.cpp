#include <iostream> 
#include <thread>
using namespace std;


static bool is_Finished = false;

void print_msg()
{
	while (!is_Finished)
	{
		cout << "| Running Thread #" << this_thread::get_id() << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Press ENTER to stop the Loop ..." << endl;
		cout << "----------------------------------------------" << endl;
		this_thread::sleep_for(0.5s);
	}
}

int main()
{
	// Initializing The Thread

	thread do_work(print_msg);

	// Waiting for user response

	cin.get();

	// Stopping the Thread

	is_Finished = 1;
	do_work.join();

	// Varifying if the Loop Stopped

	cout << " YES, The Loop stopped!" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " ID of main Thread #" << this_thread::get_id() << endl;
	cin.get();
}