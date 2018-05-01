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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3+10;
int deg[maxn];
int a[maxn];
vector<pii> ans;

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]);
    int now = 1, x = a[n]+1;
    for(int i = 1; i <= x; i++){
        int tmp = 0;
        if(deg[i]+x-i < a[now])tmp = a[now-1]-deg[i];
        else tmp = a[now]-deg[i];
        for(int j = 0; j < tmp; j++){
            ans.pb(mk(i, x-j));
            deg[i]++, deg[x-j]++;
        }
        now = min(now+1, n);
    }
    printf("%d\n", (int)ans.size());
    for(auto p : ans)printf("%d %d\n", p.fi, p.se);
    return 0;
}

