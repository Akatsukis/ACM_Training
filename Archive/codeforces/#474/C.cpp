#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
ll x, d, cnt = 1;
vector<ll> ans;

void solve(int n)
{
    if(!n)return;
    int k = 0;
    while((1<<k)-1 <= n)k++;
    k--;
    for(int i = 0; i < k; i++){
        ans.pb(cnt);
    }
    cnt += d+1;
    solve(n-(1<<k)+1);
}

int main()
{
    scanf("%lld%lld", &x, &d);
    solve(x);
    printf("%d\n", SZ(ans));
    for(int i = 0; i < SZ(ans); i++){
        printf("%lld%c", ans[i], " \n"[i==SZ(ans)-1]);
    }
    return 0;
}


