#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    // refernces are like constant pointers that are automatically dereferenced and must be initialized when declared. they are often used as function parameters to avoid copying large objects
    int &refX = x; // refX is a reference to x .refX is another name for x or nickname for x

    cout << "The value of x is: " << x << endl;
    cout << "The value of refX is: " << refX << endl;

    refX = 20; // changing refX changes x

    cout << "After changing refX to 20" << endl;
    cout << "The value of x is: " << x << endl;
    cout << "The value of refX is: " << refX << endl;

    cout << "=================================================" << endl;

    int y = 30;
    int *ptr = nullptr;
    ptr = &y;
    cout << "The value of y is: " << y << endl;
    cout << "The value pointed to by ptr is: " << *ptr << endl;
    *ptr = 40; // changing the value pointed to by ptr changes y
    cout << "After changing the value pointed to by ptr to 40" << endl;
    cout << "The value of y is: " << y << endl;
    cout << "The value pointed to by ptr is: " << *ptr << endl;

    cout << "=================================================" << endl;

    // int & refX2 = *ptr; // refX2 is a reference to the value pointed to by ptr

    // summary: references are like constant pointers that are automatically dereferenced and must be initialized when declared.
    //           they are often used as function parameters to avoid copying large objects.
    //           pointers are variables that store memory addresses and can be reassigned to point to different addresses.
    //           both references and pointers can be used to modify the original variable they refer to or point to.
    return 0;
}