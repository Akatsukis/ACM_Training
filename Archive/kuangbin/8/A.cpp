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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 0x3f3f3f3f;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int n, m;
const int maxn = 110;
const int maxm = 1e5 + 10;
struct edge
{
    int u, v, w;
}es[maxm];
int del;
vector<int> vec;
int par[maxn];
bool flag;


int find(int x)
{
    if(par[x] == x)return x;
    else return par[x] = find(par[x]);
}

void unite(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)return;
    par[u] = v;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int kru()
{
    int res = 0;
    for(int i = 0; i <= n; i++)par[i] = i;
    for(int i = 0; i < m; i++){
        if(del == i)continue;
        if(find(es[i].u) != find(es[i].v)){
            unite(es[i].u, es[i].v);
            //printf(" %d %d %d\n", es[i].u, es[i].v, es[i].w);
            res += es[i].w;
            if(flag)vec.pb(i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(find(i) != find(1))return INF;
    }
    return res;
}

void work()
{
    flag = 1;
    vec.clear();
    sc(n);sc(m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        sc(u);sc(v);sc(w);
        es[i].u = u, es[i].v = v, es[i].w = w;
    }
    sort(es, es + m, cmp);
//    for(int i = 0; i < m; i++){
//        printf("%d %d %d\n", es[i].u, es[i].v, es[i].w);
//    }
    del = -1;
    int ans = kru();
    flag = 0;
    for(int i = 0; i < (int)vec.size(); i++){
        del = vec[i];
        int now = kru();
        if(now == ans){
            printf("Not Unique!\n");
            return;
        }
    }
    printf("%d\n", ans);
    return;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        work();
    }
	return 0;
}


