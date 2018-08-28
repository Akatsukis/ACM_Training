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
const int maxn = 1e6+10;
int par[maxn], num[maxn];
map<int, vector<int> > mp[2];

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if(x != y)par[x] = y;
}

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++)par[i] = i;
    for(int i = 1; i <= n; i++){
        int x, y;
        sc(x); sc(y);
        mp[0][x].pb(i);
        mp[1][y].pb(i);
    }
    for(int j = 0; j < 2; j++){
        for(auto u : mp[j]){
            for(int i = 1; i < SZ(u.se); i++){
                unite(u.se[0], u.se[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        num[find(i)]++;
        ans = max(ans, num[find(i)]-1);
    }
    printf("%d\n", ans);
    return 0;
}


