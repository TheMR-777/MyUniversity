#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

struct Profile
{
    int ID;
    string name;
    string roll;
    vector<float> t_marks;
    vector<float> o_marks;

    float get_avg()
    {
        float t_sum = 0;
        float o_sum = 0;

        for ( int i = 0 ; i < t_marks.size() ; i++ )
        {
            t_sum += t_marks[i];
            o_sum += o_marks[i];
        }

        return ((o_sum * 100) / t_sum);
    }
};

namespace class_f
{
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

                flt_o = class_f::AVG(students[i].o_marks , false);
                cout << flt_o;
                spaces(float_count(flt_o) , 17);

            // Total Marks

                flt_t = class_f::AVG(students[i].t_marks , false);
                cout << flt_t;
                spaces(float_count(flt_t) , 17);

            // Percentage

                flt_temp = class_f::PT_AGE(flt_o , flt_t);
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
        Profile std_t;
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
        cout << " | REMEMBER: Set the settings in the Settings Tab first        |" << endl;
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
                            cin >> temp_f;
                            std_t.o_marks.push_back(temp_f);

                            cout << " | - Enter  TOTAL   Marks of Subject #" << j+1 << " : ";
                            cin >> temp_f;
                            std_t.t_marks.push_back(temp_f);
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
                            
                            std_t.o_marks.clear();
                            std_t.t_marks.clear();
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
