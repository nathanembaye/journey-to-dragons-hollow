#include "Trainer.h"
#include <cstdlib>
#include <time.h>

#include <iostream>
using namespace std;
#include <string>

//abstract for 1 of 3 trainer classes which when the heros collide with them boost their field of either health, armor of strength
//moves on board with each iteration only downward or upward
//the x coordinate is constant among gameboard updates

int random(int); //generates random num

Trainer::Trainer(int h, int s, int x, int y):Creature(h,s,x,y){//construcotr based on creature polymorpchcally sets health, armour, strength, x and y

}

void Trainer::move(){//moves Trainer either up or down based on where on the board he is

  if(!direction){//if false move y value down
    setY(getY()-1);
  }

  else{//if true move the y value greater
      setY(getY()+1);
  }

  changeDirection();//change direction bsaed on y value
}

void Trainer::changeDirection(){ //makes sure the Trainer does not hit top or bottom of the board

    if (getY() == 1){ //if top reached
      direction = true; //switch direction
    }

    else if (getY() == 5){//if bottom of GB hit
      direction = false; //switch direction
    }
}

void Trainer::collide(int damage){//boosts the creature in health after collison with Trainer
  health = 0;
}
