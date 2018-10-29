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
const int maxn = 2e5+10;
struct Segment
{
    int l, r;
    bool operator < (const Segment& rhs)
    {
        if(l != rhs.l)return l < rhs.l;
        else return r < rhs.r;
    }
}seg[maxn];
int tr[maxn];
int sz;

void add(int x, int val)
{
    while(x <= sz){
        tr[x] += val;
        x += x&-x;
    }
}

int sum(int x)
{
    int ret = 0;
    while(x){
        ret += tr[x];
        x -= x&-x;
    }
    return ret;
}

int main()
{
    int T; sc(T);
    while(T--){
        memset(tr, 0, sizeof(tr));
        int n, k;
        sc(n); sc(k);
        vector<int> vec;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &seg[i].l, &seg[i].r);
            vec.pb(seg[i].l); vec.pb(seg[i].r);
        }   
        sort(ALL(vec));
        vec.erase(unique(ALL(vec)), vec.end());
        sz = vec.size();
        sort(seg, seg+n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int idl = lower_bound(ALL(vec), seg[i].l)-vec.begin()+1;
            int idr = lower_bound(ALL(vec), seg[i].r)-vec.begin()+1;
            //printf("idl=%d, idr=%d\n", idl, idr);
            add(idr, 1);
            int l = idl, r = sz;
            //printf("l=%d, r=%d\n", l, r);
            while(l <= r){
                int m = (l+r)>>1;
                //printf("m=%d\n", m);
                if(sum(sz)-sum(m-1) >= k){
                    //printf("(%d,%d)\n", m-1, idl-1);
                    ans = max(ans, vec[m-1]-vec[idl-1]);
                    l = m+1;
                }
                else r = m-1;
            }
        }
        printf("%d\n", ans);
    }   
    return 0;
}

