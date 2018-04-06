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
int pre[maxn][3], sub[maxn][3];

int main()
{
    int n, q;
    while(scanf("%d%d", &n, &q) != EOF){
        for(int i = 1; i <= n; i++){
            sc(a[i]);
        }
        pre[0][0] = sub[n+1][0] = 0x7fffffff;
        pre[0][1] = sub[n+1][1] = 0;
        pre[0][2] = sub[n+1][2] = 0;
        for(int i = 1; i <= n; i++){
            pre[i][0] = pre[i-1][0]&a[i];
            pre[i][1] = pre[i-1][1]|a[i];
            pre[i][2] = pre[i-1][2]^a[i];
        }
        for(int i = n; i >= 1; i--){
            sub[i][0] = sub[i+1][0]&a[i];
            sub[i][1] = sub[i+1][1]|a[i];
            sub[i][2] = sub[i+1][2]^a[i];
        }
        for(int i = 0; i < q; i++){
            int k;
            sc(k);
            printf("%d %d %d\n", pre[k-1][0]&sub[k+1][0], pre[k-1][1]|sub[k+1][1], pre[k-1][2]^sub[k+1][2]);
        }
    }
    return 0;
}

