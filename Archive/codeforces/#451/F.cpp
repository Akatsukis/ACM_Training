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
const int maxn = 2e6+10;
char s[maxn];
ll Hash[maxn];
ll p[maxn];
int base = 10, n;

bool check(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)return 0;
    if(c < max(a, b))return 0;
    if((a!=1&&s[0]=='0')||(b!=1&&s[a]=='0')||(c!=1&&s[a+b]=='0'))return 0;
    //printf("a=%d b=%d c=%d\n", a, b, c);
    ll av = Hash[a] - Hash[0]*p[a];
    ll bv = Hash[a+b] - Hash[a]*p[b]%mod;
    ll cv = Hash[a+b+c] - Hash[a+b]*p[c]%mod;
    if((av+bv+mod)%mod == (cv+mod)%mod){
        for(int i = 0; i < a; i++)printf("%c", s[i]);
        printf("+");
        for(int i = a; i < a+b; i++)printf("%c", s[i]);
        printf("=");
        for(int i = a+b; i < a+b+c; i++)printf("%c", s[i]);
        printf("\n");
        return 1;
    }
    else return 0;
}

bool solve(int t)
{
    if(check(t-1, n-t-(t-1), t))return 1;
    if(check(t, n-t-t, t))return 1;
    if(check(n-t-(t-1), t-1, t))return 1;
    if(check(n-t-t, t, t))return 1;
    return 0;
}

int main()
{
    scanf("%s", s);
    n = strlen(s);
    p[0] = 1;
    for(int i = 1; i < maxn; i++)p[i] = (p[i-1]*10)%mod;
    for(int i = 0; i < n; i++){
        Hash[i+1] = Hash[i]*base + s[i]-'0';
        Hash[i+1] %= mod;
        //printf("Hash[%d]:%lld\n", i+1, Hash[i+1]);
    }
    for(int i = 1; i < n; i++){
        if(solve(i))return 0;
    }
    return 0;
}

