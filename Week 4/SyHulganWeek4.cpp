//----------------------------
//Sy Hulgan
//Date
//Assignment 4
//----------------------------

//Pre-processor directives
#include <iostream>
#include <string>

//declare namespace
using namespace std;

//OS blind clear screen function
void clear()
{
  cout << "\x1B[2J\x1B[H"; // "[2J" clears the screen and "[H" moves cursor to top left
}

//Starting main function
int main()
{
  srand(time(0));
  //pre conditions
  //first names
  string firstName1, firstName2, firstName3;

  //last names
  string lastName1, lastName2, lastName3;

  //postions
  string position1, position2, position3, position4, position5;

  //number of players
  int playerNum;

  cout << "First Name 1: " << endl;
  cin >> firstName1;
  cout << "First Name 2: " << endl;
  cin >> firstName2;
  cout << "First Name 3: " << endl;
  cin >> firstName3;

  cout << "\nLast Name 1: " << endl;
  cin >> lastName1;
  cout << "Last Name 2: " << endl;
  cin >> lastName2;
  cout << "Last Name 3: " << endl;
  cin >> lastName3;

  cout << "\nPosition 1: " << endl;
  cin >> position1;
  cout << "Position 2: " << endl;
  cin >> position2;
  cout << "Position 3: " << endl;
  cin >> position3;
  cout << "Position 4: " << endl;
  cin >> position4;
  cout << "Position 5: " << endl;
  cin >> position5;

  cout << "\nNumber of players on the team: " << endl;
  cin >> playerNum;

  //creating strings that combine randomize selection of first and last names
  string playerFirstName, playerLastName, playerPosition;

  //string to store randomized grade (ie. Freshman, Junior, etc)
  string yearStatus;

  /*
    assortment of variables to assign random "positions" for the previously entered
    first names and last names
  */
  int randomNum1, randomNum2, randomNum3, randomNum4;

  //part 1
  //for loop to assign players' names randomly according to rand() function
  for (int i = 1; i <= playerNum; i++)
  {
    randomNum1 = rand() % 3 + 1; //random numbers for assigning first names
    randomNum2 = rand() % 3 + 1; //random numbers for assigning last names
    randomNum3 = rand() % 5 + 1; //random numbers for assigning positions
    randomNum4 = rand() % 4 + 1; //random numbers to assign grades

    //whole bunch of if statements for assigning random names, grades, and positions
    if (randomNum1 == 1)
    {
      playerFirstName = firstName1;
    }
    else if (randomNum1 == 2)
    {
      playerFirstName = firstName2;
    }
    else
    {
      playerFirstName = firstName3;
    }

    if (randomNum2 == 1)
    {
      playerLastName = lastName1;
    }
    else if (randomNum2 == 2)
    {
      playerLastName = lastName2;
    }
    else
    {
      playerLastName = lastName3;
    }

    if (randomNum3 == 1)
    {
      playerPosition = position1;
    }
    else if (randomNum3 == 2)
    {
      playerPosition = position2;
    }
    else if (randomNum3 == 3)
    {
      playerPosition = position3;
    }
    else if (randomNum3 == 4)
    {
      playerPosition = position4;
    }
    else
    {
      playerPosition = position5;
    }

    if (randomNum4 == 1)
    {
      yearStatus = "Freshman";
    }
    else if (randomNum4 == 2)
    {
      yearStatus = "Sophomore";
    }
    else if (randomNum4 == 3)
    {
      yearStatus = "Junior";
    }
    else
    {
      yearStatus = "Senior";
    }

    //printing out each randomized players' information
    cout << "\n-------------------------" << endl;
    cout << "Player " << i << " Info: " << endl;
    cout << "Name: " << playerFirstName + " " + playerLastName << endl;
    cout << "Position: " << playerPosition << endl;
    cout << "Grade: " << yearStatus << endl;
    cout << "-------------------------" << endl;
  }

  //quick pause and clearing of the screen
  cout << "Press any key to continue! ";
  cin.ignore();
  cin.get();
  clear();

  //creating variables to be used in the upcoming loop
  int groupChoice;
  int proteinChoice, carbsChoice, fatsChoice;

  //counter to be used
  int cnt = 0;

  //part 2
  //using do-while loop to select what foods to order
  do
  {
    clear(); //clear function at the top to keep screen clear
    cout << "\nWhat item to order: " << endl;
    cout << "1. Protein" << endl;
    cout << "2. Carbs" << endl;
    cout << "3. Fats" << endl;
    cout << "4. Cancel" << endl;
    cin >> groupChoice;

    //best implementation I could muster :|
    if (groupChoice == 1)
    {
      while (true)
      {
        cout << "\nSelect desired protein source: " << endl;
        cout << "1. Whey Protein 24.99" << endl;
        cout << "2. Chicken Breast 7.99" << endl;
        cout << "3. Egg Whites 4.49" << endl;
        cout << "4. Return to food group selection" << endl;
        cin >> proteinChoice;
        //if statement for selecting anything but "Return to food group selection"
        if (proteinChoice == 1 || proteinChoice == 2 || proteinChoice == 3)
        {
          cnt++; //adding to counter so that
          break; //breaking while loop
        }
        else
        {
          break;
        }
      }
    }
    else if (groupChoice == 2)
    {
      while (true)
      {
        cout << "\nSelect desired source of carbs: " << endl;
        cout << "1. Bread 1.99" << endl;
        cout << "2. Rice 2.49" << endl;
        cout << "3. Potatoes 4.99" << endl;
        cout << "4. Return to food group selection" << endl;
        cin >> carbsChoice;
        if (carbsChoice == 1 || carbsChoice == 2 || carbsChoice == 3)
        {
          cnt++;
          break;
        }
        else
        {
          break;
        }
      }
    }
    else if (groupChoice == 3)
    {
      while (true)
      {
        cout << "\nSelect desired fat source: " << endl;
        cout << "1. Nuts 10.99" << endl;
        cout << "2. Avocados 0.99" << endl;
        cout << "3. Cheese 3.99" << endl;
        cout << "4. Return to food group selection" << endl;
        cin >> fatsChoice;
        if (fatsChoice == 1 || fatsChoice == 2 || fatsChoice == 3)
        {
          cnt++;
          break;
        }
        else
        {
          break;
        }
      }
    }
    else if (groupChoice == 4)
    {
      while (true)
      {
        cout << "You have to selection an option for each group first!" << endl;
        cout << "Press any key to continue! ";
        cin.ignore(); //making it where user can press any key to continue
        cin.get();
        break;
      }
    }
  } while (cnt < 3);

  //part 3
  //assigning choice numbers to strings
  string stringProtein, stringCarbs, stringFats;
  float proteinPrice, carbsPrice, fatsPrice;

  if (proteinChoice == 1)
  {
    stringProtein = "Whey Protein";
    proteinPrice = 24.99;
  }
  else if (proteinChoice == 2)
  {
    stringProtein = "Chicken Breast";
    proteinPrice = 7.99;
  }
  else if (proteinChoice == 3)
  {
    stringProtein = "Egg Whites";
    proteinPrice = 4.49;
  }
  ///////////////////////////////////

  if (carbsChoice == 1)
  {
    stringCarbs = "Bread";
    carbsPrice = 1.99;
  }
  else if (carbsChoice == 2)
  {
    stringCarbs = "Rice";
    carbsPrice = 2.49;
  }
  else if (carbsChoice == 3)
  {
    stringCarbs = "Potatoes";
    carbsPrice = 4.99;
  }
  ////////////////////////////////

  if (fatsChoice == 1)
  {
    stringFats = "Bread";
    fatsPrice = 10.99;
  }
  else if (fatsChoice == 2)
  {
    stringFats = "Rice";
    fatsPrice = 0.99;
  }
  else if (fatsChoice == 3)
  {
    stringFats = "Potatoes";
    fatsPrice = 3.99;
  }
  //////////////////////////////////

  clear();

  //creating quantity variables and assigning them to a default value
  int proteinQuan = 1;
  int carbsQuan = 1;
  int fatsQuan = 1;

  //variable for which option the user enters
  int optionChoice;

  //variables for total cost of each group
  int proteinCost, carbsCost, fatsCost, totalCost;

  //bad implementation... sorry about that
  //im reprinting the order screen assuming the user moves along
  clear(); //clear function at the top to keep screen clear
  cout << "\nWhat item to order: " << endl;
  cout << "1. Protein" << endl;
  cout << "2. Carbs" << endl;
  cout << "3. Fats" << endl;
  cout << "4. Proceed to checkout" << endl;
  cin >> groupChoice;

  if (groupChoice == 4)
  {
    if (proteinChoice != 0 && carbsChoice != 0 && fatsChoice != 0)
    {
      while (true)
      {
        clear();

        cout << "Item Information:" << endl;
        cout << "-------------------------------" << endl;
        cout << "Protein Choice: " + stringProtein << endl;
        cout << "Item Price: " << proteinPrice << endl;
        cout << "Item Quantity: " << proteinQuan << endl;
        cout << "-------------------------------" << endl;
        cout << "Carbs Choice: " + stringCarbs << endl;
        cout << "Item Price: " << carbsPrice << endl;
        cout << "Item Quantity: " << carbsQuan << endl;
        cout << "-------------------------------" << endl;
        cout << "Fats Choice: " + stringFats << endl;
        cout << "Item Price: " << fatsPrice << endl;
        cout << "Item Quantity: " << fatsQuan << endl;
        cout << "-------------------------------" << endl;
        cout << "Select an Option: " << endl;
        cout << "1. Randomize Quanties" << endl;
        cout << "2. Place Order" << endl;
        cin >> optionChoice;

        if (optionChoice == 1)
        {
          proteinQuan = rand() % 100 + 1;
          carbsQuan = rand() % 100 + 1;
          fatsQuan = rand() % 100 + 1;
        }
        else if (optionChoice == 2 && proteinQuan == 1 && carbsQuan == 1 && fatsQuan == 1)
        {
          cout << "You haven't randomized the quantities yet!";
        }
        else if (optionChoice == 2 && proteinQuan != 1 && carbsQuan != 1 && fatsQuan != 1)
        {
          //part 4
          proteinCost = proteinPrice * proteinQuan;
          carbsCost = carbsPrice * carbsQuan;
          fatsCost = fatsPrice * fatsQuan;
          totalCost = proteinCost + carbsCost + fatsCost;

          //printing the receipt
          cout << "\nReceipt: " << endl;
          cout << "-------------------------------" << endl;
          cout << "Protein Choice: " + stringProtein << endl;
          cout << "Item Quantity: " << proteinQuan << endl;
          cout << "Price: " << proteinCost << endl;
          cout << "-------------------------------" << endl;
          cout << "Carbs Choice: " + stringCarbs << endl;
          cout << "Item Quantity: " << carbsQuan << endl;
          cout << "Price: " << carbsCost << endl;
          cout << "-------------------------------" << endl;
          cout << "Fats Choice: " + stringFats << endl;
          cout << "Item Quantity: " << fatsQuan << endl;
          cout << "Price: " << fatsCost << endl;
          cout << "-------------------------------" << endl;
          cout << "Total Price: " << totalCost << endl;
          cout << "\nPress any key to finish! ";
          cin.ignore();
          cin.get();
          clear();
          break;
        }
      }
    }
  }
  else if (groupChoice != 4)
  {
    while (true)
    {
      cout << "You have already selected your options. You must proceed!" << endl;
      break;
    }
  }
}