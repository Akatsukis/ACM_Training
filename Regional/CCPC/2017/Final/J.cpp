#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e3+10;
vector<pii> G[maxn];
long long dist[maxn];
int n, m, x;

bool negative(int s = 0)
{
    for(int i = 0; i <= n; i++)dist[i] = INF;
    dist[s] = 0;
    int cnt = 0;
    while(1){
        cnt++;
        bool update = 0;
        for(int i = 0; i <= n; i++){
            for(auto v : G[i]){
                if(dist[v.fi] > dist[i]+v.se){
                    dist[v.fi] = dist[i]+v.se;
                    //printf("dist[%d]=dist[%d]+%d\n", v.fi, i, v.se);
                    update = 1;
                    if(cnt == n)return 1;
                }
            }
        }
        if(!update)break;
    }
    return 0;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(m); sc(x);
        for(int i = 0; i <= n; i++)G[i].clear();
        for(int i = 1; i <= n; i++)G[0].pb(mk(i, 0));
        for(int i = 1; i <= n-1; i++)G[i+1].pb(mk(i, -1));
        for(int i = 0; i < m; i++){
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if(a == b && c == d){
                G[a].pb(mk(c, x));
                G[c].pb(mk(a, -x));
            }
            else if(a == b && c == d-1){
                G[a].pb(mk(c, x-1));
                G[d].pb(mk(a, -x-1));
            }
            else if(a == b-1 && c == d){
                G[c].pb(mk(a, -x-1));
                G[b].pb(mk(c, x-1));
            }
            else{
                G[b].pb(mk(c, x-1));
                G[d].pb(mk(a, -x-1));
            }
        }
        printf("Case #%d: ", kase++);
        if(negative())puts("IMPOSSIBLE");
        else{
            for(int i = 2; i <= n; i++)printf("%lld%c", dist[i]-dist[i-1], " \n"[i==n]);
        }
    }
    return 0;
}
