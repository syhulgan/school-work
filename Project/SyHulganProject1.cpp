//----------------------------
//Sy Hulgan
//4-11-21
//Project 1
//----------------------------



//Pre-processor directives
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

//created header files
#include "Car.h"
#include "CarFunctions.h"

//declare namespace
using namespace std;

//OS blind clear screen function
void clear()
{
  cout << "\x1B[2J\x1B[H"; // "[2J" clears the screen and "[H" moves cursor to top left
}

//starting main function
int main(int argc, char *argv[])
{
  string brandsFile = argv[1];
  string colorsFile = argv[2];
  string modelsFile = argv[3];



  return 0;
}


