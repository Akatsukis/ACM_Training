#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e6+10;
ll a[maxn];
ll b[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
    for(int i = 0; i < n; i++)scanf("%lld", &b[i]);
    for(int i = 0; i < n; i++){
        ll tmp = min(a[i], b[i]);
        a[i] -= tmp, b[i] -= tmp;
    }
    ll ans = 0;
    int id = 0;
    for(int i = n-1; i >= 0; i--){
        while(b[i]){
            ll tmp = min(a[id], b[i]);
            if(id < i){
                ans += 1LL*(id+i)*tmp;
            }
            else{
                ans += 1LL*(id-i)*tmp;
            }
            a[id] -= tmp;
            b[i] -= tmp;
            if(!a[id])id++;
            //printf("ans=%lld, tmp=%d\n", ans, tmp);
        }
    }
    printf("%lld\n", ans);
    return 0;
}

