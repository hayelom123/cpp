#include <iostream>
#include "./utils/utils.h"
#include "models/user/user.model.h"

UserModel *user;
void menu();
void loginMenu();
void registerUserMenu();
void displayAllUsers();
void editUser();
void searchUserByEmail();
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
    if (user)
    {
        std::cout << "Name: " << user->getName() << " " << "Email: " << user->getEmail() << std::endl;
    }
}

//---------------------------Menu----------------------------------

void menu()
{

    clearScreen();

    std::cout << "\033[" << 36 << "m";
    header();
    std::cout << (user ? "1.Logout" : "1.Login")
              << std::endl;
    std::cout << "2.Register" << std::endl;
    std::cout << "3.Display Users" << std::endl;
    std::cout << "4.Update User" << std::endl;
    std::cout << "5.Search User BY Email" << std::endl;

    std::cout << "6.To EXIT" << std::endl;
    std::cout << "" << std::endl;

    std::string input;
    int menuID = 0;

    std::cout << "Choice: ";
    std::getline(std::cin, input);
    // std::cin >> menuID;
    menuID = std::stoi(input);
    std::cout << "\033[" << 35 << "m";
    // Clear leftover newline
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (menuID)
    {
    case 1:
    {
        loginMenu();
        break;
    }
    case 2:
    {
        registerUserMenu();
        break;
    }
    case 3:

        displayAllUsers();
        break;
    case 4:

        editUser();

        break;
    case 5:

        searchUserByEmail();

        break;
    case 6:
        exit(0);
        break;
    default:
        menu();
    }
}

void loginMenu()
{

    // if user is logged in then logout
    if (user)
    {
        delete user;
        user = nullptr;
        menu();
    }
    int trial = 0;
    while (trial < 3)
    {
        std::cout << "Login page." << std::endl;
        trial++;
        std::string email, password;

        std::cout << "Email: ";
        std::getline(std::cin, email);

        std::cout << "Password: ";
        std::getline(std::cin, password);

        user = loginWithEmailAndPassword(email, password);
        if (user)
        {
            std::cout << "Login successful! Welcome " << user->getName() << std::endl;
            user->display();

            waitForKey();
            break;
        }
        else
        {
            std::cout << "Login failed!\n";
        }
        waitForKey();
    }

    menu();
}

void registerUserMenu()
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
    waitForKey();
    menu();
}

void displayAllUsers()
{

    std::vector<UserModel> users = displayUsers();
    std::cout << "\n\n\t========================== All Users ==========================\n"
              << std::endl;
    displayUsersTable(users);

    waitForKey();
    menu();
}

void editUser()
{

    {
        UserModel uUser = editUser(*user);
        while (!validateUser(uUser))
        {

            clearScreen();
            std::cout << "Invalid user. please provide valid info.\n";
            uUser = editUser(*user);
        }
        uUser.display();
        if (updateUserDb(uUser))
        {
            std::cout << "User updated successfully.\n";

            user = &uUser;
        }

        waitForKey();
        menu();
    }
}

void searchUserByEmail()
{

    clearScreen();
    std::cout << "================== Search User By Email ==================" << std::endl;
    std::string email;
    std::cout << "Email: ";
    std::getline(std::cin, email);
    if (email.empty())
    {
        std::cout << "You didn't provide Email";
    }
    else
    {
        std::optional<UserModel> user = searchUserByEmail(email);
        if (user)
        {
            user->display();
        }
        else
        {
            std::cout << "User not found\n";
        }
    }

    waitForKey();
    menu();
}
