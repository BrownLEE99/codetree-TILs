#include <iostream>
using namespace std;
int L[100001];
int main() {
    int n,s;
    cin >> n >> s;
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin >> L[i];
        sum += L[i];
    }
    int ans = 987654321;
    if(sum < s) {
        cout << -1;
    } else{
        int j = -1;
        int sum_val = 0;
        for(int i = 0;i<n;i++){
            while(j + 1 < n && sum_val < s){
                sum_val += L[j+1];
                j++;
            }
            if(sum_val < s) break;
            ans = min(ans,j - i + 1);
            sum_val -= L[i];
        }
        if(ans == 987654321) cout << -1;
        else cout << ans;
    }
    return 0;
}