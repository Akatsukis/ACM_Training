#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 4e5;
ll a[maxn];
map<ll, ll> mp;

int main()
{
    int n;
    sc(n);
    ull ans1 = 0, ans2 = 0;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        sum += a[i];
        if(a[i] > 0){
            ans1 += a[i]*i;
        }
        else{
            ans2 += a[i]*i;
        }
        if(sum > 0)ans2 += sum;
        else ans1 += sum;
        if(mp.count(a[i]-1)){
            ans2 += mp[a[i]-1];
        }
        if(mp.count(a[i]+1)){
            ans1 += mp[a[i]+1];
        }
        ull tmp = min(ans1, ans2);
        ans1 -= tmp;
        ans2 -= tmp;
        mp[a[i]]++;
    }
    if(ans1 < ans2){
        printf("-%llu\n", ans2 - ans1);
    }
    else{
        printf("%llu\n", ans1 - ans2);
    }
    return 0;
}

