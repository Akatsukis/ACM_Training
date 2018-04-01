#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n",x)
#define debug cout << ">>>" <<endl;
const int maxn = 2e5+10;
vector<int> G[maxn];
bool ban[maxn];
list<int> lst;
int ans[maxn];

void init(int n)
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(ban, 0, sizeof(ban));
    lst.clear();
    for(int i = 1; i <= n; i++)lst.insert(lst.end(), i);
    memset(ans, -1, sizeof(ans));
}

void solve(int src)
{
    queue<int> q;
    q.push(src);
    ans[src] = 0;
    for(auto it = lst.begin(); it != lst.end();){
        if(*it == src){
            lst.erase(it++);
            break;
        }
        else it++;
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v:G[u])ban[v] = 1;
        for(auto it = lst.begin(); it != lst.end();){
            if(!ban[*it]){
                q.push(*it);
                ans[*it] = ans[u]+1;
                lst.erase(it++);
            }
            else it++;
        }
        for(auto v:G[u])ban[v] = 0;
    }
}


int main()
{
    int n, m, src;
    int T;
    sc(T);
    while(T--){
        scanf("%d%d", &n, &m);
        init(n);
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        sc(src);
        solve(src);
        bool fst = 1, flg = 1;
        for(int i = 1; i <= n; i++){
            //printf("ans[%d]:%d\n", i, ans[i]);
            if(ans[i] == -1){
                flg = 0;
                break;
            }
        }
        if(!flg){
            printf("-1\n");
            continue;
        }
        for(int i = 1; i <= n; i++){
            if(i != src){
                if(fst)fst = 0;
                else printf(" ");
                printf("%d", ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
