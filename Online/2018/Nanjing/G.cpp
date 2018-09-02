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
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
int in[maxn], tr[maxn*4];
int tot[maxn], ans[maxn];

void build(int k, int l, int r)
{
    if(l == r-1)tr[k] = in[l];
    else{
        int m = (l+r)>>1;
        build(lson, l, m);
        build(rson, m, r);
        tr[k] = min(tr[lson], tr[rson]);
    }
}

int query(int a, int b, int k, int l, int r)
{
    if(a >= r || b <= l)return INF;
    else if(a <= l && b >= r)return tr[k];
    int m = (l+r)>>1;
    int v1 = query(a, b, lson, l, m);
    int v2 = query(a, b, rson, m, r);
    return min(v1, v2);
}

void update(int t, int k, int l, int r)
{
    if(l == r-1){
        tr[k] = INF;
        return;
    }
    int m = (l+r)>>1;
    if(t < m)update(t, lson, l, m);
    else update(t, rson, m, r);
    tr[k] = min(tr[lson], tr[rson]);
}

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 0; i < n; i++)sc(in[i]);
    build(0, 0, n);
    int rem = 0;
    for(int i = 1; i < maxn; i++){
        tot[i] = tot[i-1];
        if(tot[i] == n){
            ans[i] = ans[i-1];
            continue;
        }
        rem += m;
        int id = 0;
        while(id < n){
            int pos = -1, l = id, r = n;
            while(l <= r){
                int mid = (l+r)>>1;
                if(query(id, mid, 0, 0, n) <= rem){
                    pos = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
            if(pos == -1)break;
            else{
                update(pos-1, 0, 0, n);
                rem -= in[pos-1];
                tot[i]++;
                id = pos;
            }
        }
        ans[i] = rem;
    }
    int q; sc(q);
    for(int i = 0; i < q; i++){
        int x; sc(x);
        printf("%d %d\n", tot[x], ans[x]);
    }
    return 0;
}
