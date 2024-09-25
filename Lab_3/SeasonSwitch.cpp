#include <iostream>
#include <string>

using namespace std;

int main() {
    int month;
    string season;

    // Prompt user for input
    cout << "Enter a month number: ";
    cin >> month;

    // Check for valid input
    if (month < 1 || month > 12) {
        cout << "Invalid month. Enter number 1-12" << endl;
    } else {
        switch (month) {
            // Determine the season based on the month
            
            case 3:
            case 4:
            case 5:
                season = "Spring";
                break;
            case 6:
            case 7:
            case 8:
                season = "Summer";
                break;
            case 9:
            case 10:
            case 11:
                season = "Fall";
                break;
            case 12:
            case 1:
            case 2:
                season = "Winter";
                break;
        }

    // Output the result
    cout << "It is " << season << endl;
    }
    
    return 0;
}
