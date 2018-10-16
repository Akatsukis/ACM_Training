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
const int maxn = 2e6+10;
int a[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++){
        char s[20];
        int d;
        scanf("%s%d", s, &d);
        if(s[1] == 'h')a[i] = a[d];
        else{
            a[i] = a[i-1]^d;
        }
        printf("%d\n", a[i]);
    }
    return 0;
}

