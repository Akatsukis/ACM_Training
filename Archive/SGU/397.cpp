#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 1e6+10;
int pre[maxn], nxt[maxn];
char ans[maxn], s[maxn];
int len;

void insert(int &cur, char c)
{
    ans[++len] = c;
    if(nxt[cur]){
        pre[nxt[cur]] = len;
        nxt[len] = nxt[cur];
    }
    nxt[cur] = len;
    pre[len] = cur;
    cur = len;
}

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            if(cur)cur = pre[cur];
        }
        else if(s[i] == 'R'){
            if(nxt[cur])cur = nxt[cur];
        }
        else{
            insert(cur, s[i]);
        }
    }
    for(int i = nxt[0]; i; i = nxt[i])putchar(ans[i]);
    return 0;
}

