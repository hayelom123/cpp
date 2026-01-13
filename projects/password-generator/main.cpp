#include <iostream>

std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
std::string numbers = "0123456789";
std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

int validatePasswordLength(int length) {}

std::string possiblePasswords = lowercase + uppercase + numbers + special;

char getRandomCharacter()
{
}

int main()
{
    int length;
    std::cout << "Enter password length:";
    std::cin >> length;

    std::cout << "Password Length: " << length << std::endl;

    char *password = "";

    for (int i = 0; i < length; i++)
    {
    }

    return 0;
}