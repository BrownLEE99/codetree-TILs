#include <iostream>
#include <string>
using namespace std;
int main() {
    string a,b,c;
    cin >> a;
    b = a.substr(4,4);
    c = a.substr(9,4);
    cout << a.substr(0,3) << "-" << c << "-" << b;
    return 0;
}