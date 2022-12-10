#include "PokemonCenter.h"

#include <iostream>
using namespace std;

PokemonCenter::PokemonCenter()
:Building()  
{
    display_code='C'; 
    potion_capacity=100;
    num_potions_remaining=potion_capacity;
    pokedollar_cost_per_potion=5;
    state=POTIONS_AVAILABLE;
    cout<<"PokemonCenter default constructed"<<endl;
}

PokemonCenter::PokemonCenter (int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc)
:Building('C', in_id, in_loc)  
{
    pokedollar_cost_per_potion=potion_cost;
    potion_capacity=potion_cap;
    state=POTIONS_AVAILABLE;
    num_potions_remaining=potion_cap;
    cout<<"PokemonCenter constructed"<<endl;
}

PokemonCenter::~PokemonCenter()
{
    cout<<"PokemonCenter destructed"<<endl;
}

bool PokemonCenter::HasPotions()  //check if center still has potions
{
    if (num_potions_remaining>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int PokemonCenter::GetNumPotionRemaining()
{
    return num_potions_remaining;
}

bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget)  //check if they can afford potion
{
    if (budget>potion*(pokedollar_cost_per_potion))  
    {
        return true;
    }
    else
    {
        return false;
    }
}

double PokemonCenter::GetPokeDollarCost(unsigned int potion)
{
    return pokedollar_cost_per_potion*potion;
}

unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed)
{
    if (num_potions_remaining>=potion_needed)
    {
        num_potions_remaining=num_potions_remaining-potion_needed; 
        return potion_needed;
    }
    else
    {
        unsigned int temp=num_potions_remaining;
        num_potions_remaining=0;
        return temp;
    }
}

bool PokemonCenter::Update()
{
    if (num_potions_remaining<=0)
    {
        state=NO_POTIONS_AVAILABLE;
        display_code='c';
        //??display code to c?? how??
        cout<<"PokemonCenter "<<id_num<<" has ran out of potions"<<endl;
        return true;
    }
    else
    {
        return false;
    }
    //how to make it only return true once
}

void PokemonCenter::ShowStatus()
{
    cout<<"Pokemon Center Status: "<<endl;
    Building::ShowStatus();
    Building::ShowStatus();
    cout<<"PokeDollars per potion: "<<pokedollar_cost_per_potion<<endl;
    cout<<"has "<<num_potions_remaining<<" potion(s) remaining."<<endl<<endl;;
}