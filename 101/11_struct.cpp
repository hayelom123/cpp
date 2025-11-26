#include <iostream>

using namespace std;

int main(){

    struct Person{
        string name;
        int age;
    } person3;  

    Person person1={"Alice", 30};
    Person person2={"Bob", 25};
    cout << "Name: " << person1.name << ", Age: " << person1.age << endl;
    cout << "Name: " << person2.name << ", Age: " << person2.age << endl;
    person3.name = "Charlie";
    person3.age = 28;
    cout << "Name: " << person3.name << ", Age: " << person3.age << endl;

    return 0;
}