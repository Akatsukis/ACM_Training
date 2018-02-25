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
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000009;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
ll N, A, B;
ll p[maxn];
ll q[maxn];

ll solve(int i)
{
    ll u = i, v = N-i;
    if(u>A||v>B)return 0;
    else return p[u]*q[v]%mod;
}

void init()
{
    p[0] = 1; q[0] = 1;
    for(int i = 1; i <= A; i++){
        p[i] = p[i-1]*(A-i+1)%mod;
    }
    for(int i = 1; i <= B; i++){
        q[i] = q[i-1]*(B-i+1)%mod;
    }
}

int main()
{
    scanf("%lld%lld%lld", &N, &A, &B);
    init();
    ll ans = 0;
    for(int i = 2; i <= N-1; i++){
        ans = (ans+solve(i))%mod;
    }
    printf("%lld\n", ans);
    return 0;
}

