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
const int maxn = 1e5+10;
const int sigma = 3;
char s[maxn];
int pre[sigma], nxt[maxn][sigma];
vector<int> v1, v2;
int n, pos;

int id(char c)
{
    if(c == 'm')return 0;
    if(c == 's')return 1;
    if(c == 'c')return 2;
    assert(0);
}

void dfs(int fr, int u, int v)
{
    if(u == 3 && v == 3){
        pos = min(pos, fr);
        return; 
    }
    if(u < 3 && nxt[fr][v1[u]] != n+1)dfs(nxt[fr][v1[u]], u+1, v);
    if(v < 3 && nxt[fr][v2[v]] != n+1)dfs(nxt[fr][v2[v]], u, v+1);
}

int main()
{
    scanf("%d%s", &n, s+1);
    for(int i = 0; i < sigma; i++)pre[i] = n+1;
    for(int i = n; i >= 0; i--){
        for(int j = 0; j < 3; j++)nxt[i][j] = pre[j];
        if(i)pre[id(s[i])] = i;
    }
    ll ans = 0;
    v1 = vector<int>{0, 1, 2};
    v2 = vector<int>{0, 2, 2};
    for(int i = 0; i < n; i++){
        pos = n+1;
        dfs(i, 0, 0);
        ans += n+1-pos;
    }
    printf("%lld\n", ans);
    return 0;
}

