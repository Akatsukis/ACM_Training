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
const int maxn = 101;
int n, m;
int f[maxn*maxn][maxn];
int l[maxn];
int r[maxn];

ll solve(int x, int y, int c)
{
    ll res = 0;
    for(int i = 1; i <= x; i++){
        l[i] = 0, r[i] = m + 1;
    }
    for(int i = 1; i < y; i++)l[f[c][i]] = i;
    for(int i = m; i > y; i--)r[f[c][i]] = i;
    int h = f[c][y];
    for(int i = x-1; i > h; i--){
        l[i] = max(l[i], l[i+1]);
        r[i] = min(r[i], r[i+1]);
    }
    for(int i = x; i > h; i--){
        res += (ll)(y-l[i])*(r[i]-y)*(n-x+1);
    }
    return res;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        memset(f, 0, sizeof(f));
        sc(n);sc(m);
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int c;
                sc(c);
                ans += solve(i, j, c);
                f[c][j] = i;
            }
        }
        ll sum = (ll)(n+1)*n/2*m*(m+1)/2;
        printf("%.9f\n", 1.0*ans/sum);
    }
    return 0;
}

