#include <iostream>
#include <array>
using namespace std;


int pow(int v , int p)
{
    int res=1;
    for ( int i=0 ; i < p ; i++ )
    {
        res = res*v;
    }

    return res;
}

int size(int i)
{
    int len = 1;

    if (i > 0) 
    {
        for (len = 0; i > 0; len++) 
        {
            i = i / 10;
        }
    }
    return len;
}


array<int, 2> PPP(int n)
{
    array<int, 2> A;
    int r = 0, s , sp;

    sp = pow(10, (size(n) - 1));

    
    s = n % sp;
    r = n % 10;
    n /= sp;

    

    A[0] = n;
    A[1] = r;

    return A;
}




int main()
{
    int n;
    cin >> n;
    array<int, 2> A = PPP(n);

    cout << "First digit >  " << A[0] << endl;
    cout << "Last digit  >  " << A[1] << endl;
}
