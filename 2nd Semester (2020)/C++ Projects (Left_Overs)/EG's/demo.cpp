#include "tinycon.h"

// inherited class
class tcon : public tinyConsole
{
public:
	tcon (std::string s): tinyConsole(s) {;}
	
	int trigger (std::string s)
	{
		if (s == "exit")
		{
			std::cout << "Exiting..." << std::endl;
			quit();
		} else 
		std::cout << s << std::endl;
		return 0;
	}

	int hotkeys(char c)
	{
		// pressing tab will set the line buffer to "moo"
		if (c == TAB)
		{
			int length;

			length = buffer.size();
			for (int i=0; i<length; i++)
			{
				std::cout << "\b \b";
			}
		  setBuffer("moo");
			length = buffer.size();

			std::cout << "moo";
			return 1;
		}
		return 0;
	}
};

int main(int argc, char** argv) {
	std::cout << "Starting tinycon demo..." << std::endl;
	std::cout << "(hit TAB to set the line-buffer to 'moo')" << std::endl;
	tcon tc (std::string("prompt> "));

	// test getLine
	//tc.getLine(M_PASSWORD);
	
	// run console
	tc.run();
	return 0;
}
