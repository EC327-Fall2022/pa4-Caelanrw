#ifndef MODEL_H
#define MODEL_H


#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "View.h"
#include "WildPokemon.h"
#include "Input_Handling.h"

#include <list>
#include <iostream>
using namespace std;

class Model 
{
    private:
    int time=0;
    
    list <GameObject*> object_ptrs;
    list <Trainer*> trainer_ptrs;
    list <PokemonGym*> gym_ptrs;
    list <PokemonCenter*> center_ptrs;
    list <WildPokemon*> wildpokemon_ptrs;
    list <GameObject*> active_ptrs;

    public:
    Model();
    ~Model();
    Trainer* GetTrainerPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    void Display(View& view);  //commented out bc model and view not working
    void ShowStatus();
    WildPokemon* GetWildPokemonPtr(int id);
    void GetFollowInfo(); //uses wild pokemon and trainer ptrs too call follow function
    void NewCommand(char type, int in_id, double x, double y);
    

};


#endif