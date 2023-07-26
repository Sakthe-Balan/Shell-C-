#include <iostream>
#include <string>
#include <vector>

using namespace std;
class utils{
    public:

    
void executeCommand(const string& input) {
   
     if (input == "help") {
           help();
        }
    }
void help() {
    std::cout << "Available commands:\n";
    std::cout << "  help : Display available commands.\n";
    std::cout << "  exit : Exit the shell.\n";
}

};




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
    




