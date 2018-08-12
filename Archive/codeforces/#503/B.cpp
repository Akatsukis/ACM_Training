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
const int maxn = 1e3+10;
int a[maxn];
bool vis[maxn];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]);
    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        int ans = i;
        while(!vis[ans]){
            vis[ans] = 1;
            ans = a[ans];
        }
        printf("%d%c", ans, " \n"[i==n]);
    }
    return 0;
}


