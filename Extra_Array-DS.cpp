#include <iostream>
using namespace std;

void reverseArray (int arr[], int size) {
  for (int i = size-1; i >=0; i--) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() 
{
    int size;
    cin >> size;
    
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
      cin >> array[i];
    }
      
    reverseArray (array, size);
    
    delete[] array;
    
    return 0;
}