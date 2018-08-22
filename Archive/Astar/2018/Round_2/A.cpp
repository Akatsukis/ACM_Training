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
const int maxn = 1e5+10;
vector<int> G[maxn];
int a[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        int n;
        sc(n);
        for(int i = 1; i <= n; i++)G[i].clear();
        for(int i = 2; i <= n; i++){
            int f; sc(f);
            G[f].pb(i);
        }
        for(int i = 1; i <= n; i++)sc(a[i]);
        ll mx = 0, mn = 0;
        if(a[1] < 0)mn += a[1];
        else mx += a[1];
        vector<int> v1, v2;
        for(int i = 1; i <= n; i++){
            int x[2] = {0}, y[2] = {0};
            for(auto v : G[i]){
                if(a[v] > 0){
                    x[1] = max(x[1], a[v]);
                    if(x[1] > x[0])swap(x[1], x[0]);
                }
                if(a[v] < 0){
                    y[1] = min(y[1], a[v]);
                    if(y[1] < y[0])swap(y[1], y[0]);
                }
            }
            if(x[0] > 0)mx += x[0];
            if(y[0] < 0)mn += y[0];
            if(x[1] > 0)v1.pb(x[1]);
            if(y[1] < 0)v2.pb(y[1]);
        }
        sort(ALL(v1), greater<int>());
        sort(ALL(v2));
        if(v1.size() && v1[0] > 0)mx += v1[0];
        if(v2.size() && v2[0] < 0)mn += v2[0];
        printf("%lld %lld\n", mx, mn);
    }
    return 0;
}


