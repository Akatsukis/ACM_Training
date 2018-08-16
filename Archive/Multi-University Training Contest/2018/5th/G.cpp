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
#define lson k*2+1
#define rson k*2+2
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 1e5+10;
int mx[maxn*4], mn[maxn*4], tag[maxn*4];
unsigned X, Y, Z;

void build(int k, int l, int r)
{
    mx[k] = mn[k] = tag[k] = 0;
    if(l == r-1)return;
    int m = (l+r)>>1;
    build(lson, l, m);
    build(rson, m, r);
}

void pushdown(int k, int l, int r)
{
    if(l== r-1)return;
    if(tag[k]){
        mx[lson] = mn[lson] = mx[rson] = mn[rson] = tag[k];
        tag[lson] = tag[rson] = tag[k];
        tag[k] = 0;
    }
}

void update(int a, int b, int k, int l, int r, int val)
{
    if(a >= r || b <= l || mn[k] >= val)return;
    if(a <= l && b >= r && mx[k] <= val){
        mx[k] = mn[k] = val;
        tag[k] = val;
        return;
    }
    int m = (l+r)>>1;
    pushdown(k, l, r);
    update(a, b, lson, l, m, val);
    update(a, b, rson, m, r, val);
    mx[k] = max(mx[lson], mx[rson]);
    mn[k] = min(mn[lson], mn[rson]);
}

int query(int a, int k, int l, int r)
{
    if(l == r-1)return mx[k];
    pushdown(k, l, r);
    int m = (l+r)>>1;
    if(a < m)return query(a, lson, l, m);
    else return query(a, rson, m, r);
}

unsigned RNG61()
{
    X = X^(X<<11);
    X = X^(X>>4);
    X = X^(X<<5);
    X = X^(X>>14);
    unsigned W = X^(Y^Z);
    X = Y; Y = Z; Z = W;
    return Z;
}

int main()
{
    int T; sc(T);
    while(T--){
        int n, m;
        scanf("%d%d%u%u%u", &n, &m, &X, &Y, &Z);
        build(0, 0, n);
        for(int i = 0; i < m; i++){
            int l = RNG61()%n, r = RNG61()%n, val = RNG61()%(1<<30);
            if(l > r)swap(l, r);
            //printf("%d, %d, %d\n", l, r, val);
            update(l, r+1, 0, 0, n, val);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= (ll)(i+1)*query(i, 0, 0, n);
        }
        printf("%lld\n", ans);
    }
    return 0;
}


