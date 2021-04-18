#pragma once
#include <string>
using namespace std;

void fillArrays(string fileName, string stringArray[])
{
  ifstream file; //opening file to be read from
  file.open(fileName);

  for (int i = 0; i < 10; i++) //getting data from file and storing in an array
  {
    file >> stringArray[i];
  }
}

void createGarage(Car carDataArray[], int carDataArraySize, string brandsArray[], string colorsArray[], string modelsArray[], int carInfoArraySize)
{
  int count = 0;
  //creating random cars using random indexes from respective arrays
  while (count < carDataArraySize)
  {
    int randomBrand = rand() % carInfoArraySize;
    int randomColor = rand() % carInfoArraySize;
    int randomModel = rand() % carInfoArraySize;

    carDataArray[count].brand = brandsArray[randomBrand];
    carDataArray[count].color = colorsArray[randomColor];
    carDataArray[count].model = modelsArray[randomModel];
    carDataArray[count].maxSpeed = rand() % 151; //getting random speed

    count++;
  }
  cout << "\nGarage is created!" << endl; //letting user know the function was executed
}

void printUnsortedGarage(Car carDataArray[], int carDataArraySize, string outputPath)
{
  ofstream unsortedFile; //creating a file to store data into
  unsortedFile.open(outputPath, ios::app);

  if (unsortedFile.is_open())
  {
    for (int i = 0; i < carDataArraySize; i++) //looping through all of the cars and printing their info into the file
    {
      unsortedFile << "Car " << i << endl;
      unsortedFile << "================" << endl;
      unsortedFile << carDataArray[i].brand << endl;
      unsortedFile << carDataArray[i].model << endl;
      unsortedFile << carDataArray[i].color << endl;
      unsortedFile << carDataArray[i].maxSpeed << endl;
      unsortedFile << "----------------" << endl;
      unsortedFile << "" << endl;
    }

    unsortedFile.close();
  }
}

void printSortedGarage(Car carDataArray[], int carDataArraySize, string outputPath, string brandsArray[], string colorsArray[], string modelsArray[], int carInfoArraySize)
{
  ofstream sortedFile; //creating a file to store data into
  sortedFile.open(outputPath, ios::app);

  if (sortedFile.is_open())
  {
    int userChoice; //variable to store user choice

    //menu
    cout << "\nHow do you wish to sort your garage?" << endl;
    cout << "====================================" << endl;
    cout << "1. Brands" << endl;
    cout << "2. Models" << endl;
    cout << "3. Colors" << endl;
    cout << "====================================" << endl;
    cout << "Enter your choice: ";
    cin >> userChoice;

    if (userChoice == 1) //choice for brands
    {
      for (int i = 0; i < carInfoArraySize; i++) //looping through each index of brand array
      {
        for (int j = 0; j < carDataArraySize; j++) //looping through all of the cars in the garage
        {
          if (carDataArray[j].brand == brandsArray[i]) //condition for when car in garage matches index in brands array
          {
            sortedFile << "Car " << j << endl;
            sortedFile << "================" << endl;
            sortedFile << carDataArray[j].brand << endl;
            sortedFile << carDataArray[j].model << endl;
            sortedFile << carDataArray[j].color << endl;
            sortedFile << carDataArray[j].maxSpeed << endl;
            sortedFile << "----------------" << endl;
            sortedFile << "" << endl;
          }
        }
      }
    }
    else if (userChoice == 2) //choice for models
    {
      for (int i = 0; i < carInfoArraySize; i++) //looping through each index of model array
      {
        for (int j = 0; j < carDataArraySize; j++) //looping through all of the cars in the garage
        {
          if (carDataArray[j].model == modelsArray[i]) //condition for when car in garage matches index in models array
          {
            sortedFile << "Car " << j << endl;
            sortedFile << "================" << endl;
            sortedFile << carDataArray[j].brand << endl;
            sortedFile << carDataArray[j].model << endl;
            sortedFile << carDataArray[j].color << endl;
            sortedFile << carDataArray[j].maxSpeed << endl;
            sortedFile << "----------------" << endl;
            sortedFile << "" << endl;
          }
        }
      }
    }
    else if (userChoice == 3) //choice for colors
    {
      for (int i = 0; i < carInfoArraySize; i++) //looping through each index of color array
      {
        for (int j = 0; j < carDataArraySize; j++) //looping through all of the cars in the garage
        {
          if (carDataArray[j].color == colorsArray[i]) //condition for when car in garage matches index in color array
          {
            sortedFile << "Car " << j << endl;
            sortedFile << "================" << endl;
            sortedFile << carDataArray[j].brand << endl;
            sortedFile << carDataArray[j].model << endl;
            sortedFile << carDataArray[j].color << endl;
            sortedFile << carDataArray[j].maxSpeed << endl;
            sortedFile << "----------------" << endl;
            sortedFile << "" << endl;
          }
        }
      }
    }
    else //condition for the case the user doesn't input a valid selection //terminates program
    {
      cout << "\nInvalid Selection!" << endl;
    }
    sortedFile.close();
  }
}

