#include<iostream>
using namespace std;
class Chair
{
	public:
		
	int chairNo;
	 GetChair(int chairNo);
}
class Room{
private:
 float area;
 Chair * chairs[5];
Public:
 Room();
 void AddChair(Chair *, int chairNo);
 Chair * GetChair(int chairNo);
 bool FoldChair(int chairNo);
};
Room::Room(){
for(int i = 0; i < 5; i++)
chairs[i] = NULL;
Room(char *, int)
~Room()
FoldChair(int) : bool
Chair()
DoSomething() : void
FoldChair() : bool
UnFoldChair() : bool
~Chair()
area : float
chairs[5]:Chair *
Room
Chair 
}
void Room::AddChair(Chair * chair1, int chairNo){
 if(chairNo >= 0 && chairNo < 5)
 chairs[chairNo] = chair1;
}
Chair * Room::GetChair(int chairNo){
 if(chairNo >= 0 && chairNo < 5)
 return chairs[chairNo];
 else
 return NULL;
}
bool Room::FoldChair(int chairNo){
 if(chairNo >= 0 && chairNo < 5)
 return chairs[chairNo]->FoldChair();
 else
 return false;
}
int main(){
 Chair ch1;
 {
 Room r1;
 r1.AddChair(&ch1, 1);
 r1.FoldChair(1);
 }
 ch1.UnFoldChair(1);
 return 0;
} 
