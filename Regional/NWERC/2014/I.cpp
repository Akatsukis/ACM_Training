#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 15;
unordered_set<ll> st[1<<maxn][maxn];
ll G[maxn][maxn], L;
bool flg;
int n;

void init()
{
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++)st[i][j].clear();
    }
    flg = 0;
}

inline void dfs(int u, int num, int state, ll tot)
{
    if(flg)return;
    if(num == (n+1)/2){
        st[state][u].insert(tot);
        if(n%2){
            int rev = (1<<n)-state;
            ll val = L-tot;
            for(int i = 0; i < n; i++){
                if(st[rev][i].find(val-G[u][i]) != st[rev][i].end())flg = 1;
            }
        }
        else{
            int rev = (1<<n)-state;
            ll val = L-tot;
            for(int i = 0; i < n; i++){
                if(state>>i&1)continue;
                for(int j = 0; j < n; j++){
                    if(state>>j&1)continue;
                    if(st[rev-(1<<i)][j].find(val-G[u][i]-G[i][j]) != st[rev-(1<<i)][j].end())flg = 1;
                }
            }
        }
        return;
    }
    for(int i = 1; i < n; i++){
        if(state>>i&1)continue;
        dfs(i, num+1, state|(1<<i), tot+G[u][i]);
    }
}

int main()
{
    while(scanf("%d%lld", &n, &L) != EOF){
        init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)scanf("%lld", &G[i][j]);
        }
        if(n == 2){
            if(L == G[0][1]*2)flg = 1;
            else flg = 0;
        }
        else dfs(0, 1, 1, 0);
        if(flg)puts("possible");
        else puts("impossible");
    }
    return 0;
}
