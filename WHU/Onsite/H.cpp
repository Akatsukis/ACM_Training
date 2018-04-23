#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e6+10;
int root[maxn], ls[maxn], rs[maxn], sz[maxn];
int a[maxn];
int idx;

void update(int &rt, int x, int pre)
{
    rt = ++idx;
    int now = rt;
    for(int i = 30; i >= 0; i--){
        int bit = (x>>i)&1;
        if(bit){
            ls[now] = ls[pre];
            rs[now] = ++idx;
            now = rs[now];
            pre = rs[pre];
        }
        else{
            rs[now] = rs[pre];
            ls[now] = ++idx;
            now = ls[now];
            pre = ls[pre];
        }
        sz[now] = sz[pre]+1;
    }
}

int query(int ss, int tt, int x)
{
    int ret = 0;
    for(int i = 30; i >= 0; i--){
        int bit = (x>>i)&1;
        if(bit){
            if(sz[ls[tt]]-sz[ls[ss]]){
                tt = ls[tt];
                ss = ls[ss];
                ret += (1<<i);
            }
            else{
                tt = rs[tt];
                ss = rs[ss];
            }
        }
        else{
            if(sz[rs[tt]]-sz[rs[ss]]){
                tt = rs[tt];
                ss = rs[ss];
                ret += (1<<i);
            }
            else{
                tt = ls[tt];
                ss = ls[ss];
            }
        }
    }
    return ret;
}

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]);
    for(int i = 1; i <= n; i++)update(root[i], a[i], root[i-1]);
    int m;
    sc(m);
    for(int i = 0; i < m; i++){
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        int ans = query(root[l-1], root[r], x);
        printf("%d\n", ans);
    }
    return 0;
}

