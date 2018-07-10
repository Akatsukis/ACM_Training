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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e6+10;
char s[maxn], t[maxn];
int ma[maxn], tb[maxn];
vector<int> G[maxn];
int bit[maxn];
int n;

void init()
{
    for(int i = 0; i < maxn; i++)G[i].clear();
    memset(bit, 0, sizeof(bit));
}

void manacher()
{
    t[0] = '$', t[1] = '#';
    int n = strlen(s);
    for(int i = 0; i < n; i++)t[i*2+2] = s[i], t[i*2+3] = '#';
    int mx = -1, ctr = -1;
    for(int i = 1; i < 2*n+2; i++){
        if(mx > i)ma[i] = min(ma[2*ctr-i], mx-i);
        else ma[i] = 1;
        while(t[i-ma[i]] == t[i+ma[i]])ma[i]++;
        if(i+ma[i]-1 > mx){
            mx = i+ma[i]-1;
            ctr = i;
        }
    }
    for(int i = 0; i < n; i++){
        tb[i+1] = (ma[i*2+2]-1)/2;
        //printf("tb[%d]=%d\n", i, tb[i]);
    }   
}

void add(int x, int v)
{
    while(x <= n){
        bit[x] += v;
        x += x&-x;
    }
}

int sum(int x)
{
    int ret = 0;
    while(x){
        ret += bit[x];
        x -= x&-x;
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        scanf("%s", s);
        n = strlen(s);
        manacher();
        ll ans = 0;
        for(int i = 1; i <= n; i++)G[i-tb[i]].pb(i);
        for(int i = 1; i <= n; i++){
            for(auto u : G[i])add(u, 1);
            ans += sum(i+tb[i])-sum(i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

