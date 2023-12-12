#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    int f = a+b;
    int s = a-b;
    double result = (double)f/s;
    cout << fixed;
    cout.precision(2);
    cout << ceil(result*100) / (double)100;
    return 0;
}