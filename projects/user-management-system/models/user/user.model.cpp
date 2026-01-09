#include "user.model.h"
#include "../../db/db.h"

std::string secretkey = "testkey123";
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

bool saveUser1(const UserModel user)
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

UserModel *loginWithEmailAndPassword1(std::string userEmail, std::string userPassword)
{
    std::ifstream fileIn(filename);
    if (!fileIn.is_open())
    {
        std::cerr << "Failed to open " << filename << "\n";
        return nullptr;
    }
    std::string line;

    while (std::getline(fileIn, line))
    {
        std::stringstream ss(line);
        std::string id, name, email, password;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, email, ',');
        std::getline(ss, password, ',');

        // if (userEmail.compare(email) == 0)
        // std::cout << email << std::endl;
        if (userEmail == email && UserModel::hashPassword(userPassword) == password)
        {
            return new UserModel{id, name, email, password};
        }
    }
    return nullptr;
}

void displayUsersTable(const std::vector<UserModel> &users)
{
    const int ID_W = 38;
    const int NAME_W = 20;
    const int EMAIL_W = 26;

    // Header line
    std::cout << "+"
              << std::string(ID_W, '-') << "+"
              << std::string(NAME_W, '-') << "+"
              << std::string(EMAIL_W, '-') << "+\n";

    // Header titles
    std::cout << "|"
              << std::left << std::setw(ID_W) << " ID"
              << "|"
              << std::left << std::setw(NAME_W) << " Name"
              << "|"
              << std::left << std::setw(EMAIL_W) << " Email"
              << "|\n";

    // Header line
    std::cout << "+"
              << std::string(ID_W, '-') << "+"
              << std::string(NAME_W, '-') << "+"
              << std::string(EMAIL_W, '-') << "+\n";

    // Rows
    for (const auto &user : users)
    {
        std::cout << "|"
                  << std::left << std::setw(ID_W) << user.getId()
                  << "|"
                  << std::left << std::setw(NAME_W) << user.getName()
                  << "|"
                  << std::left << std::setw(EMAIL_W) << user.getEmail()
                  << "|\n";
    }

    // Footer line
    std::cout << "+"
              << std::string(ID_W, '-') << "+"
              << std::string(NAME_W, '-') << "+"
              << std::string(EMAIL_W, '-') << "+\n";
}

// using database================================================================
bool saveUser(const UserModel user)
{
    sqlite3 *db = openDB();
    if (!db)
    {
        return false;
    }

    createUsersTable();

    const char *sql =
        "INSERT INTO users (id, name, email, password) VALUES (?, ?, ?, ?);";

    sqlite3_stmt *stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, user.getId().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, user.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, user.getEmail().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, user.getPassword().c_str(), -1, SQLITE_TRANSIENT);

    bool ok = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);

    return ok;
}

UserModel *loginWithEmailAndPassword(std::string userEmail, std::string userPassword)
{

    sqlite3 *db = openDB();
    if (!db)
        return nullptr;

    const char *sql =
        "SELECT id, name, email, password FROM users WHERE email = ?;";

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, userEmail.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {

        std::string dbPassword =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));

        if (dbPassword == UserModel::hashPassword(userPassword))
        {
            UserModel *user = new UserModel(
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)),
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)),
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)),
                dbPassword);
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return user;
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return nullptr;
}

void displayUsers()
{
    sqlite3 *db = openDB();
    if (!db)
        return;

    const char *sql = "SELECT id, name, email FROM users;";
    sqlite3_stmt *stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::cout << std::left
                  << std::setw(38) << sqlite3_column_text(stmt, 0)
                  << std::setw(20) << sqlite3_column_text(stmt, 1)
                  << std::setw(30) << sqlite3_column_text(stmt, 2)
                  << "\n";
    }

    sqlite3_finalize(stmt);
}
