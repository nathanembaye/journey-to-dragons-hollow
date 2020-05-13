#ifndef CONTROL_H
#define CONTROL_H

#include "Array.h"
#include "./Templates/Creature.h"
#include "./Heros/Harold.h"
#include "./Heros/Timmy.h"
#include "./Fighters/Dorc.h"
#include "./Fighters/Borc.h"
#include "./Fighters/Porc.h"
#include "Dragon.h"
#include "./Trainers/Yoda.h"
#include "./Trainers/Rocky.h"
#include "./Trainers/Ladybug.h"
#include "View.h"
#include <list>


class Control{

  public:
    Control();
    ~Control();
    void launch();
    void updateGameboard();
    void handleCollisions(Creature* creature); //hanldes collisons on gameboard among any hero and any other creature
    void handleCreatureDeaths(); //checks health for each creature after gameboard is updaed, this is done after collisons are iterated over
    bool checkLoss(); //checks if both heros are dead, if so game is lost for everybnody
    bool checkWin(); //checks if either hero has caught the meral by checking x,y coordinate on gameboard for ech hero
    void initGameboard();
    void newFighter();
    void newTrainer();

  private:
    list<Creature*> questPlayers;
    Harold* harold;
    Timmy* timmy;
    Dragon* dragon;
    Array<char> gameBoard; //gameboard holding display
    View view;

};


#endif
