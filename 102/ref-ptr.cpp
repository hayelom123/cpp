
#include <iostream>

using namespace std;

void passByRef(int &ref);
void passByPtr(int *ptr);

// the Difference Between Pass By Pointer and Pass By Pointer Reference (int * and int * &) C++
void modifyByPointer(int *ptr)
{
    if (ptr != nullptr)
    {
        *ptr += 5; // Modify the value pointed to by ptr
    }
}
void modifyByPointerRef(int *&ptrRef)
{
    static int newValue = 50; // Static to ensure it remains valid after function ends
    ptrRef = &newValue;       // Reassign ptrRef to point to a new value
}

int main()
{
    return 0;
}
void passByRef(int &ref)
{
    ref += 10; // Modify the original variable
}
void passByPtr(int *ptr)
{
    if (ptr != nullptr)
    {
        *ptr += 10; // Modify the original variable
    }
}

/*
Reference = a permanent nickname

You cannot make the nickname refer to someone else.

The person must exist.

Pointer = a mobile phone contact

It can be empty (no number).

You can change the number anytime.

You can delete the contact.
*/
/*
| Use a **Reference** when…         | Use a **Pointer** when…                             |
| --------------------------------- | --------------------------------------------------- |
| The object must exist (not null)  | The object can be null / optional                   |
| You don’t want to check for null  | You need nullptr meaning "no object"                |
| You want clean syntax (`obj.x`)   | You need dynamic memory (new/delete)                |
| You don’t want to reassign it     | You want to reassign which object it points to      |
| Use mostly in function parameters | Use in low-level systems (drivers, data structures) |

 */

/*

🔥 Key Difference (Super Simple)
| Feature                                         | `int *p` (pass pointer)        | `int *&p` (pass pointer reference) |
| ----------------------------------------------- | ------------------------------ | ---------------------------------- |
| Can change the value `*p`                       | ✔ Yes                          | ✔ Yes                              |
| Can reassign pointer (change what it points to) | ❌ No (affects only local copy) | ✔ Yes (affects caller's pointer)   |
| Pointer inside function is a copy?              | ✔ Yes                          | ❌ No                               |
| Can set caller’s pointer to nullptr?            | ❌ No                           | ✔ Yes                              |

*/