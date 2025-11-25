#include <iostream>
using namespace std;

int main(){

    // The auto keyword automatically detects the type of a variable based on the value you assign to it.

    auto a = 5;          // int
    auto b = 5.99;      // double
    auto c = 'A';       // char
    auto d = true;      // bool
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
    cout<<"d = "<<d<<endl;

     auto sum = a + b; // sum will be of type double
    cout<<"sum = "<<sum<<endl;

    auto greeting = "Hello, World!"; // greeting will be of type const char*
    cout<<greeting<<endl;

    return 0;
}