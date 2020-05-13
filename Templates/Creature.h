#ifndef CREATURE_H
#define CREATURE_H

//abstract class for all creatures on gameboard, this doesnt include emerald
//ploymorphically handles for collsison and move funcitons as it is uniqe for each fighter, trainer (innovation) and hero
//each quest player here has armor, health, strength, and x/y coordiante for placement on gameBoard
//death and winning in the game is determined by the use of these coordinates that are iterated and changed over each time on gameBoard

class Creature{

  public:
    //constructors and deconstructors for creature abstract class
    Creature();
    Creature(int, int, int, int);
    ~Creature();

    //each field of createure has bot a setter and getter, in addition to virtual functions for paritcular move and collide f(x)'s'
    char getAvatar();
    void setAvatar(char);
    void setHealth(int);
    int getHealth();
    void setStrength(int);
    int getStrength();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    virtual void move() = 0;
    virtual void collide(int damage) = 0;


  protected:
    //name, health, strength, and x/y x coordinate of players on board
    char avatar;
    int health;
    int strength;
    int x;
    int y;

};
#endif
