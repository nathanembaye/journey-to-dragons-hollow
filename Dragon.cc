#include "Dragon.h"

#include <iostream>
using namespace std;
#include <string>



Dragon::Dragon():Creature(1,100,25,3){ //dragon constructor, works with creature and its constructor. works in order of health, armor, strength, x, y
  avatar = 'D';
  direction = false;
}


void Dragon::move(){//moves dragon up and dows in front of cave, that is y range of 2,3,4 for itnts

    if(!direction){ //if false
      setY(getY()-1); //decrease y
    }

    else{
        setY(getY()+1); //increasee dragons y coordinate
    }

    changeDirection(); //change direction after every iteration
}

void Dragon::changeDirection(){

    if (getY() == 2){ //if dragon has reached top of cave, move downard by changing to true
      direction = true;
    }

    else if (getY() == 4){ //if dragon has reached bottom of case, set to false to move upwards in front of cave
      direction = false;
    }
}

void Dragon::collide(int damage){ //on collision of dragon, kill said hero but no damage to dragon so no body of F(X)

}
