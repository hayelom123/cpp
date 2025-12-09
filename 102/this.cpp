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
    Vector operator+(const Vector &right)
    {
        return Vector{x + right.x, y + right.y};
    }
    Vector operator-(const Vector &right)
    {
        return Vector{this->x - right.x, this->y - right.y};
    }
    friend ostream &operator<<(ostream &os, const Vector &v)
    {
        os << "{" << v.x << ", " << v.y << "}";
        return os;
    }
};

int main()
{
    cout << "Operator overloading" << endl;
    Vector v1{3, 6};
    Vector v2{4, 7};
    Vector result = v1 + v2; // Using overloaded + operator
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << result << endl;
    result = v1 - v2; // Using overloaded - operator
    cout << "v1 - v2 = " << result << endl;
    return 0;
}