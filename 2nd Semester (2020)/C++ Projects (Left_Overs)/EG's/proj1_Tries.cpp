#include<iostream>
#include<vector>
#include<string>
using namespace std;
// making class
class STUDENT
{


public:

    vector<float> Percentage_calc(vector<float> marks, vector<float> finalMArks, int& size)
    {
        vector<float> percent(size);
        int i = 0;
        for (i = 0; i < size; i++)
        {
            percent[i] = (marks[i] / finalMArks[i]) * 100;
        }

        return percent;
    }




    STUDENT(vector<float>& marks, vector<float>& totalMarks, int& size)
    {
        Percentage_calc(marks, totalMarks, size);

    }

};
// main function
int main()
{
    int size{}, x = 0; float temp_i;
    int i = 0, j = 0;
    string temp;
    

    cout << "enter the strength of your class\n";
    cout << "--------------------------------\n";
    cin >> size;
    vector<string> name(size), subjName;
    vector<float> marks(size), totalMarks, Percentage(size);
    cout << "--------------------------------\n";
    cout << "please enter name of each subject\n";
    cout << "------------------------------\n";
    cout << "please enter [ f ] when you want to finish entering the values\n";
    for (i = 0; temp != "f"; i++)
    {
        cout << "name of subject " << 1 + i << ": ";
        cin >> temp;
        subjName.push_back(temp);
        cout << endl;
        x++;
    }
    subjName.shrink_to_fit();

    for (i = 0; i < x; i++)
    {
        cout << "please enter total marks of " << subjName[i];
        cin >> temp_i;
        totalMarks.push_back(temp_i);
        cout << endl;
    }
    totalMarks.shrink_to_fit();



    for (i = 0; i < size; i++)
    {
        cout << "please enter the name of student " << i + 1 << " ";
        cin >> name[i];
        for (j = 0; j < x; j++)
        {
            cout << "enter the " << name[i] << "'s marks of " << subjName[j];

        }
    }
    name.shrink_to_fit();


    STUDENT S(marks, totalMarks, size);

    Percentage = S.Percentage_calc(marks, totalMarks, size);


    for (i = 0; i < size; i++)
    {

        for (j = 0; j < x; j++)
        {
            cout << "name of student is " << name[i];
            cout << name[i] << "'s marks of " << subjName[j] << " are " << marks[i];
            cout << name[i] << "'s percentage marks are " << Percentage[i];


        }
    }

}