#include "Rocky.h"
#include <cstdlib>
#include <time.h>

#include <iostream>
using namespace std;
#include <string>

//1 of 3 trainer classes which when the heros collide with them boost their field of either health, armor of strength
//moves on board with each iteration only downward or upward
//the x coordinate is constant among gameboard updates

int random(int);//generates random numb

Rocky::Rocky():Trainer(1,-4,14,3){//construcotr for trinare based on creature constructor seething health, armor strenth x and y in that order
  avatar = 'R';//sets avatar to R for rocky
}
