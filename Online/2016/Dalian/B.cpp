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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
const int maxm = 1e6+10;
int tr[maxm];
int a[maxn];
int ans[maxn];
int pre[maxm];
vector<pii> vec[maxn];
vector<pii> qry[maxm];
int n, q;

void init()
{
    memset(pre, 0, sizeof(pre));
    memset(tr, 0, sizeof(tr));
    for(int i = 0; i < maxm; i++)qry[i].clear();
    for(int i = 0; i < maxn; i++)vec[i].clear();
}

void add(int x, int val)
{
    //printf("add(%d,%d)\n", x, val);
    while(x <= n){
        tr[x] += val;
        x += x&(-x);
    }
}

int cal(int x)
{
    int ret = 0;
    while(x){
        ret += tr[x];
        x -= x&(-x);
    }
    return ret;
}

int main()
{
    while(scanf("%d%d", &n, &q) != EOF){
        init();
        for(int i = 1; i <= n; i++)sc(a[i]);
        for(int i = 1; i <= n; i++){
            vec[i].pb(mk(a[i], i));
            int val = a[i], pos = i;
            for(int j = 0; j < (int)vec[i-1].size(); j++){
                int now = gcd(val, vec[i-1][j].fi);
                if(now != val){
                    val = now, pos = vec[i-1][j].se;
                    vec[i].pb(mk(now, pos));
                }
            }
        }
        for(int i = 1; i <= q; i++){
            int l, r;
            sc(l); sc(r);
            qry[r].pb(mk(l, i)); 
        }
        for(int i = 1; i <= n; i++){
            for(auto p : vec[i]){
                if(pre[p.fi])add(pre[p.fi], -1);
                add(p.se, 1);
                pre[p.fi] = p.se;
            }
            for(auto u : qry[i]){
                ans[u.se] = cal(i)-cal(u.fi-1);
            }
        }
        for(int i = 1; i <= q; i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

