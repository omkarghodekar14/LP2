#include <iostream>
#include <string>
#include <iomanip> // For setw
using namespace std;

class EmployeePerformance
{
private:
    string name;
    string department;
    int workQuality;
    int punctuality;
    int teamwork;
    int communicationSkills;
    int problemSolving;

public:
    // Constructor
    EmployeePerformance() : workQuality(0), punctuality(0), teamwork(0), communicationSkills(0), problemSolving(0) {}

    // Function to input employee details and ratings
    void inputDetails()
    {
        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "\nEnter the ratings for the following categories (1 to 10):\n";

        cout << "Work Quality: ";
        cin >> workQuality;

        cout << "Punctuality: ";
        cin >> punctuality;

        cout << "Teamwork: ";
        cin >> teamwork;

        cout << "Communication Skills: ";
        cin >> communicationSkills;

        cout << "Problem Solving: ";
        cin >> problemSolving;
    }

    // Function to evaluate the performance based on ratings
    void evaluatePerformance()
    {
        int totalScore = workQuality + punctuality + teamwork + communicationSkills + problemSolving;
        double averageScore = totalScore / 5.0;

        cout << "\n"
             << string(50, '=') << "\n";
        cout << "Performance Evaluation Report\n";
        cout << string(50, '=') << "\n";
        cout << left << setw(20) << "Employee Name" << ": " << name << endl;
        cout << left << setw(20) << "Department" << ": " << department << endl;

        // Display ratings in tabular format
        cout << "\n"
             << left
             << setw(25) << "Criteria"
             << setw(10) << "Rating" << endl;
        cout << string(35, '-') << endl;
        cout << setw(25) << "Work Quality" << setw(10) << workQuality << endl;
        cout << setw(25) << "Punctuality" << setw(10) << punctuality << endl;
        cout << setw(25) << "Teamwork" << setw(10) << teamwork << endl;
        cout << setw(25) << "Communication Skills" << setw(10) << communicationSkills << endl;
        cout << setw(25) << "Problem Solving" << setw(10) << problemSolving << endl;

        cout << string(35, '-') << endl;
        cout << setw(25) << "Average Score" << setw(10) << fixed << setprecision(2) << averageScore << endl;

        cout << "\nOverall Performance: ";
        if (averageScore >= 9)
        {
            cout << "Excellent\n";
        }
        else if (averageScore >= 7)
        {
            cout << "Best\n";
        }
        else if (averageScore >= 5)
        {
            cout << "Average\n";
        }
        else
        {
            cout << "Needs Improvement\n";
        }
        cout << string(50, '=') << "\n";
    }
};

int main()
{
    EmployeePerformance employee;

    employee.inputDetails();
    employee.evaluatePerformance();

    return 0;
}