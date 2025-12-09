#include <iostream>
#include <string>
using namespace std;

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
