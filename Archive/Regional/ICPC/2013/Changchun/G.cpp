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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 800 + 10;
int n, m;
int a[maxn][maxn];
struct node
{
    int mx, mn;
}tree[maxn * maxn * 16];

void build(int k, int l1, int r1, int l2, int r2)
{
    //printf("l1=%d r1=%d l2=%d r2=%d\n", l1, r1, l2, r2);
    if(l1 == r1 && l2 == r2){
        tree[k].mn = tree[k].mx = a[l1 + 1][l2 + 1];
        return;
    }
    int m1 =(l1 + r1) / 2, m2 = (l2 + r2) / 2;
    if(l1 == r1 && l2 != r2){
        build(k * 4 + 1, l1, r1, l2, m2);
        build(k * 4 + 2, l1, r1, m2 + 1, r2);
        tree[k].mx = max(tree[k*4+1].mx, tree[k*4+2].mx);
        tree[k].mn = min(tree[k*4+1].mn, tree[k*4+2].mn);
    }
    else if(l2 == r2 && l1 != r1){
        build(k * 4 + 1, l1, m1, l2, r2);
        build(k * 4 + 2, m1 + 1, r1, l2, r2);
        tree[k].mx = max(tree[k*4+1].mx, tree[k*4+2].mx);
        tree[k].mn = min(tree[k*4+1].mn, tree[k*4+2].mn);
    }
    else{
        build(k * 4 + 1, l1, m1, l2, m2);
        build(k * 4 + 2, l1, m1, m2 + 1, r2);
        build(k * 4 + 3, m1 + 1, r1, l2, m2);
        build(k * 4 + 4, m1 + 1, r1, m2 + 1, r2);
        tree[k].mx = max(max(tree[k*4+1].mx, tree[k*4+2].mx), max(tree[k*4+3].mx, tree[k*4+4].mx));
        tree[k].mn = min(min(tree[k*4+1].mn, tree[k*4+2].mn), min(tree[k*4+3].mn, tree[k*4+4].mn));
    }
}

int query(int a1, int b1, int a2, int b2, int k, int l1, int r1, int l2, int r2, int t)
{
    if(l1 > b1 || r1 < a1 || l2 > b2 || r2 < a2){
        if(t == 0)return -INF;
        else return INF;
    }
    if(l1 >= a1 && r1 <= b1 && l2 >= a2 && r2 <= b2){
        if(t == 0)return tree[k].mx;
        else return tree[k].mn;
    }
    int m1 = (l1 + r1) / 2;
    int m2 = (l2 + r2) / 2;
    if(l1 == r1 && l2 != r2){
        int v1 = query(a1, b1, a2, b2, k * 4 + 1, l1, r1, l2, m2, t);
        int v2 = query(a1, b1, a2, b2, k * 4 + 2, l1, r1, m2 + 1, r2, t);
        if(t == 0){
            int ans = max(v1, v2);
            return ans;
        }
        else{
            int ans = min(v1, v2);
            return ans;
        }
    }
    else if(l2 == r2 && l1 != r1){
        int v3 = query(a1, b1, a2, b2, k * 4 + 1, l1, m1, l2, r2, t);
        int v4 = query(a1, b1, a2, b2, k * 4 + 2, m1 + 1, r1, l2, r2, t);
        if(t == 0){
            int ans = max(v3, v4);
            return ans;
        }
        else{
            int ans = min(v3, v4);
            return ans;
        }
    }
    else{
        int v1 = query(a1, b1, a2, b2, k * 4 + 1, l1, m1, l2, m2, t);
        int v2 = query(a1, b1, a2, b2, k * 4 + 2, l1, m1, m2 + 1, r2, t);
        int v3 = query(a1, b1, a2, b2, k * 4 + 3, m1 + 1, r1, l2, m2, t);
        int v4 = query(a1, b1, a2, b2, k * 4 + 4, m1 + 1, r1, m2 + 1, r2, t);
        if(t == 0){
            int ans = max(max(v1, v2), max(v3, v4));
            return ans;
        }
        else{
            int ans = min(min(v1, v2), min(v3, v4));
            return ans;
        }
    }
}

void update(int x, int y, int k, int l1, int r1, int l2, int r2, int val)
{
    if(l1 > x || r1 < x || l2 > y || r2 < y){
        return;
    }
    if(l1 >= x && r1 <= x && l2 >= y && r2 <= y){
        tree[k].mx = tree[k].mn = val;
        return;
    }
    int m1 = (l1 + r1) / 2;
    int m2 = (l2 + r2) / 2;
    if(l1 == r1 && l2 != r2){
        update(x, y, k * 4 + 1, l1, r1, l2, m2, val);
        update(x, y, k * 4 + 2, l1, r1, m2 + 1, r2, val);
        tree[k].mx = max(tree[k*4+1].mx, tree[k*4+2].mx);
        tree[k].mn = min(tree[k*4+1].mn, tree[k*4+2].mn);
    }
    else if(l2 == r2 && l1 != r1){
        update(x, y, k * 4 + 1, l1, m1, l2, r2, val);
        update(x, y, k * 4 + 2, m1 + 1, r1, l2, r2, val);
        tree[k].mx = max(tree[k*4+1].mx, tree[k*4+2].mx);
        tree[k].mn = min(tree[k*4+1].mn, tree[k*4+2].mn);
    }
    else{
        update(x, y, k * 4 + 1, l1, m1, l2, m2, val);
        update(x, y, k * 4 + 2, l1, m1, m2 + 1, r2, val);
        update(x, y, k * 4 + 3, m1 + 1, r1, l2, m2, val);
        update(x, y, k * 4 + 4, m1 + 1, r1, m2 + 1, r2, val);
        tree[k].mx = max(max(tree[k*4+1].mx, tree[k*4+2].mx), max(tree[k*4+3].mx, tree[k*4+4].mx));
        tree[k].mn = min(min(tree[k*4+1].mn, tree[k*4+2].mn), min(tree[k*4+3].mn, tree[k*4+4].mn));
    }
}

void work()
{
    sc(n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sc(a[i][j]);
        }
    }
    build(0, 0, n - 1, 0, n - 1);
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        int x, y, l;
        scanf("%d%d%d", &x, &y, &l);
        int x1 = max(0, x - 1 - l / 2);
        int y1 = min(n - 1, x - 1 + l / 2);
        int x2 = max(0, y - 1 - l / 2);
        int y2 = min(n - 1, y - 1 + l / 2);
        //printf("x1=%d x2=%d y1=%d y2=%d\n", x1, x2, y1, y2);
        int mx = query(x1, y1, x2, y2, 0, 0, n - 1, 0, n - 1, 0);
        int mn = query(x1, y1, x2, y2, 0, 0, n - 1, 0, n - 1, 1);
        int ans = floor((mx + mn) / 2);
        printf("%d\n", ans);
        update(x - 1, y - 1, 0, 0, n - 1, 0, n - 1, ans);

    }
}


int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        printf("Case #%d:\n", kase++);
        work();
    }
    return 0;
}


