#include "Borc.h"
#include <cstdlib>
#include <time.h>

#include <iostream>
using namespace std;
#include <string>


//this serves as one of the three fighter that could damage and thus kill one of the heros
//it iterates to left only and randomly generates y directly when init
//they also loose health on colllison while dmaging hero handled in collide()


int random(int);//generates random num

Borc::Borc():Fighter(5,random(4)+8,23,random(5)+1){ //works with creature cosntructor, in order of health, armor, strength, x, y
  avatar = 'b';//avatr is b for borc
}
