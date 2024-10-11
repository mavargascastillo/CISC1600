#include <iostream>

using namespace std;

int main ()
{
  int transport = 0;
  int miles = 14;
  int i = 0;

  for (i == 0; i < 4; i++)
    {
      cout << "You are " << miles << " mile(s) from campus!" << endl;
      cout << "How do you wish to travel? (1 bus, 2 subway, 3 jetpack) ";
      cin >> transport;
      switch (transport){

        case 1:
          miles = miles - 2;
          break;

        case 2:
          miles = miles - 5;
          break;

        case 3:
          miles = miles - 10;
          break;

        default:
          cout << "Invalid choice, try again!" << endl;
          i--;

      }
      
      if (miles < 0)
	      break;
      else if (miles == 0)
	      break;
    }

  if (miles == 0)
    {
      cout << "You are " << miles << " mile(s) from campus!" << endl;
      cout << "You have won!" << endl;
    }
  else if (miles < 0)
    {
      cout << "You have over-shot your target!" << endl;
      cout << "You lose!" << endl;
    }
  else if (miles > 0)
    {
      cout << "You are " << miles << " mile(s) from campus!" << endl;
      cout << "You haven't reached your target!" << endl;
      cout << "You lose!" << endl;
    }


  return 0;
}