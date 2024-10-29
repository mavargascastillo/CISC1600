/* 
CISC 1600
Programming assignment #7 - Areas and Volume
This program focuses on function overloading. The user is prompted to indicate if he wants to calculate areas or volumes
of shapes. 
Date: Oct 28, 2024
Author: Miguel Angel Vargas
*/

#include <iostream>
#include <cmath> // to handle squaring the radius
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

double calculateVolume(double height, double breadth, double width);
/* Pre-condition: user must have entered length, breadth and height
Returns volume of a cuboid 
*/

double areaFunction(char shape);
/* Pre-condition: user must have desired shape to calculate area
Returns area of selected shape
*/

double volumeFunction(char shape);
/* Pre-condition: user must have desired shape to calculate volume
Returns volume of selected shape
*/

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    char ans;
    int numberAreas = 0, numberVolumes = 0;
    double totalArea = 0, totalVolume = 0;

    while (true) {
        cout << "Calculate (a)rea or (v)olume? (q to quit): ";
        cin >> ans;

        char shape;
        double area, volume;
        if (ans == 'a' || ans == 'A'){
            cout << "Which shape: (r)ectangle, (c)ircle, or (t)rapezoid?: ";
            cin >> shape;
            area = areaFunction(shape);
            cout << "Area: " << area << endl;
            totalArea += area;
            numberAreas += 1;
        } else if (ans == 'v' || ans == 'V'){
            cout << "Which shape: (s)phere, (c)ylinder, or c(u)boid?: ";
            cin >> shape;
            volume = volumeFunction(shape);
            cout << "Volume: " << volume << endl;
            totalVolume += volume;
            numberVolumes += 1;
        } else if (ans == 'q' || ans == 'Q')
            break;
        else
            cout << "Enter your choice again." << endl;
        
    }

    cout << "Number of calculated areas: " << numberAreas << endl;
    if (numberAreas > 0)
        cout << "Average of areas: " << totalArea/numberAreas << endl;
        
    cout << "Number of calculated volumes: " << numberVolumes << endl;
    if (numberVolumes > 0)
        cout << "Average of volumes: " << totalVolume/numberVolumes << endl;

    return 0;
}

double calculateArea(double length, double width){
    double rectangleArea;
    rectangleArea = length * width;
    return rectangleArea;
}

double calculateArea(double radius){
    double circleArea;
    circleArea = pi * pow(radius, 2);
    return circleArea;
}

double calculateArea(double baseOne, double baseTwo, double height){
    double trapezoidArea;
    trapezoidArea = ((baseOne + baseTwo)/2) * height; // ask why (1/2) * (baseOne + baseTwo) gives problems
    return trapezoidArea;
}

double areaFunction(char shape){
    if (shape == 'r' || shape == 'R'){
        double length, width, area;
        cout << "Enter the length and width: ";
        cin >> length >> width;
        area = calculateArea(length, width);
        return area;
    } else if (shape == 'c' || shape == 'C'){
        double radius, area;
        cout << "Enter the radius: ";
        cin >> radius;
        area = calculateArea(radius);
        return area;
    } else if (shape == 't' || shape == 'T'){
        double baseOne, baseTwo, height, area;
        cout << "Enter base 1, base 2, and the height: ";
        cin >> baseOne >> baseTwo >> height;
        area = calculateArea(baseOne, baseTwo, height);
        return area;
    }
}

double calculateVolume(double radius){
    double sphereVolume;
    sphereVolume = (4*pi/3) * pow(radius, 3);
    return sphereVolume;
}

double calculateVolume(double radius, double height){
    double cylinderVolume;
    cylinderVolume = pi * pow(radius, 2) * height;
    return cylinderVolume;
}

double calculateVolume(double height, double breadth, double width){
    double cuboidVolume;
    cuboidVolume = width * breadth * height;
    return cuboidVolume;
}

double volumeFunction(char shape){
    if (shape == 's' || shape == 'S'){
        double radius, volume;
        cout << "Enter the radius: ";
        cin >> radius;
        volume = calculateVolume(radius);
        return volume;
    } else if (shape == 'c' || shape == 'C'){
        double radius, height, volume;
        cout << "Enter the radius and height: ";
        cin >> radius >> height;
        volume = calculateVolume(radius, height);
        return volume;
    } else if (shape == 'u' || shape == 'U'){
        double height, breadth, width, volume;
        cout << "Enter the height, breadth, and width: ";
        cin >> height >> breadth >> width;
        volume = calculateVolume(height, breadth, width);
        return volume;
    }
}
