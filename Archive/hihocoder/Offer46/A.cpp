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
const int maxn = 1e6+10;
int dp[maxn][3];
int dp1[maxn][2];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='a'){
            if(i)dp[i][0] = dp[i-1][0]+1;
            else dp[i][0] = 1;
        }
        else if(i)dp[i][0] = dp[i-1][0];
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='e'){
            if(i)dp[i][1] = max(dp[i-1][1]+1, dp[i-1][0]+1);
            else dp[i][1] = 1;
        }
        else if(i)dp[i][1] = dp[i-1][1];
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='i'){
            if(i)dp[i][2] = max(dp[i-1][2]+1, dp[i-1][1]+1);
            else dp[i][2] = 1;
        }
        else if(i)dp[i][2] = dp[i-1][2];
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='o'){
            if(i)dp1[i][0] = dp1[i-1][0]+1;
            else dp1[i][0] = 1;
        }
        else if(i)dp1[i][0] = dp1[i-1][0];
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='u'){
            if(i)dp1[i][1] = max(dp1[i-1][1]+1, dp1[i-1][0]+1);
            else dp1[i][1] = 1;
        }
        else if(i)dp1[i][1] = dp1[i-1][1];
    }
    int ans = dp[n-1][2] + dp1[n-1][1];
    printf("%d\n", ans);
    return 0;
}

