#include<iostream>
#include<string>
using namespace std;
class Date
{
private:
    int day, month, year;
public:
    Date() = default;

    Date(int x, int y, int z)
    {
        day = x;
        month = y;
        year = z;
    }
    void show()
    {
        cout << day << "/" << month << "/" << year;
    }
};
class Birthday
{
private:
    string name;
    Date adae;
public:
    Birthday(string aname, int  a, int b, int c)
        : adae(a, b, c)
    {
        name = aname;
    }
    void print()
    {
        cout << name << "birthday date is ";
        adae.show();

    }
};
int main()
{
    Birthday p1("amina", 2, 5, 2000);
    p1.print();
    return 0;
}