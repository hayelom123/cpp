#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, Smart Pointer!" << endl;
    // smart pointer is an abstract data type that simulates a pointer while providing additional features
    // such as automatic memory management and reference counting to prevent memory leaks and dangling pointers.
    // smart pointers are typically implemented as template classes in C++ and are part of the C++ Standard Library.
    // smart pointers are used to manage the lifetime of dynamically allocated objects and ensure proper deallocation when they are no longer needed.
    // there are several types of smart pointers in C++ including unique_ptr, shared_ptr, and weak_ptr.
    // unique_ptr is a smart pointer that owns a dynamically allocated object exclusively and automatically deallocates it when it goes out of scope.
    // shared_ptr is a smart pointer that allows multiple pointers to share ownership of a dynamically allocated object and uses reference counting to manage the object's lifetime.
    // weak_ptr is a smart pointer that provides a non-owning reference to a dynamically allocated object managed by a shared_ptr, allowing access to
    // the object without affecting its reference count.
    // smart pointers help prevent memory leaks and dangling pointers by automatically managing the memory of dynamically allocated objects.
    // they provide a safer and more convenient way to handle dynamic memory in C++ compared to raw pointers.
    // example of smart pointer usage in C++

    return 0;
}