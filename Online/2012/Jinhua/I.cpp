#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sc(x) scanf("%d",&x)
#define debug cout<<"STOP" <<endl
int n, m, mod;
const int maxn = 110;
const int maxm = 1010;
typedef long long ll;
struct edge
{
    int u, v, w;
    bool operator < (const edge& rhs)const
    {
        return w<rhs.w;
    }
}es[maxm];
int dfn[maxn];
int par[maxn];
int link[maxn][maxn];
ll mat[maxn][maxn];
bool vis[maxn];
vector<int> vec[maxn];

void init()
{
    memset(link, 0, sizeof(link));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++)dfn[i] = i, par[i] = i;
}

int Find(int x, int arr[])
{
    //printf("Find(%d):%d\n", x, arr[x]);
    return arr[x]==x?x:arr[x]=Find(arr[x], arr);
}

void unite(int x, int y, int arr[])
{
    x = Find(x, arr), y = Find(y, arr);
    if(x != y)arr[x] = y;
}

ll det(int sz)
{
    ll ret = 1;
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            mat[i][j] = (mat[i][j]%mod+mod)%mod;
            //printf("mat[%d][%d]:%lld\n", i, j, mat[i][j]);
        }
    }
    for(int i = 1; i < sz; i++){
        for(int j = i+1; j < sz; j++){
            while(mat[j][i]){
                //printf("mat[%d][%d]:%d\n", j, i, mat[j][i]);
                ll t = mat[i][i]/mat[j][i];
                //printf("t=%lld\n", t);
                for(int k = i; k < sz; k++){
                    mat[i][k] = (mat[i][k]-t*mat[j][k])%mod;
                    swap(mat[i][k], mat[j][k]);
                }
                ret = -ret;
                //printf("ret=%lld\n", ret);
            }
        }
        if(!mat[i][i])return 0;
        ret = ret*mat[i][i]%mod;
    }
    return (ret%mod+mod)%mod;
}

int kruskal()
{
    ll ret = 1;
    sort(es, es+m);
    int pre = -1;
    for(int i = 0; i <= m; i++){
        if(es[i].w != pre || i == m){
            for(int j = 0; j < n; j++){
                if(vis[j]){
                    int fj = Find(j, par);
                    //printf("vec[%d].pb(%d)\n", fj, j);
                    dfn[j] = fj;
                    vec[fj].pb(j);
                    vis[j] = 0;
                }
            }
            for(int j = 0; j < n; j++){
                if(vec[j].size() <= 1)continue;
                memset(mat, 0, sizeof(mat));
                int sz = vec[j].size();
                for(int k = 0; k < sz; k++){
                    for(int h = k+1; h < sz; h++){
                        int u = vec[j][k], v = vec[j][h];
                        mat[k][h] = mat[h][k] = -link[u][v];
                        mat[k][k] += link[u][v];
                        mat[h][h] += link[v][u];
                    }
                }
                ret = ret*det(sz)%mod;
                //printf("ret=%lld\n", ret);
            }
            for(int j = 0; j < n; j++){
                vec[j].clear();
            }
            if(i == m)break;
            pre = es[i].w;
        }
        int u = Find(es[i].u, dfn), v = Find(es[i].v, dfn);
        if(u == v)continue;
        vis[u] = vis[v] = 1;
        unite(u, v, par);
        link[u][v]++;
        link[v][u]++;
    }
    for(int i = 1; i < n; i++){
        if(Find(i, dfn) != Find(0, dfn))return 0;
    }
    return (ret+mod)%mod;
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &mod) != EOF && (n|m||mod)){
        init();
        for(int i = 0; i < m; i++){
            sc(es[i].u); sc(es[i].v); sc(es[i].w);
            es[i].u--, es[i].v--;
        }
        int ans = kruskal();
        printf("%d\n", ans);
    }
    return 0;
}
