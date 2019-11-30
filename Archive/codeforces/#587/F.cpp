#include <bits/stdc++.h>
using namespace std;
#define lson k*2+1
#define rson k*2+2
constexpr int maxn = 2e5+10;
char s[maxn];
long long tr[maxn*4], tag[maxn*4];

void build(int k, int l, int r) {
    tag[k] = LONG_LONG_MAX;
    if(l == r-1) {
        if(!l) tr[k] = 0;
        else tr[k] = LONG_LONG_MAX;
        return;
    }
    int m = (l+r)/2;
    build(lson, l, m);
    build(rson, m, r);
}

void push_down(int k, int l, int r) {
    if(l != r-1 && tag[k] != LONG_LONG_MAX) {
        tag[lson] = min(tag[lson], tag[k]);
        tag[rson] = min(tag[rson], tag[k]);
        tr[lson] = min(tr[lson], tag[k]);
        tr[rson] = min(tr[rson], tag[k]);
        tag[k] = LONG_LONG_MAX;
    }
}

void update(int a, int b, int k, int l, int r, long long val) {
    if(a >= r || b <= l) return;
    if(a <= l && b >= r) {
        tr[k] = min(tr[k], val);
        tag[k] = min(tag[k], val);
        return;
    }
    push_down(k, l, r);
    int m = (l+r)/2;
    update(a, b, lson, l, m, val);
    update(a, b, rson, m, r, val);
}

long long query(int a, int k, int l, int r) {
    if(l == r-1) return tr[k];
    int m = (l+r)/2;
    push_down(k, l, r);
    if(a < m) return query(a, lson, l, m);
    else return query(a, rson, m, r);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s+1);
    build(0, 0, n+1);
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0') {
            long long pre = query(i-1, 0, 0, n+1);
            update(i, i+1, 0, 0, n+1, pre+i);
        }
        else {
            long long pre = query(max(0, i-k-1), 0, 0, n+1);
            int l = max(1, i-k), r = min(n, i+k);
            update(l, r+1, 0, 0, n+1, pre+i);
        }
    }
    printf("%lld\n", query(n, 0, 0, n+1));
    return 0;
}

