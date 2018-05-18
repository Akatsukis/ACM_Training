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
#define lson k*2+1
#define rson k*2+2
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 4e5+10;
struct Node
{
    ll sum[2], tag;
}tree[maxn*4][2];

void init()
{
    memset(tree, 0, sizeof(tree));
}

void pushdown(int k, int t, int l, int r)
{
    if(l != r-1 && tree[k][t].tag){
        int m = (l+r)>>1, tag = tree[k][t].tag;
        tree[lson][t].sum[0] += 1LL*tag*(m-l);
        tree[lson][t].sum[1] += 1LL*tag*(l+m-1)*(m-l)/2;
        tree[lson][t].tag += tag;
        tree[rson][t].sum[0] += 1LL*tag*(r-m);
        tree[rson][t].sum[1] += 1LL*tag*(m+r-1)*(r-m)/2;
        tree[rson][t].tag += tag;
        tree[k][t].tag = 0;
    }
}

void pushup(int k, int t)
{
    tree[k][t].sum[0] = tree[lson][t].sum[0]+tree[rson][t].sum[0];
    tree[k][t].sum[1] = tree[lson][t].sum[1]+tree[rson][t].sum[1];
}

void update(int a, int b, int k, int l, int r, int t)
{
    //printf("update(%d,%d,%d,%d,%d,%d)\n", a, b, k, l, r, t);
    //fflush(stdout);
    if(a >= r || b <= l)return;
    if(a <= l && b >= r){
        tree[k][t].sum[0] += r-l;
        tree[k][t].sum[1] += 1LL*(l+r-1)*(r-l)/2;
        //printf("l=%d, r=%d, a[i]=%lld, a[i]*i=%lld\n", l, r, tree[k][t].sum[0], tree[k][t].sum[1]);
        tree[k][t].tag++;
        return;
    }
    pushdown(k, t, l, r);
    int m = (l+r)>>1;
    update(a, b, lson, l, m, t);
    update(a, b, rson, m, r, t);
    pushup(k, t);
    //printf("l=%d, r=%d, a[i]=%lld, a[i]*i=%lld\n", l, r, tree[k][t].sum[0], tree[k][t].sum[1]);
}

ll query(int a, int b, int k, int l, int r, int t, int p)
{
    //printf("query(%d,%d,%d,%d,%d,%d,%d)\n", a, b, k, l, r, t, p);
    if(a >= r || b <= l)return 0;
    if(a <= l && b >= r)return tree[k][t].sum[p];
    //printf("l=%d, r=%d, a[i]=%lld, a[i]*i=%lld\n", l, r, tree[k][t].sum[0], tree[k][t].sum[1]);
    pushdown(k, t, l, r);
    //printf("l=%d, r=%d, a[i]=%lld, a[i]*i=%lld\n", l, r, tree[k][t].sum[0], tree[k][t].sum[1]);
    int m = (l+r)>>1;
    ll v1 = query(a, b, lson, l, m, t, p);
    ll v2 = query(a, b, rson, m, r, t, p);
    //printf("v1=%lld, v2=%lld\n", v1, v2);
    return v1+v2;
}

ll qtriangle(int l, int r, int t)
{
    //printf("qtri(%d,%d,%d)\n", l, r, t);
    //ll v1 = query(l, r+1, 0, 0, maxn, t, 1);
    //ll v2 = 1LL*(l-1)*query(l, r+1, 0, 0, maxn, t, 0);
    //printf("v1=%lld, v2=%lld\n", v1, v2);
    ll ret = query(l, r+1, 0, 0, maxn, t, 1)-1LL*(l-1)*query(l, r+1, 0, 0, maxn, t, 0);
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        init();
        int n, q;
        sc(n); sc(q);
        printf("Case #%d:\n", kase++);
        for(int i = 0; i < q; i++){
            int t; sc(t);
            if(t == 1){
                int l, r;
                sc(l); sc(r);
                //printf("%d %d\n", l, r+1);
                //fflush(stdout);
                update(l-1, r, 0, 0, maxn, 0);
            }
            else if(t == 2){
                int l, r;
                sc(l); sc(r);
                //printf("%d %d\n", l+n, r+n+1);
                //fflush(stdout);
                update(l+n, r+n+1, 0, 0, maxn, 1);
            }
            else if(t == 3){
                int x1, x2, y1, y2;
                scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
                ll ans = 0;
                ans += qtriangle(x1+y1-1, x2+y2-1, 0);
                ans -= qtriangle(x1+y2, x2+y2-1, 0);
                ans -= qtriangle(x2+y1, x2+y2-1, 0);
                //printf("ans=%lld\n", ans);
                ans += qtriangle(x1-y2+n, x2-y1+n, 1);
                ans -= qtriangle(x1-y1+1+n, x2-y1+n, 1);
                ans -= qtriangle(x2-y2+1+n, x2-y1+n, 1);
                printf("%lld\n", ans);                
            }
        }
    }
    return 0;
}

