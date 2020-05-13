#ifndef TRAINER_H
#define TRAINER_H

#include "Creature.h"
class Trainer: public Creature{

  public:
    Trainer(int, int, int, int);
    virtual void move(); //each trainer has a move that is unique to them
    virtual void collide(int damage); //each trainer has a collison function unique to how they handle it
    void changeDirection();//changes up and down direction trainer moves

  protected:
    bool direction;
};
#endif
