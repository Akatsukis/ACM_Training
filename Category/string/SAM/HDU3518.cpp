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
const int maxn = 2e3+10;
struct Trie
{
    int nxt[maxn][26], par[maxn], len[maxn];
    int idx, lst;
    int newnode()
    {
        int u = ++idx;
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = 0;
        return u;
    }
    void init()
    {
        idx = 0;
        lst = newnode();
    }
    void extend(int c)
    {
        int rt = lst, np = newnode();
        len[np] = len[rt]+1;
        for(; rt && !nxt[rt][c]; rt = par[rt])nxt[rt][c] = np;
        if(!rt)par[np] = 1;
        else{
            int q = nxt[rt][c];
            if(len[q] == len[rt]+1)par[np] = q;
            else{
                int nq = ++idx;
                len[nq] = len[rt]+1;
                par[nq] = par[q];
                memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
                par[q] = par[np] = nq;
                for(; rt && nxt[rt][c] == q; rt = par[rt])nxt[rt][c] = nq;
            }
        }
        lst = np;
    }
    int query(char* t)
    {
        int n = strlen(t);
        for(int i = 0; i < n; i++){
            
        }
    }
}SAM;

int main()
{

    return 0;
}

