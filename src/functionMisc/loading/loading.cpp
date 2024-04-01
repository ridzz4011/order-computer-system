#include <iostream>
#include "../../../include/clearscreen.hpp"
#include "../../../include/pauseconsole.hpp"

#include "../../../include/loading.hpp"

void Loading() {
    ClearScreen();

    char a = 177;
    char b = 219;

    std::cout << "\n\n\n\t\t\t\tMohon Tunggu Sejenak!\n\n";
    std::cout << "\t\t\t\t";

    for (int i = 0; i <= 15; i++)
        std::cout << a;
    std::cout << "\r";
    std::cout << "\t\t\t\t";

    for (int i = 0; i <= 15; i++) {
        std::cout << b;
        for (int j = 0; j <= 1e8; j++);
    }

    std::cout << "\n\n\t\t\t\t" ;

    PauseConsole();
    ClearScreen();
}