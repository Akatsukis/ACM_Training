#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e5+10;
ll tree[maxn*4];
bool vis[maxn*4];
int num[maxn];
int n, m;

void build(int k, int l, int r)
{
    //printf("%d %d %d\n", k, l, r);
    if(l == r - 1){
        tree[k] = num[l];
        if(num[l] == 1 || num[l] == 2)vis[k] = 1;
    }
    else{
        int m = (l+r)/2;
        build(k*2+1, l, m);
        build(k*2+2, m, r);
        tree[k] = tree[k*2+1]+tree[k*2+2];
        if(vis[k*2+1]&&vis[k*2+2])vis[k] = 1;
    }
}

void D(int id)
{
    int tmp = tree[id];
    vector<int> v;
    for(int i = 2; (ll)i*i <= tmp; i++){
        if(tmp%i==0){
            int cnt = 0;
            while(tmp%i==0){
                tmp/=i;
                cnt++;
            }
            v.pb(cnt);
        }
    }
    if(tmp > 1)v.pb(1);
    int ans = 1;
    for(int i = 0; i < (int)v.size(); i++){
        ans *= v[i]+1;
    }
    //printf("D(%lld):%d\n", tree[id], ans);
    tree[id] = ans;
}

void update(int a, int b, int k, int l, int r)
{
    //printf("update(%d,%d,%d,%d,%d)\n", a, b, k, l, r);
    if(vis[k])return;
    if(r <= a || l >= b)return;
    if(l==r-1){
        D(k);
        if(tree[k] == 1 || tree[k] == 2)vis[k] = 1;
        return;
    }
    int m = (l+r)/2;
    update(a, b, k*2+1, l, m);
    update(a, b, k*2+2, m, r);
    tree[k] = tree[k*2+1] + tree[k*2+2];
    if(vis[k*2+1]&&vis[k*2+2])vis[k] = 1;
}

ll query(int a, int b, int k, int l, int r)
{
    //printf("query(%d,%d,%d,%d,%d)\n", a, b, k, l, r);
    if(r <= a || l >= b)return 0;
    if(l >= a && r <= b)return tree[k];
    int m= (l+r)/2;
    ll v1 = query(a, b, k*2+1, l, m);
    ll v2 = query(a, b, k*2+2, m, r);
    return v1+v2;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    build(0, 0, n);
    for(int i = 0; i < m; i++){
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        //printf("tree[0]:%lld\n", tree[0]);
        if(t == 1){
            update(l-1, r, 0, 0, n);
        }
        if(t == 2){
            ll ans = query(l-1, r, 0, 0, n);
            printf("%lld\n", ans);
        }
    }
	return 0;
}

