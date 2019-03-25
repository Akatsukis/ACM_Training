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
const int maxn = 3e2+10;
const int INF = 0x3f3f3f3f;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dist[maxn][maxn];
int n, m;

bool check(int d)
{
    for(int i = 0; i < n; i++){
        int l = 0, r = m-1;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(dist[x][y] > d){
                    int u = abs(x-i), v = d-u;
                    l = max(l, y-v); r = min(r, y+v);
                }
            }
        }
        if(l <= r)return 1;
    }
    return 0;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(m);
        queue<pii> q;
        for(int i = 0; i < n; i++){
            char s[maxn];
            scanf("%s", s);
            for(int j = 0; j < m; j++){
                if(s[j] == '1'){
                    q.push(mk(i, j));
                    dist[i][j] = 0;
                }
                else dist[i][j] = INF;
            }
        }
        while(!q.empty()){
            pii p = q.front(); q.pop();
            int x = p.fi, y = p.se;
            for(int i = 0; i < 4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(dist[nx][ny] > dist[x][y]+1){
                        dist[nx][ny] = dist[x][y]+1;
                        q.push(mk(nx, ny));
                    }
                }
            }
        }
        int l = 0, r = n+m, ans = 0;
        while(l <= r){
            int m = (l+r)/2;
            if(check(m)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

