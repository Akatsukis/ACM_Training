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
const ll mod = 100000;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
const int maxs = 20;
char s[maxs];
int id(char c)
{
    if(c == 'A')return 0;
    else if(c == 'T')return 1;
    else if(c == 'C')return 2;
    return 3;
}
struct Mat
{
    ll a[maxn][maxn];
    void init()
    {
        memset(a, 0, sizeof(a));
    }
    void set()
    {
        init();
        for(int i = 0; i < maxn; i++)a[i][i] = 1;
    }
}mat;
struct Node
{
    int nxt[maxn][4], fail[maxn], last[maxn];
    int idx;
    void init()
    {
        memset(nxt[0], -1, sizeof(nxt[0]));
        fail[0] = last[0] = 0;
        idx = 0;
    }
    void init(int u)
    {
        memset(nxt[u], -1, sizeof(nxt[u]));
        fail[u] = last[u] = 0;
    }
    void insert()
    {
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int u = id(s[i]);
            if(nxt[rt][u] == -1){
                nxt[rt][u] = ++idx;
                init(idx);
            }
            rt = nxt[rt][u];
        }
        last[rt] = 1;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        for(int i = 0; i < 4; i++){
            if(nxt[rt][i] == -1)nxt[rt][i] = rt;
            else{
                fail[nxt[rt][i]] = rt;
                q.push(nxt[rt][i]);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int v = fail[u];
                if(nxt[u][i] == -1)nxt[u][i] = nxt[v][i];
                else{
                    fail[nxt[u][i]] = nxt[v][i];
                    if(last[fail[nxt[u][i]]])last[nxt[u][i]] = 1;
                    q.push(nxt[u][i]);
                }
            }
        }
    }
    void build()
    {
        mat.init();
        for(int i = 0; i <= idx; i++){
            for(int j = 0; j < 4; j++){
                int k = nxt[i][j];
                if(!last[i] && !last[k])mat.a[i][k]++;
            }
        }
    }
}ACAM;

Mat mul(Mat a, Mat b)
{
    Mat ret;
    ret.init();
    for(int i = 0; i <= ACAM.idx; i++){
        for(int k = 0; k <= ACAM.idx; k++){
            for(int j = 0; j <= ACAM.idx; j++){
                ret.a[i][j] = (ret.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
            }
        }
    }
    return ret;
}

Mat mpow(Mat a, int n)
{
    Mat ret;
    ret.set();
    while(n){
        if(n&1)ret = mul(ret, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ret;
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        ACAM.init();
        for(int i = 1; i <= n; i++){
            scanf("%s", s);
            ACAM.insert();
        }
        ACAM.get_fail();
        ACAM.build();
        mat = mpow(mat, m);
        ll ans = 0;
        for(int i = 0; i <= ACAM.idx; i++){
            ans = (ans+mat.a[0][i])%mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

