//----------------------------
//Sy Hulgan
//3-21-21
//Week 10 - Classes/Structures
//----------------------------

//explanation of program
//----------------------------
//this program calculates the value of a definite integral using the trapezoidal method
//by default f(x) = sqrt(x)
//----------------------------

//pre-processor directives
#include <iostream>
#include <string>
#include <string.h>
#include <time.h>
#include <cmath>

//declare namespace
using namespace std;

//OS blind clear screen function
void clear()
{
  cout << "\x1B[2J\x1B[H"; // "[2J" clears the screen and "[H" moves cursor to top left
}

//mathematical function to have definite integral calculated
//can be changed to anything and the program still works!
double f(double(x))
{
  return (sqrt(x));
}

//data structures
//------------------------
struct IntegralStruct
{
  double x0;   //lower integration bound
  double x1;   //upper integration bound
  double n;    //number of intervals (degree of precision)
  double area; //self-explanatory
};

//function Protypes
//------------------------
IntegralStruct calculateIntegralValues();                                //function to assign values to the members of IntegralStruct
void printIntegralInfo(IntegralStruct tempIntegral);                     //prints information found in IntegralStruct
void createIntegralSet(IntegralStruct tempApprox[], int tempApproxSize); //function to create an array for IntegralStruct
double trapezoidal(double x0, double x1, double n);                      //function to determine value of definite integral using the trapezoidal method

//Starting main function
int main()
{
  clear(); //clearing screen because it gets very messy after multiple runs

  //start of program
  cout << "This program approximates the definite integral of f(x) = sqrt(x)" << endl;
  cout << "The user will be able to try different bounds and degrees of precision!" << endl;
  cout << "-----------------------------\n" << endl;
       

  //creating struct and setting its values
  IntegralStruct integral;
  integral = calculateIntegralValues();
  integral.area = trapezoidal(integral.x0, integral.x1, integral.n); //determing area using trapezoidal function
  printIntegralInfo(integral);                                       //print results

  //part 2 where an array of structs will be used
  cout << "\nThe next part will allow the user to try several different values of n" << endl;
  cout << "-----------------------------" << endl;

  //determining how big the array will be...
  //the size of the array is also the number of values of n what will be used
  int num;
  cout << "\nHow many values of n do you want to test?" << endl;
  cin >> num;                      //getting size (values of n to be calculated)
  IntegralStruct integralSet[num]; //creating array of structs using num

  //setting the values of the structs in the array
  createIntegralSet(integralSet, num);

  //for loop to get the integral value using the various values of n
  for (int i = 0; i < num; i++)
  {
    integralSet[i].area = trapezoidal(integralSet[i].x0, integralSet[i].x1, integralSet[i].n);
  }

  //printing out results
  cout << "\nResults of various degrees of precision" << endl;
  for (int i = 0; i < num; i++)
  {
    printIntegralInfo(integralSet[i]);
  }
}

//function Definitions
//------------------------
IntegralStruct calculateIntegralValues() //function to get parameters need for trapezoidal();
{
  IntegralStruct tempIntegral; //temp struct

  //user input
  cout << "Lower Bound" << endl;
  cin >> tempIntegral.x0;
  cout << "Upper Bound" << endl;
  cin >> tempIntegral.x1;
  cout << "Enter Value of n (higher for more precision)" << endl;
  cin >> tempIntegral.n;

  return tempIntegral; //returning struct
}

void printIntegralInfo(IntegralStruct tempResults) //function that prints out members of struct
{
  cout << "-----------------------------" << endl;
  cout << "Lower Bound: " << tempResults.x0 << endl;
  cout << "Upper Bound: " << tempResults.x1 << endl;
  cout << "Degree of Precision: " << tempResults.n << endl;
  cout << "Area: " << tempResults.area << endl;
  cout << "-----------------------------" << endl;
}

void createIntegralSet(IntegralStruct tempApprox[], int tempApproxSize) //function to create array of IntegralStruct
{
  //user input
  double xl, xu;
  cout << "Lower Bound" << endl;
  cin >> xl;
  cout << "Upper Bound" << endl;
  cin >> xu;

  for (int i = 0; i < tempApproxSize; i++) //for loop to get what values of n will be used and then assigning them to the "n" member of the struct
  {
    cout << "Enter n for Index: " << i << endl;
    cin >> tempApprox[i].n;
    tempApprox[i].x0 = xl; //setting all of the lower and upper bounds to the same value for all structs in the array
    tempApprox[i].x1 = xu;
  }
}

//trapezoidal method for approximating the value of a definite integral
double trapezoidal(double a, double b, double n)
{
  //spacing across the x-axis (delta(x))
  double h = (b - a) / n;

  // Computing sum of first and last terms
  // in above formula
  double s = f(a) + f(b);

  // Adding middle terms in above formula
  for (int i = 1; i < n; i++)
  {
    s += 2 * f(a + i * h);
  }

  // h/2 indicates (b-a)/2n. Multiplying h/2
  // with s.
  return (h / 2) * s;
}