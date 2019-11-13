#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define lson k*2+1
#define rson k*2+2
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 2e5+10;
int a[maxn];
int tr[maxn*4];
int mx[maxn];
struct hero {
    int p, s;
    hero(){}
    hero(int p, int s): p(p), s(s){}
    bool operator < (const hero &rhs) {
        if(p != rhs.p) return p < rhs.p;
        else return s < rhs.s;
    }
}hr[maxn];
int n, m;

void build(int k, int l, int r) {
    if(l == r-1) {
        tr[k] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(lson, l, mid);
    build(rson, mid, r);
    tr[k] = max(tr[lson], tr[rson]);
}

int query(int a, int b, int k, int l, int r) {
    if(a >= r || b <= l) return 0;
    if(a <= l && b >= r) return tr[k];
    int mid = (l+r)/2;
    int v1 = query(a, b, lson, l, mid);
    int v2 = query(a, b, rson, mid, r);
    return max(v1, v2);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int maxPw = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            maxPw = max(maxPw, a[i]);
        }
        build(0, 0, n);
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &hr[i].p, &hr[i].s);            
        }
        sort(hr, hr+m);
        for(int i = m-1; i >= 0; i--) {
            if(i == m-1) mx[i] = hr[i].s;
            else mx[i] = max(mx[i+1], hr[i].s);
        }
        if(hr[m-1].p < maxPw) {
            printf("-1\n");
            continue;
        }
        int pos = 0, ans = 0;
        while(pos < n) {
            ans++;
            int l = 1, r = n-pos, cur = 0;
            while(l <= r) {
                int mid = (l+r)/2;
                int maxSeg = query(pos, pos+mid, 0, 0, n);
                int id = lower_bound(hr, hr+m, hero(maxSeg, 0))-hr;
                if(mx[id] >= mid) {
                    cur = mid;
                    l= mid+1;
                }
                else r = mid-1;
            }
            pos = pos+cur;
        }
        printf("%d\n", ans);
    }
    return 0;
}

