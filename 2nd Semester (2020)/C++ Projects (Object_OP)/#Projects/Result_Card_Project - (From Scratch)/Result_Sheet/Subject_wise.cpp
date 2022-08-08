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









void Subject_wise(vector<Profile> &students)
{
    // Initializing Temporary Stuff

        string stg_t;
        float flt_temp;

    // Result Card

        for ( int i=0 ; i < students[0].subjects.size() ; i++ )
        {
            system("cls");
            cout << endl;
            cout << " +----------------------------------------------------------------------------------------------------+" << endl;
            cout << " | Subject [ " << i+1 << " / " << students[0].subjects.size() << " ] - " << students[0].subjects[i].name; spaces(students[0].subjects[i].name.size() , 70); cout << "//////// |" << endl;
            cout << " +----------------------------------------------------------------------------------------------------+" << endl;
            cout << " | Names of Students" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
            cout << " |                                                                                                    |" << endl;

            for( int j=0 ; j < students.size() ; j++ )
            {
                // Name Generation

                    cout << " | " << students[j].name;
                    spaces(students[j].name.size());

                // Obtained Marks

                    cout << students[j].subjects[i].o_marks;
                    spaces(float_count(students[j].subjects[i].o_marks) , 17);

                // Total Marks

                    cout << students[j].subjects[i].t_marks;
                    spaces(float_count(students[j].subjects[i].t_marks) , 17);

                // Percentage

                    flt_temp = class_function::PT_AGE(students[j].subjects[i].o_marks , students[j].subjects[i].t_marks);
                    cout << flt_temp;
                    spaces(float_count(flt_temp) ,10);

                // Roll_Number

                    cout << students[j].roll;
                    spaces(students[j].roll.size() ,25);
                    cout << "|" << endl;

                // Flushing

                    stg_t = "";
                    flt_temp = 0.0;
            }

            cout << " |                                                                                                    |" << endl;
            cout << " +----------------------------------------------------------------------------------------------------+" << endl;
            cout << endl;
            // system("pause");
        }
}









int main()
{
    // Initialization

        Subject subject_t;
        Profile std_t;
        vector<Profile> students;

    // Student #1

        // Student Data

            std_t.ID = 1;
            std_t.name = "Dr_Han";
            std_t.roll = "BSCS_F19_M23";

        // Subject Data

            subject_t.name = "English";
            subject_t.o_marks = 89;
            subject_t.t_marks = 100;
            std_t.subjects.push_back(subject_t);

        // Student Filling

            students.push_back(std_t);

        // Flushing

            std_t.subjects.clear();
            subject_t.name = "";
            subject_t.o_marks = 0;
            subject_t.t_marks = 0;

    // Student #2

        // Student Data

            std_t.ID = 2;
            std_t.name = "Mr_Riyaz";
            std_t.roll = "BSCS_F19_M98";

        // Subject Data

            subject_t.name = "English";
            subject_t.o_marks = 95;
            subject_t.t_marks = 100;
            std_t.subjects.push_back(subject_t);

        // Student Filling

            students.push_back(std_t);

        // Flushing

            std_t.subjects.clear();
            subject_t.name = "";
            subject_t.o_marks = 0;
            subject_t.t_marks = 0;

    // Call

        Subject_wise(students);
}