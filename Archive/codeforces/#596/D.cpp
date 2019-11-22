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
constexpr int maxn = 1e5+10;
vector<int> G[maxn];
vector<int> seq, opt;
int p[maxn], hv[maxn], dep[maxn];
int cnt;

void dfs(int u) {
    seq.push_back(u);
    for(int i = 0; i < cnt; i++) {
        opt.push_back(u);
    }
    cnt = 0;
    for(auto v: G[u]) {
        if(hv[u] == v)continue;
        dfs(v);
    }
    if(hv[u]) dfs(hv[u]);
    cnt++;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d", &p[i]);
        dep[i] = dep[p[i]]+1;
        G[p[i]].push_back(i);
    }
    dfs(0);
    for(int i = 0; i < n; i++) {
        printf("%d%c", seq[i], " \n"[i==n-1]);
    }
    int k = opt.size();
    printf("%d\n", k);
    for(int i = 0; i < k; i++) {
        printf("%d%c", opt[i], " \n"[i==k-1]);
    }
    return 0;
}

