#include "Timmy.h"//include hear
#include <iostream>
using namespace std;
#include <string>

// hero Timmy that is 1 of 2 heros from Creature class and 1 of 9 quest players from create
//collision does nothing but has his own move function moving rightwards towards emerals

int random(int);//for random num generator


Timmy::Timmy():Hero(15,3,3,2,random(5)+1){// constructor for timmy, in order of health, armor, strength, x and y. works with creature constructor
  avatar = 'T';
}
