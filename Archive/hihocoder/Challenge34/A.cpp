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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+10;
ll a[maxn], b[maxn];

int main()
{
    int T, kase = 1; sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
        for(int j = 0; j < m; j++)scanf("%lld", &b[j]);
        ll mn = INF64, mx = -INF64;
        int pn = 0, px = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < mn)mn = a[i], pn = i;
            if(a[i] > mx)mx = a[i], px = i;
        }
        ll ans = mx;
        int del = px;
        for(int i = 0; i < m; i++){
            if(mx*b[i] > ans){
                ans = mx*b[i];
                del = px;
            }
        }
        for(int i = 0; i < m; i++){
            if(mn*b[i] > ans){
                ans = mn*b[i];
                del = pn;
            }
        }
        mn = INF64, mx = -INF64;
        for(int i = 0; i < n; i++){
            if(i == del)continue;
            if(a[i] < mn)mn = a[i];
            if(a[i] > mx)mx = a[i];
        }
        ans = mx;
        for(int i = 0; i < m; i++){
            if(mx*b[i] > ans){
                ans = mx*b[i];
            }
        }
        for(int i = 0; i < m; i++){
            if(mn*b[i] > ans){
                ans = mn*b[i];
            }
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

