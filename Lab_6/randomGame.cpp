/* 
CISC 1600 
Programming assignment #6 - Random Game
This game comes up with a number from 1-10 and the user has to guess it in three tries. 
Date: Oct 16, 2024
Author: Miguel Angel Vargas
*/

#include <iostream>
#include <cstdlib>

using namespace std;

bool runGame(int randomNumber);

int main() {
    srand(10); // Seed the random number generator
    char ans;
    int wins = 0, losses = 0;
    
    do {
        int randomNumber = rand() % 10 + 1; // Generate a number between 1 and 10. I have to do it inside the loop so the
                                            // random number is not always the same
        cout << "Can you guess the number I generated between 1 and 10 within three tries?" << endl;
        bool status = runGame(randomNumber);
        
        if (status){ 
            cout << "You win!" << endl;
            wins += 1;
        } else {
            losses += 1;
        }
            
        cout << "Would you like to play again? (Y/N): ";
        
        cin >> ans;
        // while loop for input validation
        while (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N')) { // needs to be in one () because if not it always evaluates to TRUE
            cout << "Please enter a valid response. (Y/N) : ";
            cin >> ans;
        }
        // repeat the game until the user wants to exit
    } while (ans == 'y' || ans == 'Y');
    
    cout << "Number of wins: " << wins << endl
        << "Number of losses: " << losses << endl
        << "Thanks for playing!";
    
    
    return 0;
}

bool runGame(int randomNumber) {
    for (int i = 3; i > 0; i--) {
        int numberGuessed;
        cout << "Guess a number between 1 and 10: ";
        cin >> numberGuessed;

        if (numberGuessed == randomNumber) {
            return true; // Correct guess
        } else if (numberGuessed > randomNumber) {
            cout << "Go lower." << endl;
        } else if (numberGuessed < randomNumber) {
            cout << "Go higher." << endl;
        }
        
        cout << "You have " << i - 1 << " guess(es) left." << endl;
    }
    return false; // Failed to guess correctly
}