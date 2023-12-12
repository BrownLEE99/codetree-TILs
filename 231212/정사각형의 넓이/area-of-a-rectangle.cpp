#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    if(a >= 5) {
        cout << a*a;
    } else{
        cout << a*a << "\ntiny";
    }
    return 0;
}