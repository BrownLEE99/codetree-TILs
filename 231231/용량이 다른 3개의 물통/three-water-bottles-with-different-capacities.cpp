#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> bucket;
int main() {

    for(int i = 0; i < 3; i ++){
        int a,b;
        cin >> a >> b;
        bucket.push_back({a,b});
    }
    int cnt = 0;
    int totalCnt = 0;
    while(true) {
        totalCnt++;
        int next = (cnt+1)%3;
        int nextLimit = bucket[next].first;
        // 넣을 수 있는 양
        int nextLast = bucket[next].first - bucket[next].second;
        if(nextLast > 0){
            if(nextLast >= bucket[cnt].second) {
                bucket[next].second += bucket[cnt].second;
                bucket[cnt].second = 0;
            } else {
                int gap = bucket[cnt].second - nextLast;
                bucket[next].second = bucket[next].first;
                bucket[cnt].second = gap;
            }
        }
        cnt = next;
        if(totalCnt ==  304) break;
    }
    for(int i = 0; i < 3; i++){
        cout << bucket[i].second << "\n";
    }
    return 0;
}