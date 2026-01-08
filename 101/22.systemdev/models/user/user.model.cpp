#include "user.model.h"

// defntions
std::string UserModel::getId() const
{
    return id;
}

std::string UserModel::getName() const
{
    return name;
}

std::string UserModel::getEmail() const
{
    return email;
}
std::string UserModel::getPassword() const
{
    return password;
}

std::string UserModel::setName(std::string newName)
{
    name = newName;
    return name;
}
// ----------------Setters-------------
std::string UserModel::setEmail(std::string newEmail)
{

    return email;
}
std::string UserModel::setPassword(std::string olPassword, std::string newPassword)
{
    return password;
}

UserModel registerUser()
{
    std::cout << "====================User Registration System====================" << std::endl;

    std::string name, email, password;
    std::getchar();
    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    return UserModel(name, email, password);
}

bool validateUser(UserModel user)
{
    if (user.getName().empty())
    {
        std::cout << "Name cannot be empty\n";
        return false;
    }
    if (user.getEmail().empty())
    {
        std::cout << "Email cannot be empty\n";
        return false;
    }
    if (user.getPassword().empty())
    {
        std::cout << "Password cannot be empty\n";
        return false;
    }
    return true;
}

std::string filename = "users.csv";

bool saveUser(const UserModel user)
{
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open())
    {
        std::cerr << "Failed to open users.txt\n";
        return false;
    }

    file << user.getId() << ","
         << user.getName() << ","
         << user.getEmail() << ","
         << user.getPassword() << "\n";

    file.close();
    return true;
}
std::vector<UserModel> loadCSV()
{
    std::vector<UserModel> users;

    std::ifstream fileIn(filename);
    if (!fileIn.is_open())
    {
        std::cerr << "Failed to open " << filename << "\n";
        return users;
    }

    std::string line;

    while (std::getline(fileIn, line))
    {

        std::stringstream ss(line);
        std::string id, name, email, hash;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, email, ',');
        std::getline(ss, hash, ',');

        users.push_back(UserModel(id, name, email, hash));
    }

    fileIn.close();
    return users;
}