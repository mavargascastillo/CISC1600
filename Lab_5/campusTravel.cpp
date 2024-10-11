#include <iostream>
using namespace std;

int main(){

    int distance_from_campus = 14;

    cout << "You are " << distance_from_campus << " mile(s) from campus!" << endl;

    for (int i = 0 ; i < 4 ; i++)
    {
        int travel_method;
        bool valid_input = false;
        cout << "How do you wish to travel? (1 bus, 2 subway, 3 jetpack) ";

        // While loop to check for invalid input
        while (!valid_input)
        {
            cin >> travel_method;
            /* if string, character, ask for input again
            if (!(cin >> travel_method)){
                cout << "Invalid choice, try again! ";
                break;
                
            } */
            
            switch (travel_method){
                case 1:
                    distance_from_campus -= 2;
                    valid_input = true;
                    break;
                case 2:
                    distance_from_campus -= 5;
                    valid_input = true;
                    break;
                case 3:
                    distance_from_campus -= 10;
                    valid_input = true;
                    break;
                default:
                    cout << "Invalid choice, try again! ";
                    break;
            }
        }

        // Check if user is past the distance and get out of the for loop
        if (distance_from_campus < 0)
            break;

        cout << "You are " << distance_from_campus << " mile(s) from campus!" << endl;
    }
    
    if (distance_from_campus == 0) {
        cout << "You have won!" << endl;
    } else if (distance_from_campus < 0) {
        cout << "You have over-shot your target!" << endl;
        cout << "You lose!" << endl;
    } else if (distance_from_campus > 0) {
        cout << "You haven't reached your target!" << endl;
        cout << "You lose!" << endl;
    }

    return 0;
}