/* 
CISC 1600
Programming assignment #9 - Print result of operations calculated with numbers from a .txt file

Date: Nov 19, 2024
Author: Miguel Angel Vargas
*/

#include <iostream>
#include <fstream>
#include <string>
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


    return 0;
}

void openInputFile(ifstream& inStream){
    cout << "Enter a file name: "
    string filename;
    cin >> filename;
    inStream.open(filename);
    if (inStream.fail()){
        cout << "File not found! Exiting program." << endl;
    }

}

int multAndSum(ifstream& inStream){


}