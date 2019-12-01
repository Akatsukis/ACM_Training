#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6+10;
int a[maxn];

int get(int &id) {
    if(a[id] == -1) id--;
    return a[id--];
}
 
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] == -1) {
            for(int j = i-1; j >= 0; j--) a[j] = 0;
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    long long ans = 0;
    int id = n-1;
    for(int i = n/2; i; i >>= 1) {
        pq.push(get(id));
        ans += pq.top(); pq.pop();
        for(int j = 1; j < i; j++) {
            pq.push(get(id));
        }
    }
    printf("%lld\n", ans);
    return 0;
}
 
