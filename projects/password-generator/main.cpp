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

    int length = possiblePasswords.length();
    int randomIndex = std::rand() % length;
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