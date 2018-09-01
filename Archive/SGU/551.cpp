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

int main()
{
    int n, t1, t2;
    scanf("%d%d%d", &n, &t1, &t2);
    int ans1 = 0, ans2 = 0;
    int u = 0, v = 0;
    for(int i = 1; i <= max(n*t1, n*t2); i++){
        if(ans1 < n)u++;
        if(ans1 < n)v++;
        if(u == t1)u = 0, ans1++;
        if(v == t2)v = 0, ans1++;
        if(ans1 >= n){
            if(u != 0)ans2 = i+t1-u, ans1++;
            else if(v != 0)ans2 = i+t2-v, ans1++;
            else ans2 = i;
            break;
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}

