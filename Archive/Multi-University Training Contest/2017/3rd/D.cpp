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
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e5+10;
struct Trie
{
    int l, r, sum, ext;
}trie[maxn*32];
int a[maxn];
int cnt[32][2];
int n, cur;
ll ans;

void Insert(int &o, int val, int d)
{
    if(o == 0)o = ++cur;
    trie[o].sum++;
    if(d == -1)return;
    int nxt = (val >> d) & 1;
    if(nxt){
        cnt[d][1]++;
        //printf("trie[%d].ext=%d\n", o, trie[o].ext);
        Insert(trie[o].r, val, d - 1);
        trie[trie[o].r].ext += cnt[d][1];
    }
    else{
        cnt[d][0]++;
        //printf("trie[%d].ext=%d\n", o, trie[o].ext);
        Insert(trie[o].l, val, d - 1);
        trie[trie[o].l].ext += cnt[d][0];
    }
}

void cal(int o, int val, int d)
{
    if(d == -1 || !o)return;
    int nxt = (val >> d) & 1;
    if(nxt){
        int son = trie[o].l;
        if(son)ans += 1LL*(trie[son].sum)*cnt[d][!nxt]-trie[son].ext;
        //printf("val=%d d=%d, son=%d trie[son].sum=%d cnt[d][!nxt]=%d trie[son].ext=%d\n", val, d, son, trie[son].sum, cnt[d][!nxt], trie[son].ext);
        cal(trie[o].r, val, d - 1);
    }
    else{
        int son = trie[o].r;
        if(son)ans += 1LL*(trie[son].sum)*cnt[d][!nxt]-trie[son].ext;
        //printf("val=%d d=%d, son=%d trie[son].sum=%d cnt[d][!nxt]=%d trie[son].ext=%d\n", val, d, son, trie[son].sum, cnt[d][!nxt], trie[son].ext);
        cal(trie[o].l, val, d - 1);
    }
}

int main()
{
#ifdef Akatsuki
    //frein;
    //freout;
#endif // Akatsuki
    int T;
    sc(T);
    while(T--){
        memset(trie, 0, (cur+1)*sizeof(trie[0]));
        //memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
        cur = ans = 0;
        sc(n);
        for(int i = 0; i < n; i++){
            sc(a[i]);
        }
        int root = 0;
        for(int i = 0; i < n; i++){
            if(i >= 2)cal(root, a[i], 30);
            Insert(root, a[i], 30);
            //printf("ans=%lld\n", ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

