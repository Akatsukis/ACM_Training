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
    int n, m;
    sc(m); sc(n);
    vector<int> vec(n, 0);
    for(auto &u : vec)sc(u);
    sort(ALL(vec));
    vector<int> num;
    long long ans = 0;
    for(int i = 0; i < (int)vec.size()-1; i++){
        num.pb(vec[i+1]-vec[i]);
        ans += vec[i+1]-vec[i];
    }
    sort(ALL(num), greater<int>());
    for(int i = 0; i < min(m-1, (int)num.size()); i++){
        ans -= num[i];
    }
    printf("%lld\n", ans);
    return 0;
}

