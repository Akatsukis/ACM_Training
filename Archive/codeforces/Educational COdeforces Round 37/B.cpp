#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int n;
vector<int> ans;

int main()
{
    int T;
    sc(T);
    while(T--){
        ans.clear();
        scanf("%d", &n);
        int now = 0;
        for(int i = 0; i < n; i++){
            int l, r;
            scanf("%d%d", &l, &r);
            if(r < now)ans.pb(0);
            else{
                now = max(now, l);
                ans.pb(now);
                now++;
            }
        }
        for(int i = 0; i < (int)ans.size(); i++){
            printf("%d%c", ans[i], " \n"[i==n-1]);
        }
    }
	return 0;
}

