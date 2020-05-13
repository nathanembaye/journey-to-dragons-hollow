#include "Harold.h"
#include <iostream>
using namespace std;
#include <string>

// hero Harold that is 1 of 2 heros from Creature class and 1 of 9 quest players from create
//collision does nothing but has his own move function moving rightwards towards emeralds

int random(int); //random number generator for y coordinates

Harold::Harold():Hero(15,1,5,2,random(5)+1){ //in order of health, armor, strength x, y. works with creture constructo
  avatar = 'H'; //display H on board as Harold
}
