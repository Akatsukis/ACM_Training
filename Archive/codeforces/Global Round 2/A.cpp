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
const int maxn = 3e5+10;

int main()
{
    int n;
    sc(n);
    vector<int> vec(n, 0);
    for(auto &u :vec)sc(u);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(vec[i] != vec[0])ans = max(ans, i);
        if(vec[i] != vec[n-1])ans = max(ans, n-1-i);
    }
    printf("%d\n", ans);
    return 0;
}

