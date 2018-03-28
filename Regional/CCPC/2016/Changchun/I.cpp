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
const int maxn = 2e5+10;
int root[maxn], val[maxn*40], ls[maxn*40], rs[maxn*40];
int a[maxn], pre[maxn];
int tot;

void init()
{
    memset(root, 0, sizeof(root));
    memset(pre, 0, sizeof(pre));
    tot = 0;
}

void build(int &rt, int l, int r)
{
    rt = ++tot;
    val[rt] = 0;
    if(l == r-1)return;
    int m = (l+r)>>1;
    build(ls[rt], l, m);
    build(rs[rt], m, r);
}

void update(int &rt, int l, int r, int last, int pos, int v)
{
    //printf("update(%d,%d,%d,%d)\n", l, r, pos, v);
    rt = ++tot;
    val[rt] = val[last]+v; ls[rt] = ls[last], rs[rt] = rs[last];
    //printf("val=%d\n", val[rt]);
    if(l == r-1)return;
    int m = (l+r)>>1;
    if(pos < m)update(ls[rt], l, m, ls[last], pos, v);
    else update(rs[rt], m, r, rs[last], pos, v);
}

int query_num(int a, int b, int rt, int l, int r)
{
    if(l >= b || r <= a)return 0;
    else if(l >= a && r <= b)return val[rt];
    int m = (l+r)>>1;
    int v1 = query_num(a, b, ls[rt], l, m);
    int v2 = query_num(a, b, rs[rt], m, r);
    return v1+v2;
}

int query_id(int rt, int l, int r, int k)
{
    //printf("id(%d,%d,%d,%d)\n", rt, l, r, k);
    if(l == r-1)return l;
    int m = (l+r)>>1;
    int cnt = val[ls[rt]];
    if(cnt >= k)return query_id(ls[rt], l, m, k);
    else return query_id(rs[rt], m, r, k-cnt);
    return -1;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        init();
        int n, m;
        sc(n); sc(m);
        for(int i = 1; i <= n; i++)sc(a[i]);
        build(root[n+1], 1, n+1);
        for(int i = n; i >= 1; i--){
            int tmp = root[i+1];
            if(pre[a[i]])update(tmp, 1, n+1, root[i+1], pre[a[i]], -1);
            update(root[i], 1, n+1, tmp, i, 1);
            pre[a[i]] = i;
        }
        int ans = 0;
        printf("Case #%d: ", kase++);
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            int l = min((u+ans)%n+1, (v+ans)%n+1);
            int r = max((u+ans)%n+1, (v+ans)%n+1);
            int k = query_num(l, r+1, root[l], 1, n+1);
            //puts("");
            //printf("l=%d, r=%d, k=%d\n", l, r, k);
            k = (k+1)>>1;
            ans = query_id(root[l], 1, n+1, k);
            printf("%d%c", ans, " \n"[i==m-1]);
        }
    }
    return 0;
}

