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
const int maxn = 110;
int a[maxn];

int main()
{
    int n, s;
    sc(n); sc(s);
    for(int i = 1; i <= n; i++){
        int h, m;
        sc(h); sc(m);
        a[i] = h*60+m;
    }
    sort(a+1, a+1+n);
    if(a[1] >= s+1){
        printf("%d %d\n", 0, 0);
        return 0;
    }
    int ans = a[n]+1+s;
    for(int i = 2; i <= n; i++){
        if(a[i]-a[i-1] >= 2*s+2){
            ans = a[i-1]+1+s;
            break;
        }
    }
    printf("%d %d\n", ans/60, ans%60);
    return 0;
}

