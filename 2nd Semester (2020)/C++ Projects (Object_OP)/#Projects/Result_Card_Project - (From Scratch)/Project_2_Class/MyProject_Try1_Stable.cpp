#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

struct Subject
{
    string name;
    float o_marks;
    float t_marks;
};

struct Profile
{
    int ID;
    string name;
    string roll;
    vector<Subject> subjects;
};





namespace class_function
{
    float Sub_Sum(const vector<Subject> &sbj , bool op)
    {
        float sum = 0;

        if ( op == 0 )
        {
            for (int i=0 ; i < sbj.size() ; i++)
            {
                sum += sbj[i].o_marks;
            }
            return sum;
        }
        else
        {
            for (int i=0 ; i < sbj.size() ; i++)
            {
                sum += sbj[i].t_marks;
            }
            return sum;
        }
        
    }
    
    float AVG(const vector<float> &o_marks , bool op = 1)
    {
        float sum = 0;

        for ( int i=0 ; i < o_marks.size() ; i++ )
        {
            sum += o_marks[i];
        }

        if ( op == 1 )
        {
            return (sum / o_marks.size());
        }
        else
        {
            return sum;
        }
        
    }

    float PT_AGE(const float obt , const float total)
    {
        return ( (obt * 100) / total );
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

void spaces(int size_in , int required = 30)
{
    int loop = required - size_in;

    for (int i = 0; i < loop; i++)
    {
        cout << " ";
    }
    
}

int float_count(float f)
{
    string s;
    stringstream out;
    out << f;
    s = out.str();

    return s.length();
}



void Settings(vector<Profile> &students)
{

}


void Input( vector<Profile> &students , int &temp_i , string &temp_s , float &temp_f )
{
    // Initialization

        Subject subject_t;
        Profile std_t;
        int m_limit=2;

    // Vector Filling
    
    Filling:

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

                        std_t.ID = i;

                    // Just a Bar

                        ID_ing:
                    
                        if ( i != 0 || temp_f == 1 )
                        {
                            cout << endl;
                            cout << " +-------------------------------------------------------------+" << endl;
                        }

                    // Inputting Name

                        cout << " | Enter Name of Student #" << i+1 << " : ";
                        getline(cin, temp_s);

                        if (temp_s != "F" && temp_s != " F" && temp_s != "F " && temp_s != " F " && temp_s != "f" && temp_s != " f" && temp_s != "f " && temp_s != " f " )
                        {
                            std_t.name = temp_s;
                        }
                        else
                        {
                            cin.clear();
                            cin.sync();
                            system("cls");
                            break;
                        }
                        

                    // Inputting Roll number

                        cout << " |-------------------------------------------------------------|" << endl;
                        cout << " | - Enter Roll Number of " << std_t.name << " : ";
                        getline(cin, std_t.roll);

                    // Inputting Individual Marks

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
                            cin >> subject_t.o_marks;

                            cout << " | - Enter  TOTAL   Marks of Subject #" << j+1 << " : ";
                            cin >> subject_t.t_marks;

                            std_t.subjects.push_back(subject_t);
                        }

                    // Confirmation

                        cin.clear();
                        cin.sync();
                        cout << " +-------------------------------------------------------------+" << endl;
                        cout << " | Check the above Informaion U entered. Enter 0 to make       |" << endl;
                        cout << " | changes, or Enter any other key to Move Forward.            |" << endl;
                        cout << " +-------------------------------------------------------------+" << endl;
                        cout << " |" << endl;
                        cout << " +---> Input : ";
                        getline(cin , temp_s);
                    
                    // Flushing + Finalization

                        temp_f = 0.0;
                        system("cls");
                        cin.clear();
                        cin.sync();

                        if (temp_s == "0")
                        {
                            temp_f = 1;
                            goto ID_ing;
                        }
                        else
                        {
                            temp_s = "";
                            students.push_back(std_t);
                            
                            std_t.subjects.clear();
                        }
                        
                }


        }


        catch(...)
        {
            cout << endl;
            cout << "Something went Wrong! U just Crashed the Program, plz Enter Input as asked only!" << endl;
            cout << endl;
            system("pause");
            goto Filling;
        }
}




