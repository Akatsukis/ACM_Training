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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

long double C(int n, int k)
{
    long double ret = 1;
    for(int i = 1; i <= k; i++){
        ret = ret*(n-i+1)/i;
    }
    return ret;
}

int main()
{
    int p, q, r, s;
    while(scanf("%d%d%d%d", &p, &q, &r, &s) != EOF){
        long double ans = C(p, q)/C(r, s);
        printf("%.5Lf\n", ans);
    }
    return 0;
}

