#include <iostream>
#include <string>
#include <vector>

using namespace std;

class utils {
public:
    void executeCommand(const string& input) {
        string command;
        vector<string> flags;
        vector<string> words = split(input);
        execute(words);
        }

    void help() {
        std::cout << "Available commands:\n";
        std::cout << "  help : Display available commands.\n";
        std::cout << "  exit : Exit the shell.\n";
    }

    vector<string> split(string line) {
        vector<string> words;
        string word;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += line[i];
            }
        }
        words.push_back(word);
        return words;
    }

    void execute(vector<string> input) {
        if (input[0] == "help") {
            help();
        }
        else if (input[0] == "ls") {
            for(auto i:input)
            {
            
            }
        } 
        else {
            std::cout << "Unknown command: " << input[0] << std::endl;
        }
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
        if (input == "exit") {
            std::cout << "Exiting shell";
            return 0;
        }
        obj.executeCommand(input);
    }
}
