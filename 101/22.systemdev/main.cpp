#include <iostream>
#include "./utils/utils.h"
#include "models/user/user.model.h"

void menu();
int main()
{
    // fatures
    //  1. register users
    //  2.login
    //  3.diplay profile
    //  4.edit profile

    menu();
}

//---------------------------Header----------------------------------

void header()
{
    std::cout << "---------------- User Management System ----------------" << std::endl;
}

//---------------------------Menu----------------------------------

void menu()
{

    clearScreen();
    std::cout << "\033[" << 36 << "m";
    header();
    std::cout << "1.Login" << std::endl;
    std::cout << "2.Register" << std::endl;
    std::cout << "3.Display Users" << std::endl;
    std::cout << "4.Search User" << std::endl;
    std::cout << "" << std::endl;

    int menuID = 0;

    std::cout << "Choice: ";
    std::cin >> menuID;

    switch (menuID)
    {
    case 1:
        std::cout << "Login page." << std::endl;
        //

        break;
    case 2:
    {
        // 2.register user
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
        menu();
        break;
    }
    default:
    {
        std::vector<UserModel> users = loadCSV();

        for (UserModel user : users)
        {
            user.display();
            std::cout << std::endl;
        }

        waitForKey();
        menu();
        break;
    }
    }
}