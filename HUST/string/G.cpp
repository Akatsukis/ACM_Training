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
const int maxn = 200100;
int n;
int a[maxn];
int b[maxn];
int p[maxn];

int manacher()
{
    int ret = 0;
    int id = -1, mx = -1;
    b[0] = -2, b[1] = -1;
    for(int i = 0; i < n; i++){
        b[i*2+2] = a[i];
        b[i*2+3] = -1;
    }
    for(int i = 1; i < 2*n+2; i++){
        if(i < mx)p[i] = min(p[2*id-i], mx-i);
        else p[i] = 1;
        while(b[i-p[i]] == b[i+p[i]] && (b[i-p[i]] == -1 ||  b[i-p[i]] <= b[i-p[i]+2]))p[i]++;
        if(i+p[i] > mx){
            mx = i+p[i];
            id = i;
        }
        ret = max(ret, p[i]-1);
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++){
            sc(a[i]);
        }
        int ans = manacher();
        printf("%d\n", ans);
    }
    return 0;
}

