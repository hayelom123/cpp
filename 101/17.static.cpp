

// static definition in C++

// there are 2 types of static
// 1. internal static
// 2. external static

// internal static variable retains its value between function calls
// but is not visible outside the function
// external static variable is visible only within the file it is declared in
// and retains its value between function calls
// external static variables have file scope
// internal static variables have function scope
// internal static variables are initialized only once, the first time the function is called
// external static variables are initialized only once, when the program starts
// internal static variables are stored in the data segment of the program
// external static variables are also stored in the data segment of the program
// internal static variables are not thread-safe
// external static variables are also not thread-safe
// internal static variables can be used to implement function-level singletons
// external static variables can be used to implement file-level singletons
// internal static variables can be used to count function calls
// external static variables can be used to count function calls across multiple files
// internal static variables can be used to cache function results
// external static variables can be used to cache results across multiple files
// internal static variables can be used to maintain state between function calls
// external static variables can be used to maintain state across multiple files
// internal static variables can be used to implement lazy initialization
// external static variables can be used to implement lazy initialization across multiple files
// internal static variables can be used to reduce memory usage
// external static variables can be used to reduce memory usage across multiple files

#include <iostream>

using namespace std;

static int countFunctionCalls()
{
    static int count = 0; // internal static variable
    count++;
    return count;
}

int main()
{
    cout << "Function called " << countFunctionCalls() << " times." << endl;
    cout << "Function called " << countFunctionCalls() << " times." << endl;
    cout << "Function called " << countFunctionCalls() << " times." << endl;

    return 0;
}