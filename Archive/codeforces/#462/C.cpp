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
const int maxn = 2000+10;
int a[maxn];
int one[maxn];
int n;

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++)one[i] = one[i-1]+(a[i]==1), ans = max(ans, one[i]);
    for(int i = 1; i <= n; ){
        if(a[i] == 2){
            bool flag = 0;
            int t = 0;
            while(i+t <= n){
                if(!flag && a[i+t] == 1)flag = 1;
                else if(flag && a[i+t] == 2)break;
                t++;
            }
            ans = max(ans, one[i-1]+t+(n-i-t+1)-(one[n]-one[i+t-1]));
            i += t;
        }
        else i++;
    }
    printf("%d\n", ans);
    return 0;
}

