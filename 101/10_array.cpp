#include <iostream>
using namespace std;

int main(){
   
  const int size = 5;
   int arr[size] = {10, 20, 30, 40, 50};
   for(int i=0;i<size;i++)
     cout<<arr[i]<<", ";

     cout << endl;

     const int arr_size= sizeof(arr)/sizeof(arr[0]);

      //find size of array
        cout << "Size of array: " << arr_size << endl;

    return 0;
}