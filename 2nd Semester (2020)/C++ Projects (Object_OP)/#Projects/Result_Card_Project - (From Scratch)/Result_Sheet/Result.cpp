#include <iostream> 
#include <vector>
using namespace std;

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

    // Student #1

        std_t.ID = 1;
        std_t.name = "DR_Han";
        std_t.o_marks.push_back(12);
        std_t.t_marks.push_back(75);
        std_t.o_marks.push_back(23);
        std_t.t_marks.push_back(75);
        std_t.roll = "BSCS_F19_M23";

        students.push_back(std_t);

        std_t.o_marks.clear();
        std_t.t_marks.clear();

    // Student #2

        std_t.ID = 2;
        std_t.name = "Mr. Riyaz";
        std_t.o_marks.push_back(56);
        std_t.t_marks.push_back(75);
        std_t.o_marks.push_back(22);
        std_t.t_marks.push_back(75);
        std_t.roll = "BSCS_F19_M55";

        students.push_back(std_t);

        std_t.o_marks.clear();
        std_t.t_marks.clear();

    // Call

        Result_Gen(students);

}