#include <iostream>
using namespace std;


int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    char destination, weekEndOrWeekDayLetter;
    int flightTime, ticketPrice, numTickets;
    double totalCost;
    bool isDayFlight, isWeekend;

    cout << "Welcome to Fordham Airlines!";
    cout << "What is your destination? ([C]hicago, [M]iami, [P]ortland) ";
    cin >> destination;
    cout << "What time will you travel? (Enter time between 0-2359)";
    cin >> flightTime;

    if (flightime >= 500 && flightime <= 1900) {
        // Determine the time of the flight based on input
        isDayFlight = true;
    } else {
        isDayFlight = false;
    }

    cout << "What type of day are you travelling? (week[E]nd or week[D]ay) "
    cin >> weekEndOrWeekDayLetter
    switch (weekEndOrWeekDayLetter){
        // Determine if it is the weekend based on the character input
        case 'E':
            isWeekend = true;
            break;
        case 'D':
            isWeekend = false;
            break;
    }

    // Capture different possibilities:
    // Miami
    if (destination == 'M' && isDayFlight && isWeekend){
        ticketPrice = 180;
    } else if (destination == 'M' && isDayFlight && !isWeekend){
        ticketPrice = 150;
    } else if (destination == 'M' && !isDayFlight && isWeekend){
        ticketPrice = 120;
    } else if (destination == 'M' && !isDayFlight && !isWeekend){
        ticketPrice = 100;
    }
    // Chicago
    else if (destination == 'C' && isDayFlight && isWeekend){
        ticketPrice = 90;
    } else if (destination == 'C' && isDayFlight && !isWeekend){
        ticketPrice = 75;
    } else if (destination == 'C' && !isDayFlight && isWeekend){
        ticketPrice = 60;
    } else if (destination == 'C' && !isDayFlight && !isWeekend){
        ticketPrice = 50;
    }
    // Portland
    else if (destination == 'P' && isDayFlight && isWeekend){
        ticketPrice = 360;
    } else if (destination == 'P' && isDayFlight && !isWeekend){
        ticketPrice = 300;
    } else if (destination == 'P' && !isDayFlight && isWeekend){
        ticketPrice = 240;
    } else if (destination == 'P' && !isDayFlight && !isWeekend){
        ticketPrice = 200;
    }
}