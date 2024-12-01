/* 
CISC 1600
Programming assignment #10:
This program counts the number of capital letters in a sentence. The user chooses if it is from a file or if he inputs it.
Date: Dec 1, 2024
Author: Miguel Angel Vargas
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype> // for isupper()
using namespace std;

void openFile(ifstream& instream);
//Precondition: instream is not currently associated with a file.
//Asks the user for a file name, then attempts to open the file on instream with the provided name.
//Exits the program if the file does not exist


int countCapitals(string sentence);
// Precondition: the sentence has been inputted
// Takes input until it reaches a newline character. For each capital letter found in the string, it adds one to the total number of cappitals. 
// Returns the total number of caps


int main(){
    char input;
    do {
        cout << "Are you using a file for input? (Y/N): ";
        cin >> input;

        if (!(input == 'y' || input == 'Y' || input == 'n' || input == 'N')){
            // this if needs to be inside the do because of the way input must be handled
            cout << "Invalid input - try again." << endl;
        } 

    } while (!(input == 'y' || input == 'Y' || input == 'n' || input == 'N'));

    string sentence;
    // This if statement's purpose is to store the sentence in a string variable
    if (input == 'y' || input == 'Y'){
        ifstream filename; 
        openFile(filename);
        getline(filename, sentence);
        filename.close();
    } else {
        cout << "Enter your string. Press Enter/Return to end: ";
        cin.ignore(); 
        // Ignore the newline character left from previous input. THIS IS THE ANSWER TO THE QUESTION IN THE ASSIGNMENT INSTRUCTIONS
        getline(cin, sentence); 
        // Read the entire sentence, including spaces. We use getline() because cin would only read until the first whitespace
    }

    int numCaps;
    numCaps = countCapitals(sentence);

    cout << "The number of capitals in your string is: " << numCaps << endl;
    
    return 0;
}


void openFile(ifstream& inStream){
    // There is no need to declare the inStream here because it is called by reference
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    inStream.open(filename);
    if (inStream.fail()){
        cout << "Error! File not found. Exiting..." << endl;
        exit(1);
    }

}

int countCapitals(string sentence){
    int numCaps = 0;

    // Loop to go over each character in the sentence:
    for (char c : sentence){
        if (isupper(c)) { // Checks if the caracter is a capital letter
            numCaps ++;
        }
    }
    return numCaps;
}

