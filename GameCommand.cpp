#include "GameCommand.h"

void DoMoveCommand(Model & model, int trainer_id, Point2D p1)  //for command m
{
    if (model.GetTrainerPtr(trainer_id) ==NULL)  //check if id is valid
    {
        throw Invalid_Input("Error: Please enter a valid command!");
    }
    else
    {
        model.GetTrainerPtr(trainer_id)->StartMoving(p1); //starts moving
        cout<<"Moving "<<model.GetTrainerPtr(trainer_id)->GetName()<<" to "<<p1<<endl;
    }
}

void DoMoveToCenterCommand(Model & model, int trainer_id, int center_id) //command c
{
    if (model.GetTrainerPtr(trainer_id) ==NULL)  //check if id is valid
    {
        throw Invalid_Input("Error: Please enter a valid command!");
    }
    if (model.GetPokemonCenterPtr(center_id) ==NULL)  //check if id is valid
    {
        throw Invalid_Input("Error: Please enter a valid command!");
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartMovingToCenter( model.GetPokemonCenterPtr(center_id) ); //starts moving to cenetr
        cout<<"Moving "<<model.GetTrainerPtr(trainer_id)->GetName()<<" to PokemonCenter"<<center_id<<endl;
    }
}

void DoMoveToGymCommand(Model & model, int trainer_id, int gym_id)  //command g
{
    if (model.GetTrainerPtr(trainer_id) ==NULL) //check id is valid
    {
        throw Invalid_Input("Error: Please enter a valid command!");
    }
    if (model.GetPokemonGymPtr(gym_id) ==NULL) //check id is valid
    {
        throw Invalid_Input("Error: Please enter a valid command!");
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartMovingToGym( model.GetPokemonGymPtr(gym_id) ); //starts moving to gym
        cout<<"Moving "<<model.GetTrainerPtr(trainer_id)->GetName()<<" to gym"<<gym_id<<endl;
    }
}

void DoStopCommand(Model & model, int trainer_id) //command s
{
    if (model.GetTrainerPtr(trainer_id) ==NULL) //check id is valid
    {
        throw Invalid_Input("Error: Please enter a valid command!");
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->Stop();  //stops
        cout<<"Stopping "<<model.GetTrainerPtr(trainer_id)->GetName()<<endl;
    }
}

void DoBattleCommand(Model & model, int trainer_id, unsigned int battles) //command b
{
    if (model.GetTrainerPtr(trainer_id) ==NULL)//check id valid
    {
        throw Invalid_Input("Error: Please enter a valid command!");
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartBattling(battles);  //starts battles
        cout<<model.GetTrainerPtr(trainer_id)->GetName()<<" is battling"<<endl;
    }
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)  //command p
{
    if (model.GetTrainerPtr(trainer_id) ==NULL) //check id valid
    {
        throw Invalid_Input("Error: Please enter a valid command!");
    }
    else 
    {
        model.GetTrainerPtr(trainer_id)->StartRecoveringHealth(potions_needed);  //starts recovering
        cout<<"Recovering "<<model.GetTrainerPtr(trainer_id)->GetName()<<"'s Pokemon's health"<<endl;
    }
}

void DoAdvanceCommand(Model& model, View& view)  //command a
{
    model.Update();
    model.Display(view);  //commented out bc model and view not working
    cout<<"Advancing one tick."<<endl;
}

void DoRunCommand(Model& model, View& view)  //command r
{
    for (int i=0; i<5;i++)
    model.Update();
    model.Display(view);     //commented out bc model and view not working
    cout<<"Advancing to next event"<<endl;
}