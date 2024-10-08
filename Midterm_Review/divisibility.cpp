#include <iostream>
using namespace std;

int main()
{
    int num1, num2;

    cout << "Welcome! Please insert the first integer: ";
    cin >> num1; 
    cout << "Please insert the second integer: ";
    cin >> num2;

    for (int i=1; i <= 10000; i++)
    {
        if (i % num1 == 0) && (i % num2 == 0)
        {
            cout << "The number " << i << " is divisible by " << num1 << " and " << num2 << endl;
        }
    }

    return 0;
}