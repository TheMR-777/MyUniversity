#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

struct Subject
{
    int ID;
    string name;
    float o_marks;
    int t_marks;
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

namespace External
{
    void Write(vector<Subject> sbj , string filename)
    {
        ofstream o_file (filename);

        for ( int i=0 ; i < sbj.size() ; i++)
        {
            o_file << sbj[i].name << endl;
            o_file << sbj[i].t_marks << endl;
        }

        o_file.close();
    }

    vector<Subject> Scan(string filename)
    {
        // Initialization

            string temp_s;
            Subject subject_t;
            vector<string> data;
            vector<Subject> subjects;
            ifstream i_file (filename);

        // Scanning

            while ( getline(i_file, temp_s) )
            {
                data.push_back(temp_s);
            }

        // Filling Subjects

            for (int i = 0; i < data.size(); i++)
            {
                if (i % 2 == 0)
                {
                    subject_t.name = data[i];
                    subject_t.t_marks = stoi(data[i + 1]);
                    subjects.push_back(subject_t);
                }
            }

        // Finalization

            i_file.close();
            return subjects;
    }
}

namespace Utilities
{
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



    void Settings(vector<Subject> &subjects , int temp_i , string temp_s )
    {
        // Initialization

            subjects.clear();
            int total;
            bool same;
            Subject subject_t;
            
        // Settings Menu

            system("cls");

            Settings:

            cout << endl;
            cout << " +-----------------------------------------------------------------+" << endl;
            cout << " | Select any Option listed below :-                               |" << endl;
            cout << " |                                                                 |" << endl;
            cout << " | [ 1 ] - Set Pre-Configured Settings for Subjects                |" << endl;
            cout << " | [ 2 ] - Go back to Main Menu                                    |" << endl;
            cout << " |                                                                 |" << endl;
            cout << " +-----------------------------------------------------------------+" << endl;
            cout << " |" << endl;
            cout << " +--[Input]--> ";
            getline(cin, temp_s); cin.clear() ; cin.sync();
            stringstream(temp_s) >> temp_i;

            system("cls");
            switch (temp_i)
            {
                case 1:
                {
                    // Input Menu

                        cout << " +-----------------------------------------------------------------+" << endl;
                        cout << " | Enter names of the Subjects as asked. Enter \"F\" when finished   |" << endl;
                        cout << " | entering names of the subjects.                                 |" << endl;
                        cout << " | --------------------------------------------------------------- |" << endl;
                        cout << " | Answer a little question first, does all the subjects have same |" << endl;
                        cout << " | total markes ?                                                  |" << endl;
                        cout << " |" << endl;
                        cout << " +--{Y/N}--> ";
                        getline(cin, temp_s); cin.clear(); cin.sync();

                    // If total marks are Identical

                        if(temp_s == "Y" || temp_s == "y")
                        {
                            cout << " |" << endl;
                            cout << " | Enter Total marks for all subjects : ";
                            getline(cin, temp_s); cin.clear(); cin.sync();
                            stringstream(temp_s) >> total;
                            same = 1;
                        }
                        else
                        {
                            same = 0;
                        }
                        cout << " |" << endl;

                    // Inputting begins here
                    
                        for ( int i=0 ; true ; i++)
                        {
                            cout << " | --------------------------------------------------------------- |" << endl;
                            cout << " | Enter name of Subject #" << i+1 << " : ";
                            getline(cin, temp_s); cin.clear() ; cin.sync();
                            
                            if ( temp_s != "F" && temp_s != " F" && temp_s != "F " && temp_s != " F " && temp_s != "f" && temp_s != " f" && temp_s != "f " && temp_s != " f " )
                            {
                                subject_t.name = temp_s;
                            }
                            else
                            {
                                External::Write(subjects, "Subjects");
                                temp_s = "";
                                break;
                            }
                            
                            
                            if (same == 0)
                            {
                                cout << " | Enter Total marks of " << temp_s << " : ";
                                getline(cin, temp_s); cin.clear(); cin.sync();
                                stringstream(temp_s) >> subject_t.t_marks;
                            }
                            else
                            {
                                subject_t.t_marks = total;
                            }

                            subjects.push_back(subject_t);
                        }

                    break;
                }

                case 2:
                {
                    return;
                }
                
                default:
                {
                    cout << "Invalid Input!" << endl;
                    cout << endl;
                    goto Settings;
                    break;
                }
            }
    }


