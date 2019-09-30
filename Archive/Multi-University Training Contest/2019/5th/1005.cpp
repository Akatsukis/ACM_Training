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
const int maxn = 21;
ll fac[maxn];

void init() {
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = fac[i-1]*i;
}

bool cmp(vector<int> &a, vector<int> &b) {
    int n = a.size();
    for(int i = 0; i < n-1; i++) {
        int u = a[i+1]-a[i], v = b[i+1]-b[i];
        if(u < v)return 1;
        if(u > v)return 0;
    }
    return 0;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> ans;
        if(fac[n-2] >= k) {
            vector<int> vec;
            for(int i = 2; i < n; i++) vec.push_back(i);
            while(--k) next_permutation(ALL(vec));
            ans.pb(n); ans.pb(1);
            for(auto u: vec) ans.pb(u);
        }
        else {
            vector<vector<int>> all;
            vector<int> vec;
            for(int i = 1; i <= n; i++) {
                vec.pb(i);
            }
            do all.pb(vec);
            while(next_permutation(ALL(vec)));
            sort(ALL(all), cmp);
            ans = all[k-1];
        }
        for(int i = 0; i < n; i++) {
            printf("%d%c", ans[i], " \n"[i==n-1]);
        }
    }
    return 0;
}

