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
const int maxn = 5e3+10;
bool vis[maxn];
vector<int> prime;

void init()
{
    for(int i = 2; i < maxn; i++){
        if(!vis[i]){
            prime.pb(i);
            for(int j = i*2; j < maxn; j += i)vis[j] = 1;
        }
    }
}

int main()
{
    int n, m;
    sc(n); sc(m);
    if(m < n-1)puts("Impossible");
    else{
        vector<pii> ans;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(SZ(ans) == m)break;
                if(gcd(i, j) == 1)ans.pb(mk(i, j));
            }
        }
        if(SZ(ans) == m){
            puts("Possible");
            for(auto u : ans)printf("%d %d\n", u.fi, u.se);
        }
        else puts("Impossible");
    }
    return 0;
}


