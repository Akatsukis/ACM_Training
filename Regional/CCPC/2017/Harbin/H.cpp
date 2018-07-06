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
const int maxn = 5e5+10;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
int a[maxn], b[maxn];
int n;

int main()
{
    int T; 
    sc(T);
    while(T--){
        sc(n);
        ll sum = 0;
        for(int i = 0; i < n; i++)sc(a[i]), sum += a[i];
        vector<int> vec;
        for(int i = 2; (ll)i*i <= sum; i++){
            if(sum%i == 0){
                vec.pb(i);
                while(sum%i == 0)sum /= i;
            }
        }
        if(sum != 1)vec.pb(sum);
        ll ans = INF64;
        for(auto u : vec){
            for(int i = 0; i < n; i++)b[i] = a[i]%u;
            sort(b, b+n);
            ll now = 0;
            for(int l = 0, r = n-1; l < r;){
                int tmp = min(b[l], u-b[r]);
                b[l] -= tmp;
                b[r] += tmp;
                now += tmp;
                if(b[l] == 0)l++;
                if(b[r] == u)r--;
            }
            ans = min(ans, now);
        }   
        printf("%lld\n", ans);
    }
    return 0;
}

