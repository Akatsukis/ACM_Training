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
#define Abs(x) ((x)>=0?(x):(-(x)))
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
int a[maxn];
int n;

int main()
{
    sc(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        sc(a[i]);
        mx = max(mx, a[i]);
    }
    if(n == 1){
        printf("YES\n");
        printf("%d %d\n", 1, a[0]);
        return 0;
    }
    int pre = a[0], m = 0;
    for(int i = 1; i < n; i++){
        if(Abs(pre-a[i]) != 1){
            if(m && m != Abs(pre-a[i])){
                printf("NO\n");
                return 0;
            }
            else m = Abs(pre-a[i]);
        }
        if(a[i] == a[i-1]){
            printf("NO\n");
            return 0;
        }
        pre = a[i];
    }
    if(m == 0){
        printf("YES\n");
        printf("1 %d\n", mx);
        return 0;
    }
    for(int i = 1; i < n; i++){
        if((a[i-1]%m)+(a[i]%m)==1){
            printf("NO\n");
            return 0;
        }
        mx = max(mx, a[i]);
    }
    printf("YES\n");
    printf("%d %d\n", (mx-1)/m+1, m);
    return 0;
}

