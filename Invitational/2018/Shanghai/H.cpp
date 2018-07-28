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
#define lson k*2+1
#define rson k*2+2
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxv = 2019;
const int mod = 2018;
const int maxn = 5e4+10;
bool vis[maxv], inc[maxv];
struct Node
{
    int sum, len, pos, tag;
    bool inc;
    int v[6];
}tr[maxn*4];
int val[maxn];

void init()
{
    for(int i = 0; i < maxv; i++)inc[i] = 1;
    for(int i = 0; i < maxv; i++){
        if(!vis[i]){
            vis[i] = 1;
            int now = i*i%mod;
            while(!vis[now]){
                vis[now] = 1;
                now = now*now%mod;
            }
            for(int j = i; j != now; j = j*j%mod)inc[j] = 0;
        }
    }
}

void pushup(int k)
{
    tr[k].sum = tr[lson].sum+tr[rson].sum;
    tr[k].inc = tr[lson].inc&tr[rson].inc;
    if(tr[k].inc){
        tr[k].len = gcd(tr[lson].len, tr[rson].len);
        tr[k].pos = 0;
        for(int i = 0, u = tr[lson].pos, v = tr[rson].pos; i < tr[k].len; i++){
            tr[k].v[i] = tr[lson].v[u]+tr[rson].v[v];
            u = (u+1)%tr[lson].len;
            v = (v+1)%tr[rson].len;
        }
    }
}

void build_circle(int k)
{
    tr[k].inc = 1;
    int &len = tr[k].len;
    for(int i = tr[k].sum; !len || i != tr[k].sum; i = i*i%mod){
        tr[k].v[len++] = i;
    }
}

void build(int k, int l, int r)
{
    tr[k].sum = tr[k].len = tr[k].pos = tr[k].tag = tr[k].inc = 0;
    if(l == r-1){
        tr[k].sum = val[l];
        if(inc[val[l]])build_circle(k);
        return;
    }
    int m = (l+r)>>1;
    build(lson, l, m);
    build(rson, m, r);
    pushup(k);
}

void pushdown(int k, int l, int r)
{
    if(tr[k].tag && l != r-1){
        int &tag = tr[k].tag;
        tr[lson].pos = (tr[lson].pos+tag)%tr[lson].len;
        tr[rson].pos = (tr[rson].pos+tag)%tr[rson].len;
        tr[lson].tag += tag;
        tr[rson].tag += tag;
        tag = 0;
    }
}

void update(int a, int b, int k, int l, int r)
{
    //printf("update(%d,%d,%d,%d,%d)\n", a, b, k, l, r);
    //fflush(stdout);
    if(a >= r || b <= l)return;
    else if(a <= l && b >= r && tr[k].inc){
        int &pos = tr[k].pos;
        pos = (pos+1)%tr[k].len;
        tr[k].sum = tr[k].v[pos];
        tr[k].tag++;
        return;
    }
    else if(l == r-1){
        tr[k].sum = tr[k].sum*tr[k].sum%mod;
        if(inc[tr[k].sum])build_circle(k);
        return;
    }
    pushdown(k, l, r);
    int m = (l+r)/2;
    update(a, b, lson, l, m);
    update(a, b, rson, m, r);
    pushup(k);
}

int query(int a, int b, int k, int l, int r)
{
    //printf("query(%d,%d,%d,%d,%d)\n", a, b, k, l, r);
    if(a >= r || b <= l)return 0;
    else if(a <= l && b >= r)return tr[k].sum;
    pushdown(k, l, r);
    int m = (l+r)/2;
    int v1 = query(a, b, lson, l, m);
    int v2 = query(a, b, rson, m, r);
    return v1+v2;
}

int main()
{
    init();
    int T, kase = 1; 
    sc(T);
    while(T--){
        printf("Case #%d:\n", kase++);
        int n; sc(n);
        for(int i = 0; i < n; i++)sc(val[i]);
        build(0, 0, n);
        int q; sc(q);
        for(int i = 0; i < q; i++){
            char s[2];
            int l, r;
            scanf("%s%d%d", s, &l, &r);
            if(s[0] == 'Q'){
                int ans = query(l-1, r, 0, 0, n);
                printf("%d\n", ans);
            }
            else update(l-1, r, 0, 0, n);
        }   
    }
    return 0;
}


