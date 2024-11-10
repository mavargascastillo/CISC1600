/* 
CISC 1600
Programming assignment #8 - Print or Graph the Sin Function
This program focuses on printing or graphing the sin function, given user input.
Date: Nov 10, 2024
Author: Miguel Angel Vargas
*/

#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.14159265358979323846;

double degrees2Radians(int degrees);
// assumes the variable degrees has already been assigned a value from 0 to 360
// returns the angle in radian form

void drawline(char character, int numRepetitions);
// assumes a character has already been assigned by the user and the number of repetitions indicated
// prints the character numRepetitions times, followed by a newline

void doPrinting(int maxAngle, int angleIncrement, char charPrint, int numChars);
// assumes all variables have been inputted by the user
// prints the values of the sin function, starting from 0 until the maxAngle indicated by the user, by increments of angleIncrements
// everytime an angle value is divisible by 90, it calls the drawline function

void doGraphing(int maxAngle, int angleIncrement);
// assumes maxAngle and angleIncrement have been given by the user
// prints vertically the graph of sin, from the initial value of 0 to the maxAngle indicated

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint); // show decimals even if not needed
    cout.precision(5); // show 5 digits to right of decimal

    int degrees, angleIncrement;
    char graphDecision;
    cout << "Perform calculations from angle=0 to what value (in degrees)? ";
    cin >> degrees;
    cout << "How often should the angle be incremented? ";
    cin >> angleIncrement;
    cout << "Graph it? ";
    cin >> graphDecision;

    switch(graphDecision){
        case 'y':
        case 'Y':
            doGraphing(degrees, angleIncrement);
            break;

        case 'n':
        case 'N':
            char lineCharacter;
            int numCharacters;
            cout << "Make the line from what character? ";
            cin >> lineCharacter;
            cout << "How many characters form a line? ";
            cin >> numCharacters;

            doPrinting(degrees, angleIncrement, lineCharacter, numCharacters);
            break;
    }

    return 0;
        
}

double degrees2Radians(int degrees){
    double radians;
    radians = degrees * (pi/180.0);
    return radians;
}

void drawline(char character, int numRepetitions){
    // This function will be called from the doPrinting Function
    for (int i = 0 ; i < numRepetitions ; i++){
        cout << character;
    }
    cout << endl; // To print a newline after drawing the line   
}

void doPrinting(int maxAngle, int angleIncrement, char charPrint, int numChars){
    for(int i = 0; i <= maxAngle; i += angleIncrement){
        double radians;
        radians = degrees2Radians(i);
        cout << "sin(" << i << ") = " << sin(radians) << endl;
        if ( (i % 90) == 0){
            drawline(charPrint, numChars);
        }
    }  
}

void doGraphing(int maxAngle, int angleIncrement){
    for (int i = 0 ; i <= maxAngle; i += angleIncrement){
        char linepoint = 'X', space =' ';
        double numSpaces, radians;
        radians = degrees2Radians(i); // the sin function in the next line takes radians. IMPORTANT STEP
        numSpaces = sin(radians) * 20 + 20;  // proper number of spaces before the 'X'

        int spaces = static_cast<int>(numSpaces); // Round numSpaces to an integer since the loop index must be an integer
        
        for (int k = 0; k < spaces; k++){
            // loop to print spaces before the 'X' 
            cout << space;
        }
        cout << linepoint << endl;
    }
}
