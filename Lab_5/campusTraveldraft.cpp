#include <iostream>
using namespace std;

int main() {
    int distance = 14; // total distance to school
    int turn = 0;

    cout << "You are " << distance << " mile(s) from campus!" << endl;

    while (turn < 4) {
        cout << "How do you wish to travel? (1 bus, 2 subway, 3 jetpack) ";

        int choice;
        bool validInput = false;

        while(!validInput){

            cin >> choice;

            switch (choice) {
                case 1:
                    distance -= 2;
                    validInput = true;
                    break;
                case 2:
                    distance -= 5;
                    validInput = true;
                    break;
                case 3:
                    distance -= 10;
                    validInput = true;
                    break;
                default:
                    cout << "Invalid choice, try again! ";
            }
        }

        if (distance < 0) {
            cout << "You have over-shot your target!" << endl;
            cout << "You lose!" << endl;
            return 0; // End the game if the user reaches the school
        }
        cout << "You are " << distance << " mile(s) from campus.!" << endl;

        if (distance == 0){
            cout << "You won!";
            return 0;
        }
        turn++; // Increment the turn count
    }

    if (distance > 0) {
        cout << "You haven't reached your target!" << endl;
        cout << "You lose!" << endl;
    } else if (distance == 0) {
        cout << "You won!";
    }

    return 0;
}