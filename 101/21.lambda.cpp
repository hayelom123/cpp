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
    // it was started in c++ 11
    // Constructs a closure (an unnamed function object capable of capturing variables in scope).
    //[captures] front-attr(optional) specs except (optional)  back - attr (optional)trailing (optional)contract - specs ﻿(optional){body}
    /*
    [capture](parameters) -> return_type {
        body
    };
     */
    std::vector<int>
        values = {1, 5, 6, 8};

    auto lambda = [](int value)
    { std::cout << "Value:" << value << std::endl; };
    //
    int a = 3, b = 4;
    auto sum = [&a, &b]()
    {
        a++;
        b++;
        std::cout << "SUM:" << a + b << std::endl;
    };

    sum();

    // if you pass it by value it is not mutable
    // inorder to take make it mutable  add mutable

    auto multiply = [a, b]() mutable
    {
        a += 8; // without mutable key it won't work
        b += 6;
        std::cout << "Multiply: " << a * b << std::endl;
    };
    multiply();
    forEach(values, lambda);
}