#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
std::string numbers = "0123456789";
std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

int validatePasswordLength(int length)
{
    return 0;
}

std::string possiblePasswords = lowercase + uppercase + numbers + special;

char getRandomCharacter()
{

    // seed random number ganerator using the current time
    // This ensures a different sequence of numbers each time the program runs

    // srand(): Seeds the pseudo-random number generator. It should be called once at the beginning of the program.

    // std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int length = possiblePasswords.length();
    int randomIndex = (std::rand() % 10) + 1;
    // rand() % length + 0;
    std::cout << "RandomIndex: " << randomIndex << std::endl;

    return possiblePasswords[randomIndex];
}

int main()
{
    int length;
    std::cout << "Enter password length:";
    std::cin >> length;

    std::cout << "Password Length: " << length << std::endl;

    std::string password = "";

    for (int i = 0; i < length; i++)
    {
        password += getRandomCharacter();
    }
    std::cout << "Password: " << password << std::endl;

    return 0;
}