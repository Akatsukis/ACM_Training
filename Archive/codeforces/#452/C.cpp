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
vector<int> ans;

int main()
{
    int n;
    sc(n);
    ll sum = (ll)n*(n+1)/2;
    ll now = sum / 2;
    for(int i = n; i >= 1; i--){
        if(now >= i){
            now -= i;
            ans.pb(i);
        }
    }
    if(sum%2)printf("1\n");
    else printf("0\n");
    printf("%d ", ans.size());
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}

