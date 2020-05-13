#include <iostream>
using namespace std;
#include <string>

#include "Control.h"


//this class contrls the logic of the program
//it inits the gameboard, updates the iteration of the gameboar each time manageing the new coordiates of all creatures
//it also hadnles collisons of each players, and updates gamabord removing them if they die
//winning is checked here as when someone has captured the ermald (when one hero gets the ermald the other is a loser)
//loss here is identified as when both heros are dead

int random(int);//generates random numb

Control::Control(){
  harold = new Harold();
  timmy = new Timmy();
  dragon = new Dragon();
  questPlayers.push_back(harold);
  questPlayers.push_back(timmy);
  questPlayers.push_back(dragon);
  initGameboard();
}

Control::~Control(){
  list<Creature*>::iterator itr;
  for (itr = questPlayers.begin(); itr != questPlayers.end(); itr++) {
    delete (*itr);
  }
}

void Control::launch(){

  srand ((unsigned)time(NULL));//seeds time for random number gen


  while(1){

    //generates new fighter and trainer based on 3/5 chance of a fighter occuring, 1/5 for each
    newFighter();
    newTrainer();
    updateGameboard(); //updates positions of players

    if (checkLoss()) { //checks if both our heros are dead
      break;
    }

    if(checkWin()){ //checks if one of our heros have reached emerald on gameboard
      break;
    }

  }

}

void Control::newTrainer(){
  int newTrainer = random(5)+1; //generates numbers 1 to 5, 1 to 3 generates a fighter meaning 35 is 60%.
  int trainerCount = 0; //trainer counter

  list<Creature*>::iterator itr;
  for (itr = questPlayers.begin(); itr != questPlayers.end(); itr++) {
    if((*itr)->getAvatar() == 'Y' || (*itr)->getAvatar() == 'R'  || (*itr)->getAvatar() == 'L'){ //count number of trainers in playerlist
      trainerCount++;
    }
  }

  if (trainerCount == 3) { //if 3 trainers already there stop addition of trainers
    return;
  }
  //if 3 generate a yoda
  if(newTrainer == 3){
    Yoda* y = new Yoda();
    questPlayers.push_back(y);
  }

  //if 2 generate a ladybug
  else if(newTrainer == 2){
    Ladybug* l = new Ladybug();
    questPlayers.push_back(l);
  }

  //if 1 generate a rocky
  else if(newTrainer == 1){
    Rocky* r = new Rocky();
    questPlayers.push_back(r);
  }
}

//checks if the user has got the emeral and won by checking x and y coordinates
bool Control::checkWin(){ //checks if a heor has reached the emeral
  list<Creature*>::iterator itr;
  for (itr = questPlayers.begin(); itr != questPlayers.end(); itr++) { //iterate through playrs
    if ((*itr)->getAvatar() == 'T' || (*itr)->getAvatar() == 'H'){ //if a hero
      if ((*itr)->getX() == gameBoard.getWidth()-3 && ((*itr)->getY() > 1 && (*itr)->getY() < 5)){ //if cooridates are on the emerald
          cout << (*itr)->getAvatar() << " HAS WON AND GOT THE EMERALD.";
          return true; //return true that they win
      }
    }
  }
  return false;
}

//checks if the game is over and both heros loose by checking if they are both dead
bool Control::checkLoss(){
  int deathCount = 0; //counts number of deaths in game

  list<Creature*>::iterator itr;
  for (itr = questPlayers.begin(); itr != questPlayers.end(); itr++) { //iterates through list of players
    if ((*itr)->getAvatar() == '+'){ //if dead increment death count
        deathCount++;
    }
  }

  if (deathCount == 2){ //ifb oth heros are dead
    cout <<"HAROLD AND TIMMY HAVE DIED. GAME OVER.";
    return true; //return true if game over
  }

  else{ //return false otherswise
    return false;
  }
}

