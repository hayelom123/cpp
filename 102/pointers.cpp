#include <iostream>

int main()
{

    std::cout << "God please forgive me for I have sinned." << std::endl;
    std::cout << "I am sorry for all my wrongdoings." << std::endl;
    std::cout << "Help me to be a better person." << std::endl;

    int *pNum = nullptr; // Initialize pointer to nullptr

    std::cout << "The value of pNum is: " << pNum << std::endl;
    std::cout << "The address of pNum is: " << &pNum << std::endl;
    std::cout << "===============================================" << std::endl;
    int num = 42;
    pNum = &num; // Assign the address of num to pNum
    *pNum = 99;  // Dereference pNum to change the value of num
    std::cout << "The value of pNum after assignment is: " << pNum << std::endl;
    std::cout << "The value pointed to by pNum is: " << *pNum << std::endl;
    std::cout << "The address of num is: " << &num << std::endl;
    std::cout << "The address of pNum is: " << &pNum << std::endl;
    std::cout << "===============================================" << std::endl;

    int anotherNum(100);
    std::cout << "The value of anotherNum is: " << anotherNum << std::endl;

    std::cout << "=============================================" << std::endl;
    // different pointer sizes on different systems
    std::cout << "The size of double is: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "The size of double* is: " << sizeof(double *) << " bytes" << std::endl;
    std::cout << "The size of char is: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "The size of char* is: " << sizeof(char *) << " bytes" << std::endl;
    std::cout << "The size of int is: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "The size of int* is: " << sizeof(int *) << " bytes" << std::endl;
    std::cout << "The size of float is: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "The size of float* is: " << sizeof(float *) << " bytes" << std::endl;
    std::cout << "=============================================" << std::endl;

    int *ptr1 = &anotherNum, another; // only ptr1 is a pointer to int, another is a regular int
    double pDouble = 3.14;
    double *ptr2 = &pDouble, third; // only ptr2 is a pointer to double, third is a regular double
    int *ptr3, ptr4;                // only ptr3 is a pointer to int, ptr4 is a regular int
    ptr3 = ptr1;

    std::cout << "The value of ptr1 is: " << ptr1 << std::endl;
    std::cout << "The value of ptr2 is: " << ptr2 << std::endl;
    std::cout << "The value of ptr3 is: " << ptr3 << std::endl;
    std::cout << "=============================================" << std::endl;

    std::cout << "The address of ptr1 is: " << &ptr1 << std::endl;
    std::cout << "The address of ptr2 is: " << &ptr2 << std::endl;
    std::cout << "The address of ptr3 is: " << &ptr3 << std::endl;

    std::cout << "=============================================" << std::endl;
    std::cout << "The value of ptr1 is: " << *ptr1 << std::endl;
    std::cout << "The value of ptr2 is: " << *ptr2 << std::endl;
    std::cout << "The value of ptr3 is: " << *ptr3 << std::endl;

    std::cout << "=============================================" << std::endl;

    // string literal pointer
    const char *message = "Hello, World!";
    message = "Goodbye, World!";
    // *message = 'g'; // This will cause a runtime error (segmentation fault) because string literals are immutable
    std::cout << "The message is: " << message << std::endl;
    std::cout << "The address of message is: " << &message << std::endl;
    std::cout << "The first character of message is: " << *message << std::endl;

    // pointer array
    int values[] = {10, 20, 30};
    int *pValues = &values[0]; // Pointer to the first element of the array
    std::cout << "The values in the array are: " << std::endl;
    std::cout << "pValue: " << *pValues << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Value " << i << ": " << *(pValues + i) << std::endl;
    }

    std::cout << "=============================================" << std::endl;
    std::cout << "Enter your Name: ";
    char name[] = "unkown";
    // char *pName = "hey";
    std::cin >> name; // This is unsafe and can lead to undefined behavior
    std::cout << "Hello, " << name << "!" << std::endl;

    // int values[] = {10, 20, 30};
    // int *pValues[] = {&values[0], &values[1], &values[2]};
    // std::cout << "The values in the pointer array are: " << std::endl;
    // for (int i = 0; i < 3; ++i)
    // {
    //     std::cout << "Value " << i << ": " << *pValues[i] << std::endl;
    // }

    return 0;
}