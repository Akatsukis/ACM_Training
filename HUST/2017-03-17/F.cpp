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
const int maxn = 260;
vector<bool> tmp[maxn];
vector<bool> mp[maxn];
bool broken[maxn][maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k;

void init()
{
    memset(broken, 0, sizeof(broken));
    for(int i = 0; i < n; i++)mp[i].clear();
}

void flip(int x, int y)
{
    for(int i = 0; i < n; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m)tmp[nx][ny] = !tmp[nx][ny];
    } 
}

bool solve()
{
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tmp[i-1][j]){
                if(broken[i][j])return false;
                else flip(i, j);
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(tmp[n-1][i])return false;
    }
    return true;
}

bool solve2()
{
    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            if(tmp[j][i-1]){
                if(broken[j][i-1])return false;
                else flip(j, i);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(tmp[i][m-1])return false;
    }
    return true;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%d%d%d", &n, &m, &k);
        init();
        for(int i = 0; i < n; i++){
            char s[maxn];
            scanf("%s", s);
            for(int j = 0; j < m; j++){
                if(s[j] == 'B')mp[i].pb(1);
                else mp[i].pb(0);
            }
        }
        for(int i = 0; i < k; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            broken[u][v] = 1;
        }
        bool ans = 0;
        if(m < n){
        for(int i = 0; i < (1<<m); i++){
            for(int j = 0; j < n; j++)tmp[j] = mp[j];
            bool flag = 1;
            for(int j = 0; j < m; j++){
                if((i>>j)&1){
                    if(broken[0][j]){
                        flag = 0;
                        break;
                    }
                    else flip(0, j);
                }
            }
            if(!flag)continue;
            if(solve()){
                ans = 1;
                break;
            }
        }
        }
        else{
        for(int i = 0; i < (1<<n); i++){
            for(int j = 0; j < n; j++)tmp[j] = mp[j];
            bool flag = 1;
            for(int j = 0; j < n; j++){
                if((i>>j)&1){
                    if(broken[j][0]){
                        flag = 0;
                        break;
                    }
                    else flip(j, 0);
                }
            }
            if(!flag)continue;
            if(solve2()){
                ans = 1;
                break;
            }
        }
        
        }
        if(ans)printf("Case %d: Yes\n", kase++);
        else printf("Case %d: No\n", kase++);
    }
    return 0;
}

