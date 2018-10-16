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
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int mod = 1e9+7;
const int maxn = 1e6+10;
ll tr[maxn][2];
ll a[maxn], w[maxn];

void update(int t, int k, int l, int r, int x, int p)
{
    if(l == r-1){
        tr[k][p] += x;
        return;
    }
    int m = (l+r)>>1;
    if(t < m)update(t, lson, l, m, x, p);
    else update(t, rson, m, r, x, p);
    tr[k][p] = tr[lson][p]+tr[rson][p];
}

ll query_sum(int a, int b, int k, int l, int r, int p)
{
    if(a >= r || b <= l)return 0;
    else if(a <= l && b >= r)return tr[k][p];
    int m = (l+r)>>1;
    ll v1 = query_sum(a, b, lson, l, m, p);
    ll v2 = query_sum(a, b, rson, m, r, p);
    return v1+v2;
}

ll query_id(int a, int b, int k, int l, int r, ll tot)
{
    printf("id(%d,%d,%d,%d,%d,%lld)\n", a, b, k, l, r, tot);
    if(l == r-1)return l;
    int m = (l+r)>>1;
    if(tot-tr[lson][0] >= tot)return query_id(a, b, rson, m, r, tot-tr[lson][0]);
    else return query_id(a, b, lson, l, m, tot);
}

int main()
{
    int n, q;
    sc(n); sc(q);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        update(i, 0, 0, n, (i-a[i])*w[i], 1);
    }
    for(int i = 0; i < n; i++){
        scanf("%lld", &w[i]);
        update(i, 0, 0, n, w[i], 0);
    }
    for(int i = 0; i < q; i++){
        int x, y;
        sc(x); sc(y);
        if(x < 0){
            x = -x-1;
            update(x, 0, 0, n, y-w[x], 0);
            update(x, 0, 0, n, 1LL*(i-a[i])*(y-w[x]), 1);
            w[x] = y;
        }
        else{
            ll tot = query_sum(x-1, y, 0, 0, n, 0);
            int k = query_id(x-1, y, 0, 0, n, tot/2);
            ll ans = ((a[k]-k)*query_sum(x-1, k, 0, 0, n, 0)%mod+query_sum(x-1, k, 0, 0, n, 1)%mod)%mod-((a[k]-k)*query_sum(k+1, y, 0, 0, n, 0)%mod+query_sum(k+1, y, 0, 0, n, 1)%mod)%mod;
            ans = (ans%mod+mod)%mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}

