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
const int maxn = 1e3+10;
const int maxs = 50+10;
const int maxnode = 5e4+10;
const int maxlen = 26;
const int maxt = 2e6+10;
int ans[maxn];
char s[maxn][maxs], t[maxt];
struct Node{
    int nxt[maxnode][maxlen], fail[maxnode], last[maxnode];
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
        int rt = 0, n = strlen(s[id]);
        for(int i = 0; i < n; i++){
            int u = s[id][i]-'A';
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
        int rt = 0;
        fail[rt] = rt;
        queue<int> q;
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
    void get_ans()
    {
        int rt = 0, n = strlen(t)-1;
        for(int i = 0; i < n; i++){
            if(!isupper(t[i])){
                rt = 0;
                continue;
            }
            rt = nxt[rt][t[i]-'A'];
            int tmp = rt;
            while(tmp){
                if(last[tmp])ans[last[tmp]]++;
                tmp = fail[tmp];
            }
        }
    }
}ACAM;

int main()
{
    int n;
    while(scanf("%d\n", &n) != EOF){
        memset(ans, 0, sizeof(ans));
        ACAM.init();
        for(int i = 1; i <= n; i++){
            scanf("%s\n", s[i]);
            ACAM.insert(i);
        }
        ACAM.get_fail();
        fgets(t, maxt, stdin);
        ACAM.get_ans();
        for(int i = 1; i <= n; i++){
            if(ans[i])printf("%s: %d\n", s[i], ans[i]);
        }
    }
    return 0;
}

