#include "Dorc.h"
#include <cstdlib>
#include <time.h>

#include <iostream>
using namespace std;
#include <string>


//this serves as one of the three fighter that could damage and thus kill one of the heros
//it iterates to left only and randomly generates y directly when init
//they also loose health on colllison while dmaging hero handled in collide()

int random(int);//alows random number generation

Dorc::Dorc():Fighter(5,random(3)+6,23,random(5)+1){ //works with creture construcotr, order of health, armor, stength, x and y
  avatar = 'd'; //dorc shows as d on gameboard
}
