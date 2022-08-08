#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

struct Subject
{
    string name;
    float t_marks;
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





int main()
{
    // Initialization

        float temp_f;
        int temp_i = 0;
        string temp_s;
        Subject subject_t;
        Profile std_t;
        vector<Profile> students;
        int m_limit=2;

    // Student #1

        std_t.ID = 1;
        std_t.name = "Dr_Han";
        std_t.roll = "BSCS_F19_M23";

        subject_t.name = "English";
        subject_t.o_marks = 89;
        subject_t.t_marks = 100;
        std_t.subjects.push_back(subject_t);

        students.push_back(std_t);

        std_t.subjects.clear();
        subject_t.name = "";
        subject_t.o_marks = 0;
        subject_t.t_marks = 0;

    // Student #2

        std_t.ID = 2;
        std_t.name = "Mr. Riyaz";
        std_t.roll = "BSCS_F19_M98";

        subject_t.name = "English";
        subject_t.o_marks = 95;
        subject_t.t_marks = 100;
        std_t.subjects.push_back(subject_t);

        students.push_back(std_t);

        std_t.subjects.clear();
        subject_t.name = "";
        subject_t.o_marks = 0;
        subject_t.t_marks = 0;

    // Call

        Result_Gen(students);

}