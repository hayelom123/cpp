#include <iostream>

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
    }

public:
    UserModel(const std::string &userName, const std::string &userEmail, const std::string &userPassword)
        : name(userName), email(userEmail)
    {

        password = encryptPassword(userPassword);
        id = generate_uuid_v4();
    }

    std::string &generate_uuid_v4()
    {
        std::string newId = "";

        return newId;
    }
    // -------- Getters --------
    std::string getId() const
    {
        return id;
    }

    std::string getName() const
    {
        return name;
    }

    std::string getEmail() const
    {
        return email;
    }
};
