#ifndef USER_MODEL_H
#define USER_MODEL_H

#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>

extern std::string secretkey; // declaration only

class UserModel
{
    // id, name,email, password,
private:
    std::string id;
    std::string name;
    std::string email;
    std::string password;

public:
    UserModel() = default; // ✅ ADD THIS
    UserModel(const std::string &userName, const std::string &userEmail, const std::string &userPassword)
        : name(userName), email(userEmail)
    {

        password = hashPassword(userPassword);
        std::cout << "Password: " << password << std::endl;
        id = generate_uuid_v4();
    }
    UserModel(const std::string UUID, const std::string &userName, const std::string &userEmail, const std::string &userPassword)
        : id(UUID), name(userName), email(userEmail), password(userPassword)
    {
    }
    static std::string hashPassword(const std::string &pass)
    {
        uint64_t hash = 5381;
        for (char c : pass + secretkey)
        {
            hash = ((hash << 5) + hash) + static_cast<unsigned char>(c);
        }
        return std::to_string(hash);
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
    std::string getPassword() const;

    //------- Setters ----------
    std::string setName(std::string newName);
    std::string setEmail(std::string newEmail);
    std::string setPassword(std::string olPassword, std::string newPassword);

    // display
    void display()
    {
        std::cout << "{"
                  << "\"id\": \"" << id << "\", "
                  << "\"name\": \"" << name << "\", "
                  << "\"email\": \"" << email << "\", "
                  << "\"password\": \"" << password << "\""
                  << "}" << std::endl;
    }
};
UserModel registerUser();

bool validateUser(UserModel user);

bool saveUser(UserModel user);
std::vector<UserModel> loadCSV();
UserModel *loginWithEmailAndPassword(std::string userEmail, std::string userPassword);

void displayUsersTable(const std::vector<UserModel> &users);

#endif
