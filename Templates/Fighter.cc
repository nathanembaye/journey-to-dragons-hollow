#include "Fighter.h"

#include <iostream>
using namespace std;
#include <string>

int random(int); //random number generator for y coordinates


Fighter::Fighter(int h, int s, int x, int y):Creature(h,s,x,y){ //construcotr for Fighter where health, armor, strength, x and y are handled

}

void Fighter::move(){ //handle Fighters moving each iteration

  int originalY = getY();
  int newY = (random(3)+1); //generates random number from 1 to 3, 1 is down 2 is stay same, 3 is move up


  if(newY == 1){ //moves down
    setY(getY()+1);
  }

  else if(newY == 2){ //stays same
    setY(getY()+0);
  }

  else{ //moves up
    setY(getY()-1);
  }

  if(getY() < 1){ //out of bounds hitting top, move to adjacent place by 1
    setY(originalY+1);
  }

  else if(getY() > 5){ //out of bounds hitting bottom, move to adjacent place by up 1
    setY(originalY-1);
  }

  if(x == 1){ //if reached out of bounds left, kill the fighter to remove from list later
    setHealth(0);
  }

  else//if not at end decrease x to keep moving fighter left
    setX(getX()-1);

}

void Fighter::collide(int damage){ //handles collisons betweent o Heros
  health -= damage;

}
