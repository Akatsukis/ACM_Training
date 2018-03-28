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
const int maxn = 1e6+10;
const int maxlen = 12;
int trie[maxn][maxlen];
bool ed[maxn];
char s[maxn];
int idx;

void init()
{
    memset(trie[0], 0, sizeof(trie[0]));
    idx = 0;
}

void Insert(int &rt, int i, int len)
{
    if(!rt){
        rt = ++idx;
        memset(trie[rt], 0, sizeof(trie[rt]));
        ed[rt] = 0;
    }
    if(i == len){
        ed[rt] = 1;
        return;
    }
    Insert(trie[rt][s[i]-'0'], i+1, len);
}

bool dfs(int rt)
{
    if(ed[rt]){
        for(int i = 0; i < 10; i++){
            if(trie[rt][i])return false;
        }
        return true;
    }
    for(int i = 0; i < 10; i++){
        if(!trie[rt][i])continue;
        if(!dfs(trie[rt][i]))return false;
    }
    return true;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        int n;
        sc(n);
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            int len = strlen(s);
            Insert(trie[0][s[0]-'0'], 0, len);
        }
        bool flag = 1;
        for(int i = 0; i < 10; i++){
            flag = dfs(trie[0][i]);
            if(!flag)break;
        }
        if(!flag)puts("NO");
        else puts("YES");
    }
    return 0;
}

