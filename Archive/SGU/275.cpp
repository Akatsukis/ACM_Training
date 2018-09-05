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
const int maxl = 63;
const int maxn = 110;
ll b[maxn];

void insert(ll x)
{
    for(int i = maxl; i >= 0; i--){
        if((x>>i)&1){
            if(b[i])x ^= b[i];
            else{
                b[i] = x;
                for(int j = i-1; j >= 0; j--)if(b[j] && ((b[i]>>j)&1))b[i] ^= b[j];
                for(int j = i+1; j <= maxl; j++)if((b[j]>>i)&1)b[j] ^= b[i];
                break;
            }
        } 
    }
}

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++){
        ll x; scanf("%lld", &x);
        insert(x);
    }
    ll ans = 0;
    for(int i = 0; i <= maxl; i++)ans ^= b[i];
    printf("%lld\n", ans);
    return 0;
}

