#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
int p[maxn], pos[maxn];
long long rev[maxn], num[maxn];
int n;

void add(int x, int val, long long tr[]) {
    while(x <= n) {
        tr[x] += val;
        x += x&-x;
    }
}

long long query(int x, long long tr[]) {
    if(!x) return 0;
    long long ret = 0;
    while(x) {
        ret += tr[x];
        x -= x&-x;
    }
    return ret;
}

int push(int x) {
    if(pq1.empty() || x < pq1.top()) pq1.push(x);
    else pq2.push(x);
    while(pq1.size() > pq2.size()) {
        int y = pq1.top(); pq1.pop();
        pq2.push(y);
    }
    while(pq2.size() > pq1.size()) {
        int y = pq2.top(); pq2.pop();
        pq1.push(y);
    }
    int tot = pq1.size()+pq2.size();
    if(tot%2) return pq1.top();
    else return (pq1.top()+pq2.top())/2;
}

long long calc(int l, int r) {
    return 1LL*(l+r)*(r-l+1)/2;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += query(n, rev)-query(pos[i], rev);
        add(pos[i], 1, rev);
        add(pos[i], pos[i], num);
        int mid = push(pos[i]);
        int l = (i+1)/2, r = i-l;
        //printf("l=%d, r=%d, mid=%d\n", l, r, mid);
        long long l_sum = calc(mid-l+1, mid)-query(mid, num);
        long long r_sum = (query(n, num)-query(mid, num))-calc(mid+1, mid+r);
        //printf("%lld, %lld\n", l_sum, r_sum);
        long long cur = l_sum+r_sum;
        printf("%lld%c", ans+cur, " \n"[i==n]);
    }
    return 0;
}

