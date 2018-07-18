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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int a[maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        int n;
        sc(n);
        for(int i = 1; i <= n; i++)sc(a[i]);
        int ans = 0;
        //if(n >= 5){
            //ans = max(ans, a[4]-a[2]-2+(a[n]-a[4]-n+4)*2);
            //ans = max(ans, a[n-1]-a[n-3]-2+(a[n-3]-a[1]-n+4)*2);
        //}
        //else{
            ans = max(ans, a[n-1]-a[1]);
            ans = max(ans, a[n]-a[2]);
            ans -= n-2;
        //}
        printf("%d\n", ans);
    }
    return 0;
}