void Result_Gen(const vector<Profile> &students)
{
    // Initializing Temporary Stuff

        string stg_t;
        float flt_o , flt_t , flt_temp;

    // Result Card

        cout << endl;
        cout << " +----------------------------------------------------------------------------------------------------+" << endl;
        cout << " | Names of Students" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
        cout << " |                                                                                                    |" << endl;

        for( int i=0 ; i < students.size() ; i++ )
        {
            // Name Generation

                cout << " | " << students[i].name;
                spaces(students[i].name.size());

            // Obtained Marks

                flt_o = class_function::Sub_Sum(students[i].subjects , false);
                cout << flt_o;
                spaces(float_count(flt_o) , 17);

            // Total Marks

                flt_t = class_function::Sub_Sum(students[i].subjects , true);
                cout << flt_t;
                spaces(float_count(flt_t) , 17);

            // Percentage

                flt_temp = class_function::PT_AGE(flt_o , flt_t);
                cout << flt_temp;
                spaces(float_count(flt_temp) ,10);

            // Roll_Number

                cout << students[i].roll;
                spaces(students[i].roll.size() ,25);
                cout << "|" << endl;

            // Flushing

                stg_t = "";
                flt_temp = 0.0;
                flt_o = 0.0;
                flt_t = 0.0;
        }

        cout << " |                                                                                                    |" << endl;
        cout << " +----------------------------------------------------------------------------------------------------+" << endl;
        cout << endl;
}




int main()
{
    // Initialization

        float temp_f;
        int temp_i = 0;
        string temp_s;
        vector<Profile> students;
        
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
        cout << " | REMEMBER: Set the settings in the Settings Tab first        |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << endl;
        system("pause");
        system("cls");

    // Decision


        MAIN:

        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " | Select any of the Options below :-                          |" << endl;
        cout << " |                                                             |" << endl;
        cout << " | 1. Open Interface to Generate Result Card                   |" << endl;
        cout << " | 2. Open Settings Menu                                       |" << endl;
        cout << " |                                                             |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " |" << endl;
        cout << " +---[Input]---> ";
        getline(cin, temp_s);
        stringstream(temp_s) >> temp_i;
        cin.clear() ; cin.sync();

        system("cls");
        switch (temp_i)
        {
            case 1:
            {
                Input(students , temp_i , temp_s , temp_f);
                cout << endl;
                cin.get();
                break;
            }

            case 2:
            {
                Settings(students);
                break;
            }
                
            
            default:
            {
                cout << "Invalid Input!" << endl;
                cout << endl;
                goto MAIN;
                break;
            }
        }

        

        // Menu For Type of Result

            Result_Menu:
            cout << " +-------------------------------------------------------------+" << endl;
            cout << " |          Enter type of the result u wanna Generate          |" << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << " |                                                             |" << endl;
            cout << " | 1. General List for all Students                            |" << endl;
            cout << " | 2. Students-Wise List for Every Student                     |" << endl;
            cout << " | 3. Subject-Wise List, for every Subject                     |" << endl;
            cout << " |                                                             |" << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " +----[Input]---> ";
            getline(cin, temp_s);
            cin.clear() ; cin.sync();

            temp_i = stoi(temp_s);

            system("cls");
            switch (temp_i)
            {
                case 1:
                {
                    Result_Gen(students);
                    system("pause");
                    system("cls");
                    break;
                }

                default:
                {
                    cout << endl;
                    cout << "Invalid Input" << endl;
                    goto Result_Menu;
                }
            }

            Decision:
            cout << " +-------------------------------------------------------------+" << endl;
            cout << " |                 Enter your decision below                   |" << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << " |                                                             |" << endl;
            cout << " | 1. Go to Main Menu                                          |" << endl;
            cout << " | 2. Go to Result Menu                                        |" << endl;
            cout << " |                                                             |" << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << " |" << endl;
            cout << " +--[Input]--> ";
            getline(cin, temp_s);

            temp_i = stoi(temp_s);

            system("cls");
            switch (temp_i)
            {
                case 1:
                {
                    goto MAIN;
                }

                case 2:
                {
                    goto Result_Menu;
                }

                default:
                {
                    cout << "Invalid Input" << endl;
                    cout << endl;
                    goto Decision;
                }
            }
        


}
