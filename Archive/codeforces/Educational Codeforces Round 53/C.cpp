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
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+10;
char s[maxn];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, sx, sy;

int id(char c)
{
    if(c == 'U')return 0;
    if(c == 'D')return 1;
    if(c == 'L')return 2;
    if(c == 'R')return 3;
    assert(0);
}

bool check(int m)
{
    int x1 = 0, y1 = 0, x2 = sx, y2 = sy;
    for(int i = n-1; i >= m; i--){
        x2 += dx[id(s[i])^1], y2 += dy[id(s[i])^1];
    }
    for(int i = 0; i+m <= n; i++){
        if(ABS(x1-x2)+ABS(y1-y2) <= m)return 1;
        if(i+m == n)break;
        x1 += dx[id(s[i])]; y1 += dy[id(s[i])];
        x2 += dx[id(s[i+m])]; y2 += dy[id(s[i+m])];
    }
    return 0;
}

int main()
{
    scanf("%d%s%d%d", &n, s, &sx, &sy);
    if((ABS(sx)+ABS(sy))%2 != n%2){
        printf("-1\n");
        return 0;
    }
    int l = 0, r = n, ans = INF;
    while(l <= r){
        int m = (l+r)>>1;
        if(check(m)){
            ans = min(ans, m);
            r = m-1;
        }
        else l = m+1;
    }
    if(ans == INF)ans = -1;
    printf("%d\n", ans);
    return 0;
}

