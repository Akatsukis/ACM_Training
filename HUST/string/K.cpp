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
const int maxn = 1e5+10;
const int maxm = 1010;
const int maxs = 10010;
const int maxlen = 128;
struct Trie
{
    int nxt[maxlen];
    int fail, id, u;
    void init()
    {
        memset(nxt, -1, sizeof(nxt));
        fail = id = 0;
    }
}trie[maxn];
char s[maxs];
vector<int> ans;
int idx;

void Insert(int u)
{
    int n = strlen(s)-1;
    int rt = 0;
    for(int i = 0; i < n; i++){
        int id = s[i];
        if(trie[rt].nxt[id] == -1){
            trie[rt].nxt[id] = ++idx;
            trie[idx].init();
        }
        rt = trie[rt].nxt[id];
    }
    trie[rt].id = u;
}

void get_fail()
{
    queue<int> q;
    int rt = 0;
    trie[rt].fail = rt;
    for(int i = 0; i < maxlen; i++){
        if(trie[rt].nxt[i] == -1){
            trie[rt].nxt[i] = rt;
        }
        else{
            int v = trie[rt].nxt[i];
            trie[v].fail = rt;
            q.push(v);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < maxlen; i++){
            int v = trie[u].fail;
            if(trie[u].nxt[i] == -1){
                trie[u].nxt[i] = trie[v].nxt[i];
            }
            else{
                int w = trie[u].nxt[i];
                trie[w].fail = trie[v].nxt[i];
                q.push(w);
            }
        }
    }
}

void Query(int u)
{
    int n = strlen(s)-1;
    int rt = 0;
    for(int i = 0; i < n; i++){
        int id = s[i];
        rt = trie[rt].nxt[id];
        if(trie[rt].id && trie[rt].u != u){
            trie[rt].u = u;
            ans.pb(trie[rt].id);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d\n", &n);
    trie[0].init();
    for(int i = 1; i <= n; i++){
        fgets(s, maxn-1, stdin);
        Insert(i);
    }
    get_fail();
    scanf("%d\n", &m);
    int tot = 0;
    for(int i = 1; i <= m; i++){
        fgets(s, maxn-1, stdin);
        ans.clear();
        Query(i);
        if(ans.size()){
            sort(ALL(ans));
            tot++;
            printf("web %d:", i);
            for(int j = 0; j < (int)ans.size(); j++){
                printf(" %d", ans[j]);
            }
            puts("");
        }
    }
    printf("total: %d\n", tot);
    return 0;
}
