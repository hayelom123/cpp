#include <iostream>

void hey()
{
    std::cout << "Hello from hey function!" << std::endl;
}
void helloName(std::string name)
{
    std::cout << "Hello: " << name << std::endl;
}
int main()
{

    auto funcPtr = hey; // pointer to function hey
    funcPtr();          // call the function using the function pointer

    void (*someFunName)(/*parametrs here*/);
    someFunName = hey;
    someFunName();

    void (*helloHayelom)(std::string name) = helloName;
    helloHayelom("Hayelom Kiros");
    return 0;
}