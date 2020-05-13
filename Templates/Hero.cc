#include "Hero.h"

#include <iostream>
using namespace std;
#include <string>

//abstract class for all Heros on gameboard, this doesnt include emerald
//ploymorphically handles for collsison and move funcitons as it is uniqe for each hero
//each hero player here has armor, health, strength, and x/y coordiante for placement on gameBoard
//death and winning in the game is determined by the use of these coordinates that are iterated and changed over each time on gameBoard

int random(int); //random number generator for y coordinates


Hero::Hero(int h, int a, int s, int x, int y):Creature(h,s,x,y), armor(a){ //construcotr for Hero where health, armor, strength, x and y are handled
}

void Hero::move(){ //handle Heros moving each iteration


  if (health <= 0){ //if dead dont move hero
    return;
  }

  int originalY = getY();
  int newY = (random(3)+1); //generates random number from 1 to 3, 1 is up 2 is stay same, 3 is move down

  if(x < 25)//if within bounds move hero right
    setX(getX()+1);

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
}

void Hero::collide(int damage){ //handles collisons betweent o Heros

  if(damage < 0){//if it is a trainer hitting hero, the minus of a negative value occurs, giving a boost
    if (damage == -3){
      health -= damage; //if ladybug
    }
    else if (damage == -4){
      strength -= damage; //if rocky
    }
    else if (damage == -5){
      armor -= damage; //if yoda
    }
  }

  else
    health -= (damage - armor); //if regular fighter just descrease health by damage

}

int Hero::getArmor(){
  return armor;
}

void Hero::setArmor(int a){
  armor = a;
}
