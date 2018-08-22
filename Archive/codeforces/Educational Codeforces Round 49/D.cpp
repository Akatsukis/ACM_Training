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
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+10;
int a[maxn], c[maxn];
bool vis[maxn];
bool inc[maxn];
bool cal[maxn];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++)inc[i] = 1;
    for(int i = 1; i <= n; i++)sc(c[i]);
    for(int i = 1; i <= n; i++)sc(a[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        else vis[i] = 1;
        int now = a[i];
        while(!vis[now]){
            vis[now] = 1;
            now = a[i];
        }
        for(int j = i; j != now; j = a[j])inc[j] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(inc[i] && !cal[i]){
            int mn = c[i], now = a[i];
            cal[i] = 1;
            while(now != i){
                cal[now] = 1;
                mn = min(mn, c[now]);
                now = a[now];
            }
            ans += mn;
        }
    }
    printf("%d\n", ans);
    return 0;
}


