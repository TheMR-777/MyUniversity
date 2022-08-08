#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

int float_count(float f)
{
    std::string s;
    std::string t;
    std::stringstream out;
    out << f;
    s = out.str();

    t = s.substr(s.find(".")+1);
    return s.length();
}

int main()
{
    float f;
    system("cls");
    cout << endl;
    cin >> f;
    cout << "Digits : " << float_count(f) << endl;
    system("pause");
}