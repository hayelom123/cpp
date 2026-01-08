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

UserModel registerUser()
{
    std::cout << "====================User Registration System====================" << std::endl;

    std::string name, email, password;

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    return UserModel(name, email, password);
}