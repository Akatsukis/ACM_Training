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
int x[maxn];
int vis[maxn];

int main()
{
    memset(vis, -1, sizeof(vis));
    int a, b, c, d, k;
    scanf("%d%d%d%d%d%d", &x[0], &a, &b, &c, &d, &k);
    if(k == 0){
        printf("%d\n", x[0]);
        return 0;
    }
    vis[x[0]] = 0;
    for(int i = 1; i < maxn; i++){
        x[i] = (1LL*a*sqr(x[i-1])+1LL*b*x[i-1]+c)%d;
        if(i == k){
            printf("%d\n", x[k]);
            return 0;
        }
        if(vis[x[i]] == -1)vis[x[i]] = i;
        else{
            int st = vis[x[i]];
            int q = i-vis[x[i]];
            k = (k-st)%q;
            printf("%d\n", x[st+k]);
            return 0;
        }
    }
    return 0;
}

