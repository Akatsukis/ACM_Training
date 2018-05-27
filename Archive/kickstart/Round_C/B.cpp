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
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 20;
int len[maxn][maxn];
int ban[maxn][maxn];
int n, ans;

void dfs(vector<int> v, int x, int y)
{
    if(v.size() >= 3){
        //for(auto u : v)printf("%d ", u);
        int sum = 0;
        for(auto u : v)sum += u;
        //printf("sum=%d mx=%d\n", sum, *max_element(ALL(v)));
        if(sum - (*max_element(ALL(v)))*2 > 0)ans++;
    }
    for(int i = x; i <= n; i++){
        for(int j = (i==x)?y:i+1; j <= n; j++){
            if(!ban[i][j] && len[i][j]){
                v.pb(len[i][j]);
                vector<pii> tmp;
                for(int k = 1; k <= n; k++){
                    if(!ban[i][k]){
                        ban[i][k] = ban[k][i] = 1;
                        tmp.pb(mk(i, k));
                    }
                    if(!ban[k][j]){
                        ban[k][j] = ban[j][k] = 1;
                        tmp.pb(mk(k, j));
                    }
                }
                dfs(v, i, j+1);
                v.pop_back();
                for(pii p : tmp){
                    ban[p.fi][p.se] = ban[p.se][p.fi] = 0;
                }
            }
        }
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        ans = 0;
        sc(n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)sc(len[i][j]);
        }
        dfs(vector<int>(), 1, 1);
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

