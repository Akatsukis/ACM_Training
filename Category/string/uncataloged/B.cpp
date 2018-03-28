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
const int maxn = 1e7+10;
int trie[maxn][2];
int val[maxn];
int sz[maxn];
int idx;

void init()
{
    memset(trie[0], 0, sizeof(trie[0]));
    idx = 0;
}

void Insert(int num)
{
    int rt = 0;
    for(int i = 31; i >= 0; i--){
        int nxt = (num>>i)&1;
        if(!trie[rt][nxt]){
            trie[rt][nxt] = ++idx;
            memset(trie[idx], 0, sizeof(trie[idx]));
            sz[idx] = 0;
        }
        rt = trie[rt][nxt];
        sz[rt]++;
    }
}

void Remove(int num)
{
    int rt = 0;
    for(int i = 31; i >= 0; i--){
        int nxt = (num>>i)&1;
        rt = trie[rt][nxt];
        sz[rt]--;
    }
}

int query(int num)
{
    int rt = 0, ans = 0;
    for(int i = 31; i >= 0; i--){
        int nxt = !((num>>i)&1);
        if(trie[rt][nxt] && sz[trie[rt][nxt]]){
            ans += (1<<i);
            rt = trie[rt][nxt];
        }
        else rt = trie[rt][!nxt];
    }
    return ans;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        int n;
        sc(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            sc(val[i]);
            Insert(val[i]);
        }
        for(int i = 0; i < n; i++){
            Remove(val[i]);
            for(int j = i+1; j < n; j++){
                Remove(val[j]);
                ans = max(ans, query(val[i]+val[j]));
                Insert(val[j]);
            }
            Insert(val[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

