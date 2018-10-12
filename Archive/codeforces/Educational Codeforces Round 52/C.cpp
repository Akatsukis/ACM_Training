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
ll num[maxn], sum[maxn];
int n, k;

int main()
{
    sc(n); sc(k);
    for(int i = 0; i < n; i++){
        int h; sc(h);
        num[h]++;
    }
    for(int i = maxn-2; i >= 1; i--)num[i] += num[i+1];
    for(int i = 1; i < maxn; i++)sum[i] = sum[i-1]+num[i];
    int pos = 1;
    while(sum[pos] == 1LL*pos*n)pos++;
    int ans = 0, now = 0;
    for(int i = maxn-1; i >= pos; i--){
        if(now+num[i] > k){
            now = 0;
            ans++;
        }
        now += num[i];
    }
    if(now)ans++;
    printf("%d\n", ans);
    return 0;
}

