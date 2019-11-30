#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i+1;
    }
    sort(a.begin(), a.end(), greater<pair<int, int> >());
    long long ans = 0;
    vector<int> order;
    for(int i = 0; i < n; i++) {
        ans += a[i].first*i+1;
        order.push_back(a[i].second);
    }
    printf("%lld\n", ans);
    for(int i = 0; i < n; i++) {
        printf("%d%c", order[i], " \n"[i==n-1]);
    }
    return 0;
}
