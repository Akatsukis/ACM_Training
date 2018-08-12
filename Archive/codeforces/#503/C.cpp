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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e3+10;
vector<int> v[maxn];
int vote[maxn];

int main()
{
    int n, m;
    sc(m); sc(n);
    for(int i = 0; i < m; i++){
        int p, w;
        sc(p); sc(w);
        v[p].pb(w);
        vote[p]++;
    }
    for(int i = 1; i <= n; i++)sort(ALL(v[i]));
    ll ans = INF64;
    for(int i = 1; i <= m; i++){
        ll now = 0;
        int cnt = 0;
        vector<int> tmp;
        for(int j = 2; j <= n; j++){
            for(int k = 0; k < SZ(v[j]); k++){
                if(vote[j]-k >= i)now += v[j][k], cnt++;
                else tmp.pb(v[j][k]);
            }   
        }
        sort(ALL(tmp));
        for(int j = 0; vote[1]+cnt < i && j < SZ(tmp); j++){
            now += tmp[j];
            cnt++;
        }
        ans = min(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}


