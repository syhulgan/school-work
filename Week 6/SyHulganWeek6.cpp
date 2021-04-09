//----------------------------
//Sy Hulgan
//2-21-21
//Assignment 6
//----------------------------

//Pre-processor directives
#include <iostream>
#include <cmath> //not all of these will be used, they are just there just in case
#include <string>
#include <string.h>

//declare namespace
using namespace std;

//OS blind clear screen function
void clear()
{
  cout << "\x1B[2J\x1B[H"; // "[2J" clears the screen and "[H" moves cursor to top left
}

//function protypes
//-------------------------------
string genName();
void genTitle(string &a);
int genAttackVal();
void genDefenseVal(int &a);
void printStats(string name, string title, int attackVal, int defenseVal, int health);
int genAttackDam(int a);
void attack(int a, int b, int &c);
bool checkHealth(int a);

//main
int main()
{
  //player 1 variables
  //---------------------------
  string playerName1 = "";
  string playerTitle1 = "";
  int playerAttackVal1 = 0;
  int playerDefenseVal1 = 0;
  int playerHealth1 = 100;

  //player 2 variables
  //---------------------------
  string playerName2 = "";
  string playerTitle2 = "";
  int playerAttackVal2 = 0;
  int playerDefenseVal2 = 0;
  int playerHealth2 = 100;

  //generating seed
  srand(time(0));

  //starting with a pause
  cout << "Press any key to start! ";
  cin.get();

  //generating player 1
  //--------------------------------
  playerName1 = genName();           //calling function 1
  genTitle(playerTitle1);            //calling function 2
  playerAttackVal1 = genAttackVal(); //calling function 3
  genDefenseVal(playerDefenseVal1);  //calling function 4
  cout << "\nPlayer: 1 Stats" << endl;
  printStats(playerName1, playerTitle1, playerAttackVal1, playerDefenseVal1, playerHealth1); //calling function 5

  //generating player 2
  //--------------------------------
  playerName2 = genName();           //calling function 1
  genTitle(playerTitle2);            //calling function 2
  playerAttackVal2 = genAttackVal(); //calling function 3
  genDefenseVal(playerDefenseVal2);  //calling function 4
  cout << "\nPlayer: 2 Stats" << endl;
  printStats(playerName2, playerTitle2, playerAttackVal2, playerDefenseVal2, playerHealth2); //calling function 5
  clear();

  //fight loop
  //-------------------------------
  int counter = 1; //counter for round numbers
  while (true)
  {
    //round header
    cout << "Round: " << counter << endl;
    cout << "----------------------------------------------" << endl;
    cout << playerName1 << " \t" << playerName2 << endl;
    cout << playerTitle1 << " \t\t" << playerTitle2 << endl;
    cout << playerHealth1 << " \t\t" << playerHealth2 << endl;
    cout << "----------------------------------------------" << endl;

    //prompting player 1 to attack
    cout << playerName1 << "! Press anything to attack!" << endl;
    cin.get();
    clear();

    //damage calcution and health check for player1 attacking player2
    cout << playerName1 << " - Round: " << counter << endl;
    cout << "==============================================" << endl;
    int player1Attack = genAttackDam(playerAttackVal1);      //calling function 6
    attack(player1Attack, playerDefenseVal2, playerHealth2); //calling function 7
    bool result1 = checkHealth(playerHealth2);               //calling function 8

    //condition for if player 2 is defeated
    if (result1 == false)
    {
      cout << playerName1 << " won!" << endl;
      cout << "Press any key to end program! " << endl;
      cin.get();
      break;
    }

    //prompting player 2 to attack
    cout << playerName2 << "! Press anything to attack!" << endl;
    cin.get();
    clear();

    //damage calcution and health check for player2 attacking player1
    cout << playerName2 << " - Round: " << counter << endl;
    cout << "==============================================" << endl;
    int player2Attack = genAttackDam(playerAttackVal2);      //calling function 6
    attack(player2Attack, playerDefenseVal1, playerHealth1); //calling function 7
    bool result2 = checkHealth(playerHealth1);               //calling function 8

    //condition for if player 1 is defeated
    if (result2 == false)
    {
      cout << playerName2 << " won!" << endl;
      cout << "Press any key to end program! " << endl;
      cin.get();
      break;
    }

    //next round prompt if neither player was defeated
    cout << "Proceed to Next Round!" << endl;
    cin.get();
    clear();

    //adding to counter so while loop will continue if neither player is defeated in the previous round
    counter++;
  }

  return 0;
}

