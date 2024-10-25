#include <iostream>
#include <state.h>
 
EXPORT void InitializeEngine () {
    std::cout << "hi from the dll\n";
}


EXPORT void UpdateGame () {
    std::cout << "hi from the dll\n";
}
