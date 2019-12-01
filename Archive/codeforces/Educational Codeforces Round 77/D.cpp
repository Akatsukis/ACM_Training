#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
int a[maxn];
int l[maxn], r[maxn], d[maxn];
int n, m, k, t;

bool check(int mid) {
    vector<pair<int, int>> seg;
    for(int i = 0; i < k; i++) {
        if(d[i] > mid) {
            seg.push_back(make_pair(l[i], r[i]));
        }
    }
    sort(seg.begin(), seg.end());
    int ans = 0, cur = 0;
    for(int i = 0; i < (int)seg.size();) {
        ans += seg[i].first-1-cur;
        int j = 1, mx = seg[i].second;
        while(i+j < (int)seg.size() && seg[i+j].first <= mx) {
            mx = max(mx, seg[i+j].second);
            j++;
        }
        ans += 3*(mx-seg[i].first+1);
        cur = mx;
        i += j;
    }
    ans += (n+1)-cur;
    return ans <= t;
}

int main()
{
    scanf("%d%d%d%d", &m, &n, &k, &t);
    for(int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+m, greater<int>());
    for(int i = 0; i < k; i++) {
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
    }
    int low = 0, up = maxn, cur = 0;
    while(low <= up) {
        int mid = (low+up)/2;
        if(check(mid)) {
            cur = mid;
            up = mid-1;
        }
        else low = mid+1;
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        if(a[i] >= cur) ans++;
    }
    printf("%d\n", ans);
    return 0;
}

