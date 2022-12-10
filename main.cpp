#include <iostream>
#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Trainer.h"
#include "GameCommand.h"
#include "Model.h"
#include "View.h"



using namespace std;

int main()
{
    Model M;
    View V;
    bool loop=true;
    char input,type;
    M.ShowStatus();
    M.Display(V);
    int id,id2,potions,battles;
    double x,y;
    Point2D p1;


    cout<<"Enter the game command: "<<endl;
    cin>>input;

    while(loop)
    {
        try{
            switch(input)
            {
                case 'm':
                    cin >> id; 
                    cin>> p1.x; 
                    cin>> p1.y;
                    DoMoveCommand(M,id,p1);
                    M.GetFollowInfo(); //calls function to check if being followed
                    //checks if being followed after each command because it's health will be affected differently
                    break;
                case 'c':
                    cin>>id;
                    cin>>id2;
                    DoMoveToCenterCommand(M,id,id2);
                    M.GetFollowInfo(); //calls function to check if being followed
                    break;
                case 'g':
                    cin>>id;
                    cin>>id2;
                    DoMoveToGymCommand(M,id,id2);
                    M.GetFollowInfo(); //calls function to check if being followed
                    break;
                case 's':
                    cin>>id;
                    DoStopCommand(M,id);
                    break;
                case 'p':
                    cin>>id;
                    cin>>potions;
                    DoRecoverInCenterCommand(M,id,potions);
                    M.GetFollowInfo(); //calls function to check if being followed
                    break;
                case 'b':
                    cin>>id;
                    cin>>battles;
                    DoBattleCommand(M,id,battles);
                    M.GetFollowInfo(); //calls function to check if being followed
                    break;
                case 'a':
                    DoAdvanceCommand(M,V);
                    M.GetFollowInfo(); //calls function to check if being followed
                    M.ShowStatus();
                    break;
                case 'r':
                    DoRunCommand(M,V);
                    M.GetFollowInfo(); //calls function to check if being followed
                    M.ShowStatus();
                    break;
                case 'q':
                    cout<<"Quitting Game"<<endl;
                    loop=false;
                    exit(1);
                    break;
                case 'n':
                    cin>>type;
                    cin>>id;
                    cin>>x;
                    cin>>y;
                    M.NewCommand(type,id,x,y);
                    M.GetFollowInfo();
                    M.ShowStatus();
                    break;
                default:
                    {
                        cout<<"Please enter a valid command..."<<endl;
                        break;
                    }
            }
        }

        catch (Invalid_Input& except){
        cout << "Invalid input - " << except.msg_ptr << endl;
        // actions to be taken if the input is wrong
        }

        M.Display(V);

        cout<<"Enter the game command: "<<endl;
        cin>>input;

    }


}


