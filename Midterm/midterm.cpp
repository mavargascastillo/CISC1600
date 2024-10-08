/*
Miguel Angel Vargas
10/08/2024
This is code for my CISC 1600 midterm exam. This program will perform statistical analysis of student's performance
in an exam, based on user input. 
*/

#include <iostream>
using namespace std;

int main()
{
    int num_students, passing_grades = 0 , failing_grades = 0;

    cout << "Enter the number of students: ";
    cin >> num_students;

    if (num_students < 0)
        cout << "There are no grading statistics then!";
    else
    {
        for (int i = 1; i <= num_students; i++)
        {
            int score_student;
            cout << "Student #" << i << endl
                << "Enter the student's score: ";
            cin >> score_student;

            while (score_student > 5 || score_student < 0)
            {
            cout << "Invalid grade. Enter again: ";
            cin >> score_student;
            }

            switch(score_student)
            {
                case 1:
                case 2:
                    failing_grades++;
                    break;
                case 3:
                case 4:
                case 5:
                    passing_grades++;
                    break;
            }

        }
        //Display the results
        cout << "Grading Statistics:\n";
        cout << "Passing grades: " << passing_grades << endl;
        cout << "Failing grades: " << failing_grades << endl;
        
        if (passing_grades > failing_grades)
            cout << "Your students performed well!";
        else
            cout << "We need to improve quiz scores.";
    }
    return 0;
}