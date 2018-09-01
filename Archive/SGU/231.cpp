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
bool vis[maxn];
vector<int> prime;

int main()
{
    int n; sc(n);
    for(int i = 2; i <= n; i++){
        if(!vis[i])prime.pb(i);
        for(int j = 0; j < SZ(prime) && prime[j]*i <= n; j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)break;
        }
    }
    vector<pii> ans;
    for(int j = 1; j < SZ(prime); j++){
        if(prime[0]+prime[j] > n)break;
        else if(!vis[prime[0]+prime[j]])ans.pb(mk(prime[0], prime[j]));
    }
    printf("%d\n", SZ(ans));
    for(int i = 0; i < SZ(ans); i++){
        printf("%d %d\n", ans[i].fi, ans[i].se);
    }
    return 0;
}

