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

    // unique_ptr example
    {
        cout << "unique_ptr example:" << endl;
        unique_ptr<int> ptr1(new int(42));  // create a unique_ptr that owns an integer
        cout << "Value: " << *ptr1 << endl; // access the value
        // unique_ptr automatically deallocates the memory when it goes out of scope
    } // ptr1 goes out of scope here
    cout << "unique_ptr has been deallocated." << endl;
    // shared_ptr example
    {
        cout << "shared_ptr example:" << endl;
        shared_ptr<int> ptr2(new int(100)); // create a shared_ptr that owns an integer
        {
            shared_ptr<int> ptr3 = ptr2; // create another shared_ptr that shares ownership
            cout << "Value from ptr2: " << *ptr2 << endl;
            cout << "Value from ptr3: " << *ptr3 << endl;
            cout << "Reference count: " << ptr2.use_count() << endl; // show reference count
        } // ptr3 goes out of scope here
        cout << "Reference count after ptr3 goes out of scope: " << ptr2.use_count() << endl;
    } // ptr2 goes out of scope here
    cout << "shared_ptr has been deallocated." << endl;

    // weak_ptr example
    {
        cout << "weak_ptr example:" << endl;
        shared_ptr<int> ptr4(new int(200)); // create a shared_ptr that owns an integer
        weak_ptr<int> wptr = ptr4;          // create a weak_ptr that references the shared_ptr

        cout << "Value from shared_ptr: " << *ptr4 << endl;
        cout << "Reference count: " << ptr4.use_count() << endl; // show reference count

        if (auto sptr = wptr.lock()) // attempt to get a shared_ptr from weak_ptr
        {
            cout << "Value from weak_ptr: " << *sptr << endl;
        }
        else
        {
            cout << "The object has been deallocated." << endl;
        }
    } // ptr4 goes out of scope here
    cout << "weak_ptr example completed." << endl;

    return 0;
}