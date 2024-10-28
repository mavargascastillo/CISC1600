/* CISC 1600
Programming assignment #7
This program focuses on function overloading. The user is prompted to indicate if he wants to calculate areas or volumes
of shapes. 
Date: 10/28/2024
Miguel Angel Vargas
*/

#include <iostream>
using namespace std;

const double pi = 3.14159;

double calculateArea(double length, double width);
/* Pre-condition: user must have entered l and w
Returns area of rectangle
*/

double calculateArea(double radius);
/* Pre-condition: user must have entered radius
Returns area of circle 
*/

double calculateArea(double baseOne, double baseTwo, double height);
/* Pre-condition: user must have entered the two bases and the height
Returns area of a trapezoid 
*/

double calculateVolume(double radius);
/* Pre-condition: user must have entered radius
Returns volume of a sphere 
*/

double calculateVolume(double radius, double height);
/* Pre-condition: user must have entered radius and height
Returns volume of a cylinder 
*/

double calculateVolume(double length, double breadth, double height);
/* Pre-condition: user must have entered length, breadth and height
Returns volume of a cuboid 
*/

int main(){
    while (true) {
        
    }
}