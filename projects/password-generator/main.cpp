#include <iostream>
#include <random>

std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
std::string numbers = "0123456789";
std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

std::string possiblePasswords = lowercase + uppercase + numbers + special;

char getRandomCharacter()
{
    int length = possiblePasswords.length();

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(0, length);

    int randomIndex = dist(engine);

    return possiblePasswords[randomIndex];
}

int main()
{
    std::cout << "\n\n=== PASSWORD GENERATOR ===\n\n";

    int length;

    std::cout << "Enter password length:";
    std::cin >> length;

    // std::cout << "Password Length: " << length << std::endl;

    std::string password = "";

    for (int i = 0; i < length; i++)
    {
        password += getRandomCharacter();
    }
    std::cout << "Password: " << password << std::endl;

    return 0;
}