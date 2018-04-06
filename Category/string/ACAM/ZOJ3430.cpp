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
const int maxs = 5e4+10;
const int maxnode = 5e4+10;
const int maxlen = 256;
char s[maxs];
bool bnr[maxs];
int t[maxs];
struct Node
{
    int nxt[maxnode][maxlen], fail[maxnode], last[maxnode], qry[maxnode];
    int idx;
    queue<int> q;
    void init()
    {
        memset(nxt[0], -1, sizeof(nxt[0]));
        fail[0] = last[0] = qry[0] = 0;
        idx = 0;
        while(!q.empty())q.pop();
    }
    void init(int u)
    {
        memset(nxt[u], -1, sizeof(nxt[u]));
        fail[u] = last[u] = qry[u] = 0;
    }
    void insert(int n)
    {
        int rt = 0;
        for(int i = 0; i < n; i++){
            int v = nxt[rt][t[i]];
            if(v == -1){
                nxt[rt][t[i]] = ++idx;
                init(idx);
            }
            rt = nxt[rt][t[i]];
        }
        last[rt] = 1;
    }
    void get_fail()
    {
        int rt = 0;
        fail[rt] = rt;
        for(int i = 0; i < maxlen; i++){
            int v = nxt[rt][i];
            if(v == -1)nxt[rt][i] = rt;
            else{
                fail[v] = rt;
                q.push(v);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < maxlen; i++){
                int v = nxt[u][i], w = fail[u];
                if(v == -1)nxt[u][i] = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    q.push(v);
                }
            }
        }
    }
    int get_ans(int n, int id)
    {
         int rt = 0, ret = 0;
         for(int i = 0; i < n; i++){
            rt = nxt[rt][t[i]];
            int tmp = rt;
            while(tmp){
                if(last[tmp] && qry[tmp] != id){
                    ret++;
                    qry[tmp] = id;
                }
                tmp = fail[tmp];
            }
         }
         return ret;
    }
}ACAM;

int id(char c)
{
    if(isupper(c))return c-'A';
    else if(islower(c))return c-'a'+26;
    else if(isdigit(c))return c-'0'+52;
    else if(c == '+')return 62;
    else if(c == '-')return 63;
    return 64;
}

int cal(int pos)
{
    int ret = 0;
    for(int i = pos; i < pos+8; i++){
        ret = ret*2+bnr[i];
    }
    return ret;
}

int decode()
{
    int len = 0, ret = 0, n = strlen(s);
    for(int i = 0; i < n; i++){
        int u = id(s[i]);
        if(u == 64){
            len -= 2;
            continue;
        }
        for(int j = 0; j < 6; j++){
            bnr[len+5-j] = u%2;
            u /= 2;
        }
        len += 6;
    }
    for(int i = 0; i < len; i += 8){
        t[ret++] = cal(i);
    }
    return ret;
}

int main()
{
    int n, m;
    while(scanf("%d", &n) != EOF){
        ACAM.init();
        for(int i = 1; i <= n; i++){
            scanf("%s", s);
            int len = decode();
            ACAM.insert(len);
        }
        ACAM.get_fail();
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            scanf("%s", s);
            int len = decode();
            int ans = ACAM.get_ans(len, i);
            printf("%d\n", ans);
        }
        puts("");
    }
    return 0;
}

