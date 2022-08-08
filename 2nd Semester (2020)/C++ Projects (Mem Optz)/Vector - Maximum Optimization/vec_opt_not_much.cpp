#include <iostream> 
#include <vector>
using namespace std;

struct VerteX
{
	float x, y, z;

	// Constructor

		VerteX(float x, float y, float z)
			: x(x), y(y), z(z) 
		{
			cout << endl;
            cout << "Constructor Called!" << endl;
		}

	// Copy Constructor

		VerteX(const VerteX & V)
			: x(V.x), y(V.y), z(V.z)
		{
			cout << "| Copied!" << endl;
		}
};

int main()
{
	// Initialization

		system("cls");
		vector<VerteX> vertices;

	// Pushing Items into Vector

		vertices.push_back(VerteX(1, 2, 3));
		vertices.push_back(VerteX(4, 5, 6));
		vertices.push_back(VerteX(6, 8, 9));
}