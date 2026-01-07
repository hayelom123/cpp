#include <iostream>

void forEach(std::vector<int> &values, void (*func)(int))
{
    for (int val : values)
    {
        func(val);
    }
}

int main()
{
    // lambda function
    //

    std::vector<int> values = {1, 5, 6, 8};

    forEach(values, [](int value)
            { std::cout << "Value:" << value << std::endl; });
}