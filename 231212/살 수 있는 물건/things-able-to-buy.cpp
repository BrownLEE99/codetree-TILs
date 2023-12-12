#include <iostream>
using namespace std;
int main() {
    int money;
    cin >> money;
    string a = (money >= 3000) ? "book" : "mask";
    if(money < 1000) a = "no";
    cout << a;
    return 0;
}