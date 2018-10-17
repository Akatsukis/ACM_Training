#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
const int maxn = 2e3+10;
vector<int> G[maxn];
int a[4];
char s[4][4];
bool mark[maxn];
stack<int> sk;
int n, m;

void init()
{
    for(int i = 0; i < 2*n; i++){
        mark[i] = 0;
        G[i].clear();
    }
}

bool dfs(int u)
{
    if(mark[u^1])return 0;
    if(mark[u])return 1;
    mark[u] = 1; sk.push(u);
    for(auto v : G[u]){
        if(!dfs(v))return 0;
    }
    return 1;
}

bool solve()
{
    for(int i = 0; i < 2*n; i += 2){
        if(!mark[i] && !mark[i^1]){
            bool ok1 = 0, ok2 = 0;
            while(!sk.empty())sk.pop();
            ok1 = dfs(i);
            while(!sk.empty()){
                int x = sk.top(); sk.pop();
                mark[x] = 0;
            }
            ok2 = dfs(i^1);
            while(!sk.empty()){
                int x = sk.top(); sk.pop();
                mark[x] = 0;
            }
            if(ok1 && !ok2)dfs(i);
            else if(!ok1 && ok2)dfs(i^1);
            else if(!ok1 && !ok2)return 0;
        }
    }
    return 1;
}

int main()
{
    int kase = 1;
    while(scanf("%d%d", &n, &m) != EOF && n){
        init();
        bool ok = 1;
        for(int i = 0; i < m; i++){
            int k; sc(k);
            for(int j = 0; j < k; j++){
                scanf("%d%s", &a[j], s[j]);
                a[j] = (a[j]-1)*2;
                if(s[j][0] == 'n')a[j] = a[j]^1;
            }
            if(k <= 2){
                for(int u = 0; u < k; u++){
                    if(mark[a[u]^1])ok = 0;
                    mark[a[u]] = 1;
                }
            }
            else{
                for(int u = 0; u < k; u++){
                    for(int v = 0; v < k; v++){
                        if(u == v)continue;
                        G[a[u]^1].pb(a[v]);
                    }
                }
            }
        }
        printf("Case %d: ", kase++);
        if(ok && solve()){
            for(int i = 0; i < 2*n; i += 2){
                if(!mark[i] && !mark[i^1])putchar('?');
                else if(mark[i])putchar('y');
                else putchar('n');
            }
            puts("");
        }
        else puts("impossible");
    }
    return 0;
}

