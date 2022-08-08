#include <iostream> 
using namespace std;

static int gs_var_x = 10;
static int gs_var_y = 20;


void GS_Print()
{
    cout << endl;
    cout << "Accessing the Global_Static Variable outside the main" << endl;
    cout << "[ x ] - Variable : " << gs_var_x << endl;
    cout << "[ y ] - Variable : " << gs_var_y << endl;
}

void Modify()
{
    cout << endl;
    cout << "Modifying Global_Static Variables" << endl;
    gs_var_x = 50;
    gs_var_y = 90;

    cout << "[ x ] - Variable : " << gs_var_x << endl;
    cout << "[ y ] - Variable : " << gs_var_y << endl;
}


int main()
{
    system("cls");
    cout << "[ SUM ] - Sum of Global_Static Variables : " << gs_var_x + gs_var_y << endl;
    GS_Print();

    cout << endl;

    Modify();

    cout << endl;
}