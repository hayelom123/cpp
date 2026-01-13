#include <iostream>
#include <random>

int generateRandom(int max)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(0, max);

    int randomIndex = dist(engine);
    return randomIndex;
}

std::string generatePassword(int length, bool upper = true, bool lower = true, bool digits = true, bool symbols = true)

{
    std::cout << "Password Length: " << length << std::endl;

    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string numbers = "0123456789";
    std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    std::string possiblePasswords = "";
    if (upper)
        possiblePasswords += uppercase;
    if (lower)
        possiblePasswords += lowercase;
    if (digits)
        possiblePasswords += numbers;
    if (symbols)
        possiblePasswords += symbols;

    int max = possiblePasswords.length();

    std::string password = "";

    for (int i = 0; i < length; i++)
    {
        password += possiblePasswords[generateRandom(max)];
    }

    return password;
}

int main()
{
    std::cout << "\n\n=== PASSWORD GENERATOR ===\n\n";

    int length;

    std::cout << "Enter password length:";
    std::cin >> length;

    // std::cout << "Password Length: " << length << std::endl;

    std::string password = generatePassword(length);

    std::cout << "Password: " << password << std::endl;

    return 0;
}