#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int main() {
    int a,b;
    string str;
    cin >> a >> str >> b;
    int number = 0;
    for(int i = 0;i<str.length();i++){
        char c = str[i];
        int n;
        if(c >= 'a' && c <= 'z') {
            n = 10 + c - 'a';
        }else {
            n = c - '0';
        }
        int result = (int)pow(a,str.length() - i -1);
        number += result*n;
    }
    int mok,last;
    string answer = "";
    while(number > b) {
        mok = number / b;
        last = number % b;
        char c = last + '0';
        if(last >= 10) {
            c = 'a' + (last - 10);
        }
        answer = c + answer;
        number = mok;
    }
    char c;
    if(mok >= 10) c = 'a' + (mok - 10);
    else c = '0' + mok;
    answer = c + answer;
    cout << answer;
    return 0;
}