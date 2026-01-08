#include <iostream>
#include "models/user/user.model.h"

int main()
{
    // fatures
    //  1. register users
    //  2.login
    //  3.diplay profile
    //  4.edit profile

    // 1.register user
    UserModel user = registerUser();

    // validate
    if (!validateUser(user))
    {
        std::cout << "Invalid user. please provide valid info.\n";
        user = registerUser();
    }

    std::cout << "\nUser Registered!\n";
    std::cout << "ID: " << user.getId() << "\n";
    std::cout << "Name: " << user.getName() << "\n";
    std::cout << "Email: " << user.getEmail() << "\n";
}