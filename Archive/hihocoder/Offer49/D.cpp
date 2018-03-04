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
const int maxn = 31;
ll T[maxn];
int a[maxn];
ll n, k;
vector<int> ans;

void dfs(int l, int r, ll t)
{
    //printf("dfs(%d,%d,%lld)\n", l, r, t);
    if(l > r)return;
    if(l == r){
        ans.pb(a[l]);
        return;
    }
    pii p[maxn];
    for(int i = l; i <= r; i++){
        p[i-l].fi = a[i], p[i-l].se = i;
    }
    sort(p, p+r-l+1);
    for(int i = l; i <=r; i++){
        int pos = p[i-l].se;
        //printf("pos=%d\n", pos);
        if(T[pos-l]*T[r-pos] >= t){
            ans.pb(a[pos]);
            dfs(l, pos-1, (t-1)/T[r-pos]+1);
            dfs(pos+1, r, (t-1)%T[r-pos]+1);
            break;
        }
        else t -= T[pos-l]*T[r-pos];
    }
}

int main()
{
    T[0] = T[1] = 1;
    for(int i = 2; i < maxn; i++){
        for(int j = 1; j <= i; j++){
            T[i] += T[j-1]*T[i-j];
        }
        //printf("T[%d]:%lld\n", i, T[i]);
    }
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
    }
    dfs(1, n, k);
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}

