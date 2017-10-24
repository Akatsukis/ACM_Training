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
const int maxn = 2e5 + 10;
int n;
vector<vector<int> > G(maxn);
bool on[maxn];
int cnt;
int id[maxn];
int from[maxn];
int to[maxn];
struct node
{
    int val, tag;
}tree[maxn * 4];

void dfs(int v)
{
    id[cnt] = v;
    from[v] = cnt;
    cnt++;
    for(int i = 0; i < (int)G[v].size(); i++){
        dfs(G[v][i]);
    }
    to[v] = cnt;
}

void build(int k, int l, int r)
{
    if(l == r - 1){
        tree[k].val = on[id[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2 + 1, l, mid);
    build(k * 2 + 2, mid, r);
    tree[k].val = tree[k * 2 + 1].val + tree[k * 2 + 2].val;
    //printf("tree[%d].val=%d l=%d r=%d\n", k, tree[k].val, l, r);
}

void pushdown(int k, int l, int r)
{
    if(tree[k].tag){
        tree[k * 2 + 1].tag = (tree[k * 2 + 1].tag + 1) % 2;
        tree[k * 2 + 2].tag = (tree[k * 2 + 2].tag + 1) % 2;
        int m = (l + r) / 2;
        tree[k * 2 + 1].val = (m - l) - tree[k * 2 + 1].val;
        tree[k * 2 + 2].val = (r - m) - tree[k * 2 + 2].val;
        tree[k].tag = 0;
    }
}

void pushup(int k, int l, int r)
{
    tree[k].val = tree[k * 2 + 1].val + tree[k * 2 + 2].val;
}

void update(int a, int b, int k, int l, int r)
{
    if(r <= a || l >= b)return;
    if(l >= a && r <= b){
        tree[k].tag = (tree[k].tag + 1) % 2;
        tree[k].val = (r - l) - tree[k].val;
        return;
    }
    pushdown(k, l, r);
    int m = (l + r) / 2;
    update(a, b, k * 2 + 1, l, m);
    update(a, b, k * 2 + 2, m, r);
    pushup(k, l, r);
}

int query(int a, int b, int k, int l, int r)
{
    if(r <= a || l >= b)return 0;
    if(l >= a && r <= b)return tree[k].val;
    pushdown(k, l, r);
    int m = (l + r) / 2;
    int v1 = query(a, b, k * 2 + 1, l, m);
    int v2 = query(a, b, k * 2 + 2, m, r);
    pushup(k, l, r);
    return v1 + v2;
}

int main()
{
    sc(n);
    for(int i = 2; i <= n; i++){
        int v;
        sc(v);
        G[v].pb(i);
    }
    for(int i = 1; i <= n; i++){
        int v;
        sc(v);
        if(v == 1)on[i] = 1;
    }
    dfs(1);
    build(0, 0, cnt);
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        char s[10];
        int d;
        scanf("%s%d", s, &d);
        if(s[0] == 'g'){
            int ans = query(from[d], to[d], 0, 0, cnt);
            printf("%d\n", ans);
        }
        else{
            update(from[d], to[d], 0, 0, cnt);
        }
    }
    return 0;
}


