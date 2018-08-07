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
const int INF = 0x3f3f3f3f;
set<int> st1, st2;

int main()
{
    int n, x;
    sc(n); sc(x);
    int ans = INF;
    for(int i = 0; i < n; i++){
        int y; sc(y);
        if(st1.count(y))ans = min(ans, 0);
        else if(st1.count(y&x) || st2.count(y))ans = min(ans, 1);
        else if(st2.count(y&x))ans = min(ans, 2);
        st1.insert(y);
        st2.insert(y&x);
    }
    if(ans == INF)puts("-1");
    else printf("%d\n", ans);
    return 0;
}


