#include <iostream>

void hey()
{
    std::cout << "Hello from hey function!" << std::endl;
}
int main()
{
    auto funcPtr = hey; // pointer to function hey
    funcPtr();          // call the function using the function pointer
    return 0;
}