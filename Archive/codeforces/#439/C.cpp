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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 998244353;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int p[5010][5010];
int q[5010][5010];

void init()
{
    for(int i = 1; i <= 5000; i++){
        p[0][i] = 1;
        for(int j = 1; j <= i; j++){
            p[j][i] = (ll)p[j - 1][i] * (i - j + 1) % mod;
        }
    }
    for(int i = 1; i <= 5000; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i)q[j][i] = 1;
            else q[j][i] = (q[j][i - 1] + q[j - 1][i - 1]) % mod;
        }
    }
}



int main()
{
    init();
    ll a, b, c;
    cin >> a >> b >> c;
    if(a < b)swap(a, b);
    if(a < c)swap(a, c);
    if(b < c)swap(b, c);
    ll ans = 0;
    ll x = 0, y = 0, z = 0;
    for(int i = 0; i <= b; i++){
         x += (ll)p[i][a] * q[i][b];
         x %= mod;
    }
    for(int i = 0; i <= c; i++){
         y += (ll)p[i][b] * q[i][c];
         y %= mod;
    }
    for(int i = 0; i <= c; i++){
         z += (ll)p[i][a] * q[i][c];
         z %= mod;
    }
    ans = x * y % mod;
    ans = ans * z % mod;
    cout << ans << endl;
	return 0;
}


