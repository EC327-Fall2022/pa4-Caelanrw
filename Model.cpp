#include "Model.h"

#include <iostream>
using namespace std;


Model::Model()  //initialize all members and set appropraite pointers to objects
{
    time=0;

    Point2D PT1(5,1);
    Trainer* T1=new Trainer("Ash",1,'T',1,PT1);
    object_ptrs.push_back(T1);
    trainer_ptrs.push_back(T1);

    Point2D PT2(10,1);
    Trainer* T2=new Trainer("Misty",2,'T',2,PT2);
    object_ptrs.push_back(T2);
    trainer_ptrs.push_back(T2);

    Point2D PC1(1,20);
    PokemonCenter* C1=new PokemonCenter(1,1,100,PC1);
    object_ptrs.push_back(C1);
    center_ptrs.push_back(C1);

    Point2D PC2(10,20);
    PokemonCenter* C2=new PokemonCenter(2,2,200,PC2);
    object_ptrs.push_back(C2);
    center_ptrs.push_back(C2);

    Point2D PG1(0,0);
    PokemonGym* G1=new PokemonGym(1,1,1,1,1,PG1);
    object_ptrs.push_back(G1);
    gym_ptrs.push_back(G1);

    Point2D PG2(5,5);
    PokemonGym* G2=new PokemonGym(1,1,1,4,2,PG2);
    object_ptrs.push_back(G2);
    gym_ptrs.push_back(G1);


    Point2D PW1(10,12);
    WildPokemon* W1=new WildPokemon("WildPokemon1",1,2,0,1,PW1);
    object_ptrs.push_back(W1);
    wildpokemon_ptrs.push_back(W1);

    Point2D PW2(15,5);
    WildPokemon* W2=new WildPokemon("WildPokemon2",1,10,1,2,PW2);
    object_ptrs.push_back(W2);
    wildpokemon_ptrs.push_back(W2);

    active_ptrs.assign(object_ptrs.begin(),object_ptrs.end());
    
    cout<<"Model default constructed"<<endl;
}

Model::~Model()     
{
    for (list <GameObject*> :: iterator iter = object_ptrs.begin(); iter != object_ptrs.end(); iter++)
    {
        delete *iter;
    }
    cout<<"Model destructed"<<endl;
}

Trainer* Model::GetTrainerPtr(int id)
{
    for (list <Trainer*> :: iterator iter = trainer_ptrs.begin(); iter != trainer_ptrs.end(); iter++)
    {
        if ( (*iter)->GetId() == id)
        {
            return *iter;
        }
    }
    
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    for (list <PokemonCenter*> :: iterator iter = center_ptrs.begin(); iter != center_ptrs.end(); iter++)
    {
        if ( (*iter)->GetId() == id)
        {
            return *iter;
        }
    }
    
    return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
    for (list <PokemonGym*> :: iterator iter = gym_ptrs.begin(); iter != gym_ptrs.end(); iter++)
    {
        if ( (*iter)->GetId() == id)
        {
            return *iter;
        }
    }
    
    return 0;
}

WildPokemon* Model::GetWildPokemonPtr(int id)
{
    for (list <WildPokemon*> :: iterator iter = wildpokemon_ptrs.begin(); iter != wildpokemon_ptrs.end(); iter++)
    {
        if ( (*iter)->GetId() == id)
        {
            return *iter;
        }
    }
    
    return 0;
}

bool Model:: Update()
{
    time++;

    int temp=0;
    for (list <PokemonGym*> :: iterator iter = gym_ptrs.begin(); iter != gym_ptrs.end(); iter++)
    {
        if ((*iter)->passed())
        {
            temp++;
            
        }
    }

    if (temp>=2)
    {
        cout<<"GAME OVER: You win! All battles done!"<<endl;
        exit(0);
    }
    
    int temp1=0;
    for (list <Trainer*> ::iterator iter = trainer_ptrs.begin(); iter != trainer_ptrs.end(); iter++)
    {
        if ( (*iter)->HasFainted())
        {
            temp1++;
        }
    }
    
    if (temp1>=2)
    {
        cout<<"GAME OVER: You lose! All of your Trainers' pokemon have fainted!"<<endl;
        exit(0);
    }

    int temp2=0;
    for(list <GameObject*> ::iterator iter = object_ptrs.begin();iter != object_ptrs.end();iter++)
    {
        if ( !(*iter)->Update() )
        {
            temp2++;
        }
    }
    if (temp2>0)
    {
        return false;
    }
    else
    return true;
    
}



void Model::Display(View& view)    
{
    view.Clear();
    for(list <GameObject*> ::iterator iter = object_ptrs.begin();iter != object_ptrs.end();iter++)
    {
        view.Plot((*iter));
    }
    view.Draw();

}


void Model::ShowStatus()  //shows status of all objects
{
    cout<<"Time: "<<time<<endl;;
    for(list <GameObject*> ::iterator iter = object_ptrs.begin();iter != object_ptrs.end();iter++)
    {
        (*iter)->ShowStatus();
    }

}

void Model::GetFollowInfo()
{
    for (list <WildPokemon*> ::iterator iter1 = wildpokemon_ptrs.begin();iter1 != wildpokemon_ptrs.end();iter1++)
    {
        for (list <Trainer*> ::iterator iter2 = trainer_ptrs.begin();iter2 != trainer_ptrs.end();iter2++)
        {
            (*iter1)->follow( *iter2 );
        }
    }

}


void Model :: NewCommand(char type, int in_id, double x, double y)
{
    switch(type)
    {
        case 'c': 
        {
            for(list <PokemonCenter*> :: iterator iter1 = center_ptrs.begin(); iter1 != center_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Pokemon Center ID that doesn't already exist");
            }
            PokemonCenter* C = new PokemonCenter(in_id, 100, 2, Point2D(x,y));
            object_ptrs.push_back(C);
            active_ptrs.push_back(C);
            center_ptrs.push_back(C);
            cout << "New PokemonCenter created" << endl;
            break;
        }

        case 'g':
        {    
            for(list <PokemonGym*> :: iterator iter1 = gym_ptrs.begin(); iter1 != gym_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Pokemon Gym ID that doesn't already exist");
            }
            PokemonGym* G = new PokemonGym(25,2,10,5,in_id,Point2D(x,y));
            object_ptrs.push_back(G);
            active_ptrs.push_back(G);
            gym_ptrs.push_back(G);
            cout << "New PokemonGym created" << endl;
            break;
        }

        case 't':
        {
            for(list <Trainer*> :: iterator iter1 = trainer_ptrs.begin(); iter1 != trainer_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Trainer ID that doesn't already exist");
            }
            Trainer* T = new Trainer("NewTrainer",in_id,'T',1,Point2D(x,y));
            object_ptrs.push_back(T);
            active_ptrs.push_back(T);
            trainer_ptrs.push_back(T);
            cout << "New Trainer created" << endl;
            break;
        } 

        case 'w':
        {
            for(list <WildPokemon*> :: iterator iter1 = wildpokemon_ptrs.begin(); iter1 != wildpokemon_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Wild Pokemon ID that doesn't already exist");
            }
            WildPokemon* W = new WildPokemon("NewWildPokemon",2,10,1,in_id,Point2D(x,y));
            object_ptrs.push_back(W);
            active_ptrs.push_back(W);
            wildpokemon_ptrs.push_back(W);
            cout << "New WildPokemon created" << endl;
            break;
        }

        default:
        cout << "Unrecognized command code for creating new object" << endl;
    }
}

