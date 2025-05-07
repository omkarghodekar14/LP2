#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Convert string to lowercase
string toLower(string input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

// Check if keyword exists in user input
bool containsKeyword(string input, string keyword)
{
    return toLower(input).find(toLower(keyword)) != string::npos;
}

int main()
{
    string userInput;

    cout << "Welcome to ShopBot! How can I assist you today?\n";
    cout << "Type 'exit' to end the chat.\n\n";

    while (true)
    {
        cout << "You: ";
        getline(cin, userInput);

        if (toLower(userInput) == "exit")
        {
            cout << "ShopBot: Thank you for visiting. Have a great day!\n";
            break;
        }

        if (containsKeyword(userInput, "price") || containsKeyword(userInput, "cost"))
        {
            cout << "ShopBot: Our prices vary by product. Could you tell me which item you're interested in?\n";
        }
        else if (containsKeyword(userInput, "refund") || containsKeyword(userInput, "return"))
        {
            cout << "ShopBot: You can return any item within 30 days for a full refund.\n";
        }
        else if (containsKeyword(userInput, "order") || containsKeyword(userInput, "track"))
        {
            cout << "ShopBot: You can track your order using the tracking ID sent to your email.\n";
        }
        else if (containsKeyword(userInput, "hello") || containsKeyword(userInput, "hi"))
        {
            cout << "ShopBot: Hello! How can I help you today?\n";
        }
        else
        {
            cout << "ShopBot: I'm sorry, I didn't understand that. Could you please rephrase?\n";
        }
    }

    return 0;
}