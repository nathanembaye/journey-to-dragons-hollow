#include "Ladybug.h"
#include <cstdlib>
#include <time.h>

#include <iostream>
using namespace std;
#include <string>

//1 of 3 trainer classes which when the heros collide with them boost their field of either health, armor of strength
//moves on board with each iteration only downward or upward
//the x coordinate is constant among gameboard updates

int random(int); //generates random int

Ladybug::Ladybug():Trainer(1,-3,7,3){ //sets constructor to that of creatures with health, armor, strength x and y
  avatar = 'L';//avatar is L for ladybug
}
