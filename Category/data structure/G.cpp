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
struct Node
{
    int l, r, val;
}tree[maxn];
bool vis[maxn];
map<int, pair<bool, int> > mp;
int ans;

void dfs(int u, int mn, int mx)
{
    //printf("dfs(%d,%d,%d)\n", u, mn, mx);
    if(tree[u].val >= mn && tree[u].val <= mx)mp[tree[u].val].fi = 1;
    if(tree[u].l != -1){
        dfs(tree[u].l, mn, min(mx, tree[u].val-1));
    }
    if(tree[u].r != -1){
        dfs(tree[u].r, max(mn, tree[u].val), mx);
    }
}

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(tree[i].val); sc(tree[i].l); sc(tree[i].r);
        vis[tree[i].l] = vis[tree[i].r] = 1;
        mp[tree[i].val].se++;
    }
    int root = 1;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            root = i;
            break;
        }
    }
    dfs(root, -INF, INF);
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(!it->se.fi)ans += it->se.se;
    }
    printf("%d\n", ans);
    return 0;
}

