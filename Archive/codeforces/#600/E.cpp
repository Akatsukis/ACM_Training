#include <bits/stdc++.h>
using namespace std;
#define lson k*2+1
#define rson k*2+2
const int maxn = 1e5+10;
int x[maxn], s[maxn];
int tr[maxn*4];

void build(int k, int l, int r) {
    tr[k] = INT_MAX;
    if(l == r-1) {
        if(l == 0)tr[k] = 0;
        else tr[k] = INT_MAX;
        return;
    }
    int m = (l+r)/2;
    build(lson, l, m);
    build(rson, m, r);
}

void push_down(int k, int l, int r) {
    if(l == r-1)return;
    if(tr[k] != INT_MAX) {
        tr[lson] = min(tr[lson], tr[k]);
        tr[rson] = min(tr[rson], tr[k]);
        tr[k] = INT_MAX;
    }
}

void update(int a, int b, int k, int l, int r, int val) {
    if(a >= r || b <= l) return;
    if(a <= l && b >= r) {
        tr[k] = min(tr[k], val);
        return;
    }
    int m = (l+r)/2;
    push_down(k, l, r);
    update(a, b, lson, l, m, val);
    update(a, b, rson, m, r, val);
}

int query(int a, int k, int l, int r) {
    if(l == r-1)return tr[k];
    int m = (l+r)/2;
    push_down(k, l, r);
    if(a < m) return query(a, lson, l, m);
    else return query(a, rson, m, r);
}

int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &x[i], &s[i]);
    }
    build(0, 0, n+1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int len = abs(x[j]-i);
            int l = max(1, x[j]-len), r = min(n, x[j]+len);
            int val = query(l-1, 0, 0, n+1)+max(0, len-s[j]);
            update(i, r+1, 0, 0, n+1, val);
        }
    }
    printf("%d\n", query(n, 0, 0, n+1));
    return 0;
}

