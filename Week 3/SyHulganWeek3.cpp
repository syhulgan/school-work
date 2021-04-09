//----------------------------
//Sy Hulgan
//1-30-21
//Assignment 3
//----------------------------

//Pre-processor directives
#include <iostream>
#include <cstdlib>
#include <ctime>

//declaring namespace(s)
using namespace std;

//clear screen function that is OS blind
void clear(){
    cout << "\x1B[2J\x1B[H"; // "[2J" clears the screen and "[H" moves cursor to top left
  }

//Starting main function
int main(){

  //creating a seed for the rand() function that appears later
  unsigned seed = time(0);
  srand(seed);
  //part 1
  //getting the first and last name via cin and cout
  string firstName;
  string lastName;
  cout << "What is your first name? " << endl;
  cin >> firstName;
  cout << "Last name? " << endl;
  cin >> lastName;

  //part 2 
  //determining the birth month by the character length of first name
  string birthMonth;
  int firstNameLength = firstName.length();

  if (firstNameLength == 1) {
    birthMonth = "January";
  }
  else if (firstNameLength == 2) {
    birthMonth = "February";
  }
  else if (firstNameLength == 3) {
    birthMonth = "March";
  }
  else if (firstNameLength == 4) {
    birthMonth = "April";
  }
  else if (firstNameLength == 5) {
    birthMonth = "May";
  }
  else if (firstNameLength == 6) {
    birthMonth = "June";
  }
  else if (firstNameLength == 7) {
    birthMonth = "July";
  }
  else if (firstNameLength == 8) {
    birthMonth = "August";
  }
  else if (firstNameLength == 9) {
    birthMonth = "September";
  }
  else if (firstNameLength == 10) {
    birthMonth = "October";
  }
  else if (firstNameLength == 11) {
    birthMonth = "November";
  }
  else if (firstNameLength == 12) {
    birthMonth = "December";
  }

  //part 3 
  //determing birthday by character length of last name
  int birthDay = lastName.length();

  //part 4
  //generating random birth year using rand()
  int birthYear = rand() % 1201 + 1000;

  //part 5
  //determing generation
  int generation;
  string stringGen; //same things as for stringRole but with the names of the generations
  
  if (birthYear <= 1400 && birthYear >= 1000) {
    generation = 1; //"Neanderthal"
  }
  else if (birthYear <= 1800 && birthYear > 1400) {
    generation = 2; //"First Civilians" basically when the first civiliations started forming to Mesopotamia
  }
  else {
    generation = 3; //"Year Zero" basically 0 B.C.
  }

  //this section gets the generation names from the generation numbers
  if (generation == 1) {
    stringGen = "Neanderthal";
  }
  else if (generation == 2) {
    stringGen = "First Civilians";
  }
  else {
    stringGen = "Year Zero";
  }

  //part 6
  //assigning user their role 
  int role;
  string stringRole; //setting role numbers into respective string names... ex) role = 1 ---> stringRole = "Hunter"

  //going to use firstNameLength since it was used to determine the birth month
  if ((firstNameLength >= 1) && (firstNameLength <= 4)) {
    role = 1; //hunter
  }
  else if ((firstNameLength >= 5) && (firstNameLength <= 8)) {
    role = 2; //scholar
  }
  else {
    role = 3; //politician
  }

  //this section is getting role names from the role numbers
  if (role == 1) {
    stringRole = "Hunter";
  }
  else if (role == 2) {
    stringRole = "Scholar";
  }
  else {
    stringRole = "Politician";
  }

  //part 7
  //customizing user's role
  int choice1;
  int choice2;
  string selection1; //answer to the first question
  string selection2; //answer to the second question


  /* I had to split the if statements into two separate "if (role == 1)" loops
     I couldn't figure out a better way of doing this so that is what I did */
  if (role == 1) 
  {
    //asking user questions about being a hunter if that is their role
    cout << "What is your preferred weapon? " << endl;
    cout << "1. Range Weapon\n" << "2. Close Weapon" << endl;
    cin >> choice1; //answer to question 1 as an interger
    cout << "What is your preferred prey? " << endl;
    cout << "1. Land Animal\n" << "2. Flying Animal\n" << "3. Water Animal" << endl;
    cin >> choice2; //same as choice1 but for the answer of question 2

    //if statement to determine which choice to use depending on the user's generation
    /*I tried to do everything in one extra nested if statement but it wasn't working smoothly,
      so I decided to split the if statement into two separate chunks for each of the three
      possible roles. You'll see this in action later. */
    if (choice1 == 1) 
    {
      if (generation == 1) {
        selection1 = "Slingshot";
      } 
      else if (generation == 2) {
        selection1 = "Throwing Spear"; 
      }
      else if (generation == 3) {
        selection1 = "Shortbow";
      }
    }
    else if (choice1 == 2) 
    {
      if (generation == 1) {
        selection1 = "Rock-o-Stick";
      } 
      else if (generation == 2) {
        selection1 = "Flint Knife"; 
      }
      else if (generation == 3) {
        selection1 = "Iron Sword";
      }
    }
  }

  if (role == 1) //here is one of those additional if statements
  {
    if (choice2 == 1 ) 
    {
      if (generation == 1) {
        selection2 = "Rabbit";
      } 
      else if (generation == 2) {
        selection2 = "Deer"; 
      }
      else if (generation == 3) {
        selection2 = "Goat";
      }
    }
    else if (choice2 == 2)
    {
      if (generation == 1) {
        selection2 = "Duck";
      }
      else if (generation == 2) {
        selection2 = "Pheasant";
      }
      else if (generation == 3) {
        selection2 = "Pigeon";
      }
    }
    else if (choice2 == 3)
    {
      if (generation == 1) {
        selection2 = "Freshwater Bass";
      }
      else if (generation == 2) {
        selection2 = "Catfish";
      }
      else if (generation == 3) {
        selection2 = "Sturgeon";
      }
    }
  }
  
  /*This sections is exactly this same as the code for the "Hunter" role but with 
    different strings and additional choice for choice1. */
  if (role == 2) 
  { //scholar
    cout << "What is your preferred subject? " << endl;
    cout << "1. Math\n" << "2. Science\n" << "3. History" << endl;
    cin >> choice1;
    cout << "What is your preferred discipline? " << endl;
    cout << "1. Educator\n" << "2. Engineer\n" << "3. Researcher" << endl;
    cin >> choice2;

    if (choice1 == 1) 
    {
      if (generation == 1) {
        selection1 = "Understand that you can have multiple of something";
      } 
      else if (generation == 2) {
        selection1 = "Understand the concept of addition"; 
      }
      else if (generation == 3) {
        selection1 = "a^2 + b^2 = c^2";
      }
    }
    else if (choice1 == 2) 
    {
      if (generation == 1) {
        selection1 = "Fire make food better";
      } 
      else if (generation == 2) {
        selection1 = "Planting food can be beneficial"; 
      }
      else if (generation == 3) {
        selection1 = "Mixing these two substances makes another";
      }
    }
    else if (choice1 == 3) 
    {
      if (generation == 1) {
        selection1 = "I remember only my family";
      } 
      else if (generation == 2) {
        selection1 = "We have artifacts from the past"; 
      }
      else if (generation == 3) {
        selection1 = "Vast recording of local events written down";
      }
    }
  } 
  
  if (role == 2) //here is another additional if statement
  {  
    if (choice2 == 1) 
    {
      if (generation == 1) {
        selection2 = "Teach children how to hunt";
      } 
      else if (generation == 2) {
        selection2 = "Teach others how to farm"; 
      }
      else if (generation == 3) {
        selection2 = "Teach others how to write";
      }
    }
    else if (choice2 == 2)
    {
      if (generation == 1) {
        selection2 = "Working on a more deadly Rock-o-Stick";
      }
      else if (generation == 2) {
        selection2 = "Developing better farming equipment";
      }
      else if (generation == 3) {
        selection2 = "Designing an arch bridge";
      }
    }
    else if (choice2 == 3)
    {
      if (generation == 1) {
        selection2 = "Wondering why one rock breaks another";
      }
      else if (generation == 2) {
        selection2 = "Studying the effects of soil on crops";
      }
      else if (generation == 3) {
        selection2 = "Examining different substances' affects on each other";
      }
    }
  }

  //same as before, this section is just like the one above
  if (role == 3)
  { //politician
    cout << "What is your area of interest? " << endl;
    cout << "1. Community\n" << "2. Budgeting\n" << "3. Planning" << endl;
    cin >> choice1;
    cout << "What is your preferred proposal? " << endl;
    cout << "1. Community Development\n" << "2. Hunting Development\n" << "3. Scholar Development" << endl;
    cin >> choice2;

    if (choice1 == 1) 
    {
      if (generation == 1) {
        selection1 = "My community is my family";
      } 
      else if (generation == 2) {
        selection1 = "Our little tribe is my community"; 
      }
      else if (generation == 3) {
        selection1 = "The community is the whole city";
      }
    }
    else if (choice1 == 2) 
    {
      if (generation == 1) {
        selection1 = "Our nut and berry budget is all over the place";
      } 
      else if (generation == 2) {
        selection1 = "Their isn't enough grain for the desired trade"; 
      }
      else if (generation == 3) {
        selection1 = "Local taxes need to be increased to keep the budget";
      }
    }
    else if (choice1 == 3) 
    {
      if (generation == 1) {
        selection1 = "We need a central cave";
      } 
      else if (generation == 2) {
        selection1 = "The plaza needs to be there"; 
      }
      else if (generation == 3) {
        selection1 = "The local bazaar needs to run throught the center of town";
      }
    }
  }

  if (role == 3) //here's the final extra if statement
  {  
    if (choice2 == 1) 
    {
      if (generation == 1) {
        selection2 = "We need to work together so that we can eat";
      } 
      else if (generation == 2) {
        selection2 = "The local tribe needs to work together so we can survive"; 
      }
      else if (generation == 3) {
        selection2 = "The city needs to have individuals specialize";
      }
    }
    else if (choice2 == 2)
    {
      if (generation == 1) {
        selection2 = "More rocks need to kill more animals";
      }
      else if (generation == 2) {
        selection2 = "Better strategies need to be put into place for hunting";
      }
      else if (generation == 3) {
        selection2 = "Specialized hunters need better equipment";
      }
    }
    else if (choice2 == 3)
    {
      if (generation == 1) {
        selection2 = "The best kind of rock needs to be found";
      }
      else if (generation == 2) {
        selection2 = "The best agricultural technique needs to be found";
      }
      else if (generation == 3) {
        selection2 = "Research on new chemical mixtures need to be explored";
      }
    }
  }

  //output of user information
  //making use of to_string() to get string from of numbers
  string fullBirthInfo = birthMonth + "-" + to_string(birthDay) + "-" + to_string(birthYear); //combining birth day, month, and year into one string also
  cout << "User Profile\n";
  cout << "-----------------------------------------\n"; //decoration
  cout << "First Name: " << firstName << endl;
  cout << "Last Name: " << lastName << endl;
  cout << "Birth Info: " << fullBirthInfo << endl;
  cout << "Generation: " << stringGen << endl;
  cout << "Role: " << stringRole << endl;
  cout << "Choice 1: " << selection1 << endl;
  cout << "Choice 2: " << selection2 << endl;
  cout << "-----------------------------------------\n";

  cout << "Press any key to continue! ";
  cin.ignore(); //making it where user can press any key to continue
  cin.get();
  clear(); //calling clear function to clear screen after pressing any key

  //the end
}