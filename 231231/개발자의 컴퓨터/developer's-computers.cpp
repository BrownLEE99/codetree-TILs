#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L[1001];
int main() {
    int n;
    cin >> n;
    int maxNeed = 0;
    for(int i = 0;i<n;i++){
        int s,t,b;
        cin >> s >> t >> b;
        for(int j = s; j <= t;j++){
            L[j] += b;
            maxNeed = max(maxNeed,L[j]);
        }
    }
    cout << maxNeed;
    return 0;
}