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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
ll Pow[20];

int main()
{
    ll n;
    Pow[0] = 1;
    for(int i = 1; i < 12; i++){
        Pow[i] = Pow[i-1] * 10;
    }
    while(scanf("%lld", &n) != EOF){
        ll sum = n+n-1;
        ll now = 0;
        int cnt = 0;
        while(now*10+9 <= sum){
            now = now*10+9;
            cnt++;
        }
        //pr(now);
        ll ans = 0;
        for(ll i = 0; i < 10; i++){
            ll tmp = now+i*Pow[cnt];
            //cout << tmp << endl;
            ll a = n, b;
            if(tmp <= n + 1){
                ans += (tmp-1)/2;
                //cout << (tmp-1)/2 << endl;
            }
            else{
                ll a = n, b = tmp - n;
                if(b <= n)ans += (a-b+1) / 2;
                //cout <<(a+b-1)/2 << endl;
            }
        }
        //cout << endl;
        printf("%lld\n", ans);
    }
    return 0;
}

