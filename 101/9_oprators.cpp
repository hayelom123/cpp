#include <iostream>
using namespace std;

int main(){

    // Arithmetic Operators
    int a = 10, b = 3;
    cout<<"Arithmetic Operators:" << endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout << "a + b = " << a + b << endl; // Addition
    cout << "a - b = " << a - b << endl; // Subtraction
    cout << "a * b = " << a * b << endl; // Multiplication
    cout << "a / b = " << a / b << endl; // Division
    cout << "a % b = " << a % b << endl; // Modulus or reminder
    cout << "++a = " << ++a << endl;     // Pre-increment
    cout << "b-- = " << b-- << endl;     // Post-decrement
    cout << "New value of b = " << b << endl;

    cout<<"Modified value:"<<++a+b-- << endl;

    cout<<endl<<"-----------------------------------"<<endl;
    // Relational Operators
    int u = 15, v = 20;
    cout<<"\nRelational Operators:"<<endl;
    cout<<"u = "<<u<<endl;
    cout<<"v = "<<v<<endl;
    cout << "u == v: " << (u == v) << endl; // Equal to
    cout << "u != v: " << (u != v) << endl; // Not equal to
    cout << "u > v: " << (u > v) << endl;   // Greater than
    cout << "u < v: " << (u < v) << endl;   // Less than
    cout << "u >= v: " << (u >= v) << endl; // Greater than or equal to
    cout << "u <= v: " << (u <= v) << endl; // Less than or equal to

    cout<<endl<<"-----------------------------------"<<endl;

    // Increment and Decrement Operators
    int m1 = 7, n1 = 5;
    cout<<"\nIncrement and Decrement Operators:"<<endl;
    cout<<"m1 = "<<m1<<endl;
    cout<<"n1 = "<<n1<<endl;
    cout << "Pre-increment ++m1: " << ++m1 << endl; // Pre-increment
    cout << "Post-increment n1++: " << n1++ << endl; // Post-increment
    cout << "Value of n1 after post-increment: " << n1 << endl;
    cout << "Pre-decrement --m1: " << --m1 << endl; // Pre-decrement
    cout << "Post-decrement n1--: " << n1-- << endl; // Post-decrement
    cout << "Value of n1 after post-decrement: " << n1 << endl;
    cout<<endl<<"-----------------------------------"<<endl;

    cout<<"Oprator precedence and Associativity:"<<endl;
    int res = 10 + 5 * 2 - 8 / 4;
    cout<<"res = 10 + 5 * 2 - 8 / 4 = "<<res<<endl;
    cout<<"(10 + 5) * (2 - 8) / 4 = "<< ( (10 + 5) * (2 - 8) / 4 ) <<endl;  

    /*
    () - Parentheses
    *, /, % - Multiplication, Division, Modulus
    +, - - Addition, Subtraction
    >, <, >=, <= - Comparison
    ==, != - Equality
    && - Logical AND
    || - Logical OR
    = - Assignment
    */

    cout<<endl<<"-----------------------------------"<<endl;
    // assignment Operators
    int x = 5;
    cout<<"\nAssignment Operators:"<<endl;
    cout<<"x = "<<x<<endl;
    x += 3; // x = x + 3
    cout << "x += 3 -> " << x << endl;
    x -= 2; // x = x - 2
    cout << "x -= 2 -> " << x << endl;
    x *= 4; // x = x * 4
    cout << "x *= 4 -> " << x << endl;
    x /= 2; // x = x / 2
    cout << "x /= 2 -> " << x << endl;
    x %= 3; // x = x % 3
    cout << "x %= 3 -> " << x << endl;

    cout<<endl<<"-----------------------------------"<<endl;

    // Comparison Operators
    int p = 7, q = 10;
    cout<<"\nComparison Operators:"<<endl;
    cout<<"p = "<<p<<endl;
    cout<<"q = "<<q<<endl;
    cout << "p == q: " << (p == q) << endl; // Equal to
    cout << "p != q: " << (p != q) << endl; // Not equal to
    cout << "p > q: " << (p > q) << endl;   // Greater than
    cout << "p < q: " << (p < q) << endl;   // Less than
    cout << "p >= q: " << (p >= q) << endl; // Greater than or equal to
    cout << "p <= q: " << (p <= q) << endl; // Less than or equal to

    cout<<endl<<"-----------------------------------"<<endl;

    // Logical Operators
    bool A = true, B = false;
    cout<<"\nLogical Operators:"<<endl;
    cout<<"A = "<<A<<endl;
    cout<<"B = "<<B<<endl;
    cout << "A && B: " << (A && B) << endl; // Logical AND
    cout << "A || B: " << (A || B) << endl; // Logical OR
    cout << "!A: " << (!A) << endl;          // Logical NOT
    cout << "!B: " << (!B) << endl;          // Logical NOT

    cout<<endl<<"-----------------------------------"<<endl;

    cout<<"\nBitwise Operators:"<<endl;
    int m = 5, n = 3; // In binary: m = 0101, n = 0011
    cout<<"m = "<<m<<endl;
    cout<<"n = "<<n<<endl;
    cout << "m & n: " << (m & n) << endl; // Bitwise AND
    cout << "m | n: " << (m | n) << endl; // Bitwise OR
    cout << "m ^ n: " << (m ^ n) << endl; // Bitwise XOR 
    cout << "~m: " << (~m) << endl;   // Bitwise NOT  min binary:  0000...0101 => ~m = 1111...1010 (Two's complement representation)
    cout << "m << 1: " << (m << 1) << endl; // Left shift  
    cout << "n >> 1: " << (n >> 1) << endl; // Right shift

    cout<<endl<<"-----------------------------------"<<endl;

    cout<<"\nCompound Operators:"<<endl;
    int c = 4;
    cout<<"c = "<<c<<endl;
    c += 2; // c = c + 2
    cout << "c += 2 -> " << c << endl;
    c *= 3; // c = c * 3
    cout << "c *= 3 -> " << c << endl;
    c -= 5; // c = c - 5
    cout << "c -= 5 -> " << c << endl;
    c /= 2; // c = c / 2
    cout << "c /= 2 -> " << c << endl;
    c %= 3; // c = c % 3
    cout << "c %= 3 -> " << c << endl;  
    cout<<endl<<"-----------------------------------"<<endl;

    cout<<"\nUnary Operators:"<<endl;
    int d = 6;
    cout<<"d = "<<d<<endl;
    cout << "+d: " << (+d) << endl; // Unary plus
    cout << "-d: " << (-d) << endl; // Unary minus
    cout << "++d: " << (++d) << endl; // Pre-increment
    cout << "--d: " << (--d) << endl; // Pre-decrement
    cout << "d++: " << (d++) << endl; // Post-increment
    cout << "d--: " << (d--) << endl; // Post-decrement
    cout << "Final value of d: " << d << endl;  
    cout<<endl<<"-----------------------------------"<<endl;

    cout<<"\nTernary Operator:"<<endl;
    int age = 20;
    cout<<"age = "<<age<<endl;
    string eligibility = (age >= 18) ? "Eligible to vote" : "Not eligible to vote";
    cout << "Voting Eligibility: " << eligibility << endl;  
    cout<<endl<<"-----------------------------------"<<endl;

    cout<<"\nSizeof Operator:"<<endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
    cout<<endl<<"-----------------------------------"<<endl;

    cout<<"\nTypecast Operator:"<<endl;
    float f = 9.78;
    cout<<"f = "<<f<<endl;
    int intF = (int)f; // Typecasting float to int
    cout << "Typecasted int value of f: " << intF << endl;  
    cout<<endl<<"-----------------------------------"<<endl;

    cout<<"\nAddress-of (&) and Dereference (*) Operators:"<<endl;
    int var = 42;
    cout<<"var = "<<var<<endl;
    cout << "Address of var: " << &var << endl; // Address-of operator
    int *ptrVar = &var; // Pointer to var
    cout << "Value pointed to by ptrVar: " << *ptrVar << endl; // Dereference operator
    cout<<endl<<"-----------------------------------"<<endl;    

    // Special Operators

    cout<<"\nSpecial Operators:"<<endl;
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer to the first element of the array
    cout<<"Array elements using pointer arithmetic:"<<endl;
    for(int i = 0; i < 5; i++){
        cout << *(ptr + i) << " "; // Accessing array elements using pointer arithmetic
    }
    cout << endl;   

    return 0;

}