    void Input( vector<Profile> &students, vector<Subject> &subjects , int &temp_i , string &temp_s , float &temp_f )
    {
        // Initialization

            students.clear();
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

                    for (int i=0 ; true ; i++)
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

                            for ( int j=0 ; j < subjects.size() ; j++ )
                            {
                                subjects[j].ID = j;
                                
                                if ( i == 0 )
                                {
                                    cout << " |-------------------------------------------------------------|" << endl;
                                }
                                else
                                {
                                    cout << " | ----------------------------------------------------------- |" << endl;
                                }
                                
                                cout << " | - Enter Obtained Marks of [ " << subjects[j].name << " ] : ";
                                cin >> subjects[j].o_marks;
                                std_t.subjects.push_back(subjects[j]);
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

    void sort(vector<Profile> &students, int op, int i = 0)
    {
        // Key for Operation
        // 1 for General List
        // 2 for Student Wise
        // 3 for Subject Wise

        int replacer;
        vector<float> receptor;

        switch (op)
        {
            case 1:
            {
                for ( int i=0 ; i < students.size() ; i++ )
                {
                    receptor.push_back(class_function::Sub_Sum(students[i].subjects , false));
                }

                for (int i=0 ; i < (receptor.size()-1) ; i++)
                {
                    for (int j=(i+1) ; j < receptor.size() ; j++)
                    {
                        if (receptor[j] > receptor[i])
                        {
                            replacer = receptor[j];
                            receptor[j] = receptor[i];
                            receptor[i] = replacer;

                            replacer = students[j].ID;
                            students[j].ID = students[i].ID;
                            students[i].ID = replacer;
                        }
                    }
                }

                break;
            }

            case 2:
            {
                for ( int i=0 ; i < students.size() ; i++ )
                {
                    for ( int j=0 ; j < students[i].subjects.size() ; j++ )
                    {
                        receptor.push_back(students[i].subjects[j].o_marks);
                    }

                    for ( int j=0 ; j < (receptor.size()-1) ; j++ )
                    {
                        for (int k=(j+1) ; k < receptor.size() ; k++)
                        {
                            if (receptor[k] > receptor[j])
                            {
                                replacer = receptor[k];
                                receptor[k] = receptor[j];
                                receptor[j] = replacer;

                                replacer = students[i].subjects[k].ID;
                                students[i].subjects[k].ID = students[i].subjects[j].ID;
                                students[i].subjects[j].ID = replacer;
                            }
                        }
                    }
                    receptor.clear();
                }
                break;
            }

            case 3:
            {
                for ( int j=0 ; j < students.size() ; j++ )
                {
                    receptor.push_back(students[j].subjects[i].o_marks);
                }

                for ( int j=0 ; j < (receptor.size()-1) ; j++ )
                {
                    for (int k=(j+1) ; k < receptor.size() ; k++)
                    {
                        if (receptor[k] > receptor[j])
                        {
                            replacer = receptor[k];
                            receptor[k] = receptor[j];
                            receptor[j] = replacer;

                            replacer = students[k].ID;
                            students[k].ID = students[j].ID;
                            students[j].ID = replacer;
                        }
                    }
                }
                receptor.clear();
                break;
            }
        }
    /*
        for (int i=0 ; i < (V.size()-1) ; i++)
        {
            for (int j=(i+1) ; j < V.size() ; j++)
            {
                if (op == 0)
                {
                    if (V[j] < V[i])
                    {
                        temp = V[j];
                        V[j] = V[i];
                        V[i] = temp;
                    }
                }
                else
                {
                    if (V[j] > V[i])
                    {
                        temp = V[j];
                        V[j] = V[i];
                        V[i] = temp;
                    }
                }
            }
        }
    */
    }
}

namespace Result
{
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

                    cout << " | " << students[students[i].ID].name;
                    Utilities::spaces(students[students[i].ID].name.size());

                // Obtained Marks

                    flt_o = class_function::Sub_Sum(students[students[i].ID].subjects , false);
                    cout << flt_o;
                    Utilities::spaces(Utilities::float_count(flt_o) , 17);

                // Total Marks

                    flt_t = class_function::Sub_Sum(students[students[i].ID].subjects , true);
                    cout << flt_t;
                    Utilities::spaces(Utilities::float_count(flt_t) , 17);

                // Percentage

                    flt_temp = class_function::PT_AGE(flt_o , flt_t);
                    cout << flt_temp;
                    Utilities::spaces(Utilities::float_count(flt_temp) ,10);

                // Roll_Number

                    cout << students[i].roll;
                    Utilities::spaces(students[i].roll.size() ,25);
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

    void Subject_wise(vector<Profile> &students)
    {
        // Initializing Temporary Stuff

            string stg_t;
            float flt_temp;

        // Result Card

            for ( int i=0 ; i < students[i].subjects.size() ; i++ )
            {
                Utilities::sort(students, 3, i);
                system("cls");
                cout << endl;
                cout << " +----------------------------------------------------------------------------------------------------+" << endl;
                cout << " | Subject [ " << i+1 << " / " << students[0].subjects.size() << " ] - " << students[0].subjects[i].name; Utilities::spaces(students[0].subjects[i].name.size() , 70); cout << "//////// |" << endl;
                cout << " +----------------------------------------------------------------------------------------------------+" << endl;
                cout << " | Names of Students" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
                cout << " |                                                                                                    |" << endl;

                for( int j=0 ; j < students.size() ; j++ )
                {
                    // Name Generation

                        cout << " | " << students[students[j].ID].name;
                        Utilities::spaces(students[students[j].ID].name.size());

                    // Obtained Marks

                        cout << students[students[j].ID].subjects[i].o_marks;
                        Utilities::spaces(Utilities::float_count(students[students[j].ID].subjects[i].o_marks) , 17);

                    // Total Marks

                        cout << students[students[j].ID].subjects[i].t_marks;
                        Utilities::spaces(Utilities::float_count(students[students[j].ID].subjects[i].t_marks) , 17);

                    // Percentage

                        flt_temp = class_function::PT_AGE(students[students[j].ID].subjects[i].o_marks , students[students[j].ID].subjects[i].t_marks);
                        cout << flt_temp;
                        Utilities::spaces(Utilities::float_count(flt_temp) ,10);

                    // Roll_Number

                        cout << students[students[j].ID].roll;
                        Utilities::spaces(students[j].roll.size() ,25);
                        cout << "|" << endl;

                    // Flushing

                        stg_t = "";
                        flt_temp = 0.0;
                }

                cout << " |                                                                                                    |" << endl;
                cout << " +----------------------------------------------------------------------------------------------------+" << endl;
                cout << endl;
                system("pause");

                for ( int i = 0 ; i < students.size() ; i++ )
                {
                    students[i].ID = i;
                }
            }
    }

    void Student_wise(const vector<Profile> &students)
    {
        // Initializing Temporary Stuff

            string stg_t;
            float flt_temp;

        // Result Card

            for ( int i=0 ; i < students.size() ; i++ )
            {
                system("cls");
                cout << endl;
                cout << " +----------------------------------------------------------------------------------------------------+" << endl;
                cout << " | Student [ " << i+1 << " / " << students.size() << " ] - " << students[i].name; Utilities::spaces(students[i].name.size() , 70); cout << "//////// |" << endl;
                cout << " +----------------------------------------------------------------------------------------------------+" << endl;
                cout << " | Names of Subjects" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
                cout << " |                                                                                                    |" << endl;

                for( int j=0 ; j < students[i].subjects.size() ; j++ )
                {
                    // Name Generation

                        cout << " | " << students[i].subjects[students[i].subjects[j].ID].name;
                        Utilities::spaces(students[i].subjects[students[i].subjects[j].ID].name.size());

                    // Obtained Marks

                        cout << students[i].subjects[students[i].subjects[j].ID].o_marks;
                        Utilities::spaces(Utilities::float_count(students[i].subjects[students[i].subjects[j].ID].o_marks) , 17);

                    // Total Marks

                        cout << students[i].subjects[students[i].subjects[j].ID].t_marks;
                        Utilities::spaces(Utilities::float_count(students[i].subjects[students[i].subjects[j].ID].t_marks) , 17);

                    // Percentage

                        flt_temp = class_function::PT_AGE(students[i].subjects[students[i].subjects[j].ID].o_marks , students[i].subjects[students[i].subjects[j].ID].t_marks);
                        cout << flt_temp;
                        Utilities::spaces(Utilities::float_count(flt_temp) ,10);

                    // Roll_Number

                        cout << students[i].roll;
                        Utilities::spaces(students[i].roll.size() ,25);
                        cout << "|" << endl;

                    // Flushing

                        stg_t = "";
                        flt_temp = 0.0;
                }

                cout << " |                                                                                                    |" << endl;
                cout << " +----------------------------------------------------------------------------------------------------+" << endl;
                cout << endl;
                system("pause");
            }
    }

}






int main()
{
    // Initialization

        float temp_f;
        int temp_i = 0;
        string temp_s;
        Subject subject_t;
        vector<Subject> subjects = External::Scan("Subjects");
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
        cout << " | 2. Open Settings Menu to Configure Subjects                 |" << endl;
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
                if (subjects.empty())
                {
                    cout << "Please Configure Settings first" << endl;
                    goto MAIN;
                }
                else
                {
                    Utilities::Input(students , subjects , temp_i , temp_s , temp_f);
                    cout << endl;
                    break;
                }
                
            }

            case 2:
            {
                Utilities::Settings(subjects , temp_i , temp_s);
                system("cls");
                goto MAIN;
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
                    Utilities::sort(students , 1);
                    Result::Result_Gen(students);
                    system("pause");
                    system("cls");
                    break;
                }

                case 2:
                {
                    Utilities::sort(students , 2);
                    Result::Student_wise(students);
                    system("cls");
                    break;
                }

                case 3:
                {
                    Utilities::sort(students , 3);
                    Result::Subject_wise(students);
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

            for ( int i = 0 ; i < students.size() ; i++ )
            {
                students[i].ID = i;
                for ( int j = 0 ; j < students[i].subjects.size() ; j++ )
                {
                    students[i].subjects[j].ID = j;
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
