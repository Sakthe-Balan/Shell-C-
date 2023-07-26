#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes
void help();
void executeCommand(const string& command);

int main() {
    string input;
    
    cout << "Simple Shell Interface\n";
    cout << "Type 'help' to see available commands.\n";
    
    while (true) {
        cout << "> ";
        getline(cin, input);
        
        if (input.empty())
            continue; // Ignore empty inputs
        
        if (input == "exit")
            break; // Exit the shell
        
        if (input == "help") {
            help();
        } else {
            executeCommand(input);
        }
    }
    
    cout << "Exiting the shell.\n";
    return 0;
}

void help() {
    cout << "Available commands:\n";
    cout << "  help : Display available commands.\n";
    // Add more command descriptions here
    cout << "  exit : Exit the shell.\n";
}

void executeCommand(const string& command) {
    // Implement your custom command execution here
    cout << "Executing: " << command << endl;
    // You can parse the command string and take appropriate actions based on the input.
}
