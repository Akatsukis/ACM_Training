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
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 20;
int a[maxn], b[maxn];
int sum[2][3];
int fac[20];
double ans, now, tot;
int n;


void dfs2(int u, int v, int w)
{
    //printf("dfs2(%d,%d,%d)\n", u, v, w);
    if(u == 3 && v == 3 && w == 3){
        tot++;
        int win = 0;
        for(int i = 0; i < 3; i++){
            if(sum[0][i] > sum[1][i])win++;
        }
        if(win > n/2)now++;
        return;
    }
    int id = u+v+w;
    if(u < 3){
        sum[1][0] += b[id];
        dfs2(u+1, v, w);
        sum[1][0] -= b[id];
    }
    if(v < 3){
        sum[1][1] += b[id];
        dfs2(u, v+1, w);
        sum[1][1] -= b[id];
    }
    if(w < 3){
        sum[1][2] += b[id];
        dfs2(u, v, w+1);
        sum[1][2] -= b[id];
    }   
}

void dfs1(int u, int v, int w)
{
    //printf("dfs1(%d,%d,%d)\n", u, v, w);
    if(u == 3 && v == 3 && w == 3){
        now = tot = 0;
        dfs2(0, 0, 0);
        ans = max(ans, now/tot);
        return;
    }
    int id = u+v+w;
    if(u < 3){
        sum[0][0] += a[id];
        dfs1(u+1, v, w);
        sum[0][0] -= a[id];
    }
    if(v < 3){
        sum[0][1] += a[id];
        dfs1(u, v+1, w);
        sum[0][1] -= a[id];
    }
    if(w < 3){
        sum[0][2] += a[id];
        dfs1(u, v, w+1);
        sum[0][2] -= a[id];
    }
}

int main()
{
    fac[0] = 1;
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < 3*n; i++)sc(a[i]);
        for(int j = 0; j < 3*n; j++)sc(b[j]);
        ans = 0;
        dfs1(0, 0, 0);
        printf("Case #%d: %.10f\n", kase++, ans);
    }
    return 0;
}


