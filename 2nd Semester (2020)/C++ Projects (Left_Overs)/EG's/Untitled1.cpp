#include<iostream>
using namespace std;
void life(string death,bool alive)
{
	if(alive=1,0)
	{
		if(alive)
		{
			cout<<"Luckyl you are alive. Congratulations"<<endl;
			
		}
		else if(!alive)
		cout<<"You died.Remain in peace in the afterworld. Goodbye"<<endl;
		
	}
	else if(death){
		cout<<"YOU HAVE ENTERED AN INCORRECT NUMBER"<<endl;
		
	}
}
int main()
{
	bool alive;
    string death,hive;
    cout<<"Heared that you had an accident recently. ALAS! Now, Tell me if ou are alive or not"<<endl;
    getline(cin,hive);
    if(hive=0,1){
    	alive=hive;
	}
	else{
		death=hive
	}
	life(death,alive);
	return 0;
}
