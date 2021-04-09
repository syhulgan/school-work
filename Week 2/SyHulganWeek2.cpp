//----------------------------
//Sy Hulgan
//1-22-21
//Assignment 2
//----------------------------

//Pre-processor directives
#include <iostream>
#include <string.h> //i don't know why i include this, but i did when research how to solve something

//declare namespace
using namespace std;

// since I use linux I can't use system("pause") or system("cls") so here is a function 
// to clear the screen that should be OS blind (it should work on any os)
void clear(){
    cout << "\x1B[2J\x1B[H"; // "[2J" clears the screen and "[H" moves cursor to top left
  }

//Starting main function
int main(){
  //part 1
  //declaring variables
  string firstName;
  string lastName;
  string address;
  int ageInt;
  float valuePi;
  char singleCharacter;

  //asking for inputs
  cout << "Enter Your First Name: " << endl;  //first name
  cin >> firstName;

  cout << "Enter Your Last Name: " << endl; //last name
  cin >> lastName;

  //extra credit solution for address
  cout << "Enter Your Address: " << endl; //address
  cin.ignore();  //have to flush new line out of the buffer <--- according to stack overflow
  getline(cin,address);  //way to input whole line into string

  cout << "Enter Your Age: " << endl; //age
  cin >> ageInt;

  cout << "Enter First Few Digits of Pi: " << endl; //value of pi
  cin >> valuePi;

  cout << "Enter a Single Character: " << endl; //character
  cin >> singleCharacter;

  //pausing the screen until a key is pressed
  cout << "Press any key to continue! ";
  cin.ignore(); //using this to clear buffer so that cin.get() can be used for key input
  cin.get();
  clear();  //calling upon previously defined function

  //outputting user profile
  string fullName = firstName + " " + lastName; //combine strings to make one fullName string
  cout << "User Profile\n";
  cout << "------------------------------\n"; //decoration
  cout << "Full Name: " << fullName << endl;
  cout << "Address: " << address << endl;
  cout << "Age: " << ageInt << endl;
  cout << "Value of Pi: " << valuePi << endl;
  cout << "Single Character: " << singleCharacter << endl;
  cout << "------------------------------";

  //pausing the screen until a key is pressed
  cout << "\nPress any key to continue! ";
  cin.get();  //dont have to use cin.ignore because there is no buffer to clear
  clear();  //calling upon previously defined function

  //part 2 
  //declaring variables
  unsigned long largerInt; //making sure the hardcoded interger doesn't overflow
  int largeInt;
  int num1;
  int num2;

  //inputs
  cout << "Enter a number greater than 99: " << endl;
  cin >> largeInt;

  cout << "Enter a number for num1: " << endl;
  cin >> num1;

  cout << "Enter a number for num2: " << endl;
  cin >> num2;

  //calulations
  largerInt = 9983447911;
  unsigned long cal1 = largeInt * largerInt; //to get answer to be positive
  int cal2 = num1 + num2;
  int cal3 = num1 - num2;
  int cal4 = num1 * num2;
  int cal5 = num1 / num2;

  //extra credit solution for getting decimals after dividing intergers
  //setting cal6 to be float. can divide double or float varible by an interger and
  //get a float or double answer. multiplying num1 by double(1.0) and dividing by num 2
  float cal6 = 1.0 * num1 / num2;

  clear(); //clearing the screen again so it looks prettier

  //printing calulations
  cout << "Calculations\n";
  cout << "------------------------------\n";
  cout << "Large Number Value = " << cal1 << endl;
  cout << num1 << " + " << num2 << " = " << cal2 << endl; //combing intergers and strings 
  cout << num1 << " - " << num2 << " = " << cal3 << endl;
  cout << num1 << " * " << num2 << " = " << cal4 << endl;
  cout << num1 << " / " << num2 << " = " << cal5 << endl;
  cout << num1 << " / " << num2 << " = " << cal6 << endl;
  cout << "------------------------------";

  //pausing the screen until a key is pressed
  cout << "\nPress any key to finish! ";
  cin.ignore();
  cin.get();
  clear();  //calling upon previously defined function
}