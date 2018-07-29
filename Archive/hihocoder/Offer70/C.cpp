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
const int maxn = 20;
int a[maxn];
bool vis[maxn];
int n;

int dfs(int now)
{
    int ret = now;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(a[i]+a[j] > a[k] && !vis[i] && !vis[j] && !vis[k]){
                    vis[i] = 1;
                    vis[j] = 1;
                    vis[k] = 1;
                    ret = max(ret, dfs(now+1));
                    vis[i] = 0;
                    vis[j] = 0;
                    vis[k] = 0;
                }
            }
        }
    }
    return ret;
}

int main()
{
    sc(n);
    for(int i = 0; i < n; i++)sc(a[i]);
    sort(a, a+n);
    int ans = dfs(0);
    printf("%d\n", ans);
    return 0;
}


