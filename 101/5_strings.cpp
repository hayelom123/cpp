#include<iostream>
#include<string>

using namespace std;

int main(){
    string first_name;
    cout<<"Enter your first name: "<<endl;

    cin>>first_name;
    first_name += " from C++ input";

    cout<<"Hello "<<first_name<<", have a nice day!"<<endl;
    return 0;
}