//----------------------------
//Sy Hulgan
//3-21-21
//Classes/Structs
//----------------------------

//Pre-processor directives
#include <iostream>
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

//data structures
//-----------------------------
struct StudentStruct
{
  //storing name of the student
  string studentName = "DefaultName";
  //storing major of the student
  string studentMajor = "DefaultMajor";
  //storing letter grade of the student
  char studentGrade = 'Z';
  //storing gpa
  float studentGPA = 0.0;
  //storing age
  int studentAge = 18;

  void speak()
  {
    cout << "Hello world" << endl;
  }
};
//-----------------------------

//fuction prototypes
//-----------------------------
StudentStruct CreateStudent();
void printStudentInfo(StudentStruct tempStudent);
void createClass(StudentStruct tempClass[], int tempClassSize);

//Starting main function
int main()
{
  //create a student
  //-----------------------------
  //declaring variables
  StudentStruct student1;

  student1.studentName = "bill";
  student1.studentMajor = "CS";
  student1.studentGPA = 4.0;
  student1.studentGrade = 'A';
  student1.studentAge = 20;
  //-----------------------------

  //printing student out to the screen
  //-----------------------------
  printStudentInfo(student1);
  //-----------------------------

  //creating another student
  //-----------------------------
  StudentStruct student2;
  //-----------------------------

  //printing student out to the screen
  //-----------------------------
  printStudentInfo(student2);
  //-----------------------------

  //calling function to create a student
  //-----------------------------
  StudentStruct student3;
  //student3 = CreateStudent();

  cout << "break" << endl;
  //-----------------------------

  //creating a class of 50 students
  StudentStruct cs121Class[50];
  int cs121ClassSize = 50;

  //calling function
  createClass(cs121Class, cs121ClassSize);
  cout << "break" << endl;
  //-------------------------

  //showcasing assignment for student struct
  StudentStruct student4;

  student4 = cs121Class[0];
  printStudentInfo(student4);
  //-------------------------

  //calling function from struct
  student4.speak();
}

//function definations
StudentStruct CreateStudent()
{
  StudentStruct tempStudent;
  //variables
  //-----------------------------
  //storing name of the student
  string studentName;
  //storing major of the student
  string studentMajor;
  //storing letter grade of the student
  char studentGrade;
  //storing gpa
  float studentGPA;
  //storing age
  int studentAge;
  //-----------------------------

  //getting values from user
  cout << "Enter the following values for student" << endl;
  cout << "Name" << endl;
  cin >> studentName;
  cout << "Major" << endl;
  cin >> studentMajor;
  cout << "Grade" << endl;
  cin >> studentGrade;
  cout << "GPA" << endl;
  cin >> studentGPA;
  cout << "Age" << endl;
  cin >> studentAge;

  //assigning values to structure
  tempStudent.studentName = studentName;
  tempStudent.studentMajor = studentMajor;
  tempStudent.studentGrade = studentGrade;
  tempStudent.studentGPA = studentGPA;
  tempStudent.studentAge = studentAge;

  cout << "break" << endl;

  //return struct
  return tempStudent;
}

void printStudentInfo(StudentStruct tempStudent)
{
  cout << tempStudent.studentName << " info" << endl;
  cout << "-----------------------------" << endl;
  cout << tempStudent.studentName << endl;
  cout << tempStudent.studentMajor << endl;
  cout << tempStudent.studentGPA << endl;
  cout << tempStudent.studentGrade << endl;
  cout << tempStudent.studentAge << endl;
  cout << "-----------------------------" << endl;
}

void createClass(StudentStruct tempClass[], int tempClassSize)
{
  for (int i = 0; i < tempClassSize; i++)
  {
    tempClass[i].studentName = "Bill";
    tempClass[i].studentMajor = "CS";
    tempClass[i].studentGPA = 4.0;
    tempClass[i].studentGrade = 'A';
    tempClass[i].studentAge = 20;
  }
}




