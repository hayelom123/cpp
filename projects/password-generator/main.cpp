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
    std::cout << "Uppercase: " << upper << " Lowercase: " << lower << " Numbers: " << digits << " Symbols: " << symbols << std::endl;

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
        possiblePasswords += special;

    int max = possiblePasswords.length();

    std::string password = "";

    for (int i = 0; i < length; i++)
    {
        password += possiblePasswords[generateRandom(max)];
    }

    return password;
}

void yesOrNo(std::string title, bool *val)
{
    std::cout << title;
    char choice;
    std::cin >> choice;
    *val = (choice == 'y' || choice == 'Y');
}

void copyToClipboard(const std::string &text)
{
#ifdef _WIN32
    std::string command = "echo " + text + " | clip";
#elif __APPLE__
    std::string command = "echo \"" + text + "\" | pbcopy";
#elif __linux__
    std::string command = "echo \"" + text + "\" | xclip -selection clipboard";
#else
    std::cout << "Clipboard not supported on this OS.\n";
    return;
#endif

    system(command.c_str());
}
int main()
{
    std::cout << "\n\n=== PASSWORD GENERATOR ===\n\n";

    int length;

    std::cout << "Enter password length:";
    std::cin >> length;

    bool upper = true, lower = true, digits = true, symbols = true;

    // std::cout << "Password Length: " << length << std::endl;
    yesOrNo("Include Uppercase letters? (y/n): ", &upper);
    yesOrNo("Include Lowercase letters? (y/n): ", &lower);
    yesOrNo("Include Numbers? (y/n): ", &digits);
    yesOrNo("Include Symbols? (y/n): ", &symbols);

    std::string password = generatePassword(length, upper, lower, digits, symbols);

    std::cout << "\n\nPassword: " << password << "\n\n";
    copyToClipboard(password);
    std::cout << "Password copied to clipboard!\n";

    return 0;
}