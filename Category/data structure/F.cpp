#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 4e5+10;
struct Node
{
    int cover, tag;
}tree[maxn*4];
int T[maxn];
ll L[maxn];
ll R[maxn];
vector<ll> num;
map<ll, int> mp;
int n;

void build(int k, int l, int r)
{
    tree[k].cover = -1, tree[k].tag = 0;
    if(l == r-1)return;
    int m = (l+r)/2;
    build(k*2+1, l, m);
    build(k*2+2, m, r);
}

void pushdown(int k, int l, int r)
{
    if(tree[k].tag){
        if(tree[k].tag == 1){
            tree[k*2+1].cover = tree[k*2+2].cover = 1;
            tree[k*2+1].tag = tree[k*2+2].tag = 1;
        }
        else if(tree[k].tag == -1){
            tree[k*2+1].cover = tree[k*2+2].cover = -1;
            tree[k*2+1].tag = tree[k*2+2].tag = -1;
        }
        else{
            if(l != r-1){
                if(tree[k*2+1].tag == 2)tree[k*2+1].tag = 0;
                else if(tree[k*2+1].tag == 1)tree[k*2+1].tag = -1;
                else if(tree[k*2+1].tag == -1)tree[k*2+1].tag = 1;
                else tree[k*2+1].tag = 2;
                tree[k*2+1].cover = -tree[k*2+1].cover;
                if(tree[k*2+2].tag == 2)tree[k*2+2].tag = 0;
                else if(tree[k*2+2].tag == 1)tree[k*2+2].tag = -1;
                else if(tree[k*2+2].tag == -1)tree[k*2+2].tag = 1;
                else tree[k*2+2].tag = 2;
                tree[k*2+2].cover = -tree[k*2+2].cover;
            }
        }
        tree[k].tag = 0; 
    }
}

void pushup(int k)
{
    if(tree[k*2+1].cover == 1 && tree[k*2+2].cover == 1)tree[k].cover = 1;
    else if(tree[k*2+1].cover == -1 && tree[k*2+2].cover == -1)tree[k].cover = -1;
    else tree[k].cover = 0;
    //printf("cover[%d]:%d\n", k, tree[k].cover);
}

void update(int a, int b, int k, int l, int r, int val)
{
    if(l >= b || r <= a)return;
    //printf("update(%d,%d,%d,%d,%d,%d)\n", a, b, k, l, r, val);
    if(l >= a && r <= b){
        if(val == 1)tree[k].tag = tree[k].cover = 1;
        else if(val == 2)tree[k].tag = tree[k].cover = -1;
        else if(val == 3){
            tree[k].cover = -tree[k].cover;
            if(l != r-1){
                if(tree[k].tag == 2)tree[k].tag = 0;
                else if(tree[k].tag == 1)tree[k].tag = -1;
                else if(tree[k].tag == -1)tree[k].tag = 1;
                else tree[k].tag = 2;
            }
        }
        //printf("tree[%d].cover=%d\n", k, tree[k].cover);
        return;
    }
    pushdown(k, l, r);
    int m = (l+r)/2;
    update(a, b, k*2+1, l, m, val);
    update(a, b, k*2+2, m, r, val);
    pushup(k);
}

ll query(int k, int l, int r)
{
    //printf("query(%d,%d,%d)\n", k, l, r);
    if(l == r-1)return num[l];
    pushdown(k, l, r);
    int m = (l+r)/2;
    if(tree[k*2+1].cover != 1)return query(k*2+1, l, m);
    else return query(k*2+2, m, r);
}

int main()
{
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        scanf("%d%lld%lld", &T[i], &L[i], &R[i]);
        num.pb(L[i]); num.pb(L[i]+1);
        num.pb(R[i]); num.pb(R[i]+1);
    }
    num.pb(1);
    sort(ALL(num));
    n = unique(ALL(num))-num.begin();
    for(int i = 0; i < n; i++){
        mp[num[i]] = i;
    }
    build(0, 0, n);
    for(int i = 0; i < q; i++){
        int l = mp[L[i]], r = mp[R[i]];
        update(l, r+1, 0, 0, n, T[i]);
        ll ans = query(0, 0, n);
        printf("%lld\n", ans);
    }
    return 0;
}

