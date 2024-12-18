#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int miles_from_campus = 14;
    bool flag = true;

    cout << "You are " << miles_from_campus << " mile(s) from campus!" << endl;

    for (int i = 1; i <= 4 && flag; i++)
    {
        int choice_of_transport;
        cout << "How do you wish to travel? (1 bus, 2 subway, 3 jetpack) ";
        
        while (true) {
            cin >> choice_of_transport;

            // Check for invalid input
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid choice, try again! ";
            } else if (choice_of_transport > 3 || choice_of_transport < 1) {
                cout << "Invalid choice, try again! ";
            } else {
                break; // Valid input, exit the loop
            }

        }
        
        // Assign distance to be deducted
        int distance_to_deduct;
        switch(choice_of_transport){
            case 1:
                distance_to_deduct = 2;
                break;
            case 2:
                distance_to_deduct = 5;
                break;
            case 3:
                distance_to_deduct = 10;
                break;
        }
        miles_from_campus -= distance_to_deduct;
        
        if (miles_from_campus < 0){
            cout << "You have over-shot your target!" << endl;
            cout << "You lose!";
            flag = false;
        } 
        
        cout << "You are " << miles_from_campus << " mile(s) from campus!" << endl;

        if (miles_from_campus == 0){
            cout << "You have won!" << endl;
            flag = false; //Stop the while loop if won
        } 
    }
    
    if (miles_from_campus > 0 && flag){ // flag being true ensures that the game has not already ended
        cout << "You haven't reached your target!" << endl;
        cout << "You lose!" << endl;
    }

    return 0;
}