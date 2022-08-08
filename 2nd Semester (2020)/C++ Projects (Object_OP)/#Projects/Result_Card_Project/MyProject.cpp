#include <iostream>
#include <vector>
using namespace std;

struct Profile
{
    int ID;
    string name;
    string roll;
    vector<float> t_marks;
    vector<float> o_marks;
};

namespace class_f
{
    double AVG(const vector<float> &o_marks , bool op = 0)
    {
        double sum = 0;

        for ( int i=0 ; i < o_marks.size() ; i++ )
        {
            sum += o_marks[i];
        }

        if ( op == 0 )
        {
            return (sum / o_marks.size());
        }
        else
        {
            return sum;
        }
        
    }

    float PT_AGE(const float obt , const float tot)
    {
        return ( (obt * 100) / tot );
    }
}

namespace custom
{
    void getline(std::istream& in, std::string& word, char delim = '\n')
    {
        char ch;

        do
        {
            in.get(ch);
            word += ch;
        } while (ch != delim);
    }
}

void Result(const vector<Profile> &students)
{
    
}




int main()
{
    // Initialization

        float temp_i;
        string temp_s;
        Profile std;
        vector<Profile> students;
        int m_limit=2;
        
    // Introduction

        system("cls");
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " |                        Presented By                         |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " |                                                             |" << endl;
        cout << " |  `7MMM.     ,MMF'`7MM*^*Mq.                                 |" << endl;
        cout << " |    MMMb    dPMM    MM   `MM.                                |" << endl;
        cout << " |    M YM   ,M MM    MM   ,M9    M******A'M******A'M******A'  |" << endl;
        cout << " |    M  Mb  M' MM    MMmmdM9     Y     A' Y     A' Y     A'   |" << endl;
        cout << " |    M  YM.P'  MM    MM  YM.          A'       A'       A'    |" << endl;
        cout << " |    M  `YM'   MM    MM   `Mb.       A'       A'       A'     |" << endl;
        cout << " |  .JML. `'  .JMML..JMML. .JMM.     A'       A'       A'      |" << endl;
        cout << " |                                  A'       A'       A'       |" << endl;
        cout << " |                         mmmmmmm A'       A'       A'        |" << endl;
        cout << " |                                                             |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " | It's a Result Card Generator. Only U have to Input the data |" << endl;
        cout << " | of students as asked. The Whole list will be generated as a |" << endl;
        cout << " | txt file. Make sure to enter data correctly. I've managed   |" << endl;
        cout << " | to Optimize ID-ing Errors as far as We can in C++ Language. |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " | REMEMBER: Enter Number of Subjects for Each Students, in    |" << endl;
        cout << " |           the External File first!                          |" << endl; 
        cout << " +-------------------------------------------------------------+" << endl;
        cout << endl;
        system("pause");

    // Input

        MAIN:

        try
        {
            system("cls");
            cout << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << " | Enter \"F\" when finished entering names of the Students.     |" << endl;
            cout << " |-------------------------------------------------------------|" << endl;

            // ID-ing Students

                for (int i=0 ; temp_s != "F" ; i++)
                {
                    // Tagging the Student

                        std.ID = i;

                    // Just a Bar

                        ID_ing:
                    
                        if ( i != 0 || temp_i == 1 )
                        {
                            cout << endl;
                            cout << " +-------------------------------------------------------------+" << endl;
                        }

                    // Inputting Name

                        cout << " | Enter Name of Student #" << i+1 << " : ";
                        getline(cin, temp_s);

                        if (temp_s != "F" || temp_s != " F"|| temp_s != "F " || temp_s != " F " || temp_s != "f" || temp_s != " f" || temp_s != "f " || temp_s != " f " )
                        {
                            std.name = temp_s;
                        }
                        else
                        {
                            cin.clear();
                            cin.sync();
                            break;
                        }
                        

                    // Inputting Roll number

                        cout << " |-------------------------------------------------------------|" << endl;
                        cout << " | - Enter Roll Number of " << std.name << " : ";
                        getline(cin, std.roll);

                    // Inputting Indivisual Marks

                        for ( int j=0 ; j < m_limit ; j++ )
                        {
                            if ( i == 0 )
                            {
                                cout << " |-------------------------------------------------------------|" << endl;
                            }
                            else
                            {
                                cout << " | ----------------------------------------------------------- |" << endl;
                            }
                            
                            cout << " | - Enter Obtained Marks of Subject #" << j+1 << " : ";
                            cin >> temp_i;
                            std.o_marks.push_back(temp_i);

                            cout << " | - Enter  TOTAL   Marks of Subject #" << j+1 << " : ";
                            cin >> temp_i;
                            std.t_marks.push_back(temp_i);
                        }

                    // Confirmation

                        cin.clear();
                        cin.sync();
                        cout << " +-------------------------------------------------------------+" << endl;
                        cout << " | Check the above Informaion U entered. Enter 0 to make       |" << endl;
                        cout << " | changes, or Enter any other key to Move Forward.            |" << endl;
                        cout << " +-------------------------------------------------------------+" << endl;
                        cout << " --> Input : ";
                        getline(cin , temp_s);
                    
                    // Flushing + Finalization

                        temp_i = 0;
                        system("cls");
                        cin.clear();
                        cin.sync();

                        if (temp_s == "0")
                        {
                            temp_i = 1;
                            goto ID_ing;
                        }
                        else
                        {
                            temp_s = "";
                            students.push_back(std);
                        }
                        
                }


        }


        catch(...)
        {
            cout << endl;
            cout << "Something went Wrong! U just Crashed the Program, plz Enter Input as asked only!" << endl;
            cout << endl;
            system("pause");
            goto MAIN;
        }
        


}