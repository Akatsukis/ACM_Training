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
const int maxn = 30;
const int maxs = 10;
const int maxlen = 26;
struct Trie
{
    int nxt[maxlen];
    int fail, last;
    void init()
    {
        memset(nxt, -1, sizeof(nxt));
        fail = last = 0;
    }
}trie[maxs];
struct Matrix
{
    ull mat[maxn][maxn];
    int sz;
    Matrix(){}
    Matrix(int _n)
    {
        sz = _n;
        memset(mat, 0, sizeof(mat));
    }
    Matrix operator *(const Matrix &rhs)const
    {
        Matrix ret = Matrix(sz);
        for(int i = 0; i <= sz; i++){
            for(int j = 0; j <= sz; j++){
                for(int k = 0; k <= sz; k++){
                    ret.mat[i][j] +=  mat[i][k]*rhs.mat[k][j]; 
                }
            }
        }
        return ret;
    }   
};
char s[maxs];
int idx;

void Insert()
{
    int n = strlen(s), rt = 0;
    for(int i = 0; i < n; i++){
        int u = s[i]-'a';
        if(trie[rt].nxt[u] == -1){
            trie[rt].nxt[u] = ++idx;
            trie[idx].init();
        }
        rt = trie[rt].nxt[u];
    }
    trie[rt].last = 1;
}

void get_fail()
{
    int rt = 0;
    queue<int> q;
    for(int i = 0; i < maxlen; i++){
        int &u = trie[rt].nxt[i];
        if(u == -1)u = rt;
        else{
            trie[u].fail = rt;
            q.push(u);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < maxlen; i++){
            int &v = trie[u].nxt[i], w = trie[u].fail;
            if(v == -1){
                v = trie[w].nxt[i];
            }
            else{
                int x = trie[w].nxt[i];
                trie[v].fail = x;
                if(x != -1 && trie[x].last)trie[v].last = 1;
                q.push(v);
            }
        }
    }
}

void Build(Matrix &p)
{
    for(int i = 0; i <= idx; i++){
        for(int j = 0; j < maxlen; j++){
            int k = trie[i].nxt[j];
            if(!trie[i].last && !trie[k].last)p.mat[i][k]++;
        }   
    }
    for(int i = 0; i <= idx+1; i++){
        p.mat[i][idx+1] = 1;
    }
}


Matrix matpow(Matrix p, int sz, int n)
{
    Matrix ret = Matrix(sz);
    for(int i = 0; i <= sz; i++)ret.mat[i][i] = 1;
    while(n){
        if(n&1)ret = ret*p; 
        p = p*p;
        n >>= 1;
    }
    return ret;
}

int main()
{
    int n, L;
    while(scanf("%d%d", &n, &L) != EOF){
        idx = 0;
        trie[0].init();
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            Insert();
        }
        get_fail();
        Matrix p = Matrix(idx+1);
        Build(p);
        ull ans = 0;
        p = matpow(p, idx+1, L);
        for(int i = 0; i <= idx+1; i++){
            ans -= p.mat[0][i];
        }
        Matrix q = Matrix(1);
        q.mat[0][0] = 26, q.mat[1][0] = q.mat[1][1] = 1;
        q = matpow(q, 1, L);
        ans += q.mat[0][0]+q.mat[1][0];
        printf("%llu\n", ans);
    }
    return 0;
}

