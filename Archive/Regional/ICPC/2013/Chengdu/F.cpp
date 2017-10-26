#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fst fi
#define scd se
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5 + 10;
int n, m;
struct edge
{
    int u, v, w;
}es[maxn * 2];
int head[maxn];
int par[maxn];

void addedge(int i, int u, int v, int w)
{
    es[i*2].u = u, es[i*2].v = v, es[i*2].w = w, es[i * 2].next = head[u];
    head[u] = i * 2;
    es[i*2+1].u = v, es[i*2+1].u, es[i*2+1].w = w, es[i*2+1].next = head[v];
    head[v] = i * 2 + 1;
}

int find(int x)
{
    if(x == par[x])return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)return;
    par[x] = y;
}

void work(int kase)
{
    memset(head, -1, sizeof(head));
    sc(n);sc(m);
    for(int i = 0; i <= n; i++)G[i].clear();
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(i, u, v, w);
    }
    for(int i = 0; i < 2 * m; i++){
        if(es[i].w == 0)unite(es[i].u, es[i].v);
    }

    for(int i = 0; i < n; i++){

    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        work();
    }
    return 0;
}


