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





    void sort(vector<Subject> subject)
    {
        int temp;
        vector<float> recept;
        
        for ( int i=0 ; i < subject.size() ; i++ )
        {
            recept.push_back(subject)
        }
    }


    void sort(vector<Profile> &students, int &op)
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

            subject_t.ID = 1;
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

            subject_t.ID = 1;
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


    // Student #3

        // Student Data

            std_t.ID = 3;
            std_t.name = "Mr_Noman";
            std_t.roll = "BSCS_F19_M47";

        // Subject Data

            subject_t.ID = 1;
            subject_t.name = "English";
            subject_t.o_marks = 48;
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

        sort(students , 1);
}