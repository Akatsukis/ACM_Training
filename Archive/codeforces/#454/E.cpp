#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 30;
int mp[maxn][maxn];
vector<int> ans;

int main()
{
    int n, m;
    sc(n);sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u);sc(v);
        mp[u][v] = mp[v][u] = 1;
    }
    bool update = 1;
    while(update){
        update = 0;
        int mx = 0, id = 0;
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 1; j <= n; j++){
                if(!mp[i][j])continue;
                for(int k = j+1; k <= n; k++){
                    if(!mp[i][k])continue;
                    if(!mp[j][k])cnt++;
                }
            }
            if(cnt > mx){
                mx = cnt;
                id = i;
            }
        }
        if(mx){
            update = 1;
            for(int i = 1; i <= n; i++){
                for(int j = i+1; j <= n; j++){
                    if(mp[id][i] && mp[id][j])mp[i][j] = mp[j][i] = 1;
                }
            }
            ans.pb(id);
        }
    }
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d%c", ans[i], i == (int)ans.size() ? '\n' : ' ');
    }
    return 0;
}

