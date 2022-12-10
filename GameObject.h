#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>
using namespace std;

class GameObject
{
    protected: 
    Point2D location;
    int id_num;
    char display_code;
    char state;

    public:
    GameObject(char);
    GameObject(Point2D in_loc,int in_id,char in_code);
    ~GameObject();
    Point2D GetLocation();
    int GetId();
    char GetState();
    virtual void ShowStatus();
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible()=0;
    void DrawSelf(char * ptr);
};



#endif