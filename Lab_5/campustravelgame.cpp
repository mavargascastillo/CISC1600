#include <iostream>
using namespace std;

int main()
{
    int miles_from_campus = 14;

    cout << "You are " << miles_from_campus << "mile(s) from campus!" << endl;

    for (int i = 1; i <= 4; i++)
    {
        while (miles_from_campus > 0)
        {
            int choice_of_transport;
            cout << "How do you wish to travel? (1 bus, 2 subway, 3 jetpack) " << endl;
            cin >> choice_of_transport;
            
            // Check for invalid input
            while (choice_of_transport > 3 || choice_of_transport < 1)
            {
                cout << "Invalid choice, try again!" << endl;
                cin >> choice_of_transport;
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
            cout << "You are " << miles_from_campus << "mile(s) from campus!" << endl;
        }
    }

    if (miles_from_campus == 0)
        cout << "You have won!" << endl;
    else if (miles_from_campus > 0) {
        cout << "You haven't reached your target!" << endl;
        cout << "You lose!";
    }
    else {
        cout << "You have over-shot your target!" << endl;
        cout << "You lose!";
    }

    return 0;
}