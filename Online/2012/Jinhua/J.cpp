#include <bits/stdc++.h>
using namespace std;
const int len = 20;
const int maxn = 1e5+10;
#define pb push_back
#define ALL(A) (A.begin(), A.end())
struct edge
{
    int u;
    string s;
    bool operator < (const edge &rhs)const
    {
        return s<rhs.s;
    }
};
string t[maxn];
vector<edge> G[maxn];
int pre[maxn];
int dep[maxn];
int anc[maxn][len];
map<string, int> mp;

int n, m;

void init()
{
    memset(dep, 0, sizeof(dep));
    memset(anc, 0, sizeof(anc));
    memset(pre, 0, sizeof(pre));
    for(int i = 0; i <= n; i++)G[i].clear();
    mp.clear();
}
int calc(string ss)
{
    int ret = 0;
    for(int i = 0; i < (int)ss.size(); i++){
        if(ss[i] == '.')ret++;
        else break;
    }
    return ret;
}
void dfs(int u)
{
    sort(G[u].begin(), G[u].end());
    for(int i = 0; i < (int)G[u].size(); i++){
        dfs(G[u][i].u);
    }
}
void output(int u)
{
    for(int i = 1; i < dep[u]; i++)cout << ".";
    cout << t[u] << endl;
    for(int i = 0; i < (int)G[u].size(); i++){
        output(G[u][i].u);
    }
}

int lca(int u, int v)
{
    if(dep[u] < dep[v])swap(u, v);
    for(int i = len-1; i >= 0; i--){
        if(dep[anc[u][i]] >= dep[v])u = anc[u][i];
    }
    if(u == v)return anc[u][0];
    for(int i = len-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}
int main()
{
    //freopen("out.txt", "w", stdout);
    while(cin >> n && n){
        init();
        pre[1] = dep[1] = 1;
        for(int i = 1; i <= n; i++){
            cin >> t[i];
            if(i == 1)continue;
            int num = calc(t[i]);
            anc[i][0] = pre[num];
            dep[i] = num+1;
            pre[num+1] = i;
            t[i] = t[i].substr(num, (int)t[i].size()-num);
            //cout << ">>" << t[i] <<endl;
            mp[t[i]] = i;
            G[pre[num]].pb((edge){i, t[i]});
        }
        for(int i = 1; i < len; i++){
            for(int j = 1; j <= n; j++){
                anc[j][i] = anc[anc[j][i-1]][i-1];
            }
        }
        dfs(1);
        cin >> m;
        for(int i = 0; i < m; i++){
            string q;
            cin >> q;
            if(q[0] == 'L')output(1);
            else if(q[0] == 'b'){
                string A;
                cin >> A;
                int id = mp[A];
                int fa = anc[id][0];
                if(fa == 0)cout << 1 << endl;
                else cout << G[fa].size() << endl;
            }
            else{
                string A, B;
                cin >> A >> B;
                int u = mp[A], v = mp[B];
                int fa = lca(u, v);
                cout << t[fa] << endl;
            }
        }
    }
    return 0;
}
