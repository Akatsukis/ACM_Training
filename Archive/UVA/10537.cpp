#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pli;
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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e2+10;
vector<int> G[maxn];
ll dist[maxn];
int m, S, E;

int id(char c)
{
    if(isupper(c))return c-'A';
    if(islower(c))return c-'a'+26;
    assert(0);
}

void init()
{
    for(int i = 0; i < maxn; i++)G[i].clear();
}

void dijkstra(int s, int p)
{
    for(int i = 0; i < maxn; i++)dist[i] = INF64;
    dist[s] = p;
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.push(mk(dist[s], s));
    while(!pq.empty()){
        pli p = pq.top(); pq.pop();
        if(p.fi != dist[p.se])continue;
        for(auto v : G[p.se]){
            if(p.se < 26){
                if(dist[v] > dist[p.se]+(dist[p.se]+18)/19){
                    dist[v] = (dist[p.se]*20+18)/19;
                    pq.push(mk(dist[v], v));
                }
            }
            else{
                if(dist[v] > dist[p.se]+1){
                    dist[v] = dist[p.se]+1;
                    pq.push(mk(dist[v], v));
                }
            }
        }
    }
}

void dfs(int u)
{
    if(u == E){
        printf("%c\n", u<26?u+'A':u-26+'a');
        return;
    }
    else printf("%c-", u<26?u+'A':u-26+'a');
    int id = -1;
    for(auto v : G[u]){
        if(v < 26){
            if(dist[u]-(dist[u]+19)/20 == dist[v]){
                if(id == -1 || v < id)id = v;
            }
        }
        else{
            if(dist[u]-1 == dist[v]){
                if(id == -1 || v < id)id = v;
            }
        }
    }
    dfs(id);
}

int main()
{
    int kase = 1;
    while(scanf("%d", &m) != EOF && m != -1){
        init();
        for(int i = 0; i < m; i++){
            char s1[2], s2[2];
            scanf("%s%s", s1, s2);
            int u = id(s1[0]), v = id(s2[0]);
            G[u].pb(v); G[v].pb(u);
        }
        int p; 
        char s1[2], s2[2];
        scanf("%d%s%s", &p, s1, s2);
        S = id(s1[0]), E = id(s2[0]);
        dijkstra(E, p);
        printf("Case %d:\n%lld\n", kase++, dist[S]);
        dfs(S);
    }
    return 0;
}

