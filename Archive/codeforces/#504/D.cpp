#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define lson k*2+1
#define rson k*2+2
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+10;
int a[maxn], mx[maxn], mn[maxn], tr[maxn*4];

void build(int k, int l, int r)
{
    if(l == r-1){
        tr[k] = !a[l]?INF:a[l];
        return;
    }
    int m = (l+r)>>1;
    build(lson, l, m);
    build(rson, m, r);
    tr[k] = min(tr[lson], tr[rson]);
}

int query(int a, int b, int k, int l, int r)
{
    if(a >= r || b <= l)return INF;
    if(a <= l && b >= r)return tr[k];
    int m = (l+r)>>1;
    int v1 = query(a, b, lson, l, m);
    int v2 = query(a, b, rson, m, r);
    return min(v1, v2);
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int val = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(!mn[a[i]])mn[a[i]] = i;
        mx[a[i]] = i;
        if(a[i])val = max(val, a[i]);
    }
    bool flg = 1;
    if(val != q){
        flg = 0;
        for(int i = 1; i <= n; i++){
            if(!a[i]){
                flg = 1;
                a[i] = q;
                break;
            }
        }   
    }
    build(0, 0, n);
    for(int i = 1; i <= q; i++){
        if(mn[i] == mx[i])continue;
        int ans = query(mn[i], mx[i]+1, 0, 0, n);
        if(ans < i){
            flg = 0;
            break;
        }
    }
    if(!a[1])a[1] = 1;
    int pre = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i])pre = a[i];
        else a[i] = pre;
    }
    if(flg){
        puts("YES");
        for(int i = 1; i <= n; i++){
            printf("%d%c", a[i], " \n"[i==n]);
        }
    }
    else puts("NO");
    return 0;
}


