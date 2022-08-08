#include <iostream>
#include <string>
//composition (master and subclass constructors) concept
 // Command to run this :
// clear && g++ 'Concepts/2.4.cpp' && ./a.out && rm a.out
using namespace std;

class Date
{

public:
    Date(int cmonth, int cday, int cyear)
    {

        cout << " constructor of the subclass: Date class\n";
        month = cmonth;
        day = cday;
        year = cyear;

    }
    void printDate()
    {
        cout << month << "/" << day << "/" << year << endl;

    }
private:
    int month;
    int day;
    int year;

};

class Student
{

public:
    Student(string cname, Date cdateOfAdm)
        :name(cname),
        dateOfAdm(cdateOfAdm)
    {
        cout << " constructor of master class: Student class\n";
    }
    void printInfo() {
        cout << name << " was born on: ";
        dateOfAdm.printDate();
    }

private:
    string name;
    Date dateOfAdm;

};


int main()
{

    Date stdObject(7, 9, 2018);
    Student infoStd("Lenny the Cowboy", stdObject);
    infoStd.printInfo();

}
