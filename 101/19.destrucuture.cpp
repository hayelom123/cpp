#include <iostream>

using namespace std;

class MyClass
{
private:
    string name;

public:
    // constructor declarations and overloading
    MyClass()
    {
        name = "Default Name";
    }
    MyClass(string nameValue)
    {
        name = nameValue;
    }
    ~MyClass()
    {
        cout << "Destructor called for " << name << endl;
    }
    void displayMessage()
    {
        cout << "Hello, " << name << "!" << endl;
    }
    void setName(string nameValue)
    {
        name = nameValue;
    }
};

void callFunc()
{
    MyClass obj1("Hayelom");
    obj1.displayMessage();
    obj1.setName("Hayelom Kiros");
    obj1.displayMessage();
}

int main()
{
    callFunc();
    return 0;
}