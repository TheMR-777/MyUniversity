#include <iostream> 
#include <vector>
using namespace std;

int main()
{
    vector<int> *v_test = new vector<int>;

    (*v_test).push_back(20);
    v_test->push_back(10);

    for ( int i=0 ; i < (*v_test).size() ; i++ )
    {
        cout << "( * ) Element #" << i+1 << " : " << (*v_test)[i] << endl;
        cout << "( ->) Element #" << i+1 << " : " << v_test->at(i) << endl;
    }

    delete v_test;
}