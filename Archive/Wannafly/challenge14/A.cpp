include <bits/stdc++.h>
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

int main()
{
    int T;
    sc(T);
    while(T--){
        ull n, m;
        scanf("%llu%llu", &n, &m);
        ull ans1 = (n+1)*(n+2)/2;
        ull ans2 = n+3;
        if(ans1 % 3 == 0)ans1 /= 3;
        else ans2 /= 3;
        ull ans = (ans1%m)*(ans2%m)%m;
        printf("%llu\n", ans);
    }
    return 0;
}

