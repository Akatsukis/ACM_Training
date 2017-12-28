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
const int maxn = 1e5;
int ans;

int Mobius(int x)
{
    if(x == 1)return 1;
    int num = 0;
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0){
            x /= i;
            num++;
            if(x%i==0)return 0;
        }
    }
    if(x>1)num++;
    return num&1?-1:1;
}

int qpow(int a, int n)
{
    int res = 1;
    while(n){
        if(n&1)res=1LL*res*a%mod;
        a=1LL*a*a%mod;
        n>>=1;
    }
    return res;
}

void solve(int n)
{
    for(int i = 1; i*i <= n; i++){
        if(n%i==0){
            ans += Mobius(n/i)*qpow(2, i-1);
            ans = (ans+mod)%mod;
            ans += Mobius(i)*qpow(2, n/i-1);
            ans = (ans+mod)%mod;
        }
        if(i*i==n){
            ans -= Mobius(i)*qpow(2, i-1);
            ans = (ans+mod)%mod;
        }
    }

}

int main()
{
    int x, y;
    sc(x);sc(y);
    if(y%x)return !printf("0\n");
    int p = y/x;
    solve(p);
    printf("%d\n", ans);
    return 0;
}

