#include<iostream>
using namespace std;
#define Work(c) cout << c << endl

// Sub Class

class Room
{
    public:

        int chairs;

        Room() = default;

        Room(int c)
            : chairs(c) {}
};

// Master Class

class House
{
    int tables;
    Room r;

    public:
        House(int t)
            : tables(t), r(3) {}

        void show()
        {
            Work("No of tables are: " << tables);
            Work("No of chairs are: " << r.chairs);
        }
};


// main part

int main()
{
    House H(3);
    H.show();
}

