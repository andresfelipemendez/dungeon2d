#include <windows.h>
#include <stdio.h>
#include <chrono>
#include <thread>


typedef void (*InitFunc)();
typedef void (*UpdateFunc)();


HMODULE dllHandle = nullptr;
InitFunc InitializeEngine = nullptr;
UpdateFunc UpdateGame = nullptr;

void BuildDLL() {
    const char* command = "cl /LD src\\engine\\engine.cpp /Iinclude /link /implib:bin\\game_engine.lib";
    printf("Building DLL with command: %s\n", command);
    
    int result = system(command);
    if (result == 0) {
        printf("DLL compiled successfully.\n");
    } else {
        printf( "Failed to compile DLL.\n");
        exit(1);
    }
}


void LoadDLL() {
    if (dllHandle) {
        FreeLibrary(dllHandle); 
    }

    dllHandle = LoadLibraryA("bin\\game_engine.dll");
    if (!dllHandle) {
        printf("Failed to load DLL.\n");
        exit(1);
    }

    InitializeEngine = (InitFunc)GetProcAddress(dllHandle, "InitializeEngine");
    UpdateGame = (UpdateFunc)GetProcAddress(dllHandle, "UpdateGame");

    if (!InitializeEngine || !UpdateGame) {
        printf("Failed to load functions from DLL.\n");
        exit(1);
    }

    InitializeEngine();

    printf("DLL loaded successfully.\n");
}

int main() {

    BuildDLL();
    LoadDLL() ;
    // watch the directory
    // rebuild upon change
    // reload the dll
    // since the game listen for keyboard input, pass a method to exit/close the launcher 
}