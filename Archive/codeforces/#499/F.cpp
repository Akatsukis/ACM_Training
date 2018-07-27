#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mk make_pair
#define fi first
#define se second
const int maxn = 1e6+10;
struct Node
{
    char s[10];
    int l, r, ret;
    bool ok;
}G[maxn];
vector<pii> ans;

void dfs(int u, int f)
{
    int l = G[u].l, r = G[u].r;
    if(l)dfs(l, u);
    if(r)dfs(r, u);
    if(G[u].s[0] == 'A')G[u].ret = G[l].ret&G[r].ret;
    else if(G[u].s[0] == 'O')G[u].ret = G[l].ret|G[r].ret;
    else if(G[u].s[0] == 'X')G[u].ret = G[l].ret^G[r].ret;
    else if(G[u].s[0] == 'N')G[u].ret = !G[l].ret;
}

void modify(int u, int f)
{
    int l = G[u].l, r = G[u].r;
    if(G[u].ok){
        if(G[u].s[0] == 'A'){
            if(G[l].ret && G[r].ret)G[l].ok = G[r].ok = 1;
            else if(G[l].ret && !G[r].ret)G[r].ok = 1;
            else if(!G[l].ret && G[r].ret)G[l].ok = 1;
        }
        else if(G[u].s[0] == 'O'){
            if(!G[l].ret && !G[r].ret)G[l].ok = G[r].ok = 1;
            else if(G[l].ret && !G[r].ret)G[l].ok = 1;
            else if(!G[l].ret && G[r].ret)G[r].ok = 1;
        }
        else if(G[u].s[0] == 'X')G[l].ok = G[r].ok = 1;
        else if(G[u].s[0] == 'N')G[l].ok = 1;
    }
    if(l)modify(l, u);
    if(r)modify(r, u);
    if(G[u].s[0] == 'I')ans.pb(mk(u, G[1].ret^G[u].ok));
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s", G[i].s);
        if(G[i].s[0] == 'I')scanf("%d", &G[i].ret);
        else if(G[i].s[0] == 'N')scanf("%d", &G[i].l);
        else scanf("%d%d", &G[i].l, &G[i].r);
    }
    dfs(1, 0);
    G[1].ok = 1;
    modify(1, 0);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d", ans[i].se);
    }
    puts("");
}
