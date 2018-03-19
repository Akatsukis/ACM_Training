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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
string s;

void solve(int l, int r, vector<ll> &vec, ll now, ll tot)
{
    now += s[l]-'0';
    if(l == r-1){
        vec.pb(tot+now);
        return;
    }
    solve(l+1, r, vec, 0, now+tot);
    solve(l+1, r, vec, now*10, tot);
}

int calc()
{
    int ret = 0, n = s.size();
    for(int i = 1; i < n; i++){
        vector<ll> u, v;
        solve(0, i, u, 0, 0);
        solve(i, n, v, 0, 0);
        for(int i = 0; i < (int)u.size(); i++){
            for(int j = 0; j < (int)v.size(); j++){
                if(u[i] == v[j])ret++;
            }
        }
    }
   return ret;
}

int main()
{
    while(cin >> s){
        if(s == "END")break;
        int ans = calc();
        printf("%d\n", ans);
    }
    return 0;
}

