#include <iostream>
using namespace std;
#include <string>

#include "View.h"

//view displays gameboard what this does is print what we hav allocated each time
//view only calls displayGameboard for doing so working with the passed Array in params

void View::displayGameboard(Array<char> &gameBoard){
    gameBoard.arrayPrint();
}
