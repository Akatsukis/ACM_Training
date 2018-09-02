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
const int maxn = 2e2+10;
const int maxm = 2e4+10;
int deck[maxm], num[maxn][14];
int ans[maxn], tot[maxn];
int n, m, win, idx;

void init()
{
    for(int i = 0; i < n; i++){
        ans[i] = tot[i] = 0;
        for(int j = 1; j <= 13; j++)num[i][j] = 0;
    }
    idx = 0;
}

void draw(int u)
{
    if(idx < m){
        tot[u]++;
        num[u][deck[idx++]]++;
    }
}

int play(int u, int x)
{
    if(x == 2)return 0;
    if(!x){
        for(int i = 3; i <= 13; i++){
            if(num[u][i]){
                num[u][i]--;
                tot[u]--;
                return i;
            }
        }
        for(int i = 1; i <= 2; i++){
            if(num[u][i]){
                num[u][i]--;
                tot[u]--;
                return i;
            }
        }
    }
    else{
        if(x < 13)x++;
        else x = 1;
        if(num[u][x]){
            num[u][x]--;
            tot[u]--;
            return x;
        }
        else if(num[u][2]){
            num[u][2]--;
            tot[u]--;
            return 2;
        }
    }
    return 0;
}

void solve()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++)draw(i);
    }
    int pre = 0, u = 0, cnt = 0;
    while(1){
        int now = play(u, pre);
        if(!now)cnt++;
        else pre = now, cnt = 0;
        if(!tot[u]){
            win = u;
            break;
        }
        u = (u+1)%n;
        if(cnt == n-1){
            for(int i = 0; i < n; i++)draw((u+i)%n);
            cnt = pre = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 13; j++){
            ans[i] += j*num[i][j];
        }
    }
}

int main()
{
    int T, kase = 1; 
    sc(T);
    while(T--){
        sc(n); sc(m);
        init();
        for(int i = 0; i < m; i++)sc(deck[i]);
        solve();
        printf("Case #%d:\n", kase++);
        for(int i = 0; i < n; i++){
            if(win == i)puts("Winner");
            else printf("%d\n", ans[i]);
        }
    }
    return 0;
}

