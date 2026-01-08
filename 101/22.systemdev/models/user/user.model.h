#ifndef USER_MODEL_H
#define USER_MODEL_H

#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

class UserModel
{
    // id, name,email, password,
private:
    std::string id;
    std::string name;
    std::string email;
    std::string password;

    std::string encryptPassword(std::string pass)
    {
        return pass;
    }

public:
    UserModel(const std::string &userName, const std::string &userEmail, const std::string &userPassword)
        : name(userName), email(userEmail)
    {

        password = encryptPassword(userPassword);
        id = generate_uuid_v4();
    }

    std::string generate_uuid_v4()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dist(0, 15);
        static std::uniform_int_distribution<int> dist2(8, 11);

        std::stringstream ss;
        ss << std::hex;

        for (int i = 0; i < 8; i++)
            ss << dist(gen);
        ss << "-";
        for (int i = 0; i < 4; i++)
            ss << dist(gen);
        ss << "-4";
        for (int i = 0; i < 3; i++)
            ss << dist(gen);
        ss << "-";
        ss << dist2(gen);
        for (int i = 0; i < 3; i++)
            ss << dist(gen);
        ss << "-";
        for (int i = 0; i < 12; i++)
            ss << dist(gen);

        return ss.str();
    }
    // -------- Getters --------
    std::string getId() const;
    std::string getName() const;
    std::string getEmail() const;
};
UserModel registerUser();

#endif
