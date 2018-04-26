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
const int maxn = 1e5+10;
int a[maxn];

int main()
{
    int W, L;
    scanf("%d%d", &W, &L);
    for(int i = 1; i < W; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < W; i++)a[i] += a[i-1];
    int ans = INF;
    for(int i = L; i < W; i++){
        ans = min(ans, a[i]-a[i-L]);
    }
    printf("%d\n", ans);
    return 0;
}

