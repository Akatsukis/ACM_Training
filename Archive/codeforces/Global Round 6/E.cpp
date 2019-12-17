#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
int a[maxn], b[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ans += a[i];
    }
    map<pair<int, int>, int> mp;
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int s, t, u;
        scanf("%d%d%d", &s, &t, &u);
        pair<int, int> p = make_pair(s, t);
        if(mp.count(p)) {
            int id = mp[p];
            if(b[id] <= a[id]) ans++;
            b[id]--;
        }
        if(u == 0) {
            mp.erase(p);
        }
        else {
            mp[p] = u;
            b[u]++;
            if(b[u] <= a[u]) ans--;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

