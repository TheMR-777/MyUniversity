#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

struct Subject
{
    string name;
    int t_marks;
    float o_marks;
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


namespace External
{
    template<typename ANY>
    void Write(ANY value , string filename)
    {
        ofstream o_file (filename);
        o_file << value;
        o_file.close();
    }

    template<typename ANY>
    void Write(vector<ANY> data , string filename)
    {
        ofstream o_file (filename);

        for ( int i=0 ; i < data.size() ; i++)
        {
            o_file << data[i] << endl;
        }

        o_file.close();
    }


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
}


int main()
{
    // Initialization

        int total;
        bool same;
        string temp_s;
        int temp_i;
        Subject subject_t;
        vector<Subject> subjects;
        
    // Settings Menu

        system("cls");

        Settings:

        cout << endl;
        cout << " +-----------------------------------------------------------------+" << endl;
        cout << " | Configure Options listed below :-                               |" << endl;
        cout << " |                                                                 |" << endl;
        cout << " | [ 1 ] - Set Information for Subjects                            |" << endl;
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
                    getline(cin, temp_s);

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