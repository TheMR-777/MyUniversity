#include <iostream> 
#include <vector>
using namespace std;

class Student
{
    private:
        double avg()
        {
            int sum = 0;

            for (int i=0 ; i < marks.size() ; i++)
            {
                sum += marks[i];
            }

            return (sum/marks.size());
        }

    public:
        string name;
        vector<double> marks;
        double get_avg()
        {
            return avg();
        }
};

int main()
{
    // Initialization

        Student me;
        double temp = 1;

    // Input

        system("cls");
        cout << endl;
        cout << " Enter your Name : ";
        getline(cin, me.name);
        cout << endl;

        for ( int i=0 ; temp != 0 ; i++)
        {
            cout << "- Enter Marks of Subject #" << i+1 << " : ";
            cin >> temp;

            if (temp != 0)
            {
                if ( temp <= 100 )
                {
                    me.marks.push_back(temp);
                }
                else
                {
                    cout << "100+ Marks are Invalid" << endl;
                }
            }
        }

    // Output

        system("cls");
        cout << endl;
        cout << "Your Name : " << me.name << endl;
        cout << "Your Average Marks : " << me.get_avg();
        cout << endl;

        system("pause");
}