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

int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll rem = n-1, now = 1;
    int ans = 0;
    while(rem > 0){
        ans++;
        rem -= now*k;
        now += now*k;
    }
    printf("%d\n", ans);
    return 0;
}

