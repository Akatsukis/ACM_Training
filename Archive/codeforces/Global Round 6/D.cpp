#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5+10;
long long debt[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        debt[u] += d;
        debt[v] -= d;
    }
    vector<vector<long long>> ans;
    int from = 1;
    for(int i = 1; i <= n; i++) {
        while(debt[i] > 0) {
            while(from <= n && debt[from] >= 0) from++;
            long long x = min(debt[i], -debt[from]);
            debt[i] -= x;
            debt[from] += x;
            ans.push_back({i, from, x});
        }
    }
    printf("%d\n", (int)ans.size());
    for(auto vec: ans) {
        printf("%lld %lld %lld\n", vec[0], vec[1], vec[2]);
    }
    return 0;
}

