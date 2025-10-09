#include <iostream>
#include <string>
using namespace std;

long long superDigit (long long x) {
  if (x < 10) { return x; }
  long long sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return superDigit(sum);
}

int main() 
{
    string n;
    int k;
    cout << "Please enter your integer: " << endl;
    cin >> n;
    cout << "Please enter your multiplier: " << endl;
    cin >> k;
    
    long long singleSum = 0;
    for (char c : n) {
      singleSum += c- '0';
    }
    
    long long finalSum = singleSum * k;
    
    cout << superDigit(finalSum) << endl;
    
    return 0;
}