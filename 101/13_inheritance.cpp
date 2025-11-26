#include <iostream>
#include <string>

using namespace std;

// Base class
class User{
public:
    string username;
    string email;

    void displayInfo() {
        cout << "Username: " << username << ", Email: " << email << endl;
    }
};

// Derived class
class Admin :public User{
public:
    int adminLevel;

    void displayAdminInfo() {
        displayInfo();
        cout << "Admin Level: " << adminLevel << endl;
    }
};

// multi-level inheritance example
class SuperAdmin : public Admin {
    public:
        void displaySuperAdminInfo() {
            displayAdminInfo();
            cout <<username <<" is Super Admin." << endl;
        }
};

class Guest : public User {
public:
    void displayGuestInfo() {
        displayInfo();
        cout << username << " is a Guest User." << endl;
    }
};

// multiple inheritance example
class Moderator{
public:
    string stage;
    void displayModeratorInfo() {
       
        cout << stage << " is a Moderator." << endl;
    }
};

class VIPUser : public User, public Moderator {
    
    public:
        void displayVIPInfo() {
            User::displayInfo();
            Moderator::displayModeratorInfo();
            cout << username << " is a VIP User." << endl;
        }
};

// virtual inheritance example can be added here if needed

class Animal{
public:
   virtual void sound() {
        cout << "Animal sounds" << endl;
    }

};

class Dog:public Animal{
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

int main() {

    cout<<"-------------------------------------------"<<endl;

    // Creating an object of the base class
    User user1;
    user1.username = "john_doe";
    user1.email = "jond@gmail.com";
    user1.displayInfo();

    cout<<"-------------------------------------------"<<endl;

    // Creating an object of the derived class
    Admin admin1;
    admin1.username = "admin_user"; 
    admin1.email = "ad@gmail.com";
    admin1.adminLevel = 5;
    admin1.displayAdminInfo();

    cout<<"-------------------------------------------"<<endl;


    // Creating an object of the multi-level derived class
    SuperAdmin superAdmin1;
    superAdmin1.username = "super_admin";
    superAdmin1.email = "sa@gmail.com";
    superAdmin1.adminLevel = 10;
    superAdmin1.displaySuperAdminInfo();

    cout<<"-------------------------------------------"<<endl;

     // creating multiple inheritance object
    VIPUser vip1;
    vip1.username = "vip_user";
    vip1.email = "mod@gmail.com";
    vip1.stage = "Gold";
    vip1.displayVIPInfo();


     cout<<"-------------------------------------------"<<endl;
// creating virtual inheritance object

  Animal* a;
    Dog d;
    a=&d;
    a->sound();// without virtual it would have called Animal sound function not the child

      cout<<"-------------------------------------------"<<endl;

    //clearing output screen
    cout<<endl<<endl<<endl<<endl<<endl;

    return 0;
}
