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
const int maxn = 40;
char s[maxn];
struct Mat
{
    ull a[maxn][maxn];
    void init()
    {
        memset(a, 0, sizeof(a));
    }
    void set()
    {
        init();
        for(int i = 0; i < maxn; i++)a[i][i] = 1;
    }
}mat;
struct Node
{
    int nxt[maxn][26], fail[maxn], last[maxn];
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
    void insert()
    {
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int u = s[i]-'a';
            int &v = nxt[rt][u];
            if(v == -1){
                v = ++idx;
                init(idx);
            }
            rt = nxt[rt][u];
        }
        last[rt] = 1;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        for(int i = 0; i < 26; i++){
            int &v = nxt[rt][i];
            if(v == -1)v = rt;
            else{
                fail[v] = rt;
                q.push(v);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < 26; i++){
                int &v = nxt[u][i], w = fail[u];
                if(v == -1)v = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    if(last[fail[v]])last[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    void build()
    {
        mat.init();
        for(int i = 0; i <= idx; i++){
            for(int j = 0; j < 26; j++){
                int k = nxt[i][j];
                if(!last[i] && !last[k])mat.a[i][k]++;
            }
        }
        for(int i = 0; i <= idx+1; i++){
            mat.a[i][idx+1] = 1;
        }
    }
}ACAM;

Mat mul(Mat a, Mat b, int sz)
{
    Mat ret;
    ret.init();
    for(int i = 0; i <= sz; i++){
        for(int k = 0; k <= sz; k++){
            for(int j = 0; j <= sz; j++){
                ret.a[i][j] += a.a[i][k]*b.a[k][j];
            }
        }
    }
    return ret;
}

Mat mpow(Mat a, int n, int sz)
{
    Mat ret;
    ret.set();
    while(n){
        if(n&1)ret = mul(ret, a, sz);
        a = mul(a, a, sz);
        n >>= 1;
    }
    return ret;
}

int main()
{
    int n, l;
    while(scanf("%d%d", &n, &l) != EOF){
        ACAM.init();
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            ACAM.insert();
        }
        ACAM.get_fail();
        ACAM.build();
        //for(int i = 0; i <= ACAM.idx+1; i++){
            //for(int j = 0; j <= ACAM.idx+1; j++){
                //printf("%lld ", mat.a[i][j]);
            //}
            //puts("");
        //}
        mat = mpow(mat, l, ACAM.idx+1);
        ull ans = 0;
        for(int i = 0; i <= ACAM.idx+1; i++){
            ans -= mat.a[0][i];
        }
        mat.a[0][0] = 26, mat.a[0][1] = mat.a[1][1] = 1, mat.a[1][0] = 0;
        mat = mpow(mat, l, 1);
        ans = ans+mat.a[0][0]+mat.a[0][1];
        printf("%llu\n", ans);
    }
    return 0;
}

