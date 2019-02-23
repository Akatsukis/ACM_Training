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
const int maxn = 1e2+10;
int a[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++)sc(a[i]);
    sort(a, a+n);
    vector<int> v1, v2;
    for(int i = 0; i < n; i += 2)v1.pb(a[i]);
    for(int i = 1; i < n; i += 2)v2.pb(a[i]);
    reverse(ALL(v2));
    for(auto u : v1)printf("%d ", u);
    for(auto u : v2)printf("%d ", u);
    return 0;
}

