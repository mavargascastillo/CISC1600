#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Celsius\tFahrenheit" << endl;
    for (int celsius = 0; celsius <= 20; celsius++)
    {
        double fahrenheit;
        fahrenheit = 9/5 *celsius + 32;
        cout << celsius << '\t' << fahrenheit << endl;

    }
    return 0;
}