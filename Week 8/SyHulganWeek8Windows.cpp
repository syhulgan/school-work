//----------------------------
//Sy Hulgan
//Date
//Name of file/assignment
//----------------------------

//Pre-processor directives
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <string.h>
#include <time.h>

//declare namespace
using namespace std;

//OS blind clear screen function
void clear()
{
  cout << "\x1B[2J\x1B[H"; // "[2J" clears the screen and "[H" moves cursor to top left
}

//------------------------------
//IMPORTANT NOTE
//------------------------------
/*
The file structure of Linux differs when compared to Windows. 
For example, in windows you would type something like "filefolder\\sample.txt"
In Linux you type "filefolder/sample.txt"
Because of this I'm going to submit this assignment twice.
Once with the layout that should work on Windows and the other 
in the layout that works for Linux.
*/
//------------------------------

//Function Protypes
//------------------------
void setArrayValues(int intValues1[], int intValues2[], int &arrayCount); //function 1
void printArray(int intArray[], int arraySize); //function 2
void calculations(int intValues1[], int intValues2[], int calcValues[], int arraySize, string mathOp); //function 3

//Starting main function
int main()
{
  //i hard coded the array size to equal the number of elements shown in the assignment demonstration video
  int num = 13;

  int valueArray1[13]; //creating arrays to hold info
  int valueArray2[13];
  int calArray[13];

  setArrayValues(valueArray1, valueArray2, num); //getting values from input .txt files

  cout << "Array 1 Contents" << endl; //printing contents of .txt files
  cout << "----------------------------" << endl;
  printArray(valueArray1, num);
  cout << "----------------------------" << endl;

  cout << "Array 2 Contents" << endl;
  cout << "----------------------------" << endl;
  printArray(valueArray2, num);
  cout << "----------------------------" << endl;

  calculations(valueArray1, valueArray2, calArray, 13, "Add"); //calculations 
  calculations(valueArray1, valueArray2, calArray, 13, "Sub"); //these also append calculations to output files
  calculations(valueArray1, valueArray2, calArray, 13, "Mul");
  calculations(valueArray1, valueArray2, calArray, 13, "Div");

  cout << "Calculations for Addition are completed" << endl; //little decoration
  cout << "Calculations for Subtraction are completed" << endl;
  cout << "Calculations for Multiplaction are completed" << endl;
  cout << "Calculations for Division are completed" << endl;
  cout << "-----------------------------------------" << endl;
  cin.get();
  clear();

  return 0;
}

//Function Definitions
//------------------------
void setArrayValues(int intValues1[], int intValues2[], int &arrayCount) //function 1
{
  ifstream inputFile1;
  inputFile1.open("Input\\Values1Input.txt"); //format for Windows
  //inputFile1.open("Input/Values1Input.txt"); //opening file within folder
  for (int i = 0; i < arrayCount; i++) //loop to get info into array
  {
    inputFile1 >> intValues1[i];
  }
  inputFile1.close();

  ifstream inputFile2;
  inputFile1.open("Input\\Values1Input.txt"); //format for Windows
  //inputFile2.open("Input/Values2Input.txt"); //same as for Values1Input.txt
  for (int i = 0; i < arrayCount; i++)
  {
    inputFile2 >> intValues2[i];
  }
  inputFile2.close();
}

void printArray(int intArray[], int arraySize) //function 2
{
  for (int i = 0; i < arraySize; i++) //loop that prints each element of the array
  {
    cout << "Index " << i << ": " << intArray[i] << endl;
  }
}

void calculations(int intValues1[], int intValues2[], int calcValues[], int arraySize, string mathOp) //function 3
{
  string mathOpAdd = "Add"; //assigning math operations to strings
  string mathOpSub = "Sub";
  string mathOpMul = "Mul";
  string mathOpDiv = "Div";

  ofstream outputFile;
  if (mathOp == mathOpAdd) //case for addition
  {
    for (int i = 0; i < arraySize; i++)
    {
      calcValues[i] = intValues1[i] + intValues2[i];
      outputFile.open("Output\\AddResults.txt", ios::app); //format for Windows
      //outputFile.open("Output/AddResults.txt", ios::app); //format for Linux
      if (outputFile.is_open())
      {
        outputFile << intValues1[i] << " + " << intValues2[i] << " = " << calcValues[i] << endl; //appending info to output file
      }
      outputFile.close();
    }
  }
  else if (mathOp == mathOpSub) //case for subtraction
  {
    for (int i = 0; i < arraySize; i++)
    {
      calcValues[i] = intValues1[i] - intValues2[i];
      outputFile.open("Output\\SubResults.txt", ios::app); //format for Windows
      //outputFile.open("Output/SubResults.txt", ios::app);
      if (outputFile.is_open())
      {
        outputFile << intValues1[i] << " - " << intValues2[i] << " = " << calcValues[i] << endl; //appending info to output file
      }
      outputFile.close();
    }
  }
  else if (mathOp == mathOpMul) //case for multiplaction
  {
    for (int i = 0; i < arraySize; i++)
    {
      calcValues[i] = intValues1[i] * intValues2[i];
      outputFile.open("Output\\MulResults.txt", ios::app); //format for Windows
      //outputFile.open("Output/MulResults.txt", ios::app);
      if (outputFile.is_open())
      {
        outputFile << intValues1[i] << " * " << intValues2[i] << " = " << calcValues[i] << endl; //appending info to output file
      }
      outputFile.close();
    }
  }
  else if (mathOp == mathOpDiv) //case for division
  {
    for (int i = 0; i < arraySize; i++)
    {
      float floatIntValues1[arraySize];
      float floatIntValues2[arraySize];
      float floatCalcValues[arraySize];
      floatIntValues1[i] = intValues1[i];
      floatIntValues2[i] = intValues2[i];

      floatCalcValues[i] = floatIntValues1[i] / floatIntValues2[i];

      outputFile.open("Output\\DivResults.txt", ios::app); //format for Windows
      //outputFile.open("Output/DivResults.txt", ios::app);
      if (outputFile.is_open())
      {
        outputFile << intValues1[i] << " / " << intValues2[i] << " = " << floatCalcValues[i] << endl; //appending info to output file
      }
      outputFile.close();
    }
  }
}