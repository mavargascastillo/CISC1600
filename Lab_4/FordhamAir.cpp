#include <iostream>
using namespace std;


int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    char destination, weekEndOrWeekDayLetter;
    int flightTime, numTickets;
    double ticketPrice, totalCost, userPayment, change;
    bool isDayFlight, isWeekend;

    cout << "Welcome to Fordham Airlines!\n";
    cout << "What is your destination? ([C]hicago, [M]iami, [P]ortland) ";
    cin >> destination;
    cout << "What time will you travel? (Enter time between 0-2359) ";
    cin >> flightTime;

    if (flightTime >= 500 && flightTime <= 1900) {
        // Determine the time of the flight based on input
        isDayFlight = true;
    } else {
        isDayFlight = false;
    }

    cout << "What type of day are you traveling? (week[E]nd or week[D]ay) ";
    cin >> weekEndOrWeekDayLetter;
    switch (weekEndOrWeekDayLetter){
        // Determine if it is the weekend based on the character input
        case 'E':
            isWeekend = true;
            break;
        case 'D':
            isWeekend = false;
            break;
    }

    if (destination == 'M') {
        if (isDayFlight) {
            ticketPrice = isWeekend ? 180 : 150; // ternary operator: 1st value if boolean is true, 2nd if not
        } else {
            ticketPrice = isWeekend ? 120 : 100;
        }
    } else if (destination == 'C') {
        if (isDayFlight) {
            ticketPrice = isWeekend ? 90 : 75;
        } else {
            ticketPrice = isWeekend ? 60 : 50;
        }
    } else if (destination == 'P') {
        if (isDayFlight) {
            ticketPrice = isWeekend ? 360 : 300;
        } else {
            ticketPrice = isWeekend ? 240 : 200;
        }
    } else {
        cerr << "Invalid destination!" << endl;
        // Handle invalid destination if necessary
    }

    cout << "Each ticket will cost: $" << ticketPrice << endl;
    cout << "How many tickets do you want? ";
    cin >> numTickets;
    totalCost = numTickets * ticketPrice;
    cout << "You owe: $" << totalCost << endl;

    cout << "Amount paid? ";
    cin >> userPayment;

    if (userPayment < totalCost){
        cout << "That is too little! No tickets ordered.";
    } else {
        change = userPayment - totalCost;
        cout << "You will get in change: $" << change << "\n"
            << "Your tickets have been ordered!";
    }

    return 0;
}