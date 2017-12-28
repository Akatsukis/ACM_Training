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
const int maxn = 1e5+10;
char s[maxn];
int dp[maxn][2];//1->a 0->b
pii ans[maxn];
int sum[maxn];
int n, m;

pii Max(const pii &a, const pii &b)
{
    if(a.fi>b.fi)return a;
    else if(a.fi == b.fi){
        if(a.se<b.se)return a;
        else return b;
    }
    else return b;
}

int main()
{
    scanf("%d%s%d", &n, s+1, &m);
    for(int i = 1; i <= n; i++){
        sum[i]=sum[i-1]+(s[i]=='?');
        if(s[i]!='a')dp[i][0]=dp[i-1][1]+1;
        if(s[i]!='b')dp[i][1]=dp[i-1][0]+1;
        if(dp[i][m&1]>=m)ans[i]=mk(ans[i-m].fi+1, ans[i-m].se+sum[i]-sum[i-m]);
        ans[i]=Max(ans[i],ans[i-1]);
    }
    printf("%d\n", ans[n].se);
    return 0;
}

