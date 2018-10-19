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
const int maxn = 1e3+10;
int l[maxn], r[maxn], ans[maxn];
bool vis[maxn];
int n;

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++)sc(l[i]);
    for(int i = 1; i <= n; i++)sc(r[i]);
    int now = n;
    vector<int> vec;
    for(int i = 1; i <= n; i++){
        if(l[i] == 0 && r[i] == 0)vec.pb(i), vis[i] = 1;
    }
    while(vec.size()){
        for(auto u : vec){
            ans[u] = now;
            for(int i = 0; i < u; i++)if(!vis[i])r[i]--;
            for(int i = u+1; i <= n; i++)if(!vis[i])l[i]--;
        }
        vec.clear();
        for(int i = 1; i <= n; i++){
            if(!vis[i] && l[i] == 0 && r[i] == 0)vec.pb(i), vis[i] = 1;
        }
        now--;
    }
    bool ok = 1;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ok = 0;
            break;
        }
    }
    if(!ok)puts("NO");
    else{
        puts("YES");
        for(int i = 1; i <= n; i++)printf("%d%c", ans[i], " \n"[i==n]);
    }
    return 0;
}

