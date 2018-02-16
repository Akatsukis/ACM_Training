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
#define pr(x) printf(">>>"#x:"%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
vector<ll> ans;

int main()
{
    ll p, k;
    scanf("%lld%lld", &p, &k);
    int sgn = 1; 
    ll lft = p;
    while(lft >= k){
        if(sgn == -1){
            ans.pb((lft+k-1)/k*k-lft);
            lft = (lft+k-1)/k;
        }
        else{
            ans.pb(lft%k);
            lft = lft/k;
        }
        //printf(">>>%lld\n", lft);
        sgn *= -1;
    }
    if(sgn == -1){
        ans.pb(k-lft);
        ans.pb(1);
    }
    else ans.pb(lft);
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); i++)printf("%lld%c", ans[i], " \n"[i==(int)ans.size()]);
    return 0;
}

