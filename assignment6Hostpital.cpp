#include <iostream>
#include <string>
using namespace std;

class ExpertSystem
{
public:
    // Function to diagnose the symptoms
    void diagnose()
    {
        string fever, cough, fatigue, headache, vomiting;

        // Ask user for symptoms
        cout << "Please answer the following questions with 'yes' or 'no'.\n";
        cout << "Do you have fever? (yes/no): ";
        cin >> fever;
        cout << "Do you have cough? (yes/no): ";
        cin >> cough;
        cout << "Do you have fatigue? (yes/no): ";
        cin >> fatigue;
        cout << "Do you have headache? (yes/no): ";
        cin >> headache;
        cout << "Do you have vomiting? (yes/no): ";
        cin >> vomiting;

        // Diagnosis based on the symptoms
        cout << "\nDiagnosis:\n";
        if (fever == "yes" && cough == "yes" && fatigue == "yes")
        {
            cout << "You might have the flu.\n";
            provideTreatment("Rest, fluids, and over-the-counter medication.");
            categorizeSeverity("Moderate");
        }
        else if (headache == "yes" && vomiting == "yes")
        {
            cout << "These symptoms could indicate a migraine.\n";
            provideTreatment("Consult a doctor for proper diagnosis and medication.");
            categorizeSeverity("Moderate");
        }
        else if (fever == "yes" && vomiting == "yes")
        {
            cout << "These symptoms could indicate food poisoning.\n";
            provideTreatment("Stay hydrated and consult a healthcare provider.");
            categorizeSeverity("Mild");
        }
        else if (fever == "yes")
        {
            cout << "You may have a viral infection. Monitor your symptoms.\n";
            provideTreatment("Rest and fluids.");
            categorizeSeverity("Mild");
        }
        else
        {
            cout << "Symptoms do not match any common illnesses. Please consult a healthcare professional for a detailed diagnosis.\n";
        }
    }

    // Function to provide treatment recommendations
    void provideTreatment(string treatment)
    {
        cout << "Recommended Treatment: " << treatment << endl;
    }

    // Function to categorize the severity of the condition
    void categorizeSeverity(string severity)
    {
        cout << "Severity: " << severity << endl;
    }
};

int main()
{
    ExpertSystem system;

    int choice;
    cout << "Welcome to the Hospital and Medical Expert System\n";
    do
    {
        cout << "\n1. Diagnose Symptoms\n";
        cout << "2. Exit\n";
        cout << "Please choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.diagnose();
            break;
        case 2:
            cout << "Exiting the system. Take care!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);

    return 0;
}
