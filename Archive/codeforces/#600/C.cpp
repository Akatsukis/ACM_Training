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
    scanf("%d%d", &n, &m);
    vector<int> vec(n);
    vector<long long> add(m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    sort(vec.begin(), vec.end());
    vector<long long> ans(n);
    long long now = 0;
    for(int i = 0; i < n; i++) {
        now += add[i%m];
        add[i%m] += vec[i];
        now += vec[i];
        ans[i] = now;
    }
    for(int i = 0; i < n; i++) {
        printf("%lld%c", ans[i], " \n"[i==n-1]);
    }
    return 0;
}

