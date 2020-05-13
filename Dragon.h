#ifndef DRAGON_H
#define DRAGON_H

#include "./Templates/Creature.h"

//dragon class serves as what end the game if both users collides with him
//this occurs in the collison functionality of the Dragon.cc Files
//automitally sets the heros healh to 0

class Dragon: public Creature{

  public:
    Dragon();
    virtual void move(); //move dragon according to his particular move f(x), cam from creatures move()
    virtual void changeDirection(); //changes direction that y of dragon is being added or subtracted
    virtual void collide(int damage); //collide function for dragon, always kills hero he hit by setting health to 0


  private:
    bool direction; //changes direction of dragon, false is up, true is down

};
#endif
