#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
const int maxe = 2000100;
double mp[maxn][maxn];
bool used[maxn][maxn];
double path[maxn][maxn];
double mincost[maxn];
bool vis[maxn];
double x[maxn], y[maxn];
int p[maxn];
int pre[maxn];
int n;

void init()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)mp[i][j] = INF;
    }
}

double dis(int i, int j)
{
    return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

double prim()
{
    memset(vis, 0, sizeof(vis));
    memset(used, 0, sizeof(used));
    for(int i = 0; i < n; i++){
        mincost[i] = INF;
        for(int j = 0; j < n; j++){
            path[i][j] = 0;
        }
    }
    mincost[0] = 0;
    double ret = 0;
    while(1){
        int u = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && (u==-1 || mincost[i] < mincost[u]))u = i;
        }
        if(u == -1)break;
        vis[u] = 1;
        ret += mincost[u];
        if(u != 0)used[u][pre[u]] = used[pre[u]][u] = 1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && mincost[i] > mp[u][i]){
                mincost[i] = mp[u][i];
                pre[i] = u;
            }
            if(i != u && vis[i]){
                path[i][u] = path[u][i] = max(path[i][pre[u]], mincost[u]);
            }
        }

    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        sc(n);
        for(int i = 0; i < n; i++){
            scanf("%lf%lf%d", &x[i], &y[i], &p[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                mp[i][j] = mp[j][i] = dis(i, j);
            }
        }
        double ans = 0;
        double mst = prim();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(used[i][j])ans  = max(ans, (p[i]+p[j])/(mst-mp[i][j]));
                else ans = max(ans, (p[i]+p[j])/(mst-path[i][j]));
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}

