#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class InformationManagementSystem
{
private:
    // Map to store information based on categories
    map<string, vector<string>> informationDatabase;

public:
    // Add information to a category
    void addInformation(string category, string info)
    {
        informationDatabase[category].push_back(info);
        cout << "Information added to " << category << " category.\n";
    }

    // Display information of a particular category
    void displayInformation(string category)
    {
        if (informationDatabase.find(category) != informationDatabase.end())
        {
            cout << "Information in " << category << " category:\n";
            for (auto &info : informationDatabase[category])
            {
                cout << "- " << info << "\n";
            }
        }
        else
        {
            cout << "No information found for the category " << category << ".\n";
        }
    }

    // Recommend information based on a query (simple matching logic)
    void recommendInformation(string query)
    {
        bool found = false;
        cout << "Recommendations based on your query \"" << query << "\":\n";
        for (auto &category : informationDatabase)
        {
            for (auto &info : category.second)
            {
                if (info.find(query) != string::npos)
                {
                    cout << "- " << info << " (Category: " << category.first << ")\n";
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "No recommendations found based on your query.\n";
        }
    }

    // Show all available categories
    void showCategories()
    {
        cout << "Available categories:\n";
        for (auto &category : informationDatabase)
        {
            cout << "- " << category.first << "\n";
        }
    }
};

int main()
{
    InformationManagementSystem ims;
    int choice;
    string category, info, query;

    while (true)
    {
        cout << "\nInformation Management Expert System\n";
        cout << "1. Add Information\n";
        cout << "2. Display Information\n";
        cout << "3. Recommend Information\n";
        cout << "4. Show All Categories\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore newline character left by cin

        switch (choice)
        {
        case 1:
            cout << "Enter category: ";
            getline(cin, category);
            cout << "Enter information to add: ";
            getline(cin, info);
            ims.addInformation(category, info);
            break;
        case 2:
            cout << "Enter category to display information: ";
            getline(cin, category);
            ims.displayInformation(category);
            break;
        case 3:
            cout << "Enter query for recommendations: ";
            getline(cin, query);
            ims.recommendInformation(query);
            break;
        case 4:
            ims.showCategories();
            break;
        case 5:
            cout << "Exiting the system...\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}
