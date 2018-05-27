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
const int maxn = 5e3+10;
int a[maxn];
int tag[maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        memset(a, 0, sizeof(a));
        memset(tag, 0, sizeof(tag));
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++){
            sc(a[i]);
        }
        tag[0] = tag[n+1] = 1;
        for(int i = 1; i <= n; i++){
            if(a[i] <= a[i-1] && a[i] <= a[i+1])tag[i] = 1;
        }
        for(int i = 1; i <= n; i++){
           m
        }
    }
    return 0;
}

