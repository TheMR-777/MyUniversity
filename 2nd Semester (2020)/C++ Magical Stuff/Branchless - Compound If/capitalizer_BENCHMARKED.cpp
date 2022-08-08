#include <iostream>
#include <chrono>
using namespace std;



class Timer
{
	chrono::time_point<chrono::high_resolution_clock> m_Start, m_End;
	long long m_Start_us, m_End_us, m_duration_us;

public:

	Timer()
	{
		m_Start = chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		m_End = chrono::high_resolution_clock::now();

		m_Start_us = chrono::time_point_cast<chrono::microseconds>(m_Start).time_since_epoch().count();
		m_End_us = chrono::time_point_cast<chrono::microseconds>(m_End).time_since_epoch().count();

		m_duration_us = m_End_us - m_Start_us;

		cout << "Time : [ " << m_duration_us << "us ] / [ " << m_duration_us * 0.001 << "ms ]\n\n";
	}
};




void Cap_B( string name )
{
    Timer T;
    for ( int i=0 ; i < name.size() ; i++ )
    {
        if ( name[i] >= 'a' && name[i] <= 'z' )
        {
            name[i] -= 32;
        }
    }

    cout << "[ B ]  Capitalized String : " << name << endl;
}

void Cap_L_1( string name )
{
    Timer T;
    for ( int i=0 ; i < name.size() ; i++ )
    {
        name[i] = ( name[i] * !( name[i] >= 'a' && name[i] <= 'z' ) ) + ( (name[i] - 32) * ( name[i] >= 'a' && name[i] <= 'z' ) );
    }

    cout << "[ L1 ] Capitalized String : " << name << endl;
}

void Cap_L_2( string name )
{
    Timer T;
    for ( int i=0 ; i < name.size() ; i++ )
    {
        name[i] = name[i] - 32 * ( name[i] >= 'a' && name[i] <= 'z' );
    }

    cout << "[ L2 ] Capitalized String : " << name << endl;
}



int main()
{
    // Initialization

        string name;
        cout << " Enter the STRING : ";
        getline(cin, name);

    // Calling the Branched Code

        Cap_B(name);

    // Calling the 1st Branchless Code

        Cap_L_1(name);

    // Calling the 2nd Branchless Code

        Cap_L_2(name);
}



// Checking the ASCII

// for ( char c = 'A' ; c <= 'Z' ; c++ )
// {
//     cout << "Char : " << c << " - ASCII : " << (int)c << endl;
// }