#include<iostream>
#include<vector>
#include<string>
using namespace std;


void progress(string& S, string& A, vector<string>& V_S, vector<int>& V, int& temp)
{
	temp = 1;
	cout << "plz enter the name of subject  :";
	cin >> S;
	cout << "please enter the name of all students\n\n" << "plz enter F when you want to finish entering names\n";
	for (int i = 0; A != "F"; i++)
	{
		cin >> A;
		V_S.push_back(A);

	}
	cout << "plz enter marks of each student\n\n" << "plz enter 0 when you want to finish entering marks\n";
	for (int i = 0; temp != 0; i++)
	{
		cout << "Marks of ::" << V_S[i] << " is = ";
		cin >> temp;
		V.push_back(temp);

	}
}


int main()
{
	string S, A;
	vector<string> V_S;
	vector<int> V;
	int temp;
	progress(S, A, V_S, V, temp);
}
