#include <iostream>

using namespace std;

int main(){
    int total_items=50;

    double price_per_item=19.99;

    cout<<"Total items available in the grocery store: "<<total_items<<endl;
    cout<<"Price per item: $"<<price_per_item<<endl;
    double total_cost=total_items * price_per_item;
    cout<<"Total cost of all items: $"<<total_cost<<endl;
}