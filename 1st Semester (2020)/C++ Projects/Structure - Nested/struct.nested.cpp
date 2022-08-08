#include <iostream>
using namespace std;


struct Profile
{
	string name;
	string roll;
	double cgpa;
};

struct Group
{
	Profile std[10];
	string name;
};




int main()
{
	int G, S;
	cout << "Enter Number of Groups in your Class: ";
	cin >> G;
	Group Group[G];
	
	for (int i=0 ; i<G ; i++)
	{
		system("cls");
		cout << "Enter NAME of Group #" << i+1 << " : ";
		cin >> Group[i].name;
		cout << "Enter Number of Students in " << Group[i].name << " Group : ";
		cin >> S;
		cout << endl;
		
		for (int j=0 ; j<S ; j++)
		{
			system("cls");
			cout << "Enter  NAME    of Student #" << j+1 << " : ";
			cin >> Group[i].std[j].name;
			cout << "Enter ROLL No. of " << Group[i].std[j].name << " : ";
			cin >> Group[i].std[j].roll;
			cout << "Enter  CGPA    of " << Group[i].std[j].name << " : ";
			cin >> Group[i].std[j].cgpa;
		}
	}
	
	system("cls");
	for (int i=0 ; i<G ; i++)
	{
		cout << "Group #" << i+1 << " :       " << Group[i].name << " :- " << endl;
		cout << "----------------------------------------------" << endl;
		
		for (int j=0 ; j<S ; j++)
		{
			cout << j+1 <<". " << Group[i].std[j].cgpa << "\t" << Group[i].std[j].roll << "\t" << Group[i].std[j].name << endl;
		}
		
		cout << "----------------------------------------------" << endl << endl;
	}
}














