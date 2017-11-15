#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 998244353;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
ll num[maxn];
ll res[maxn];
int prime[maxn];
bool vis[maxn];
int cnt;

void init()
{
    for(int i = 2; i <= maxn; i++){
        if(!vis[i]){
            prime[cnt++] = i;
            for(int j = i*2; j <= maxn; j += i)vis[j] = 1;
        }
    }
    //cout << cnt << endl;
}

int main()
{
    init();
    int T;
    sc(T);
    while(T--){
        ll l, r, k;
        scanf("%lld%lld%lld", &l, &r, &k);
        for(ll i = 0; i <= r - l; i++){
            num[i] = i + l;
            res[i] = 1;
        }
        for(int i = 0; i < cnt; i++){
            int t = prime[i];
            for(ll j = (l+t-1)/t*t; j <= r; j += t){
                int p = 0;
                while(num[j-l]%t==0){
                    num[j-l] /= t;
                    p++;
                }
                //printf("j-l=%d\n", j - l);
                res[j-l] = (k*p+1)% mod*res[j-l]%mod;
            }
        }
        ll ans = 0;
        for(ll i = 0; i <= r - l; i++){
            if(num[i] > 1)res[i] = (k+1)*res[i]%mod;
            ans += res[i];
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

