#include <iostream> 
#include <fstream>
#include <vector>
using namespace std;

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


/*
        .............MR_speaking..................
        Following are the examples of Read Functions.
        I've tried a lot, but they don't wanna work
        with Templates. So, whenever u wanna use em,
        replace : _DATA_TYPE_ with your Data type.
        and you are done. It's simple, just need a 
        little attention while coding. Use as u want.
        Use the Vector in main or anywhere to recieve
        the vector values from Scan function.
        .............MR out.......................


    _DATA_TYPE_ Scan(string filename)
    {
        _DATA_TYPE_ data;
        ifstream i_file (filename);
        i_file >> data;
        i_file.close();
        return data;
    }

    vector<_DATA_TYPE_> Scan(string filename)
    {
        _DATA_TYPE_ temp_T;
        vector<_DATA_TYPE_> data;
        ifstream i_file (filename);

        while ( getline(i_file, temp_T) );
        {
            i_file >> temp_T;
            data.push_back(temp_T);
        }

        i_file.close();
        return data;
    }
*/
}

int Scan(string filename)
{
    int data;
    ifstream i_file (filename);
    i_file >> data;
    i_file.close();
    return data;
}


int main()
{
    External::Write(5 , "test.txt");

    cout << Scan("test.txt");
}