//handles the death of creatures on the gameboard by rmeoving them if they are dead
//if it is a hero instead it permantly adds a + as their avatar and keeps their x and y constant constant
void Control::handleCreatureDeaths(){

  list<Creature*>::iterator itr;
  for (itr = questPlayers.begin(); itr != questPlayers.end(); itr++) { //iterate through list of playres
    if ((*itr)->getHealth() <= 0){
      if ((*itr)->getAvatar() == 'p' || (*itr)->getAvatar() == 'b' || (*itr)->getAvatar() == 'd'){ //if it is fighter just remove from list
        delete (*itr);//free memory
        itr = questPlayers.erase(itr);
      }

      else if ((*itr)->getAvatar() == 'T' || (*itr)->getAvatar() == 'H'){ //if it is a hero replace with a +
        (*itr)->setAvatar('+');
      }

      else if ((*itr)->getAvatar() == 'Y' || (*itr)->getAvatar() == 'R' || (*itr)->getAvatar() == 'L'){ //if it is trainer just remove from list
        delete (*itr);//if trainer free memory
        itr = questPlayers.erase(itr);

      }
    }
  }
}

//iterte through list of players
//if x and y coordinates are the same for two players
//If the to hero types are not the same
void Control::handleCollisions(Creature* c){

  list<Creature*>::iterator itr;
  for (itr = questPlayers.begin(); itr != questPlayers.end(); itr++) {
        if ((*itr)->getX() == c->getX() && (*itr)->getY() == c->getY()){
          if((((*itr)->getAvatar() =='H' || (*itr)->getAvatar() =='T') && !(c->getAvatar() =='H' || c->getAvatar() =='T')) || ((c->getAvatar() =='H' || c->getAvatar() =='T') && !((*itr)->getAvatar() =='H' || (*itr)->getAvatar() =='T')) ){ //if the two players collides include one of our heroes
              if((*itr)->getAvatar() != c->getAvatar()){
                c->collide((*itr)->getStrength());//call collision polymorphically
                (*itr)->collide(c->getStrength());//call collision polymorphically
                return;
            }
          }
        }
      }
    }

//update gambaord with new x y coordinaties of all creature on questplayer list
void Control::updateGameboard(){

  list<Creature*>::iterator itr;
  for (itr = questPlayers.begin(); itr != questPlayers.end(); itr++) {

      (*itr)->move();
      handleCollisions((*itr)); //handles collisions with heros and fighters or heroes and trainers
  }

  handleCreatureDeaths();
  initGameboard();
  view.displayGameboard(gameBoard);
}

//generates a new fighter on user gameboard base on 60% probabiliyt of one being printed
void Control::newFighter(){
  int newFighter = random(5)+1; //generates numbers 1 to 5, 1 to 3 generates a fighter meaning 1 to 3 is 60%.

  //if 3 generate a Dorc
  if(newFighter == 3){
    Dorc* d = new Dorc();
    questPlayers.push_back(d);

  }

  //if 2 generate a Borc
  else if(newFighter == 2){
    Borc* b = new Borc();
    questPlayers.push_back(b);

  }

  //if 1 generate a Porc
  else if(newFighter == 1){
    Porc* p = new Porc();
    questPlayers.push_back(p);

  }
}


void Control::initGameboard(){

  for (int i =0; i<7; i++){
    for (int j=0; j<28; j++){
      gameBoard[i][j] = ' '; //by default make it emmpty

      list<Creature*>::iterator itr;

      for (itr = questPlayers.begin(); itr != questPlayers.end(); itr++) {

          if(j==(*itr)->getX() && i == (*itr)->getY()){
            gameBoard[i][j] = (*itr)->getAvatar();
          }

        //if top of bottom store the " - " symbol"
        if(i==0 || i == 6){
          if(j > 0 && j < (gameBoard.getWidth() - 2)){
                gameBoard[i][j] = '-';
          }
        }

        //if sides store the " | " symbol"
        if(j==0){
          gameBoard[i][j] = '|';
        }

        //if the dungeon coordinates store the " = " otherwise make it a regular wall " \ "
        if(j==(gameBoard.getWidth()-2)){
          if (i > 1 && i < 5){
              gameBoard[i][j] = '=';
          }
          else{
            gameBoard[i][j] = '|';
          }
        }

        //stores emerad if after the dungeon
        if(j==(gameBoard.getWidth()-1)){
          if (i == 3){
              gameBoard[i][j] = '*';
          }
        }

      }
    }
  }
}
