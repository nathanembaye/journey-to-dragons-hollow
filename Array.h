#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
#include <cstdlib>

//serves as the 2d array that holds gameboard that is printed to the user
//each grid part of board is stored here as well as all players in the quest avtar char
//the dimensions although different print out properly based on control.cc steatements

template <class T>
class Array{

  public:
    Array(int=28, int=7);
    ~Array();
    T*& operator [] (int i);
    void arrayPrint();
    int getHeight(){ return height;}
    int getWidth(){return width;}

  private:
    int width;
    int height;
    T**  elements; //array of arrays are elements
};


template <class T>
Array<T>::Array(int w, int h) //cehcks that height and width are valid in constructor
{
  if (w < 0 || h < 0) {//if invalid, just exist and print error
    cerr<<"The submission size is not workable!"<<endl;
    exit(1);//exist
  }

  //set dimesnsions height, width, and elements
  width = w;
  height = h;
  elements = new T*[height];

  for (int i=0; i<height; i++){
    elements[i] = new T[width];
  }
}

template <class T>
Array<T>::~Array(){//frees memeory in the array that is being used
  for (int i=0; i<height; i++){
    delete [] elements[i];
  }
  delete [] elements;
}

//return elements at said positon in list
template <class T>
T*& Array<T>::operator [] (int i){
  return elements[i];
}

template <class T>
void Array<T>::arrayPrint(){//prints the 2d array for us with a double loop
  for (int i=0; i<height; i++){
    for (int j=0; j<width; j++){
      cout<<elements[i][j];
    }
    cout<<endl;
  }
}

#endif
