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

    std::vector<int>
        values = {1, 5, 6, 8};

    auto lambda = [](int value)
    { std::cout << "Value:" << value << std::endl; };
    //

    forEach(values, lambda);
}