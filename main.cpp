//Bowlby,David Physics Calculator 
//Dr.T COSC 1437-58001 OCT 16, 2019
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
#include <iomanip>
#include <cmath>


using namespace std;

void welcomeMessage();//Function Prototypes
void showMenu();
void menuOptions(char);
void velocity();
void acceleration();
void motionMenu();
void motionOption(char);
void force();
void weight();
void momentum();

   

int main()
{
  char selection = '\0';
  
  welcomeMessage();
  
  do
  {
   showMenu();
   selection = validateChar (selection);
   menuOptions(selection);
   
    
   cout << "\033[2J\033[1;1H";   

  }while(selection != 'x' && selection != 'X');
  
  return 0;
}

//Function Definitions******************
//**************************************

void welcomeMessage()
{
  cout << "\nWelcome to  David Jason's Physics Calculator" <<endl;
}

void showMenu()
{
  cout << "\nPlease Select which Equation you would ";
  cout << "like to use: " << endl;
  cout << "A.) Velocity" << endl;
  cout << "B.) Acceleration" << endl;
  cout << "C.) Motion " << endl;
  cout << "D.) Newton's 2nd Law (Force)" << endl;
  cout << "E.) Weight (Earth) " << endl;
  cout << "F.) Momentum " << endl;
  cout << "G.) Clear Screen " << endl;
  cout << "X.) Exit Program " << endl;
}

void menuOptions(char userOption)
{
  cout << fixed << showpoint << setprecision(4);

  if(userOption == 'a' || userOption == 'A' )
  {
    velocity();
  }
  else if(userOption == 'b' || userOption == 'B')
  {
    acceleration();
  }
  else if(userOption == 'c' || userOption == 'C')
  {
    motionMenu();
  }
  else if(userOption == 'd' || userOption == 'D')
  {
    force();
  }
  else if(userOption == 'e' || userOption == 'E')
  {
    weight();
  }
  else if(userOption == 'f' || userOption == 'F')
  {
    momentum();
  }
  else if(userOption == 'g' || userOption == 'G')
  {
    cout << "\033[2J\033[1;1H";
    
  }
  else if(userOption == 'x' || userOption == 'X')
  {
    cout << "\nThank You for using Jason's Physics ";
    cout << "Calculator. " << endl;
    cout << "\nHave a Nice Day !!!" << endl;
    
  }
  else
  {
    cout << "ERROR, Invalid Input or Something went ";
    cout << "wrong. " << endl;
  }
  
} 

void velocity()
{
    int v = 0;
    double ds = 0.0, dt = 0.0;
    string dsUnits = " ", dtUnits = " ";
    
    cout << "\nYou've Selected Velocity " << endl;
    cout << "\nPlease Enter Distance & Unit of ";
    cout << "measurment (ex.300km) " << endl;
    ds = validateDouble (ds);
    dsUnits = validateString (dsUnits);
    cout << "\nPlease Enter Time traveled & Unit of ";
    cout << "measurment (ex.4hours) " << endl;
    dt = validateDouble (dt);
    dtUnits = validateString (dtUnits);
    cout << '\n';
    
    //Calculation for Velocity *******
    v = (ds / dt);

    cout << v << " = " << ds << dsUnits << " / ";
    cout << dt << dtUnits << endl;
    cout << "\nYour Calculated Velocity is : "<< v << dsUnits << "/"<< dtUnits << endl;
} 

void acceleration()
{
  
  double dt = 0.0, dv = 0.0,Accel = 0.0;
  string dtUnits = " ", dvUnits = " ";
  
  cout << "\nYou've Selected Acceleration " << endl;
    cout << "\nPlease Enter the Velocity & Unit ";
    cout << "of Measure (Ex. 5m) " << endl;
    dt = validateDouble (dt);
    dtUnits = validateString (dtUnits);
    cout << "\nPlease Enter amount of Time & Unit of ";
    cout << "Measurement (Ex. 10sec) " << endl;
    dv = validateDouble (dv);
    dvUnits = validateString (dvUnits);
    cout << '\n' << endl;
    
    //Calculation for Acceleration ******
    Accel = (dv / dt);

    cout << Accel << " = " << dv << dvUnits << " / " << dt << dtUnits << endl;
    
    cout << "\nYour Calculated Acceleration is : ";
    cout << Accel << dtUnits << "/" << dvUnits << endl;
}

void motion()
{
  motionMenu();
}

void force()
{
  int force = 0;
  double mass = 0.0, Accel = 0.0;

  cout << "\nYou've Selected Newton's 2nd Law" << endl;
    cout << "\nWhat is the Mass of your object : ";
    cout << "(Ex. 10kg) " << endl;
    mass = validateDouble (mass);
    cout << "\nWhat is the Acceleration rate of ";
    cout << "your object : (Ex. 5m/s2) " << endl;
    Accel = validateDouble (Accel);
    cout << "\n" << endl;
    
    //Calculation for Force**************
    force = (mass * Accel);

    cout << force << "N = " << mass << "kg * " ;
    cout << Accel << "m/s2 " << endl;
    cout << "\nThe Force of your object is ";
    cout << force << "N " << endl;
}

