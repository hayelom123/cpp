#include <iostream>
#include <random>

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

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(0, length);

    int randomIndex = dist(engine);
    // (rand() % length) + 0;
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