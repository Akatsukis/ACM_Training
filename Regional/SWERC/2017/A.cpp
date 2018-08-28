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
const int maxn = 2e3+10;
int a[maxn], b[maxn];
map<int, int> mp;

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 1; i <= n; i++)sc(a[i]);
    for(int i = 1; i <= m; i++)sc(b[i]);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(b[j]-a[i] >= 0)mp[b[j]-a[i]]++;
        }
    }
    int mx = 0, ans = 0;
    for(auto u : mp){
        if(u.se > mx)mx = u.se, ans = u.fi;
    }
    printf("%d\n", ans);
    return 0;
}


