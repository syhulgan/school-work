#pragma once
#include <string>
using namespace std;

void fillArrays(string fileName, string stringArray[])
{
  ifstream file;
  file.open(fileName);

  int count = 0;
  while(!file.eof())
  {
    file >> stringArray[count];
    count++;
  }
}

void createGarage(Car carDataArray[], int carDataArraySize, string brandsArray[], string colorsArray[], string modelsArray[], int carInfoArraySize)
{

}

void printUnsortedGarage(Car carDataArray[], int carDataArraySize, string outputPath)
{

}

void printSortedGarage(Car carDataArray[], int carDataArraySize, string outputPath, string BrandsArray[], string colorsArray[], string modelsArray[], int carInfoArraySize)
{

}

void printOutputFolder(Car carDataArray[], int carDataArraySize, string BrandsArray[], string colorsArray[], string modelsArray[], int carInfoArraySize, Output outputDataArray[])
{

}