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
const int maxn = 4e4+10;
bool mark[maxn];
int a[maxn];
char s[maxn];
vector<int> G[maxn];//0->unalter 1->alter 2->-1 3->+1
stack<int> sk;
int n, m;


void init()
{
    for(int i = 0; i < 4*n; i++){
        mark[i] = 0;
        G[i].clear();
    }
}

int id(char c)
{
    if(c == 'A')return 0;
    if(c == 'G')return 1;
    if(c == 'T')return 2;
    if(c == 'C')return 3;
    assert(0);
    return -1;
}

bool dfs(int u)
{
    if(mark[u^1])return 0;
    if(mark[u])return 1;
    mark[u] = 1;
    sk.push(u);
    for(auto v : G[u]){
        if(!dfs(v))return 0;
    }
    return 1;
}

bool solve()
{
    for(int i = 0; i < 2*n; i += 2){
        if(!mark[i] && !mark[i^1]){
            while(!sk.empty())sk.pop();
            if(!dfs(i)){
                while(!sk.empty()){
                    int u = sk.top(); sk.pop();
                    mark[u] = 0;
                }
                if(!dfs(i^1))return 0;
            }
        }
    }
    return 1;
}

void add(int u, int v)
{
    G[u].pb(v);
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        if(!n && !m)break;
        init();
        for(int i = 0; i < n-1; i++){
            int j = i+1;
            add(i<<1|1, j<<1); add(j<<1|1, i<<1);
        }
        scanf("%s", s);
        while(m--){
            int k;
            scanf("%d:", &k);
            for(int i = 0; i < k; i++)sc(a[i]);
            for(int i = 0, j = k-1; i < j; i++, j--){
                int c1 = id(s[a[i]]), c2 = id(s[a[j]]);
                int d = ABS(c1-c2); d = min(d, 4-d);
                if(d == 0){
                    add(a[i]<<1, a[j]<<1); add(a[i]<<1|1, a[j]<<1|1);
                    add(a[j]<<1, a[i]<<1); add(a[j]<<1|1, a[i]<<1|1);
                    add((a[i]+n)<<1, (a[j]+n)<<1); add((a[i]+n)<<1|1, (a[j]+n)<<1|1);
                    add((a[j]+n)<<1, (a[i]+n)<<1); add((a[j]+n)<<1|1, (a[i]+n)<<1|1);
                }
                else if(d == 1){
                    add(a[i]<<1, a[j]<<1|1); add(a[i]<<1|1, a[j]<<1);
                    add(a[j]<<1, a[i]<<1|1); add(a[j]<<1|1, a[i]<<1);
                    if((c1+1)%4 == c2){
                        add(a[i]<<1|1, (a[i]+n)<<1|1); add(a[j]<<1|1, (a[j]+n)<<1);
                        add((a[i]+n)<<1, (a[i]+n)<<1|1); add((a[j]+n)<<1|1, (a[j]+n)<<1);
                    }
                    else{
                        add(a[i]<<1|1, (a[i]+n)<<1); add(a[j]<<1|1, (a[j]+n)<<1|1);
                        add((a[i]+n)<<1|1, (a[i]+n)<<1); add((a[j]+n)<<1, (a[j]+n)<<1|1);
                    }
                }
                else{
                    add(a[i]<<1, a[i]<<1|1); add(a[j]<<1, a[j]<<1|1);
                    add((a[i]+n)<<1, (a[j]+n)<<1|1); add((a[i]+n)<<1|1, (a[j]+n)<<1);
                    add((a[j]+n)<<1, (a[i]+n)<<1|1); add((a[j]+n)<<1|1, (a[i]+n)<<1);
                }
            }
        }
        if(solve())puts("YES");
        else puts("NO");
    }
    return 0;
}

