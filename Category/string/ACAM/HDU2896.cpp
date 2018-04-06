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
const int maxm = 1e3+10;
const int maxs = 1e4+10;
const int maxlen = 128;
char s[maxs];
vector<int> ans[maxm];
struct Node
{
    int nxt[maxn][maxlen], fail[maxn], last[maxn];
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
    void insert(int id)
    {
        int rt = 0, n = strlen(s)-1;
        for(int i = 0; i < n; i++){
            int u = s[i];
            int &v = nxt[rt][u];
            if(v == -1){
                v = ++idx;
                init(idx);
            }
            rt = nxt[rt][u];
        }
        last[rt] = id;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        fail[rt] = rt;
        for(int i = 0; i < maxlen; i++){
            int &v = nxt[rt][i];
            if(v == -1)v = rt;
            else{
                fail[v] = rt;
                q.push(v);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < maxlen; i++){
                int &v = nxt[u][i], w = fail[u];
                if(v == -1)v = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    q.push(v);
                }
            }

        }
    }
    void get_ans(int id)
    {
        int rt = 0, n = strlen(s)-1;
        for(int i = 0; i < n; i++){
            int u = s[i];
            rt = nxt[rt][u];
            int tmp = rt;
            while(tmp){
                if(last[tmp]){
                    ans[id].pb(last[tmp]);
                }
                tmp = fail[tmp];
            }
        }
    }
}ACAM;

int main()
{
    int n;
    scanf("%d\n", &n);
    ACAM.init();
    for(int i = 1; i <= n; i++){
        fgets(s, maxs, stdin);
        ACAM.insert(i);
    }
    ACAM.get_fail();
    int m;
    scanf("%d\n", &m);
    for(int i = 1; i <= m; i++){
        fgets(s, maxs, stdin);
        ACAM.get_ans(i);
    }
    int tot = 0;
    for(int i = 1; i <= m; i++){
        if(ans[i].size()){
            tot++;
            sort(ALL(ans[i]));
            printf("web %d:", i);
            for(auto u : ans[i])printf(" %d", u);
            puts("");
        }
    }
    printf("total: %d\n", tot);
    return 0;
}

