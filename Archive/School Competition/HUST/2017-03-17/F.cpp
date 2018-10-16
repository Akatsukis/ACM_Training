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
bool mp[maxn][maxn];
bool tmp[maxn][maxn];
bool mat[maxn][maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k;

void init()
{
    memset(mp, 0, sizeof(mp));
}


bool solve()
{
    for(int i = 1; i <= m; i++){
        for(int j = i+1; j <= m; j++){
            while(mat[j][i]){
                for(int k = i; k <= m; k++){
                    mat[i][k] ^= mat[j][k];
                    swap(mat[j][k], mat[j][k]);
                }
            }
        }   
        if(!mat[i][i])return false;
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
        for(int i = 1; i <= n; i++){
            char s[maxn];
            scanf("%s", s);
            for(int j = 1; j <= m; j++)
                if(s[j-1] == 'B')mp[i][j] = 1;
        }
        for(int i = 1; i <= m; i++){
            memset(tmp, 0, sizeof(tmp));
            tmp[1][i] = 1;
            for(int j = 2; j <= n+1; j++){
                for(int k = 1; k <= m; k++){
                    tmp[j][k] = tmp[j-1][k]^tmp[j-1][k-1]^tmp[j-1][k+1]^tmp[j-2][k]^mp[j-1][k];
                }
            }
            for(int j = 1; j <= m; j++){
                mat[j][i] = tmp[n+1][j];
            }
        }
        bool flag = solve();
        if(flag)printf("Case %d: Yes\n", kase++);
        else printf("Case %d: No\n", kase++);
    }
    return 0;
}

