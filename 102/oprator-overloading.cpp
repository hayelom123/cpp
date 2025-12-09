#include <iostream>
#include <string>
using namespace std;

// the difference between a class and a struct is that members of a class are private by default, while members of a struct are public by default
// friend functions can access private members of a class or struct
// friend class can access private members of another class
// operator overloading allows us to define how operators work with user-defined types (classes or structs)
// it can make code more readable and intuitive, but it should be used judiciously to avoid confusion
// operator overloading is done by defining a function with the keyword 'operator' followed by the operator symbol
// the function can be a member function or a non-member function (friend function)
// non-member functions are often used for binary operators (operators that take two operands) to allow for commutative operations
// member functions are often used for unary operators (operators that take one operand) or when the left operand is an instance of the class
// operator overloading can be done for most operators, but not all (e.g., we cannot overload the scope resolution operator (::), sizeof operator, or member access operator (.))

class Vector
{
    int x;
    int y;

public:
    Vector(int x = 0, int y = 0) : x(x), y(y)
    {
        cout << "intialised" << endl;
    }
    friend Vector operator+(const Vector &left, const Vector &right);
    friend Vector operator-(const Vector &left, const Vector &right);
    friend ostream &operator<<(ostream &os, const Vector &v);
    friend class VectorTest; // Allow VectorTest to access private members
};

// Overloading the + operator for Vector
Vector operator+(const Vector &left, const Vector &right)
{
    return Vector{left.x + right.x, left.y + right.y};
}

Vector operator-(const Vector &left, const Vector &right)
{
    return Vector{left.x - right.x, left.y - right.y};
}

ostream &operator<<(ostream &os, const Vector &v)
{
    os << "{" << v.x << ", " << v.y << "}";
    return os;
}

istream &operator>>(istream &is, string &s)
{
    getline(is, s);
    return is;
}

int main()
{
    cout << "Operator overloading" << endl;

    Vector v1{3, 6};
    Vector v2{4, 7};

    Vector result = v1 + v2;
    // either way it works
    result = operator+(v1, v2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << result << endl;

    result = v1 - v2;
    cout << "v1 - v2 = " << result << endl;

    cout << "Please enter your name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << endl;

    return 0;
}
