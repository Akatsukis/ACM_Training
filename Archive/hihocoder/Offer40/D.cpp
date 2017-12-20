#include <bits/stdc++.h>

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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int tree[maxn*8];
int tag[maxn*8];

void pushdown(int k)
{
    if(tag[k]){
        tree[k*2+1] = max(tree[k*2+1], tag[k]);
        tree[k*2+2] = max(tree[k*2+2], tag[k]);
        tag[k*2+1] = tag[k*2+2] = tag[k];
        tag[k] = 0;
    }
}

int query(int a, int b, int k, int l, int r)
{
    //printf("query(%d,%d,%d,%d,%d)\n", a, b, k, l, r);
    if(l >= b || r <= a)return 0;
    else if(l >= a && r <= b)return tree[k];
    pushdown(k);
    int m = (l+r) / 2;
    int v1 = query(a, b, k*2+1, l, m);
    int v2 = query(a, b, k*2+2, m, r);
    return max(v1, v2);
}

void update(int a, int b, int k, int l, int r, int val)
{
    //printf("update(%d,%d,%d,%d,%d,%d)\n", a, b, k, l, r, val);
    if(l >= b || r <= a)return;
    else if(l >= a && r <= b){
        //printf("a=%d b=%d\n", a, b);
        pushdown(k);
        tree[k] = max(tree[k], val);
        tag[k] = max(tag[k], val);
        return;
    }
    pushdown(k);
    int m = (l + r) / 2;
    update(a, b, k*2+1, l, m, val);
    update(a, b, k*2+2, m, r, val);
    tree[k] = max(tree[k*2+1], tree[k*2+2]);
}

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        int l, r;
        sc(l);sc(r);
        int h = query(l, r+1, 0, 0, maxn);
        printf("%d\n", h+1);
        update(l, r+1, 0, 0, maxn, h+1);
    }
    return 0;
}

