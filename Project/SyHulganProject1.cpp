//----------------------------
//Sy Hulgan
//4-16-21
//Project 1
//----------------------------

//Pre-processor directives
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>

//created header files //step 1
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
int main(int argc, char *argv[]) //step 2
{
  if (argc != 4) //step 3
  {
    cout << "Error! Program was expecting 4 parameters!" << endl;
    return 1; //Linux can't do negatives
  }
  else if (argc == 4)
  {
    //step 4
    string brandsFile = argv[1];
    string colorsFile = argv[2];
    string modelsFile = argv[3];

    //step 5
    if (brandsFile != "brands.txt")
    {
      cout << "Error! The first parameter must be brands.txt!" << endl;
      return 2;
    }
    else if (colorsFile != "colors.txt")
    {
      cout << "Error! The second parameter must be colors.txt!" << endl;
      return 3;
    }
    else if (modelsFile != "models.txt")
    {
      cout << "Error! The third parameter must be models.txt!" << endl;
      return 4;
    }
    else
    {
      //setting size of respective arrays
      int carInfoArraySize = 10;
      int garageSize = 100;
      //creating string arrays
      string brandsArray[carInfoArraySize], colorsArray[carInfoArraySize], modelsArray[carInfoArraySize];
      //creating struct array
      Car garage[garageSize];
      //creating output struct
      Output path;

      //step 6
      fillArrays(brandsFile, brandsArray);
      fillArrays(colorsFile, colorsArray);
      fillArrays(modelsFile, modelsArray);

      //step 7
      //looping to check if any of the arrays are empty
      for (int i = 0; i < carInfoArraySize; i++)
      {
        if (brandsArray[i].empty())
        {
          cout << "Error! No data in brand array!" << endl;
          return 5;
        }
        else if (colorsArray[i].empty())
        {
          cout << "Error! No data in color array!" << endl;
          return 5;
        }
        else if (modelsArray[i].empty())
        {
          cout << "Error! No data in model array!" << endl;
          return 5;
        }
      }

      //step 8
      createGarage(garage, garageSize, brandsArray, colorsArray, modelsArray, carInfoArraySize);

      //step 9
      printUnsortedGarage(garage, garageSize, "Output/unsortedData.txt");

      //step 10
      printSortedGarage(garage, garageSize, "Output/sortedData.txt", brandsArray, colorsArray, modelsArray, carInfoArraySize);

      //step 11
      printOutputFolder(garage, garageSize, brandsArray, colorsArray, modelsArray, carInfoArraySize, path);
    }
  }
  return 0;
}