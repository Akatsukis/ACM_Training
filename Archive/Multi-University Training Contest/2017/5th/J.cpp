#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

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
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxm = 1e4+10;
ll b[maxm];
ll dp[maxm];
ll n, m;
vector<int> ans;

int main()
{
    int T;
    sc(T);
    while(T--){
        ans.clear();
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        scanf("%lld%lld", &n, &m);
        for(int i = 0; i <= m; i++){
            scanf("%lld", &b[i]);
        }
        for(int i = 1; i <= m; i++){
            ll cur = b[i] - dp[i];
            for(int j = 0; j < cur; j++)ans.pb(i);
            for(int j = 0; j < cur; j++){
                for(int k = m-i; k >= 0; k--){
                    dp[k+i] += dp[k];
                    //printf("dp[%d+%d]+=dp[%d]=%d\n", k, i, k, dp[k+i]);
                }
            }
        }
        for(int i = 0; i < (int)ans.size(); i++){
            printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}

