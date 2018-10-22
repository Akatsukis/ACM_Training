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
const int maxn = 1e2+10;
vector<int> G[maxn];
bool vis[maxn];
int a[maxn];
int n;

void init()
{
    for(int i = 1; i <= n; i++)G[i].clear(), vis[i] = 0;
}

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : G[u]){
        if(!vis[v])dfs(v);
    }
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n);
        init();
        set<int> st;
        for(int i = 1; i <= n; i++)sc(a[i]), st.insert(a[i]);
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(gcd(a[i], a[j]) == 1)G[i].pb(j), G[j].pb(i);
            }
        }
        dfs(1);
        bool ok = 1;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                ok = 0;
                break;
            }
        }
        if(ok)printf("0\n");
        else{
            printf("1\n");
            for(int i = 50; i >= 2; i--){
                bool flg = 1;
                for(int j = 2; j*j <= i; j++){
                    if(i%j == 0){
                        flg = 0;
                        break;
                    }
                }
                if(flg && !st.count(i)){
                    a[1] = i;
                    break;
                }
            }
        }
        for(int i = 1; i <= n; i++)printf("%d%c", a[i], " \n"[i==n]);
    }
    return 0;
}

