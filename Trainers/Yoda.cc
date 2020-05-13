#include "Yoda.h"
#include <cstdlib>
#include <time.h>

#include <iostream>
using namespace std;
#include <string>

//1 of 3 trainer classes which when the heros collide with them boost their field of either health, armor of strength
//moves on board with each iteration only downward or upward
//the x coordinate is constant among gameboard updates

int random(int); //generates random num

Yoda::Yoda():Trainer(1,-5,21,3){//construcotr based on creature polymorpchcally sets health, armour, strength, x and y
  avatar = 'Y';//display on board
}
