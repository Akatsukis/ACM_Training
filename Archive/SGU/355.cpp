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
const int maxn = 1e4+10;
int col[maxn];
bool vis[maxn];

int main()
{
    int n; sc(n);
    int mx = 0;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        for(int j = 1; j*j <= i; j++){
            if(i%j == 0){
                vis[col[j]] = vis[col[i/j]] = 1;
            }
        }
        for(int j = 1; j < maxn; j++){
            if(!vis[j]){
                ans.pb(j);
                col[i] = j;
                mx = max(mx, j);
                break;
            }
        }
    }
    printf("%d\n", mx);
    for(int i = 0; i < SZ(ans); i++)printf("%d%c", ans[i], " \n"[i==SZ(ans)-1]);
    return 0;
}

