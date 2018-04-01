#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n",x)
typedef long long ll;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;
int a[maxn];
int root[maxn*40], ls[maxn*40], rs[maxn*40], mn[maxn*40];
int cnt;

void init()
{
    cnt = 0;
}

void build(int &rt, int l, int r)
{
    rt = ++cnt;
    //printf("build(%d,%d,%d)\n", rt, l, r);
    mn[rt] = INF;
    if(l == r-1)return;
    int m = (l+r)>>1;
    build(ls[rt], l, m);
    build(rs[rt], m, r);
    mn[rt] = min(mn[ls[rt]], mn[rs[rt]]);
}

void update(int &rt, int l, int r, int last, int val, int id)
{
    rt = ++cnt;
    //printf("udpate(%d,%d,%d,%d,%d)\n", rt, l, r, last, val);
    mn[rt] = min(val, mn[last]), ls[rt] = ls[last], rs[rt] = rs[last];
    if(l == r-1)return;
    int m = (l+r)>>1;
    if(id < m)update(ls[rt], l, m, ls[last], val, id);
    else update(rs[rt], m, r, rs[last], val, id);
}

int query(int rt, int val, int l, int r, int qr)
{
    //printf("query(%d,%d,%d) mn[%d]=%d\n", val, l, r, rt, mn[rt]);
    //printf("mn[ls[rt]]=%d\n", mn[ls[rt]]);
    if(mn[rt] > val)return -1;
    if(l == r-1)return l;
    int m = (l+r)>>1;
    if(mn[ls[rt]] <= val || m > qr)return query(ls[rt], val, l, m, qr);
    else return query(rs[rt], val, m, r, qr);
}

int main()
{
    int T, n, q;
    sc(T);
    while(T--){
        scanf("%d", &n);
        init();
        for(int i = 1; i <= n; i++)sc(a[i]);
        build(root[n+1], 1, n+1);
        for(int i = n; i >= 1; i--){
            update(root[i], 1, n+1, root[i+1], a[i], i);
        }
        sc(q);
        for(int i = 1; i <= q; i++){
            int l, r;
            sc(l); sc(r);
            int ans = a[l];
            l++; r++;
            while(ans && l != r){
                //printf("l=%d, r=%d\n", l, r);
                l = query(root[l], ans, 1, n+1, r-1);
                if(l == -1)break;
                //printf("l=%d\n", l);
                ans %= a[l];
                l++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
