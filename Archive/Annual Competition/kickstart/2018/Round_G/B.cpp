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
const int maxn = 4e5+10;
const int maxq = 1e5+10;
const int maxa = 1e9+10;
int x[maxn], y[maxn], z[maxn];
int L[maxn], R[maxn], K[maxn];
int a[4], b[4], c[4], mod[4];
int ls[maxq*300], rs[maxq*300];
ll tot[maxq*300], tag[maxq*300];
int n, q, cnt;

int newNode()
{
    int v = ++cnt;
    ls[v] = rs[v] = tot[v] = tag[v] = 0;
    return v;
}

void pushdown(int o, int l, int r)
{
    if(tag[o] && l != r-1){
        int m = (l+r)>>1;
        if(!ls[o])ls[o] = newNode();
        if(!rs[o])rs[o] = newNode();
        tot[ls[o]] += tag[o]*(m-l);
        tot[rs[o]] += tag[o]*(r-m);
        tag[ls[o]] += tag[o];
        tag[rs[o]] += tag[o];
        tag[o] = 0;
    }
}

void update(int a, int b, int &o, int l, int r)
{
    if(!o)o = newNode();
    if(a >= r || b <= l)return;
    if(a <= l && b >= r){
        tot[o] += r-l;
        tag[o]++;
        return;
    }
    int m = (l+r)>>1;
    pushdown(o, l, r);
    update(a, b, ls[o], l, m);
    update(a, b, rs[o], m, r);
    tot[o] = tot[ls[o]]+tot[rs[o]];
}

ll query(int a, int o, int l = 1, int r = maxa)
{
    //printf("a=%d, r=%d\n", a, r);
    if(!o || a >= r)return 0;
    if(l >= a)return tot[o];
    pushdown(o, l, r);
    int m = (l+r)>>1;
    ll ret = query(a, ls[o], l, m)+query(a, rs[o], m, r);
    //printf("[%d,%d)=%lld\n", l, r, ret);
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        cnt = 0;
        sc(n); sc(q);
        scanf("%d%d%d%d%d%d", &x[1], &x[2], &a[1], &b[1], &c[1], &mod[1]);
        scanf("%d%d%d%d%d%d", &y[1], &y[2], &a[2], &b[2], &c[2], &mod[2]);
        scanf("%d%d%d%d%d%d", &z[1], &z[2], &a[3], &b[3], &c[3], &mod[3]);
        for(int i = 3; i <= n; i++){
            x[i] = (1LL*a[1]*x[i-1]+1LL*b[1]*x[i-2]+c[1])%mod[1];
            y[i] = (1LL*a[2]*y[i-1]+1LL*b[2]*y[i-2]+c[2])%mod[2];
        }
        int rt = 0;
        for(int i = 1; i <= n; i++){
            L[i] = min(x[i], y[i])+1;
            R[i] = max(x[i], y[i])+1;
            //printf("(%d,%d)\n", L[i], R[i]);
            update(L[i], R[i]+1, rt, 1, maxa);
        }
        for(int i = 3; i <= q; i++){
            z[i] = (1LL*a[3]*z[i-1]+1LL*b[3]*z[i-2]+c[3])%mod[3];
        }
        ll ans = 0;
        for(int i = 1; i <= q; i++){
            K[i] = z[i]+1;
            int l = 1, r = maxa, val = 0;
            while(l <= r){
                int m = (l+r)>>1;
                //ll tmp = query(m, rt, 1, maxa);
                //printf("m=%d, val=%lld\n", m, tmp);
                if(query(m, rt, 1, maxa) >= K[i]){
                    val = m;
                    l = m+1;
                } 
                else r = m-1;
            }
            //printf("val=%d\n", val);
            ans += 1LL*i*val;
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

