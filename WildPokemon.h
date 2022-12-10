#include <iostream>
using namespace std;

#include <string>
#include "Trainer.h"



enum WildPKStates {
IN_ENVIRONMENT = 1,
DEAD = 2,
FOLLOWING_TRAINER = 3
};

class WildPokemon: public GameObject
{
    protected:
        double attack;
        double health;
        bool variant;
        bool in_combat;
        string name;
        Trainer* current_trainer;
        bool following; //checks if being followed
        int count; 
    
    public:
        WildPokemon (string name, double attack, double health, bool variant, int id, Point2D in_loc);
        void follow(Trainer* t);
        bool get_variant();
        double get_attack();
        double get_health();
        bool get_in_combat();
        bool Update();
        void ShowStatus();
        bool IsAlive();
        bool ShouldBeVisible();
        bool ShouldBeFollowing(Trainer* t); //checks if it should start following
        void ChangeHealth(Trainer*t); //if following then change health
        Point2D GetLocation();
        bool GetFollowing(); 
        
};