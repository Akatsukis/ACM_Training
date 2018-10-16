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
const int maxn = 20;
vector<int> G[maxn];
char s[maxn*maxn];
int deg[maxn], sum[maxn];
int n;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear(), deg[i] = 0, sum[i] = -10;
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n); 
        init();
        scanf("%s", s);
        int t = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <= n; j++){
                char c = s[t++];
                if(c == '+')G[i].pb(j), deg[j]++;
                else if(c == '-')G[j].pb(i), deg[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i <= n; i++){
            if(!deg[i])sum[i] = -10, q.push(i);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto v : G[u]){
                sum[v] = max(sum[v], sum[u]+1);
                deg[v]--;
                if(!deg[v])q.push(v);
            }
        }
        for(int i = 1; i <= n; i++)printf("%d%c", sum[i]-sum[i-1], " \n"[i==n]);
    }
    return 0;
}

