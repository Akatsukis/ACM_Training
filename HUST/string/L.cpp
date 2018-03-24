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
const int maxlen = 26;
const int maxs = 1e6+10;
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
char s[maxs];
int idx;

void Insert()
{
    int n = strlen(s), rt = 0;;
    for(int i = 0; i < n; i++){
        int u = s[i]-'a';
        if(trie[rt].nxt[u] == -1){
            trie[rt].nxt[u] = ++idx;
            trie[idx].init();
        }
        rt = trie[rt].nxt[u];
    }
    trie[rt].last = n;
}

void get_fail()
{
    int rt = 0;
    trie[rt].fail = rt;
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
            int &v = trie[u].nxt[i];
            int w = trie[u].fail;
            if(v == -1)v = trie[w].nxt[i];
            else{
                trie[v].fail = trie[w].nxt[i];
                q.push(v);
            }
        }
    }
}

void Query()
{
    int n = strlen(s)-1, rt = 0;;
    for(int i = 0; i < n; i++){
        if(!isalpha(s[i])){
            rt = 0;
            continue;
        }
        int u = tolower(s[i])-'a';
        rt = trie[rt].nxt[u];
        int tmp = rt;
        while(tmp){
            if(trie[tmp].last){
                for(int j = trie[tmp].last-1; j >= 0; j--){
                    s[i-j] = '*';
                }
            }
            tmp = trie[tmp].fail;
        }
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        trie[0].init();
        idx = 0;
        int n;
        sc(n);
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            Insert();
        }
        get_fail();
        scanf(" ");
        fgets(s, maxs, stdin);
        Query();
        printf("%s", s);
    }
    return 0;
}