void printOutputFolder(Car carDataArray[], int carDataArraySize, string brandsArray[], string colorsArray[], string modelsArray[], int carInfoArraySize, Output outputData)
{
  ////////////////////////////////////////// Printing Brands
  for (int i = 0; i < carInfoArraySize; i++) //looping through brandsArray[]
  {
    ofstream brandsFile;                                                     //creating a new file for each index of brandsArray[]
    outputData.outputBrandPath = "Output/Brands/" + brandsArray[i] + ".txt"; //creating output path using Output struct
    brandsFile.open(outputData.outputBrandPath, ios::app);

    if (brandsFile.is_open())
    {
      for (int j = 0; j < carDataArraySize; j++) //looping through garage
      {
        if (carDataArray[j].brand == brandsArray[i]) //condition for when the brand of a specific car equals the respective index of the brandArray[]
        {
          brandsFile << "Car " << j << endl;
          brandsFile << "================" << endl;
          brandsFile << carDataArray[j].brand << endl;
          brandsFile << carDataArray[j].model << endl;
          brandsFile << carDataArray[j].color << endl;
          brandsFile << carDataArray[j].maxSpeed << endl;
          brandsFile << "----------------" << endl;
          brandsFile << "" << endl;
        }
      }
      brandsFile.close();
    }
  }

  ////////////////////////////////////////// Printing Models
  for (int i = 0; i < carInfoArraySize; i++) //looping through modelsArray[]
  {
    ofstream modelsFile;                                                     //creating a new file for each index of modelsArray[]
    outputData.outputModelPath = "Output/Models/" + modelsArray[i] + ".txt"; //creating output path using Output struct
    modelsFile.open(outputData.outputModelPath, ios::app);

    if (modelsFile.is_open())
    {
      for (int j = 0; j < carDataArraySize; j++) //looping through garage
      {
        if (carDataArray[j].model == modelsArray[i]) //condition for when the model of a specific car equals the respective index of the modelsArray[]
        {
          modelsFile << "Car " << j << endl;
          modelsFile << "================" << endl;
          modelsFile << carDataArray[j].brand << endl;
          modelsFile << carDataArray[j].model << endl;
          modelsFile << carDataArray[j].color << endl;
          modelsFile << carDataArray[j].maxSpeed << endl;
          modelsFile << "----------------" << endl;
          modelsFile << "" << endl;
        }
      }
      modelsFile.close();
    }
  }

  ////////////////////////////////////////// Printing Colors
  for (int i = 0; i < carInfoArraySize; i++) //looping through colorsArray[]
  {
    ofstream colorsFile;                                                     //creating a new file for each index of colorsArray[]
    outputData.outputColorPath = "Output/Colors/" + colorsArray[i] + ".txt"; //creating output path using Output struct
    colorsFile.open(outputData.outputColorPath, ios::app);

    if (colorsFile.is_open())
    {
      for (int j = 0; j < carDataArraySize; j++) //looping through garage
      {
        if (carDataArray[j].color == colorsArray[i]) //condition for when the color of a specific car equals the respective index of the colorsArray[]
        {
          colorsFile << "Car " << j << endl;
          colorsFile << "================" << endl;
          colorsFile << carDataArray[j].brand << endl;
          colorsFile << carDataArray[j].model << endl;
          colorsFile << carDataArray[j].color << endl;
          colorsFile << carDataArray[j].maxSpeed << endl;
          colorsFile << "----------------" << endl;
          colorsFile << "" << endl;
        }
      }
      colorsFile.close();
    }
  }

  ////////////////////////////////////////// Printing Fast Cars
  ofstream fastFile, slowFile;                   //creating files to store fast and slow cars
  outputData.outputSpeedPath = "Output/Speeds/"; //using Output struct to store the files location

  fastFile.open(outputData.outputSpeedPath + "fastCars.txt", ios::app); //function call adding "fastCars.txt"
  for (int i = 0; i < carDataArraySize; i++)                            //looping through garage
  {
    if (carDataArray[i].maxSpeed > 70) //if the car's speed is greater than 70 it is added to the file
    {
      fastFile << "Car " << i << endl;
      fastFile << "================" << endl;
      fastFile << carDataArray[i].brand << endl;
      fastFile << carDataArray[i].model << endl;
      fastFile << carDataArray[i].color << endl;
      fastFile << carDataArray[i].maxSpeed << endl;
      fastFile << "----------------" << endl;
      fastFile << "" << endl;
    }
  }
  fastFile.close();

  ////////////////////////////////////////// Printing Slow Cars
  slowFile.open(outputData.outputSpeedPath + "slowCars.txt", ios::app); //function call adding "fastCars.txt"
  for (int i = 0; i < carDataArraySize; i++)                            //looping through garage
  {
    if (carDataArray[i].maxSpeed <= 70) //if the car's speed is less than or equal to 70 it is added to the file
    {
      slowFile << "Car " << i << endl;
      slowFile << "================" << endl;
      slowFile << carDataArray[i].brand << endl;
      slowFile << carDataArray[i].model << endl;
      slowFile << carDataArray[i].color << endl;
      slowFile << carDataArray[i].maxSpeed << endl;
      slowFile << "----------------" << endl;
      slowFile << "" << endl;
    }
  }
  slowFile.close();

  ////////////////////////////////////////// Printing Stats
  ofstream statsFile;                                    //creating file to store the garage's stats
  outputData.outputStatsPath = "Output/garageStats.txt"; //Output struct to store file name for garage stats
  statsFile.open(outputData.outputStatsPath, ios::app);

  statsFile << "Car Count: " << carDataArraySize << endl; //printing car count (100)
  statsFile << "---------------------" << endl;

  if (statsFile.is_open())
  {
    for (int i = 0; i < carInfoArraySize; i++) //looping through brandsArray[]
    {
      int brandsCount = 0;                       //variable to store the number of cars that are a particular brand
      for (int j = 0; j < carDataArraySize; j++) //looping through garage
      {
        if (carDataArray[j].brand == brandsArray[i]) //condition to check if a car in the garage has a particular brand
        {
          brandsCount++; //adding to the counter
        }
      }
      statsFile << brandsArray[i] << ": " << brandsCount << endl; //printing out the brands' counts to the stats file
    }
    statsFile << "---------------------" << endl; //divider to make it look better
    for (int i = 0; i < carInfoArraySize; i++)    //looping through colorsArray[]
    {
      int colorsCount = 0;                       //variable to store the number of cars that are a particular color
      for (int j = 0; j < carDataArraySize; j++) //looping through garage
      {
        if (carDataArray[j].color == colorsArray[i]) //condition to check if a car in the garage has a particular color
        {
          colorsCount++; //adding to the counter
        }
      }
      statsFile << colorsArray[i] << ": " << colorsCount << endl; //printing out the colors' counts to the stats file
    }
    statsFile << "---------------------" << endl; //divider to make it look better
    for (int i = 0; i < carInfoArraySize; i++)    //looping through modelsArray[]
    {
      int modelsCount = 0;                       //variable to store the number of cars that are a particular model
      for (int j = 0; j < carDataArraySize; j++) //looping through garage
      {
        if (carDataArray[j].model == modelsArray[i]) //condition to check if a car in the garage has a particular model
        {
          modelsCount++; //adding to the counter
        }
      }
      statsFile << modelsArray[i] << ": " << modelsCount << endl;
    }
    statsFile.close(); //printing out the models' counts to the stats file
  }
}