#include <iostream>
#include "./utils/utils.h"
#include "models/user/user.model.h"

std::vector users;

int main()
{
    // fatures
    //  1. register users
    //  2.login
    //  3.diplay profile
    //  4.edit profile

    std::vector users = loadCSV();

    for (UserModel user : users)
    {
        user.display();
    }

    // 1.register user
    UserModel user = registerUser();

    // validate
    while (!validateUser(user))
    {

        clearScreen();
        std::cout << "Invalid user. please provide valid info.\n";
        user = registerUser();
    }

    if (saveUser(user))
    {
        std::cout << "\nUser Registered!\n";
        std::cout << "ID: " << user.getId() << "\n";
        std::cout << "Name: " << user.getName() << "\n";
        std::cout << "Email: " << user.getEmail() << "\n";
    }
    else
    {
        std::cerr << "Failed to register user\n";
    }
}
