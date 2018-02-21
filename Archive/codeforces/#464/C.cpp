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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x:"%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int n;
int a[maxn];
int s, f;

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]);
    sc(s);sc(f);
    ll mx = 0, now = 0;
    for(int i = s; i < f; i++){
        now += a[i];
    }
    int l = s, r = f, ans = 1;
    for(int i = 1; i <= n; i++){
        int t = i>n?i-n:i;
        if(now > mx || (now == mx && t < ans)){
            mx = now;
            ans = t;
        }
        //printf(">>now=%lld, l=%d, r=%d\n", now, l, r);
        l = (l-1)<1?l-1+n:l-1, r = (r-1)<1?r-1+n:r-1;
        now = now-a[r]+a[l];
    }
    printf("%d\n", ans);
    return 0;
}

