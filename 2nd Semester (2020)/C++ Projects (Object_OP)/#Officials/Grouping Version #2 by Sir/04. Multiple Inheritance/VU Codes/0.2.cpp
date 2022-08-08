#include <iostream>
#include <stdlib.h>
using namespace std;
/*Multiple Inheritance in case of Amphibious Vehicle*/
class Vehicle
{
public:
void changeGear(){ cout<<"\nI am Vehicle changeGear() function..\n";}
};
class WaterVehicle : public Vehicle
{ 
  public:
 void Float(){ cout<<"\nI am float function of Water Vehicle";}
};
class LandVehicle : public Vehicle
{
public:
void Move(){ cout<<"\nI am move function of Land Vehicle"<<endl;}
};
class AmphibiousVehicle : public LandVehicle,public WaterVehicle
{
};
int main( )
{
AmphibiousVehicle amphibious;
amphibious.Float();
/*Calling Float function of Water Vehicle class*/
amphibious.Move();
/*Calling Move function of Land Vehicle class*/
system("PAUSE");
return 0;
}
