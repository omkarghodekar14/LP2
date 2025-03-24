#include<bits/stdc++.h>

using namespace std;

struct PatternResponse {
    string pattern;
    string response;
};

vector<PatternResponse> patterns = {
    {"Hi", "Hello! How can I help you?"},
    {"Hello", "Hi there!"},
    {"name", "I am a simple chatbot."},
    {"how are you", "I'm always here to assist you."},
    {"bye", "Goodbye! Have a great day."}
};

void chat() {
    cout << "Hello! I am a chatbot. Type 'quit' to exit." << endl;
    string input;
    
    while (true) {
        cout << "You: ";
        getline(cin, input);
        
        if (input == "quit") {
            cout << "Chatbot: Goodbye!" << endl;
            break;
        }
        
        bool found = false;
        for (const auto& pattern : patterns) {
            if (input.find(pattern.pattern) != string::npos) {
                cout << "Chatbot: " << pattern.response << endl;
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Chatbot: Sorry, I didn't understand that." << endl;
        }
    }
}

int main() {
    chat();
    return 0;
}
