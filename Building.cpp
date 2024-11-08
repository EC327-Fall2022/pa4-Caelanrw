#include "Building.h"

#include <iostream>
using namespace std;


Building::Building()
:GameObject('B')
{
    this->trainer_count=0;
    cout<<"Building default constructed"<<endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc)
:GameObject(in_loc,in_Id,in_code)
{
    this->trainer_count=0;
    cout<<"Building constructed"<<endl;
}


void Building::AddOneTrainer()
{
    this->trainer_count++;
}

void Building::RemoveOneTrainer()
{
    this->trainer_count--;
}

void Building::ShowStatus()
{
    cout<<display_code<<id_num<<" located at "<<location; 
    if (trainer_count==1)
    {
        cout<<trainer_count<<" trainer is in this building"<<endl;
    }
    else
    {
        cout<<trainer_count<<" trainers are in this building"<<endl;
    } 
}

bool Building::ShouldBeVisible()
{
    return true;
}
