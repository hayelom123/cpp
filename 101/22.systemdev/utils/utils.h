#ifndef MYUTILS_H
#define MYUTILS_H
#include <iostream>
#include <cstdlib>
// #include <conio.h>

void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
// Check if the operating system is Windows
#if defined(_WIN32) || defined(_WIN64)
    std::system("cls");
#else
    // Assume POSIX (Linux, macOS, Unix-like)
    std::system("clear");
#endif
}
void waitForKey()
{
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
#endif