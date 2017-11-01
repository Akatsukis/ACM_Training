#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e6 + 10;
int n;
ll f[maxn];
ll inv[maxn];
map<pii, int> mp;
int kase;
struct node
{
    int l, r, id;
    bool operator < (const node &b)const{
        if(l == b.l)return r > b.r;
        return l < b.l;
    }
}p[maxn];
bool flag;
int rear;


namespace IO {
    const int MX = 4e7; //1e7占用内存11000kb
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}

void init()
{
    f[0] = f[1] = inv[0] = inv[1] = 1;
    for(int i = 1; i < maxn; i++)f[i] = f[i - 1] * i % mod;
    for(int i = 2; i < maxn; i++)inv[i] = (mod - (mod / i)) * inv[mod % i] % mod;
    for(int i = 1; i < maxn; i++)inv[i] = inv[i - 1] * inv[i] % mod;

}

ll C(ll i, ll j)
{
    ll res = (f[i] * inv[j] % mod) * inv[i - j] % mod;
    //printf("C(%d,%d)=%lld\n", i, j, res);
    return res;
}

ll dfs(int l, int r)
{
    //printf("dfs(%d,%d)\n", l, r);
    if(!flag)return 0;
    if(l > r)return 1;
    if(p[rear].l != l || p[rear].r != r){
        flag = 0;
        return 0;
    }
    node now = p[rear++];
    ll res = C(now.r - now.l, now.id - now.l) * dfs(now.l, now.id - 1) % mod;
    res = (res * dfs(now.id + 1, now.r)) % mod;
    return res;
}

void work()
{

    for(int i = 1; i <= n; i++){
        IO::read(p[i].l);
    }
    for(int i = 1; i <= n; i++){
        IO::read(p[i].r);
        p[i].id = i;
    }
    sort(p + 1, p + n + 1);
    flag = 1;
    rear = 1;
    ll ans = dfs(1, n);
    printf("Case #%d: %lld\n", kase++, ans);
}

int main()
{
    kase = 1;
    init();
    IO::begin();
    while(IO::read(n)){
        work();
    }
    return 0;
}


