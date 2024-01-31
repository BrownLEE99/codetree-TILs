#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L[200001];
int main() {
    int n;
    cin >> n;
    vector <pair<int,int>> v;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        L[a]++;
        L[b]--;
    }
    int answer = 0;
    int tmp =0;
    for(int i = 1;i<=200000;i++){
        tmp += L[i];
        answer = max(answer,tmp);
    }
    cout << answer;
    return 0;
}