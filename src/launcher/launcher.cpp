#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>

// Helper function to build the DLL
void BuildDLL() {
    std::string command = "cl /LD src\\engine\\engine.cpp /Fe:bin\\game_engine.dll";
    std::cout << "Building DLL with command: " << command << std::endl;
    
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "DLL compiled successfully.\n";
    } else {
        std::cerr << "Failed to compile DLL.\n";
        exit(1);
    }
}

int main() {
    BuildDLL();
    // load the dll
    // wathc the directory
    // rebuild upon change
    // reload the dll
}