#pragma once

//function to load data from txt file in to struct array
void LoadPatientIntoRecords(PatientRecords tempPatientArray[], int &tempArrayCount, string tempFileName, int loadCount)
{
  ifstream file;           //creating input
  file.open(tempFileName); //opening txt file
  tempArrayCount = 0;

  //loop to get information from the file and assign it to correct respected member of the struct
  for (int i = 0; i < loadCount; i++)
  {
    file >> tempPatientArray[i].firstName;
    file >> tempPatientArray[i].lastName;
    file >> tempPatientArray[i].Gender;
    file >> tempPatientArray[i].Age;
    file >> tempPatientArray[i].birthMonth;
    file >> tempPatientArray[i].Birthday;
    file >> tempPatientArray[i].birthYear;
    file >> tempPatientArray[i].Symptoms;
    tempArrayCount++; //counter to keep track of the number of patients
  }

  file.close(); //closing file
}

//function to add additional patients to the database
void AddPatientsToRecords(PatientRecords tempPatientArray[], int &tempArrayCount)
{
  //just asking user for input
  //then setting input to respective member of the new patient struct array index
  cout << "\nEnter Patient Information" << endl;
  cout << "---------------------------------" << endl;
  cout << "First Name: " << endl;
  cin >> tempPatientArray[tempArrayCount].firstName;
  cout << "Last Name: " << endl;
  cin >> tempPatientArray[tempArrayCount].lastName;
  cout << "Gender: " << endl;
  cin >> tempPatientArray[tempArrayCount].Gender;
  cout << "Age: " << endl;
  cin >> tempPatientArray[tempArrayCount].Age;
  cout << "Birth Month: " << endl;
  cin >> tempPatientArray[tempArrayCount].birthMonth;
  cout << "Birthday: " << endl;
  cin >> tempPatientArray[tempArrayCount].Birthday;
  cout << "Birth Year: " << endl;
  cin >> tempPatientArray[tempArrayCount].birthYear;
  cout << "Symptoms: " << endl;
  cin >> tempPatientArray[tempArrayCount].Symptoms;

  tempArrayCount++; //keep track of the number of patients
}

//function to print out patient database
void PrintPatientRecords(PatientRecords tempPatientArray[], int &arrayCount)
{
  if (arrayCount == 0) //condition for when there is no patients on record
  {
    cout << "\nNo patients on record" << endl;
  }

  else //actual function
  {
    for (int i = 0; i < arrayCount; i++) //for loop to print the respective information of each patient
    {
      cout << "\nPatient " << i + 1 << " Information" << endl;
      cout << "----------------------------------------------" << endl;
      cout << "First Name: " << tempPatientArray[i].firstName << "\t"
           << "Last Name: " << tempPatientArray[i].lastName << endl;
      cout << "Birth Month: " << tempPatientArray[i].birthMonth << "\t"
           << "Birth Day: " << tempPatientArray[i].Birthday << "\t"
           << "Birth Year: " << tempPatientArray[i].birthYear << endl;
      cout << "Gender: " << tempPatientArray[i].Gender << "\t"
           << "Age: " << tempPatientArray[i].Age << endl;
      cout << "Symptom: " << tempPatientArray[i].Symptoms << endl;
    }
  }
}

//function that searches the data base given a first and last name
void SearchPatientRecords(PatientRecords tempPatientArray[], int arrayCount)
{
  string firstName; //variables for first and last that the user is searching for
  string lastName;
  if (arrayCount == 0) //checking if there is no patients on record
  {
    cout << "\nNo patients on record" << endl;
  }

  else //actual function
  {
    //prompting user that they are about to provide user input
    cout << "\nYou are searching the patient data base. Enter the following information: " << endl;
    cout << "----------------------------------------------" << endl;
    cout << "First Name: " << endl;
    cin >> firstName; //storing first name
    cout << "Last Name: " << endl;
    cin >> lastName; //storing last name

    bool found; //variable to store whether or not the person entered by the user is found in the database

    for (int i = 0; i < arrayCount; i++) //for loop to check all of the patients in the data base
    {
      if (tempPatientArray[i].firstName == firstName && tempPatientArray[i].lastName == lastName) //condition for when the first and last name match
      {
        //printing out results if person is found
        cout << "\nSearch Results for " << firstName << " " << lastName << endl;
        cout << "----------------------------------------------" << endl;
        cout << "First Name: " << tempPatientArray[i].firstName << "\t"
             << "Last Name: " << tempPatientArray[i].lastName << endl;
        cout << "Birth Month: " << tempPatientArray[i].birthMonth << "\t"
             << "Birth Day: " << tempPatientArray[i].Birthday << "\t"
             << "Birth Year: " << tempPatientArray[i].birthYear << endl;
        cout << "Gender: " << tempPatientArray[i].Gender << "\t"
             << "Age: " << tempPatientArray[i].Age << endl;
        cout << "Symptom: " << tempPatientArray[i].Symptoms << endl;
        cout << "----------------------------------------------" << endl;
        found = true; //setting found to true since the patient was found
        break;        //breaking out of loop since patient is found
      }
    }

    if (found != true) //if the patient isn't found then user is alerted that the person they are searching for wasn't found
    {
      cout << "\n"
           << firstName << " " << lastName << " was not found in the records!" << endl;
    }
  }
}