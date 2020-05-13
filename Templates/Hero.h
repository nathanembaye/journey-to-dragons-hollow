#ifndef HERO_H
#define HERO_H


int random(int); //random number generator for y coordinates


#include "Creature.h"
class Hero: public Creature{

  public:
    Hero(int, int, int, int, int);
    virtual void move(); //eac Hero has a move that is unique to them
    virtual void collide(int damage); //each Hero has a collison function unique to how they handle it
    int getArmor();
    void setArmor(int a);

  protected:
      int armor;

};
#endif