//function definitions
//-------------------------------
string genName() //function 1
{
  string nameArrary[10] = //array of possible names
      {
          "David Budd",
          "Atticus Finch",
          "Frodo Baggins",
          "Jay Gatsby",
          "James Moriarty",
          "Hannibal Lecter",
          "Tyrion Lannister",
          "Luna Lovegood",
          "Cthulhu",
          "Captain Ahab"};
  string name = nameArrary[rand() % 10]; //returning randomly selected name
  return name;
}

//function 2
void genTitle(string &title)
{
  string titleArray[10] = //array of possible titles
      {
          "Bodyguard",
          "Lawyer",
          "Explorer",
          "Businessperson",
          "Professor",
          "Psychiatrist",
          "Noble",
          "Witch",
          "Demon",
          "Sailor"};
  title = titleArray[rand() % 10]; //saving randomly selected into the input variable
}

//function 3
int genAttackVal()
{
  int attackVal = rand() % 190 + 10; //returning randomly selected number between 10 and 200
  return attackVal;
}

//function 4
void genDefenseVal(int &defenseVal)
{
  defenseVal = rand() % 190 + 10; //saving randomly selected value between 10 and 200 to input variable
}

//function 5
void printStats(string name, string title, int attackVal, int defenseVal, int health)
{
  cout << "----------------------------------------------" << endl;
  cout << "Name: " << name << endl;
  cout << "Title: " << title << endl;
  cout << "Attack: " << attackVal << endl;
  cout << "Defense: " << defenseVal << endl;
  cout << "Health: " << health << endl;
  cout << "----------------------------------------------" << endl;

  cout << "Press any key to continue! ";
  cin.get();
}

//function 6
int genAttackDam(int attackDam)
{
  int randomVal = rand() % 10 + 10;     //random value between 10 and 20
  int percentage = attackDam * .1;      //random value as percentage
  int trueDam = randomVal + percentage; //final damage

  //print attack values for the round
  cout << "Attack Damage Generated: " << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Attack Value: " << randomVal << endl;
  cout << "Attack Percentage: " << percentage << endl;
  cout << "Attack Damage: " << trueDam << endl;
  cout << "----------------------------------------------" << endl;
  return trueDam;
}

//function 7
void attack(int playerAttackDam, int opponentDef, int &opponentHealth)
{
  int randomVal = rand() % opponentDef + 1;   //random defense value in range of opponent health and 1
  int percentage = randomVal * 0.1;           //defense value as percentage
  int trueDam = playerAttackDam - percentage; //deturning damage taken
  opponentHealth = opponentHealth - trueDam;  //deducting damage from

  //printing post-fight round information
  cout << "\nAttack Damage Given: " << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Attack Damage (raw): " << playerAttackDam << endl;
  cout << "Defense Random Value: " << randomVal << endl;
  cout << "Defense Buff: " << percentage << endl;
  cout << "Attack Damage (true): " << trueDam << endl;
  cout << "Opponent Health: " << opponentHealth << endl;
  cout << "----------------------------------------------" << endl;
}

//function 8
bool checkHealth(int playerHealth)
{
  if (playerHealth <= 0) //condition for if a player's health is below or equal to zero
  {
    return false;
  }
  else
  {
    return true;
  }
}