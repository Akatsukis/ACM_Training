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
    ll n;
    scanf("%lld", &n);
    ll ans = 0;
    if(n == 1)ans = 4;
    else if(n == 2)ans = 10;
    else if(n == 3)ans = 20;
    else if(n == 4)ans = 35;
    else if(n == 5)ans = 56;
    else if(n == 6)ans = 83;
    else if(n == 7)ans = 116;
    else if(n == 8)ans = 155;
    else if(n == 9)ans = 198;
    else if(n == 10)ans = 244;
    else if(n == 11)ans = 292;
    else if(n == 12)ans = 341;
    else if(n == 13)ans = 390;
    else ans = 390+(n-13)*49;
    printf("%lld\n", ans);
    return 0;
}

