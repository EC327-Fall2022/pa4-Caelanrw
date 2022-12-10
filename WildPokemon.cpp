#include "WildPokemon.h"

WildPokemon::WildPokemon (string name, double attack, double health, bool variant, int id, Point2D in_loc)
:GameObject(in_loc, id, 'W'), attack(5),health(2),in_combat(false), following(false),count(1)
{
    this->attack=attack;
    this->health=health;
    this->variant=variant;
    state=IN_ENVIRONMENT;
}

void WildPokemon::follow(Trainer* t)
{
    if ( ShouldBeFollowing(t) )
    {
        location= t->GetLocation();
        current_trainer=t; //sets current_trainer 
        ChangeHealth(t); //wp affects health
    }

    
    if (count==1) //only adds to num_wp_following the first time it is a different wp following
    {
        if (ShouldBeFollowing(t))
        {
            t->num_wp_following++;  //if following then add 1 to num_wp_following
            count++;
        }
    }
   
    if(following)
    {
        location= current_trainer->GetLocation(); //location of wp constantly follows location of trainer
    } 

    //Have to update trainer's info as well
}

bool WildPokemon::ShouldBeFollowing(Trainer* t)
{

    if ( (t->GetLocation().x +1 >= this->location.x && t->GetLocation().x -1 <= this->location.x) && (t->GetLocation().y +1 >= this->location.y && t->GetLocation().y -1 <= this->location.y) )
    { //if location is within 1 in every direction then it should follow
        following=true;
        return true;
    }
    else return false;
}

void WildPokemon::ChangeHealth(Trainer* t)
{
    if (variant)
    {
        t->GetHealth()+health; //if it is a variant then it adds to trainer health instead 
    }
    else
    {
        t->GetHealth()-attack; //if not variant then it does damage to trainer health like normal
    }

}

bool WildPokemon::get_variant()
{
    return variant;
}

double WildPokemon::get_attack()
{
    return attack;
}

double WildPokemon::get_health()
{
    return health;
}

bool WildPokemon:: get_in_combat()
{
    return in_combat;
}

bool WildPokemon::Update()
{
    if (state=IN_ENVIRONMENT)
    {
        return false;
    }
    else if (IsAlive())
    {
        state=DEAD;
    }
    else if (in_combat)//following trainer
    {
        state=FOLLOWING_TRAINER;
    }
}

void WildPokemon::ShowStatus()
{
    cout<<"WildPokemon status: ";
    GameObject::ShowStatus();
    cout<<" is in the envirnment"<<endl;
    cout<<"Health: "<<health<<endl;
    cout<<"Attack: "<<attack<<endl;
    cout<<"Variant: "<<variant<<endl;
    
}

bool WildPokemon::IsAlive()
{
    if (health>0)
    {
        return true;
    }
    else return false;
}

bool WildPokemon::ShouldBeVisible()
{
    if (health<=0)
    {
        return false;
    }
    else return true;
}

Point2D WildPokemon::GetLocation()
{
    return this->location;
}

bool WildPokemon::GetFollowing()
{
    return following;
}
