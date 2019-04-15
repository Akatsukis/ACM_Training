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

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        int r, c;
        scanf("%d%d", &r, &c);
        bool rev = 0;
        if(r > c){
            rev = 1;
            swap(r, c);
        }
        vector<vector<bool> > vis(r, vector<bool>(c, 0));
        vector<pii> ans;
        int x = 0, y = 0;
        bool found = 1;
        while(found){
            found = 0;
            while(1){
                vis[x][y] = 1;
                if(rev)ans.pb(mk(y+1, x+1));
                else ans.pb(mk(x+1, y+1));
                int nx = (x+1)%r, ny = (y+2)%c;
                if(nx == x || ny == y || nx-ny == x-y || nx+ny == x+y || vis[nx][ny])break;
                else x = nx, y = ny;
            }
            for(int i = 0; i < r; i++){
                if(i == x)continue;
                for(int j = 0; j < c; j++){
                    if(j == y || i+j == x+y || i-j == x-y || vis[i][j])continue;
                    x = i, y = j; found = 1;
                    break;
                }
                if(found)break;
            }
        }
        bool ok = 1;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!vis[i][j])ok = 0;
            }
        }
        if(!ok)printf("Case #%d: IMPOSSIBLE\n", kase++);
        else{
            printf("Case #%d: POSSIBLE\n", kase++);
            for(auto p : ans)printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}

