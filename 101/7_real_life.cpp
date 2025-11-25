#include <iostream>

using namespace std;

int main(){
    bool is_raining;
    cout<<"Is it raining today? (1 for yes, 0 for no): ";
    cin>>is_raining;

    if(is_raining){
        cout<<"Don't forget to take an umbrella!"<<endl;
    } else {
        cout<<"Have a great sunny day!"<<endl;
    }

    return 0;
}