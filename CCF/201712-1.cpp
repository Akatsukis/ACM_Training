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
#define Abs(x) ((x)>=0?(x):(-(x)))
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
int a[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++)sc(a[i]);
    int ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans = min(ans, Abs(a[i]-a[j]));
        }
    }
    printf("%d\n", ans);
    return 0;
}

