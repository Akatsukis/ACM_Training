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
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-5;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 6e4+10;
int num[maxn];
int pre[maxn];
int n;
struct Node
{
    double v, tag;
}tree[maxn*4];

void build(int l, int r, int k, double val)
{
    //printf("build(%d,%d,%d,%f)\n", l, r, k, val);
    tree[k].tag = 0;
    if(l == r-1){
        tree[k].v = val*l;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, k*2+1, val);
    build(m, r, k*2+2, val);
    //printf("k=%d\n", k);
    tree[k].v = min(tree[k*2+1].v, tree[k*2+2].v);
}

void pushdown(int k)
{
    if(tree[k].tag){
        tree[k*2+1].v += tree[k].tag;
        tree[k*2+2].v += tree[k].tag;
        tree[k*2+1].tag += tree[k].tag;
        tree[k*2+2].tag += tree[k].tag;
        tree[k].tag = 0;
    }
}

void pushup(int k)
{
    tree[k].v = min(tree[k*2+1].v, tree[k*2+2].v);
}

void update(int a, int b, int k, int l, int r)
{
    //printf("update(%d,%d,%d,%d,%d)\n", a, b, k, l, r);
    if(l >= b || r <= a)return;
    if(l >= a && r <= b){
        tree[k].v += 1;
        tree[k].tag += 1;
        return;
    }
    pushdown(k);
    int m = (l+r)/2;
    update(a, b, k*2+1, l, m);
    update(a, b, k*2+2, m, r);
    pushup(k);
}

double query(int a, int b, int k, int l, int r)
{
    if(l >= b || r <= a)return INF;
    if(l >= a && r <= b)return tree[k].v;
    pushdown(k);
    int m = (l+r)/2;
    double v1 = query(a, b, k*2+1, l, m);
    double v2 = query(a, b, k*2+2, m, r);
    return min(v1, v2);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++){
            sc(num[i]);
        }
        double l = 0, r = 1, ans;
        while(l < r - eps){
            double m = (l+r)/2;
            build(0, n, 0, m);
            //for(int i = 0; i < n; i++)printf("num[%d]:%d\n", i, num[i]);
            for(int i = 0; i < n; i++){
                //printf("num[%d]=%d pre[num[%d]]=%d\n", num[i], pre[num[i]]);
                pre[num[i]] = 0;
            }
            int i;
            for(i = 0; i < n; i++){
                update(pre[num[i]], i+1, 0, 0, n);
                double now = query(0, i+1, 0, 0, n);
                if(now-m*(i+1) < -eps)break;
                pre[num[i]] = i+1;
            }
            if(i == n){
                l = m+eps;
                ans = l;
            }
            else r = m-eps;
        }
        printf("%.10f\n", ans);
    }
    return 0;
}

