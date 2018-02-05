#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
bool vis[200];

int main()
{
    int T;
    sc(T);
    while(T--){
        memset(vis, 0, sizeof(vis));
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < k; i++){
            int u;
            scanf("%d", &u);
            vis[u] = 1;
        }
        int ans = 1;
        while(1){
            bool flag = 1;
            for(int i = 1; i <= n; i++){
                if(!vis[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag)break;
            else ans++;
            vector<int> v;
            for(int i = 1; i <= n; i++){
                if(vis[i]){
                    if(i-1>0)v.pb(i-1);
                    if(i+1<=n)v.pb(i+1);
                }
            }
            for(int i = 0; i < (int)v.size(); i++){
                vis[v[i]] = 1;
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}

