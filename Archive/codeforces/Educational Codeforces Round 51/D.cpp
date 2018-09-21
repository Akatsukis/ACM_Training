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
const int mod = 998244353;
const int maxn = 2e3+10;
int dp[maxn][maxn][4];

int get(int x, int y)
{
    if(x == 0){
        if(y == 0)return 0;
        else return 1;
    }
    else if(x == 1){
        if(y == 2)return 2;
        else return 0;
    }
    else if(x == 2){
        if(y == 1)return 2;
        else return 0;
    }
    else{
        if(y == 3)return 0;
        else return 1;
    }
}

void Add(int &a, int b)
{
    a = (a+b)%mod;
}

int main()
{
    int n, t;
    sc(n); sc(t);
    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    dp[1][1][3] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= t; j++){
            for(int k = 0; k < 4; k++){
                for(int h = 0; h < 4; h++){
                    Add(dp[i+1][j+get(k, h)][h], dp[i][j][k]);
                    //printf("dp[%d][%d]=%d\n", i+1, j+get(k, h), dp[i+1][j+get(k, h)][h]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        Add(ans, dp[n][t][i]);
    }
    printf("%d\n", ans);
    return 0;
}

