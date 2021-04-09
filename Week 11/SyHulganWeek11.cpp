//----------------------------
//Sy Hulgan
//Date
//Name of file/assignment
//----------------------------

//Pre-processor directives
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

//declare namespace
using namespace std;

#include "PatientsStruct.h"    //step 1
#include "PatientsFunctions.h" //user created header files

//OS blind clear screen function
void clear()
{
  cout << "\x1B[2J\x1B[H"; // "[2J" clears the screen and "[H" moves cursor to top left
}

//starting main function
int main(int argc, char *argv[]) //step 2
{

  if (argc < 3) //step 3 //checking if there isn't enough parameters
  {
    cout << "Not enough parameters!" << endl;
    return 1; //bash can't return negative values
  }

  else if (argc > 3) //checking if there is too many parameters
  {
    cout << "Too many parameters!" << endl;
    return 2; //bash can't return negative values
  }

  //continuation of program
  else //correct number of parameters is 3
  {
    string fileName = argv[1]; //step 4
    string iterationsString = argv[2];
    int interations = stoi(iterationsString); //converting string to int

    if (fileName != "PatientsDB.txt") //step 5 //checking if inputted file has the correct name
    {
      cout << "Text file is not PatientsDB.txt" << endl;
      return 3; //bash can't return negative values
    }
    
    //continuation of program
    else
    {
      if (interations < 1) //step 6 //checking if int argument is less than 1
      {
        cout << "Argument 2 is less than 1! Enter a value between 1 and 10!" << endl;
        return 4; //bash can't return negative values
      }

      else if (interations > 10) //checking if int argument is greater than 10
      {
        cout << "Argument 2 is greater than 10! Enter a value between 1 and 10!" << endl;
        return 5; //bash can't return negative values
      }

      //continuation of program
      else
      {
        PatientRecords PatientDB[100]; //step 7
        int patientNum = 0;            //dummy array size which also represents the number of patients

        //calling function to load data from input file
        LoadPatientIntoRecords(PatientDB, patientNum, fileName, interations); //step 8

        int choice; //variable to represent the user choice

        while (true) //step 9
        {
          //clear(); //clearing screen so it doesn't get messy

          //hospital menu layout
          cout << "\nHospital Menu" << endl;
          cout << "==============================================" << endl;
          cout << "Choice 1: Enter patient to records" << endl;
          cout << "Choice 2: Search Patients" << endl;
          cout << "Choice 3: Print Records" << endl;
          cout << "Choice 4: Leave System" << endl;
          cout << "==============================================" << endl;
          cout << "Enter corresponding number of desired choice!" << endl;
          cin >> choice; //getting user choice selection

          if (choice == 1) //enter patient records
          {
            AddPatientsToRecords(PatientDB, patientNum); //calling function to get new patient
          }

          else if (choice == 2) //search patient database
          {
            SearchPatientRecords(PatientDB, patientNum); //calling function to search for a particular patient
          }

          else if (choice == 3) //print patient records
          {
            PrintPatientRecords(PatientDB, patientNum); //printing the entire patient database
          }

          else if (choice == 4) //leave system
          {
            cout << "\nLeaving Hospital Menu" << endl;
            break; //breaking out of loop to end program
          }

          else //condition if there is an invalid choice selection
          {
            cout << "\nInvalid Choice Selection! Try Again!" << endl;
          }
        }
      }
    }
  }
  return 0;
}