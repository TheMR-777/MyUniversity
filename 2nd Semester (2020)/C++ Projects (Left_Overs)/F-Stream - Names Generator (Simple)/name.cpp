#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Initializing String

        string filename;
    
    // Some Text before Operation

        cout << endl;
        cout << "It's a File Generator with my Logo." << endl;
        cout << "Enter the Filename to generate: ";
        getline(cin, filename);

    // Adding .txt file Extension after name u entered

        filename = filename + ".txt";
    
    // Initializing the Object, from Class of fstream to generate a file

        ofstream LOGO (filename.c_str());

    // Checking if the file is generated

        if (LOGO.is_open())
        {
            cout << "LOGO Generated!" << endl;
            system("timeout 2");
        }
        else
        {
            cout << "LOGO Generation Failed!" << endl;
            system("timeout 2");
        }
    
    // Logo Generation

        LOGO << " +-------------------------------------------------------------+" << endl;
        LOGO << " |                        Presented By                         |" << endl;
        LOGO << " +-------------------------------------------------------------+" << endl;
        LOGO << " |                                                             |" << endl;
        LOGO << " |  `7MMM.     ,MMF'`7MM*^*Mq.                                 |" << endl;
        LOGO << " |    MMMb    dPMM    MM   `MM.                                |" << endl;
        LOGO << " |    M YM   ,M MM    MM   ,M9    M******A'M******A'M******A'  |" << endl;
        LOGO << " |    M  Mb  M' MM    MMmmdM9     Y     A' Y     A' Y     A'   |" << endl;
        LOGO << " |    M  YM.P'  MM    MM  YM.          A'       A'       A'    |" << endl;
        LOGO << " |    M  `YM'   MM    MM   `Mb.       A'       A'       A'     |" << endl;
        LOGO << " |  .JML. `'  .JMML..JMML. .JMM.     A'       A'       A'      |" << endl;
        LOGO << " |                                  A'       A'       A'       |" << endl;
        LOGO << " |                         mmmmmmm A'       A'       A'        |" << endl;
        LOGO << " |                                                             |" << endl;
        LOGO << " +-------------------------------------------------------------+" << endl;

    // File Completion Code

        LOGO.close();
}