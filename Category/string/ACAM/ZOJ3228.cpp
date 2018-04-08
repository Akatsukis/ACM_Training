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
const int maxn = 6e5+10;
const int maxlen = 26;
const int maxs = 1e5+10;
char s[maxs], t[maxs];
int opt[maxn], ans[maxn];
struct Node
{
    int nxt[maxn][maxlen], fail[maxn], pre[maxn], qry[maxn][2], last[maxn], len[maxn];
    int idx;
    void init()
    {
        memset(nxt[0], -1, sizeof(nxt[0]));
        fail[0] = qry[0][0] = qry[0][1] = last[0] = 0;
        idx = 0;
    }
    void init(int u)
    {
        memset(nxt[u], -1, sizeof(nxt[u]));
        fail[u] = qry[u][0] = qry[u][1] = last[u] = 0;
    }
    int insert()
    {
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int &v = nxt[rt][s[i]-'a'];
            if(v == -1){
                v = ++idx;
                init(idx);
            }
            rt = nxt[rt][s[i]-'a'];
            len[rt] = i+1;
        }
        last[rt] = 1;
        return rt;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
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
    void solve()
    {
        memset(pre, -1, sizeof(pre));
        int rt = 0, n = strlen(t);
        for(int i = 0; i < n; i++){
            rt = nxt[rt][t[i]-'a'];
            int tmp = rt;
            while(tmp){
                if(last[tmp]){
                    qry[tmp][0]++;    
                    if(i-pre[tmp] >= len[tmp]){
                        qry[tmp][1]++;
                        pre[tmp] = i;
                    }
                }
                tmp = fail[tmp];
            }
        }
    }
}ACAM;


int main()
{
    int kase = 1;
    while(scanf("%s", t) != EOF){
        ACAM.init();
        memset(ans, 0, sizeof(ans));
        int n;
        sc(n);
        for(int i = 1; i <= n; i++){
            scanf("%d%s", &opt[i], s);
            ans[i] = ACAM.insert();
        }
        ACAM.get_fail();
        ACAM.solve();
        printf("Case %d\n", kase++);
        for(int i = 1; i <= n; i++)printf("%d\n", ACAM.qry[ans[i]][opt[i]]);
        puts("");
    }
    return 0;
}

