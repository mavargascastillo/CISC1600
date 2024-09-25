#include <iostream>
#include <string>

using namespace std;

int main() {
    int month;

    // Prompt user for input
    cout << "Enter a month number: ";
    cin >> month;

    // Check for valid input
    if (month < 1 || month > 12) {
        cout << "Invalid month. Enter number 1-12" << endl;
    } else {
        // Determine the season based on the month
        string season;
        if (month >= 3 && month <= 5) {
            season = "Spring";
        } else if (month >= 6 && month <= 8) {
            season = "Summer";
        } else if (month >= 9 && month <= 11) {
            season = "Fall";
        } else {
            season = "Winter";
        }

    // Output the result
    cout << "It is " << season << endl;
    
    }
    return 0;
}
