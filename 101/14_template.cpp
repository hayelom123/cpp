#include <iostream>
#include <string>

using namespace std;


// Template function to find maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T> 
T add(T x, T y){
    return x+y;
};

// class template example

template <typename T> 
class Box {
   private:
    T value;
   public:
    Box(T l) : value(l) {}

    void display(){
        cout<<"value: "<<value<<endl;
    }
    
    T getValue() {
        return value;
    }
};



int main() {
        cout<<"-------------------Templates------------------------"<<endl;
    // Testing with integers
    int int1 = 10, int2 = 20;
    cout << "Max of " << int1 << " and " << int2 << " is " << findMax(int1, int2) << endl;

    // Testing with doubles
    double double1 = 10.5, double2 = 20.3;
    cout << "Max of " << double1 << " and " << double2 << " is " << findMax(double1, double2) << endl;
    
    // Testing with characters
    char char1 = 'A', char2 = 'B';
    cout << "Max of " << char1 << " and " << char2 << " is " << findMax(char1, char2) << endl;

    cout<<"-------------------------------------------"<<endl;

    // Testing add function
    cout << "Sum of " << int1 << " and " << int2 << " is " << add(int1, int2) << endl;
    cout << "Sum of " << double1 << " and " << double2 << " is " << add(double1, double2) << endl;
    cout << "Sum of '" << char1 << "' and '" << char2 << "' is '" << add(char1, char2) << "'" << endl;  

    cout<<"-------------------class template------------------------"<<endl;

     Box<int> box(10);
     box.display();

    cout<<"-------------------------------------------"<<endl;

    cout<<endl<<endl<<endl;

    return 0;
}
