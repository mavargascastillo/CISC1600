/* 
CISC 1600
Programming assignment #9 - Print result of operations calculated with numbers from a .txt file
Date: Nov 19, 2024
Author: Miguel Angel Vargas
*/

#include <iostream>
#include <cstdlib> // for exit()
#include <fstream> // for I/O
#include <string>
#include <iomanip> // for formatting manipulators
using namespace std;

void openInputFile(ifstream& inStream);
//Precondition: instream is not currently associated with a file.
//Asks the user for a file name, then attempts to open the file on instream with the provided name.
//Exits the program if the file does not exist

int multAndSum(ifstream& inStream);
//Precondition: instream is associated with a file.
//For each line of numbers in your file, it reads the three numbers in, multiplies them by each other, i.e. 1*2*3 = 6.
//The resulting number is printed out, then it is added to a running total, which is returned after all lines have been processed

int main(){
    ifstream inputFile; // in main we do need to declare the ifstream
    openInputFile(inputFile);
    
    double total = multAndSum(inputFile);
    cout << "Final result: " << setw(8) << right << total << endl; // Using manipulators to right-allign formatting. 8 because it is one less

    return 0;
}

void openInputFile(ifstream& inStream){
    // There is no need to declare the inStream here because it is called by reference
    string filename;
    cout << "Enter a file name: ";
    cin >> filename;
    inStream.open(filename);
    if (inStream.fail()){
        cout << "File not found! Exiting program." << endl;
        exit(1);
    }

}

int multAndSum(ifstream& inStream){
    double total = 0.0; // Running total
    double num1, num2, num3; 
    

    while (inStream >> num1 >> num2 >> num3){ // Read three numbers sequentially
        double product = num1 * num2 * num3; 
        cout << "Current Row: " << setw(9) << right << product << endl; // 9 after trial and error
        total += product;
    }

    return total;
}