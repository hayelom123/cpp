#include <iostream>
#include <string>
using namespace std;


class User{
    private:
     string password;

    public:
     int id;
     string username;
     string email;
        void displayInfo(){
            cout <<"ID: "<<id << ", Username: " << username << ", Email: " << email << endl;
        }
        void setPassword(string pwd){
            password = pwd;
        }
        bool checkPassword(string pwd){
            return password == pwd;
        }
    User(int uid, string uname, string mail, string pwd){
        id = uid;
        username = uname;
        email = mail;
        password = pwd;
    }
};

// Main function to demonstrate the User class
int main(){

    User user1(1, "john_doe", "johndoe@gmail.com", "secure123");

    user1.displayInfo();

    user1.setPassword("newpassword456");

    if(user1.checkPassword("newpassword456")){

        cout << "Password is correct." << endl;
    } else {
        cout << "Password is incorrect." << endl;
    }

    return 0;
}

// outside class member function definition
class MyClass{
    private:
      string name;
    public:
      //constructor declarations and overloading
      MyClass();
      MyClass(string nameValue);
      void displayMessage();
      // friend functions can access private members
      friend void friendFunction(MyClass obj);
};
void MyClass::displayMessage(){
    cout << "Hello"<<name<<" from MyClass!" << endl;
}

// Constructor definitions
MyClass::MyClass(){
    cout << "MyClass Constructor called!" << endl;
};
// Parameterized constructor
MyClass::MyClass(string nameValue){
    name =nameValue;
    cout << "MyClass Parameterized Constructor called for " << name << "!" << endl;
}

void friendFunction(MyClass obj){
    cout << "Hello " << obj.name << " from Friend Function!" << endl;
}

 