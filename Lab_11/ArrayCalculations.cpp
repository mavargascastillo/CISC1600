/* 
CISC 1600
Programming assignment #11:
This program declares an array of some maximum size 50 and implements different functions on it.
Date: Dec 4, 2024
Author: Miguel Angel Vargas
*/

#include <iostream>
#include <limits>
using namespace std;

// Constants
const int MAX_SIZE = 50;

// Functions declarations
void initializeArray(int array[], int& size);
// Precondition: the array has been declared and the maximum size of the array has been defined
// This function initializes the array by filling it with numbers inputted by the user.

void displayArray(const int array[], int size);
// Precondition: the array has been declared and initialized
// This functions displays the contents of the filled array

bool contains(const int array[], int size, int number);
// Precondition: the array has been declared and initialized, and a number to check has been inputted by the user
// This function loops over the contents of the array to see if they match with the number given by the user, and indicates if it does.

int countFrequency(const int array[], int size, int number);
// Precondition: the array has been declared and initialized, and a number to check the frequency of has been inputted by the user
// This functions loops over the contents of the array and counts the number of times the integer given by the user is contained in the array

int findMinimum(const int array[], int size);
// Precondition: the array has been declared and initialized
// Finds the minimum value of the array

int findMaximum(const int array[], int size);
// Precondition: the array has been declared and initialized
// Finds the maximum value of the array

int calculateSum(const int array[], int size);
// Precondition: the array has been declared and initialized
// Returns the sum of all values within the array

double calculateAverage(const int array[], int size);
// Precondition: the array has been declared and initialized
// Returns the average value of all the elements in the array


int main() {
    // Set formatting of output numbers
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    int array[MAX_SIZE];
    int size = 0; // To keep track of the number of elements initialized

    initializeArray(array, size);
    displayArray(array, size);

    // Array statistics
    // I did not know that I don't need to assign the result of a function to a variable first! I can use the returned value 
    // anywhere a value of that type is valid!!!
    cout << "The minimum value in the array is " << findMinimum(array, size) << endl;
    cout << "The maximum value in the array is " << findMaximum(array, size) << endl;
    cout << "The sum of all the elements in the array is " << calculateSum(array, size) << endl;
    cout << "The average of all the elements in the array is " << calculateAverage(array, size) << endl;

    // Check if a number is in the array
    int isNum;
    cout << "Please enter the value you want to search in the array: ";
    cin >> isNum;
    if (contains(array, size, isNum)) {
        cout << "Find your target " << isNum << endl;
    } else {
        cout << "Could not find " << isNum << endl;
    }

    int numFreq, frequency;
    cout << "Please enter the value you want to know the frequency of: ";
    cin >> numFreq;
    frequency = countFrequency(array, size, numFreq);
    if (frequency >= 0) {
        cout << "The number " << numFreq << " has occurred " << frequency << " time(s) in the array" << endl;
    } else {
        cout << numFreq << " is not in the array.\n";
    }

    return 0;
}

// Function Definitions

void initializeArray(int array[], int& size) {
    cout << "Please enter up to " << MAX_SIZE << " non-negative whole numbers separated by space." << endl
        << "Mark the end of the input list with a negative number:" << endl;
    int value;
    while (size < MAX_SIZE) {
        cin >> value;
        if (value < 0) {
            break; // End input on negative number
        }
        array[size] = value;
        size++;
    }
}

void displayArray(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " "; // space so that numbers are displayed correctly
    }
    cout << endl;
}

bool contains(const int array[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return true;
        }
    }
    return false;
}

int countFrequency(const int array[], int size, int number) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            count++;
        }
    }
    return count;
}

// I have decided to use four functions in order to have each function perform one individual task
int findMinimum(const int array[], int size) {
    int min = numeric_limits<int>::max();
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int findMaximum(const int array[], int size) {
    int max = numeric_limits<int>::min();
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int calculateSum(const int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

double calculateAverage(const int array[], int size) {
    if (size == 0) return 0.0; // Avoid division by zero
    return static_cast<double>(calculateSum(array, size)) / size;
    //use the calculateSum function for this part. We use static_cast to make sure the return value is a double
}