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
const int maxn = 1e6+10;
const int maxlen = 26;
char s[maxn];
struct Node
{
    int nxt[maxn][maxlen], fail[maxn], last[maxn], idx;
    void init()
    {
        idx = 0;
        memset(nxt[0], -1, sizeof(nxt[0]));
        fail[0] = last[0] = 0;
    }
    void init(int x)
    {
        memset(nxt[x], -1, sizeof(nxt[x]));
        fail[x] = last[x] = 0;
    }
    void insert()
    {
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int u = s[i]-'a';
            if(nxt[rt][u] == -1){
                nxt[rt][u] = ++idx;
                init(idx);
            }
            rt = nxt[rt][u];
        }
        last[rt]++;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        fail[rt] = rt;
        for(int i = 0; i < maxlen; i++){
            int &u = nxt[rt][i];
            if(u == -1)u = rt;
            else{
                fail[u] = rt;
                q.push(u);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < maxlen; i++){
                int &v = nxt[u][i];
                int w = fail[u];
                if(v == -1)v = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    q.push(v);
                }
            }   
        }
    }
    int get_ans()
    {
        int rt = 0, n = strlen(s), ret = 0;
        for(int i = 0; i < n; i++){
            int u = s[i]-'a';
            rt = nxt[rt][u];
            int tmp = rt;
            while(tmp){
                if(last[tmp])ret += last[tmp], last[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
}ACAM;

int main()
{
    int T;
    sc(T);
    while(T--){
        int n;
        sc(n);
        ACAM.init();
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            ACAM.insert();
        }
        ACAM.get_fail();
        scanf("%s", s);
        int ans = ACAM.get_ans();
        printf("%d\n", ans);
    }
    return 0;
}

