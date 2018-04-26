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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
struct Trie
{
    int nxt[26], end;
}trie[maxn];
int dep[maxn];
char s[maxn];
int idx;
multiset<int> st[maxn];

void dfs(int u, int dep)
{
    for(int i = 0; i < 26; i++){
        int v = trie[u].nxt[i];
        if(v){
            dfs(v, dep+1);
            for(auto w : st[v])st[u].insert(w);
        }
    }
    if(!trie[u].end){
        st[u].erase(--st[u].end());
        st[u].insert(dep);
    }
}


int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        int rt = 0, len = strlen(s);
        for(int j = 0; j < len; j++){
            if(trie[rt].nxt[s[j]-'a'] == 0){
                trie[rt].nxt[s[j]-'a'] = ++idx;
            }
            rt = trie[rt].nxt[s[j]-'a'];
        }
        st[rt].insert(len);
        trie[rt].end = 1;
    }
    ll ans = 0;
    for(int i = 0; i < 26; i++){
        int u = trie[0].nxt[i];
        if(u){
            dfs(u, 1);
            for(auto v : st[u])ans += v;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

