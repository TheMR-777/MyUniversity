#include <iostream> 
using namespace std;

class Pair
{
    int m_X;
    int m_Y;
    mutable int getterCount = 0;

    public:

        int Get_X() const
        {
            getterCount++;
            return m_X;
        }

        int Get_Y() const
        {
            getterCount++;
            return m_Y;
        }

        int Get_Count() const
        {
            return getterCount;
        }

} entity;



int main()
{
    cout << "[ X ] : " << entity.Get_X() << endl;
    cout << "[ Y ] : " << entity.Get_X() << endl;
    cout << "Times the Getter called : " << entity.Get_Count() << endl;
}