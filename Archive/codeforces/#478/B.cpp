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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
ll a[20];

int main()
{
    for(int i = 0; i < 14; i++)scanf("%lld", &a[i]);
    ll ans = 0;
    for(int i = 0; i < 14; i++){
        int b[20];
        for(int j = 0; j < 14; j++){
            b[j] = a[j];
        }
        ll now = b[i];
        b[i] = 0;
        for(int j = 0; j < 14; j++){
            b[(i+1+j)%14] += now/14+(now%14>j);
        }
        ll cnt = 0;
        for(int j = 0; j < 14; j++)if(b[j]%2==0)cnt += b[j];
        ans = max(ans, cnt);
    }
    printf("%lld\n", ans);
    return 0;
}

