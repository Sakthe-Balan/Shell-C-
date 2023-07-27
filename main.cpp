#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem; //aliasing
class utils {
public:
// This function just takes the initial input and passes it to the execute function
    void executeCommand(const std::string& input) {
        std::vector<std::string> words = split(input);
        execute(words);
    }
    //Add all the commands to the help function. acts as an initial mannual
    void help() {
        std::cout << "Available commands:\n";
        std::cout << "  help : Display available commands.\n";
        std::cout << "  exit : Exit the shell.\n";
        std::cout << "  ls   : List files and directories in the current directory.\n";
    }

    
    // All the functions for the commands are written as a else if condition in the execute function
    void execute(std::vector<std::string> input) {
        if (input.empty()) {
            return;
        }

        if (input[0] == "help") {
            help();
        } else if (input[0] == "ls") {
            bool showHidden = false;

            for (size_t i = 1; i < input.size(); i++) {
                std::string word = input[i];
                if (word == "-a") {
                    showHidden = true; // setting bool variables first to check which flags have been activated.
                }
            }

            listDirectory(".", showHidden);
        }else if (input[0] == "run") {
            if (input.size() < 2) {
                std::cout << "Usage: execute <path_to_sh_file>\n";
                return;
            }
            else run(input[1]);
        } 
        else {
            std::cout << "Unknown command: " << input[0] << std::endl;
        }
    }
    //From here we start defining all the functions required to execute the commands.

    void listDirectory(const std::string& directory, bool showHidden) {
        for (const auto& entry : fs::directory_iterator(directory)) {
            std::string filename = entry.path().filename().string();
            if (!showHidden && filename[0] == '.') { //when show hidden(a flag) is true the continue is not executed hence all files are given
                continue;
            }
            std::cout << filename << " ";
        }
        std::cout << std::endl;
    }
    std::vector<std::string> split(std::string line) {
        std::vector<std::string> words;
        std::string word;
        for (char c : line) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word="";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        return words;
    }
    //define the run fucntion  which takes the path of a .sh file and executes all the lines
   void run(std::string p) {
        std::string path = p;
        std::ifstream file(path); //This opens and reads the file
        std::string lin;
        while (std::getline(file, lin)) {
            executeCommand(lin);
        }
    } 
};

int main() {
    std::string input;
    utils obj;
    std::cout << "Simple Shell Interface\n";
    std::cout << "Type 'help' to see available commands.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit") {
            std::cout << "Exiting shell";
            return 0;
        }
        obj.executeCommand(input);
    }
}
