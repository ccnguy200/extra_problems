#include <iostream>
using namespace std;

void rotateLeft (int d, int arr[], int n) {
  int * holder = new int[n];
  for (int i = 0; i < n; i++) {
    holder[i] = arr[(i + d) % n];
  }
  
  for (int i = 0; i < n; i++) {
    arr[i] = holder[i];
  }
  
  delete[] holder;
}

int main() 
{
    int n, d;
    cin >> n >> d;
    
    int * array = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> array[i];
    }
    
    rotateLeft (d, array, n);
    
    for (int i = 0; i < n; i++) {
      cout << array[i] << " ";
    }
    cout << endl;
    
    delete[] array;

    return 0;
}