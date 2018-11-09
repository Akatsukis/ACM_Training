#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x) ((int)x.size())
const int maxn = 1e4+10;
struct Node
{
    int deg, id;
    Node(){}
    Node(int deg, int id):deg(deg), id(id){}
    bool operator < (const Node& rhs)const 
    {
        return deg > rhs.deg;
    }
};
struct Edge
{
    int to, type;
    Edge(){}
    Edge(int to, int type):to(to), type(type){}
    bool operator < (const Edge& rhs)const
    {
        return to < rhs.to;
    }
};
set<Edge> st[maxn];
vector<int> G[maxn], ans;
bool vis[maxn];
int deg[maxn];
priority_queue<Node> pq;
int n, m;

void init()
{
    for(int i = 1; i <= n; i++){
        deg[i] = vis[i] = 0;
        G[i].clear();
        st[i].clear();
    }
    ans.clear();
    while(!pq.empty())pq.pop();
}

void dfs(int u)
{
    vis[u] = 1;
    ans.pb(u);
    for(auto v : G[u]){
        if(!vis[v])dfs(v);
    }
}

int main()
{
    int T, fst = 1;
    scanf("%d", &T);
    while(T--){
        if(fst)fst = 0;
        else puts("");
        scanf("%d%d", &n, &m);
        init();
        for(int i = 0; i < n+m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            st[u].insert(Edge(v, 1)); st[v].insert(Edge(u, 1));
            deg[u]++, deg[v]++;
        }
        for(int i = 1; i <= n; i++)pq.push(Node(deg[i], i));
        while(!pq.empty()){
            Node t = pq.top(); pq.pop();
            int u = t.id;
            if(vis[u] || t.deg != deg[u])continue;
            else vis[t.id] = 1;
            if(t.deg == 1){
                int v = st[u].begin()->to;
                G[u].pb(v); G[v].pb(u);
                break;
            }
            vector<int> vec;
            for(Edge e : st[t.id]){
                int v = e.to;
                if(e.type)G[u].pb(v), G[v].pb(u);
                if(st[v].find(Edge(u, 0)) != st[v].end())st[v].erase(Edge(u, 0)), deg[v]--;
                if(st[v].find(Edge(u, 1)) != st[v].end())st[v].erase(Edge(u, 1)), deg[v]--;
                vec.pb(v);
            }
            assert(vec.size() == 2);
            int p = vec[0], q = vec[1];
            if(st[p].find(Edge(q, 1)) != st[p].end())st[p].erase(Edge(q, 1)), deg[p]--;
            if(st[p].find(Edge(q, 0)) != st[p].end())st[p].erase(Edge(q, 0)), deg[p]--;
            if(st[q].find(Edge(p, 1)) != st[q].end())st[q].erase(Edge(p, 1)), deg[q]--;
            if(st[q].find(Edge(p, 0)) != st[q].end())st[q].erase(Edge(p, 0)), deg[q]--;
            st[p].insert(Edge(q, 0)); deg[p]++;
            st[q].insert(Edge(p, 0)); deg[q]++;
            pq.push(Node(deg[p], p)); pq.push(Node(deg[q], q));
        }
        memset(vis, 0, sizeof(vis));
        vis[1] = 1; ans.pb(1);
        if(G[1][0] < G[1][1])dfs(G[1][0]);
        else dfs(G[1][1]);
        for(int i = 0; i < SZ(ans); i++){
            printf("%d%c", ans[i], " \n"[i==(int)ans.size()-1]);
        }
    }
    return 0;
}

