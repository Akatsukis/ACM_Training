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
char s[maxn][maxn];
int id[maxn][maxn];
bool vis[maxn*maxn];
int len[maxn];
vector<int> G[maxn*maxn];
int n, idx, dst;

void init()
{
    for(int i = 0; i <= idx; i++)G[i].clear(), vis[i] = 0;
    idx = 0;
}

bool dfs(int u)
{
    vis[u] = 1;
    if(u == dst)return 1;
    for(auto v : G[u]){
        if(!vis[v] && dfs(v))return 1;
    }
    return 0;
}

int main()
{
    int kase = 1;
    while(scanf("%d", &n) != EOF && n){
        init();
        for(int i = 0; i < n; i++){
            scanf("%*s%s", s[i]);
            len[i] = strlen(s[i]);
            for(int j = 0; j < len[i]; j++)id[i][j] = idx++;
        }
        dst = idx;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < len[i]; j++){
                for(int k = 0; k < n; k++){
                    if(i == k && !j)continue;
                    int h = 0;
                    while(j+h < len[i] && h < len[k] && s[i][j+h] == s[k][h])h++;
                    if(j+h == len[i] && h == len[k])G[id[i][j]].pb(dst);
                    else if(j+h == len[i])G[id[i][j]].pb(id[k][h]);
                    else if(h == len[k])G[id[i][j]].pb(id[i][j+h]);
                }
            }
        }
        bool ok = 1;
        for(int i = 0; i < n; i++){
            if(!vis[id[i][0]]){
                if(dfs(id[i][0])){
                    ok = 0;
                    break;
                }
            }
        }
        if(ok)printf("Case #%d: Not ambiguous.\n", kase++);
        else printf("Case #%d: Ambiguous.\n", kase++);
    }
    return 0;
}

