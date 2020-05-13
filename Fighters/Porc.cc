#include "Porc.h"
#include <cstdlib>
#include <time.h>

#include <iostream>
using namespace std;
#include <string>


//this serves as one of the three fighter that could damage and thus kill one of the heros
//it iterates to left only and randomly generates y directly when init
//they also loose health on colllison while dmaging hero handled in collide()

int random(int); //generate random num

Porc::Porc():Fighter(5,random(2)+4,23,random(5)+1){ //cosntrucotr for porc from creture displayed as health, armor, strength, x ,y
  avatar = 'p';//displayu on gameboard with a p
}
