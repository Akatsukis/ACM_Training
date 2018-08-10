#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int INF = 1e5+1;
const int maxn = 5e6+10;
int rt[maxn], ls[maxn], rs[maxn];
int tr[maxn], tag[maxn];
int cnt;

void pushdown(int k, int l, int r)
{
    if(tag[k] && l != r-1){
        if(!ls[k])ls[k] = ++cnt;
        tr[ls[k]] = max(tr[ls[k]], tag[k]);
        tag[ls[k]] = max(tag[ls[k]], tag[k]);
        if(!rs[k])rs[k] = ++cnt;
        tr[rs[k]] = max(tr[rs[k]], tag[k]);
        tag[rs[k]] = max(tag[rs[k]], tag[k]);
        tag[k] = 0;
    }
}

void update(int a, int b, int &k, int l, int r, int val)
{
    if(a >= r || b <= l)return;
    if(!k)k = ++cnt;
    if(a <= l && b >= r){
        tag[k] = max(tag[k], val);
        tr[k] = max(tr[k], val);
        return;
    }
    pushdown(k, l, r);
    int m = (l+r)>>1;
    update(a, b, ls[k], l, m, val);
    update(a, b, rs[k], m, r, val);
    tr[k] = max(tr[ls[k]], tr[rs[k]]);
}

int query(int a, int b, int k, int l, int r)
{
    if(!k || a >= r || b <= l)return 0;
    if(a <= l && b >= r)return tr[k];
    pushdown(k, l, r);
    int m = (l+r)>>1;
    int v1 = query(a, b, ls[k], l, m);
    int v2 = query(a, b, rs[k], m, r);
    return max(v1, v2);
}

int main()
{
    int n, m;
    sc(n); sc(m);
    int ans = 0;
    for(int i = 0; i < m; i++){
        int u, v, w;
        sc(u); sc(v); sc(w);
        int val = query(0, w, rt[u], 0, INF)+1;
        update(w, INF, rt[v], 0, INF, val);
        ans = max(ans, val);
    }
    printf("%d\n", ans);
    return 0;
}


