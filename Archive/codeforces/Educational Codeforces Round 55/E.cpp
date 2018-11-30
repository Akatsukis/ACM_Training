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
const int maxn = 5e5+10;
int a[maxn], sum[maxn];
vector<int> G[maxn];
int n, c;

int main()
{
    int n, c;
    sc(n); sc(c);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
        sum[i] = sum[i-1];
        if(a[i] == c)sum[i]++;
        else G[a[i]].pb(i);
    }
    int ans = sum[n];
    for(int i = 1; i < maxn; i++){
        int now = sum[n], l = 0;
        for(int j = 0; j < (int)G[i].size(); j++){
            int u = G[i][j];
            if(!l){
                now++;
                ans = max(ans, now);
            }
            else{
                now = now+1-(sum[u-1]-sum[l]);
                if(now <= sum[n])now = sum[n]+1;
                ans = max(ans, now);
            }
            l = u;
        }
    }
    printf("%d\n", ans);
    return 0;
}

