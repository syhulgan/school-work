//----------------------------
//Sy Hulgan
//2-28-21
//Assignment 7
//----------------------------

//Pre-processor directives
#include <iostream>
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

//Function Protypes
//------------------------
void setValues(int intArray[], int intArraySize, string arrayType);                           //function 1
void printArray(int intArray[], int intArraySize);                                            //function 2
void calc(int intergers1[], int intergers2[], int calculation[], int calSize, string mathOp); //function 3

//Starting main function
int main()
{
  srand(time(0));

  //creating arrays to be used in the rest of the program
  int valueArray1[10];
  int valueArray2[10];
  int calArray[10];

  setValues(valueArray1, 10, "value 1"); //calling function 1 to have user set vales for valueArray1
  cout << "Array 1 contents " << endl;
  cout << "----------------------------" << endl;
  printArray(valueArray1, 10); //callling function 2 to print results of valueArray1
  cout << "----------------------------" << endl;

  setValues(valueArray2, 10, "value 2"); //calling function 1 to have user set vales for valueArray2
  cout << "Array 2 contents " << endl;
  cout << "----------------------------" << endl;
  printArray(valueArray2, 10); //callling function 2 to print results of valueArray2
  cout << "----------------------------" << endl;

  cout << "Addition Results" << endl;
  cout << "----------------------------" << endl;
  calc(valueArray1, valueArray2, calArray, 10, "Add"); //calling function 3
  cout << "----------------------------" << endl;

  cout << "Subtraction Results" << endl;
  cout << "----------------------------" << endl;
  calc(valueArray1, valueArray2, calArray, 10, "Sub"); //calling function 3
  cout << "----------------------------" << endl;

  cout << "Multiplication Results" << endl;
  cout << "----------------------------" << endl;
  calc(valueArray1, valueArray2, calArray, 10, "Mul"); //calling function 3
  cout << "----------------------------" << endl;

  cout << "Division Results" << endl;
  cout << "----------------------------" << endl;
  calc(valueArray1, valueArray2, calArray, 10, "Div"); //calling function 3
  cout << "----------------------------" << endl;

  return 0;
}

//Function Definitions
//------------------------
void setValues(int intArray[], int intArraySize, string arrayType) //function 1
{
  string string1 = "value 1"; //assigning "value 1" and "value 2" to strings to be used in if statement
  string string2 = "value 2";
  if (arrayType == string1) //case for "value 1"
  {
    for (int i = 0; i < 10; i++)
    {
      cout << "Enter a value for Index " << i << ": " << endl;
      cin >> intArray[i];
    }
  }
  else //case for "value 2"
  {
    for (int i = 0; i < intArraySize; i++)
    {
      int tempRan = rand() % 200 + 1;
      intArray[i] = tempRan;
    }
  }
}

void printArray(int intArray[], int intArraySize) //function 2
{
  for (int i = 0; i < intArraySize; i++)
  {
    cout << "Index " << i << ": " << intArray[i] << endl; //print array
  }
}

void calc(int intergers1[], int intergers2[], int calculation[], int calSize, string mathOp) //function 3
{
  string mathOpAdd = "Add"; //assigning math operations to strings to be used in if statements
  string mathOpSub = "Sub";
  string mathOpMul = "Mul";
  string mathOpDiv = "Div";
  if (mathOp == mathOpAdd) //case for addition
  {
    for (int i = 0; i < calSize; i++)
    {
      calculation[i] = intergers1[i] + intergers2[i];
      cout << intergers1[i] << " + " << intergers2[i] << " = " << calculation[i] << endl;
    }
  }
  else if (mathOp == mathOpSub) //case for subtraction
  {
    for (int i = 0; i < calSize; i++)
    {
      calculation[i] = intergers1[i] - intergers2[i];
      cout << intergers1[i] << " - " << intergers2[i] << " = " << calculation[i] << endl;
    }
  }
  else if (mathOp == mathOpMul) //case for multiplaction
  {
    for (int i = 0; i < calSize; i++)
    {
      calculation[i] = intergers1[i] * intergers2[i];
      cout << intergers1[i] << " * " << intergers2[i] << " = " << calculation[i] << endl;
    }
  }
  else
  {
    for (int i = 0; i < calSize; i++) //case for division
    {
      //to get division results with decimals --> copy int arrays into float arrays and then do the calculation
      float floatCalculation[calSize];
      float floatInt1[calSize];
      float floatInt2[calSize];
      floatInt1[i] = intergers1[i]; //convert int arrays into float arrays
      floatInt2[i] = intergers2[i];
      floatCalculation[i] = floatInt1[i] / floatInt2[i];                                     //doing calculation with float arrays
      cout << floatInt1[i] << " / " << floatInt2[i] << " = " << floatCalculation[i] << endl; //print the results of the float calculation
    }
  }
}