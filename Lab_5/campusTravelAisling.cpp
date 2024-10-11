#include <iostream>
using namespace std;

int main() 

{
    
    int travelMethod, miles = 14;
    bool gameEnd = false;

    cout << "You are 14 mile(s) from campus!\n";

    for (int turns = 0; ((turns < 4) && (!gameEnd)); turns++) 
    {
        cout << "How do you wish to travel? (1 bus, 2 subway, 3 jetpack) ";
        cin >> travelMethod;

        while (!(travelMethod == 1 || travelMethod == 2 || travelMethod == 3)) 
        {
            cout << "Invalid choice, try again! ";
            cin >> travelMethod;
        }

        switch (travelMethod) 
        {
            case 1:
            
                miles -= 2;
                break;
                
            case 2:
            
                miles -= 5;
                break;
                
            case 3:
            
                miles -= 10;
                break;
        }

        if (miles == 0) 
        {
            cout << "You are " << miles << " mile(s) from campus!\n";
            cout << "You have won!\n";
            gameEnd = true;
            break;
        }
        
        if (miles < 0) 
        {
            cout << "You have overshot your target!\n";
            cout << "You lose!\n";
            gameEnd = true;
            break;
        }

        cout << "You are " << miles << " mile(s) from campus!\n";
    }

    if (!gameEnd && miles > 0) 
    {
        cout << "You haven't reached your target!\n";
        cout << "You lose!\n";
    }

    return 0;
}