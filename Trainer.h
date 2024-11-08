#ifndef TRAINER_H
#define TRAINER_H

#include "GameObject.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include <iostream>
#include <string>
using namespace std;

enum TrainerStates {
STOPPED = 0,
MOVING = 1,
FAINTED = 2,
AT_CENTER = 3,
IN_GYM = 4,
MOVING_TO_CENTER = 5,
MOVING_TO_GYM = 6,
BATTLING_IN_GYM = 7,
RECOVERING_HEALTH = 8
};

class Trainer:public GameObject
{
    public: 
    Trainer();
    Trainer (char in_code);
    Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    ~Trainer();
    void StartMoving(Point2D dest);
    void StartMovingToGym(PokemonGym* gym);
    void StartMovingToCenter(PokemonCenter* center);
    void StartBattling(unsigned int num_battles);
    void StartRecoveringHealth(unsigned int num_potions);
    void Stop();
    bool HasFainted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    string GetName();
    unsigned int GetHealth();
    int num_wp_following; //number of wild pokemon following this trainer

    protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);

    private:
    double speed;
    bool is_at_center=false;
    bool is_IN_GYM=false;
    unsigned int health=20;
    unsigned int experience=0;
    double PokeDollars=0;
    unsigned int battles_to_buy=0;
    unsigned int potions_to_buy=0;
    string name;
    PokemonCenter* current_center=0;
    PokemonGym* current_gym=0;
    Point2D destination;
    Vector2D delta;
};

double GetRandomAmountOfPokeDollars();


#endif
