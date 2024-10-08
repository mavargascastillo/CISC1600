#include <iostream>
#include <string>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    string first_name;
    double coffeePrice = 2.50 , bagelPrice = 1.75 , donutPrice = 1.00;
    int coffees, bagels, donuts;
    double totalNoTax, totalTax;
    double payment, change;

    cout << "Welcome to our Coffee Shop!\n"
        << "What is your first name? ";
    cin >> first_name;
    cout << "Hello, " << first_name << "!\n";
    cout << "How many coffees do you want? ";
    cin >> coffees;
    cout << "How many bagels do you want? ";
    cin >> bagels;
    cout << "How many donuts do you want? ";
    cin >> donuts;
    totalNoTax = (coffeePrice * coffees) + (bagelPrice * bagels) + (donutPrice * donuts);
    totalTax = totalNoTax * (1 + (8.875/100));
    cout << "Your total is: $" << totalTax << "\n"
        << "How much will you pay? $";
    cin >> payment;
    change = payment - totalTax;
    cout << "Receipt for customer: " << first_name << "\n"
        << "Coffees: " << coffees << "\n"
        << "Bagels: " << bagels << "\n"
        << "Donuts: " << donuts << "\n"
        << "Total is: $" << totalTax << "\n" 
        << "Your change is: $" << change;
    
    
    return 0;
}
