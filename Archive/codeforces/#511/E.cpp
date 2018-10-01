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
const int maxn = 1e6+10;
ll sum[maxn], f[maxn], g[maxn];
int p[maxn];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++)scanf("%lld", &sum[i]);
    for(int i = 2; i <= n; i++)sc(p[i]);
    for(int i = n; i >= 2; i--)sum[p[i]] += sum[i];
    for(int i = 1; i <= n; i++){
        ll d = sum[1]/gcd(sum[1], sum[i]);
        if(d <= n)f[d]++;
    }
    for(int i = n; i >= 1; i--){
        for(int j = i*2; j <= n; j += i)f[j] += f[i];
    }
    for(int i = n; i >= 1; i--){
        if(f[i] >= i){
            g[i]++;
            for(int j = i*2; j <= n; j += i)g[i] += g[j];
        }
    }
    printf("%lld\n", g[1]);
    return 0;
}

