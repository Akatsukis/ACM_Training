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
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
const int maxe = 1010;
struct edge
{
    int u, v, w;
    bool operator < (const edge &rbs)const
    {
        return w<rbs.w;
    }
}es[maxe];
int dfn[maxn], par[maxn], link[maxn][maxn];
bool vis[maxn];
ll mat[maxn][maxn];
vector<int> vec[maxn];
int n, m;
ll mod;

void init()
{
    memset(link, 0, sizeof(link));
    for(int i = 0; i < n; i++)par[i] = i, dfn[i] = i;
}

int find(int x, int arr[])
{
    return x==arr[x]?x:arr[x]=find(arr[x], arr);
}

void unite(int x, int y, int arr[])
{
    x = find(x, arr), y = find(y, arr);
    if(x != y)arr[x] = y;
}

int det(int sz)
{
    ll ret = 1;
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            mat[i][j] = (mat[i][j]%mod+mod)%mod;
        }
    }
    for(int i = 1; i < sz; i++){
        for(int j = i+1; j < sz; j++){
            while(mat[j][i]){
                ll t = mat[i][i]/mat[j][i];
                for(int k = i; k < sz; k++){
                    mat[i][k] = (mat[i][k]-mat[j][k]*t)%mod;
                    swap(mat[i][k], mat[j][k]);
                }
                ret = -ret;
            }
        }
        if(!mat[i][i])return 0;
        ret = ret*mat[i][i]%mod;
    }
    return (ret+mod)%mod;
}

int solve()
{
    ll ret = 1;
    sort(es, es+m);
    int pre = -1;
    for(int i = 0; i <= m; i++){
        if(es[i].w != pre || i == m){
            for(int j = 0; j < n; j++)if(vis[j]){
                int fj = find(j, par);
                vec[fj].pb(j);
                dfn[j] = fj;
                vis[j] = 0;
            }
            for(int j = 0; j < n; j++){
                int sz = vec[j].size();
                if(sz <= 1)continue;
                memset(mat, 0, sizeof(mat));
                for(int k = 0; k < sz; k++){
                    for(int h = k+1; h < sz; h++){
                        int u = vec[j][k], v = vec[j][h];
                        mat[k][h] = mat[h][k] = -link[v][u];
                        mat[k][k] += link[v][u];
                        mat[h][h] += link[u][v];
                    }
                }
                ret = ret*det(sz)%mod;
            }
            for(int j = 0; j < n; j++)vec[j].clear();
            if(i == m)break;
        }
        int u = find(es[i].u, dfn), v = find(es[i].v, dfn);
        if(u == v)continue;
        vis[u] = vis[v] = 1;
        unite(u, v, par);
        link[u][v]++; link[v][u]++;
        pre = es[i].w;
    }
    int flg = find(0, dfn);
    for(int i = 1; i < n; i++)if(find(i, dfn) != flg)return 0;
    return (ret+mod)%mod;
}

int main()
{
    while(scanf("%d%d%lld", &n, &m, &mod) != EOF && (n||m||mod)){
        init();
        for(int i = 0; i < m; i++){
            sc(es[i].u); sc(es[i].v); sc(es[i].w);
            es[i].u--, es[i].v--;
        }
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}

