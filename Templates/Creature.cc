#include "Creature.h"

#include <iostream>
using namespace std;
#include <string>


Creature::Creature(){ //constructor for creature

}

Creature::Creature(int h, int s, int x, int y):health(h),strength(s),x(x),y(y){ //construcotr for creature where health, armor, strength, x and y are handled

}

Creature::~Creature(){ //deconstructor for creates

}

void Creature::setAvatar(char a){ //sets avatar field to whatever char is passed in params
  avatar = a;
}

char Creature::getAvatar(){ //returns avatar field of creature called upon
  return avatar;
}

void Creature::setHealth(int h){ //sets health field to whatever int is passed in params
  health = h;
}

int Creature::getHealth(){//returns health field of creature called upon
  return health;
}


void Creature::setStrength(int s){ //sets strength field to whatever int is passed in params
  strength = s;
}

int Creature::getStrength(){ //returns strength field of creature called upon
  return strength;
}

int Creature::getX(){ //returns x field of creature called upon
    return x;
}

int Creature::getY(){ //returns y field of creature called upon
    return y;
}

void Creature::setX(int horizontal){ //sets x field to whatever int is passed in params
  x = horizontal;
}

void Creature::setY(int vertical){ //sets y field to whatever int is passed in params
  y = vertical;
}

void Creature::move(){ //handle creatures moving each iteration

}

void Creature::collide(int damage){ //handles collisons betweent o creatures

}
