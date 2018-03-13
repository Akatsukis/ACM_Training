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
const int maxn = 5e5+10;
int kase;
int l[maxn];
int r[maxn];
bool vis[maxn];
int cnt;
vector<pair<ull, int> > ans;

void ins(int &rt, ull val, int d, int bit)
{
    if(!rt)rt = ++cnt;
    //printf("ins(%d,%llu,%d,%d)\n", rt, val, d, bit);
    if(d == 0){
        vis[rt] = 1;
        return;
    }
    int now = (val >> bit) & 1;
    if(now){
        ins(l[rt], val, d - 1, bit - 1);
    }
    else{
        ins(r[rt], val, d - 1, bit - 1);
    }
}

void dfs(int rt, ull val, int bit)
{
    //printf("dfs(%d,%llu,%d)\n", rt, val, bit);
    if(vis[rt])return;
    if(!rt){
        ans.pb(mk(val, 31 - bit));
        return;
    }
    dfs(l[rt], val + (1ull << bit), bit - 1);
    dfs(r[rt], val, bit - 1);
}

void init()
{
    cnt = 1;
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(vis, 0, sizeof(vis));
    ans.clear();
}

void work()
{
    init();
    int n;
    sc(n);
    if(!n){
        printf("Case #%d:\n", kase++);
        printf("1\n");
        printf("0.0.0.0/0\n");
        return;
    }
    int root = 1;
    for(int i = 0; i < n; i++){
        ull a, b, c, d, e;
        scanf("%llu.%llu.%llu.%llu/%llu", &a, &b, &c, &d, &e);
        ull val = ((a<<24)|(b<<16)|(c<<8)|d);
        //pr(a);pr(b);pr(c);pr(d);pr(e);
        ins(root, val, e, 31);
    }
    dfs(root, 0, 31);
    printf("Case #%d:\n", kase++);
    printf("%d\n", ans.size());
    for(int i = 0; i < (int)ans.size(); i++){
        //printf("%llu %d\n", ans[i].fi, ans[i].se);
        ull now = ans[i].fi;
        for(int j = 0; j < 4; j++){
            printf("%llu%c", now>>(8*(3-j)), (j == 3) ? '/' : '.');
            now -= (now>>(8*(3-j)))<<(8*(3-j));
        }
        printf("%d\n", ans[i].se);
    }
}

int main()
{
    kase = 1;
    int T;
    sc(T);
    while(T--){
        work();
    }
    return 0;
}


