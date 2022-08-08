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
            ifstream i_file (filename.c_str());

            if (i_file.is_open())
            {
                cout << "OPEN" << endl;
            }

        // Scanning

            while ( getline(i_file, temp_s) )
            {
                cout << temp_s;
                data.push_back(temp_s);
            }

        // Filling Subjects

            for ( int i=0 ; i < data.size() ; i++)
            {
                if (i % 2 == 0)
                {
                    subject_t.name = data[i];
                }
                else
                {
                    subject_t.t_marks = stoi(data[i]);
                }
                subjects.push_back(subject_t);
            }

        // Finalization

            i_file.close();
            return subjects;
    }
}


int main()
{
    vector<Subject> subjects = External::Scan("Subjects.txt");
}