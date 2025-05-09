#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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
    EmployeePerformance() : workQuality(0), punctuality(0), teamwork(0), communicationSkills(0), problemSolving(0) {}

    void inputDetails()
    {
        cin.ignore(); // Clear input buffer
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

    void evaluatePerformance() const
    {
        int totalScore = workQuality + punctuality + teamwork + communicationSkills + problemSolving;
        double averageScore = totalScore / 5.0;

        cout << "\n"
             << string(50, '=') << "\n";
        cout << "Performance Evaluation Report\n";
        cout << string(50, '=') << "\n";
        cout << left << setw(20) << "Employee Name" << ": " << name << endl;
        cout << left << setw(20) << "Department" << ": " << department << endl;

        cout << "\n"
             << left << setw(25) << "Criteria" << setw(10) << "Rating" << endl;
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
            cout << "Excellent\n";
        else if (averageScore >= 7)
            cout << "Best\n";
        else if (averageScore >= 5)
            cout << "Average\n";
        else
            cout << "Needs Improvement\n";
        cout << string(50, '=') << "\n";
    }
};

int main()
{
    vector<EmployeePerformance> employees;
    int choice;

    do
    {
        cout << "\n=== Employee Performance System ===\n";
        cout << "1. Add New Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            EmployeePerformance emp;
            emp.inputDetails();
            employees.push_back(emp);
            break;
        }
        case 2:
        {
            if (employees.empty())
            {
                cout << "No employee records found.\n";
            }
            else
            {
                for (size_t i = 0; i < employees.size(); ++i)
                {
                    cout << "\n--- Employee #" << i + 1 << " ---";
                    employees[i].evaluatePerformance();
                }
            }
            break;
        }
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