void weight()
{
  const double gravity = 9.8;
  double mass = 0.0, wght = 0.0;
  
  cout << "\nYou've Selected Weight (Earth) "<< endl;
    cout << "\nWhat is the Mass of your object ";
    cout << "in kg (Ex. 10): " << endl;
    mass = validateDouble (mass);
    cout << "\nThe Mass you Entered is " << mass;
    cout << "kg " << endl;

    wght = ((mass * gravity) / 4.4482);
    
    cout << mass << " * " << gravity << " / ";
    cout << "4.4482 (Newtons) = " << wght << endl;
    //Calculation for Weight (Earth) *******
    cout << "\nYour Weight on Earth is : ";
    cout << wght << "lbs " << endl;

}

void momentum()
{
  int p = 0;
  double mass = 0.0, v = 0.0;
  
  cout << "\nYou've Selected Momentum " << endl;
    cout << "\nWhat is the Mass of your object :";
    cout << "(Ex. 10kg) " << endl;
    mass = validateDouble (mass);
    cout << "\nWhat is the Velocity of your " ;
    cout << "object : (Ex. 5m/s " << endl;
    v = validateDouble(v);
    
    //Calculation for Momentum **************
    p = (mass * v); 
    cout << "\n" << endl;

    cout << p << "[kg m/s] = " << mass << "kg * " << v << "m/s " << endl;

    cout << "\nThe Momentum of your object is : ";
    cout << p << "[kg m/s] " << endl;
}

void motionMenu()
{
  char selection = '\0';
  
  cout << "\033[2J\033[1;1H";
  do
  {
    
    cout << "\nWelcome to the Motion Menu " << endl;
    cout << "\nPlease Select a Equation Calculator : ";
    cout << endl;
    cout << "A.) Ma " << endl;
    cout << "B.) Ms " << endl;
    cout << "C.) Mv2 " << endl;
    cout << "D.) Mv " << endl;
    cout << "E.) Exit " << endl;
    selection = validateChar(selection);
    motionOption(selection);
    
  
  }while (selection != 'e' && selection != 'E');
}

void motionOption(char selection)
{
  double Ma = 0.0, Ms = 0.0, Mv2 = 0.0, Mv = 0.0;
  double v = 0.0, vo = 0.0, s = 0.0, so = 0.0;
  double a = 0.0, t = 0.0;
  
  if(selection == 'a' || selection == 'A')
  {
    cout << "\nPlease Enter the Initial Velocity (vo): " << endl;
  vo = validateDouble(vo);
  cout << "Please Enter the Constant Acceleration (a):"<<
  endl;
  a = validateDouble(a);
  cout << "Please Enter the Total Time (t): " << endl;
  t = validateDouble(t);

  Ma = vo + (a * t);// Calculation to solve for Ma ****
  cout << "\nMa =" << vo << " + (" << a << " * " << t ;
  cout << ")" << endl;
  cout << "\nVelocity (Ma) = " << Ma << endl;
  }
  else if(selection == 'b' || selection == 'B')
  {
    cout << "\nWhat is your Initial Distance (so): " << endl;
    so = validateDouble(so);
    cout << "What is your Initial Velocity (vo): " << endl;
    vo = validateDouble(vo);
    cout << "What is your Time (t): " << endl;
    t = validateDouble(t);
    cout << "What is your Acceleration rate (a): " << endl;
    a = validateDouble(a);

    Ms = (so + (vo*t) + .5 * a * pow (t, 2.0));

    cout << "\nDisplacement (Ms) = " << Ms << endl;
  }
  else if(selection == 'c' || selection == 'C')
  {
    cout << "\nWhat is your Initial Velocity (vo): "<< endl;
    vo = validateDouble(vo);
    cout << "What is your Acceleration rate (a): " << endl;
    a = validateDouble(a);
    cout << "What is your Distance (s): " << endl;
    s = validateDouble(s);
    cout << "What is your Initial Distance (so):" << endl;
    so = validateDouble(so);

    Mv2 = (pow(vo,2.0) + 2.0 * a * (s - so));

    cout << "\nVelocity Squared (Mv2) = " << Mv2 << endl;
  }
  else if(selection == 'd' || selection == 'D')
  {
    cout << "\nWhat is your Velocity (v):" << endl;
    v = validateDouble(v);
    cout << "What is your Intial Velocity (vo):" << endl;

    Mv = .5 * (v + vo);
    cout << "\nAverage Velocity (Mv) = " << Mv;
  }
  else if(selection == 'e' || selection == 'E')
  {
    
  }
  else
  {
    cout << "\nError Something went wrong !!! " << endl;
  }
}




