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
const int maxn = 2e5+10;
int mn[maxn], mx[maxn];
long long s;
int n;

bool check(int m) {
    vector<int> v1, v2;
    for(int i = 0; i < n; i++) {
        if(mx[i] >= m) {
            v2.push_back(mn[i]);
        }
        else {
            v1.push_back(mn[i]);
        }
    }
    int half = (n+1)/2;
    if((int)v2.size() < half)return 0;
    sort(v2.begin(), v2.end());
    long long tot = 0;
    for(int i = 0; i < (int)v2.size(); i++) {
        if(i+half >= (int)v2.size()) {
            tot += max(v2[i], m);
        }
        else v1.push_back(v2[i]);
    }
    for(auto val: v1) {
        tot += val;
    }
    return s >= tot;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%lld", &n, &s);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &mn[i], &mx[i]);
        }
        int l = 1, r = 1e9, ans = 0;
        while(l <= r) {
            int m = (l+r)/2;
            if(check(m)) {
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

