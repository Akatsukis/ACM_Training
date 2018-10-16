#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ALL(A) A.begin(),A.end()
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n", x)
#define Abs(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5000;
//int E[maxn];
//int F[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n;
        sc(n);
        int ans = 0;
        if(n < 3)ans = 1;
        else if(n < 5)ans = 2;
        else if(n < 6)ans = 4;
        else if(n < 8)ans = 5;
        else if(n < 10)ans = 6;
        else if(n < 18)ans = 7;
        else if(n < 24)ans = 8;
        else if(n < 30)ans = 9;
        else ans = 10;
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}
