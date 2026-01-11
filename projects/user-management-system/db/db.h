#ifndef DB_H
#define DB_H

#include <sqlite3.h>
#include <iostream>
// open or create database
sqlite3 *openDB()
{
    sqlite3 *db;
    if (sqlite3_open("user-management.db", &db) != SQLITE_OK)
    {
        std::cerr << "Cannot open database\n";
        return nullptr;
    }
    return db;
}

bool createUsersTable()
{
    sqlite3 *db = openDB();
    if (!db)
        return false;

    const char *sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id TEXT PRIMARY KEY,"
        "name TEXT,"
        "email TEXT UNIQUE,"
        "password TEXT);";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

#endif
