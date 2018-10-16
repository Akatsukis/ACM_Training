#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
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
#define Abs(x) ((x)>=0?(x):(-(x)))
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e3+10;
ll m;
int n;
int a[maxn];
priority_queue<pll, vector<pll>, greater<pll> > pq;
ll dist[maxn];
bool vis[maxn];

void solve()
{
    int mn = INF;
    for(int i = 0; i < n; i++)mn = min(mn, a[i]);
    memset(dist, INF, sizeof(dist));
    dist[0] = 0;
    pq.push(mk(dist[0], 0));
    while(!pq.empty()){
        pll u = pq.top(); pq.pop();
        if(u.fi > dist[u.se])continue;
        for(int i = 0; i < n; i++){
            if(dist[(u.se+a[i])%mn] > dist[u.se]+a[i]){
                dist[(u.se+a[i])%mn] = dist[u.se]+a[i];
                pq.push(mk(dist[(u.se+a[i])%mn], (u.se+a[i])%mn));
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i < mn; i++){
        if(dist[i] > m)ans = min(ans, dist[i]-m);
        else{
            ans = min(ans, min(Abs(i-m%mn), Abs(i+mn-m%mn)));
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    scanf("%lld", &m);
    sc(n);
    for(int i = 0; i < n; i++)sc(a[i]);
    solve();
    return 0;
}

