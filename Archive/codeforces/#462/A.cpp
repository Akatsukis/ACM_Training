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
const int maxn = 50+10;
int a[maxn];
int b[maxn];

int main()
{
    int n, m;
    sc(n);sc(m);
    for(int i = 0; i < n; i++)sc(a[i]);
    for(int i = 0; i < m; i++)sc(b[i]);
    ll mx = -INF64, ban = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(1LL*a[i]*b[j] > mx){
                mx = 1LL*a[i]*b[j];
                ban = i;
            }
        }
    }
    ll ans = -INF64;
    for(int i = 0; i < n; i++){
        if(i==ban)continue;
        for(int j = 0; j < m; j++){
            if(1LL*a[i]*b[j] > ans)ans = 1LL*a[i]*b[j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}

