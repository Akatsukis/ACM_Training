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
const int INF = 0x3f3f3f3f;
const int maxn = 3e5+10;
const int maxa = 4e3+10;
unordered_map<int, int> num;
vector<int> prime;
bool vis[maxa];
int a[maxn];
int n;

void init()
{
    for(int i = 2; i < maxa; i++){
        if(!vis[i])prime.pb(i);
        for(int j = 0; j < SZ(prime) && i*prime[j] < maxa; j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)break;
        }
    }
}

int main()
{
    init();
    sc(n);
    int d = 0;
    for(int i = 1; i <= n; i++)sc(a[i]), d = gcd(d, a[i]);
    for(int i = 1; i <= n; i++)a[i] /= d;
    for(int i = 1; i <= n; i++){
        for(auto u : prime){
            if(a[i]%u == 0){
                num[u]++;
                while(a[i]%u == 0)a[i] /= u;
            }
        }
        if(a[i] != 1)num[a[i]]++;
    }
    int ans = INF;
    for(auto p : num){
        ans = min(ans, n-p.se);
    }
    if(ans == INF)puts("-1");
    else printf("%d\n", ans);
    return 0;
}
