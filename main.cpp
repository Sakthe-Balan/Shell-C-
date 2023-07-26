#include <iostream>
#include <string>
#include <vector>

using namespace std;
class utils{
    public:
    void help() {
    std::cout << "Available commands:\n";
    std::cout << "  help : Display available commands.\n";
    // Add more command descriptions here
    std::cout << "  exit : Exit the shell.\n";
}
    void execute(string input){
        
       
    }
    
void executeCommand(const string& input) {
    // Implement your custom command execution here
     if (input == "help") {
           help();
        } else {
            execute(input);
        }
    // You can parse the command string and take appropriate actions based on the input.
}

};
// Function prototypes



int main() {
    string input;
    utils obj;
    std::cout << "Simple Shell Interface\n";
    std::cout << "Type 'help' to see available commands.\n";
    
    while (true) {
        std::cout << "> ";
        getline(cin, input);
        if (input=="exit"){
            std::cout<<"exiting shell";
            return 0;
        }
       obj.executeCommand(input); 
        }    
    }
    




