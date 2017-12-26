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
vector<int> v, q;

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        int x;
        sc(x);
        int r = sqrt(x);
        if(r*r == x){
            if(x == 0)v.pb(2);
            else v.pb(1);
        }
        else{
            q.pb(min(x-r*r, (r+1)*(r+1)-x));
        }
    }
    ll ans = 0;
    if(v.size() > q.size()){
        int k = (v.size()-q.size())/2;
        sort(ALL(v));
        for(int i = 0; i < k; i++){
            ans += v[i];
        }
    }
    else{
        int k = (q.size()-v.size())/2;
        sort(ALL(q));
        for(int i = 0; i < k; i++){
            ans += q[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}

