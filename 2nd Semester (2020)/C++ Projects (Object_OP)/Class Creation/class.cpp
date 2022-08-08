#include <iostream> 
#include <vector>
using namespace std;

class Car
{
    public:
        string name;
        string model;
        int year;
};

int main()
{
    // Initialization

        Car C1;

    // Input

        cout << "Enter Car Name : ";
        getline(cin, C1.name);

        cout << "Enter Car Model : ";
        getline(cin, C1.model);
        
        cout << "Enter Release year of the Car : ";
        cin >> C1.year;

        cout << endl;

    // Output

        cout << "Name : " << C1.name << " \nModel : " << C1.model << " \nYear : " << C1.year << endl;
}