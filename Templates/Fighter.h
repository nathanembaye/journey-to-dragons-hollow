#ifndef FIGHTER_H
#define FIGHTER_H

//fighter class is what brings health down of all heros when collided with
//they are b, p, d and only move left and up and down randomly generated
//when too far left they are removed, and hen helth is zero they are killed
#include "Creature.h"
class Fighter: public Creature{

  public:
    Fighter(int, int, int, int);
    virtual void move(); //eac Hero has a move that is unique to them
    virtual void collide(int damage); //each fighter has a collison function unique to how they handle it

  protected:

};
#endif
